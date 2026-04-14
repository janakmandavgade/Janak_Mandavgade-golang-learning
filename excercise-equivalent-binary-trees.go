package main

import (
	"fmt"
	"golang.org/x/tour/tree"
)

// Walk walks the tree t sending all values
// from the tree to the channel ch.
func Walk(t *tree.Tree, ch chan int){
	var walker func(*tree.Tree)
	
	walker = func(root *tree.Tree){
		if root == nil {
			return
		}
		// Use .Left, .Value, and .Right (Capitalized)
		walker(root.Left)
		ch <- root.Value
		walker(root.Right)
	}
	
	walker(t)
	
	close(ch)
}

// Same determines whether the trees
// t1 and t2 contain the same values.
func Same(t1, t2 *tree.Tree) bool {
	ch1, ch2 := make(chan int), make(chan int)
    
    go Walk(t1, ch1)
    go Walk(t2, ch2)

    for {
        v1, ok1 := <-ch1
        v2, ok2 := <-ch2

        // If both channels are closed at the same time, the trees are the same
        if !ok1 && !ok2 {
            return true
        }

        // If one finishes early, or the values don't match, they are different
        if ok1 != ok2 || v1 != v2 {
            return false
        }
    }
}

func main() {
	ch := make(chan int)
	go Walk(tree.New(1), ch)
	// var ok bool := true
	for i:=0; i < 10 ; i++ {
		v, _ := <- ch
		fmt.Printf("%v ", v)
	}
}
