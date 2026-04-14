package main

import "fmt"

// List represents a singly-linked list that holds
// values of any type.
type List[T any] struct {
	next *List[T]
	val  T
}

func main() {
	
	head := &List[int]{val: 10}
	head.next = &List[int]{val: 20}
	head.next.next = &List[int]{val: 30}
	
	for current := head; current != nil; current = current.next {
		fmt.Printf("%v -> ", current.val)
	}
	fmt.Println("nil")
}
