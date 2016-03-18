package main

import(
  "fmt"
)

func swap(b, s int) (int, int) {
  return s,b
}

func main() {
  var n int
  fmt.Println("enter the no of elem of array")
  fmt.Scan(&n)
  a := make([]int, n)
  fmt.Printf("Enter %d elem ", n)
  fmt.Println()
  for i:=0; i<len(a); i++ {
    fmt.Scan(&a[i])
  }

  for i:=0; i<n; i++ {
    for j:=0; j<n-i-1; j++ {
      if a[j]>a[j+1] {
        a[j],a[j+1] = swap(a[j],a[j+1])
      }
    }
  }

  fmt.Println(a)
}
