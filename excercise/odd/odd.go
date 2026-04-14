package main

import "fmt"

func OddValues(arr []int) ([] int){

	sz := len(arr)
	
	op := make([]int, 0)
	
	for i:=0 ; i < sz ; i++ {
		if arr[i] % 2 != 0 {
			op = append(op, arr[i]);
		}
	}

	return op
}

func main() {
    input := []int{1, 2, 3, 4, 5, -7}
    result := OddValues(input)
    fmt.Println(result) // Output: [1 3 5 -7]
}