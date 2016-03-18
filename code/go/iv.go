package main 

import (
	"fmt"
	"os"
) 

func main() {
	a := make([]int, 8)
	aa := make([]int, 0)
	diff := make([]int, 0)
	c := make([]int, 0)
	for i := 0; i < len(a); i++ {
		fmt.Scan(&a[i])
	}

	for i:=0; i<len(a); i++ {
		count := 0
		if a[i]<a[i+1] {
			aa = append(aa,a[i])
			count++
		}
	}
}