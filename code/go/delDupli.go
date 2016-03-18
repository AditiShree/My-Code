//In list of 20 elem of array remove duplicate elements

package main
import (
  "fmt"
)

func check(nw []int, x int) bool {
  for i:=0; i<len(nw); i++ {
    if x==nw[i] {
      return false
    }
  }
  return true
}

func main()  {
  fmt.Println("Enter 20 elem")
  a := make([]int, 20)
  for i:=0; i<20; i++ {
    fmt.Scan(&a[i])
  }

  nw := make([]int, 1)
  nw[0] = a[0]
  for i:=1; i<20; i++{
    ok := check(nw, a[i])
    if ok{
      nw = append(nw, a[i])
    }
  }

  fmt.Println(nw)
}
