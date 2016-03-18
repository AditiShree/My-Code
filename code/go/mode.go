//Mode of an array of no is no 'm' in array repeated most frequently
//if many no is having equal freq then mode doesnt exists
//write a pgm to accept an array of no and returns the mode or indication if no moe exists


package main

import(
  "fmt"
)

func swap(b, s int) (int, int) {
  return s,b
}

func findBig(c []int) (int, int)  {
  for i:=0; i<len(c); i++ {
    for j:=0; j<len(c)-i-1; j++ {
      if c[j]>c[j+1] {
        c[j], c[j+1] = swap(c[j], c[j+1])
      }
    }
  }
  return c[len(c)-1], c[len(c)-2]
}

func main() {
  var n int
  fmt.Println("Enter the no of elem in array")
  fmt.Scan(&n)
  a := make([]int, n)
  fmt.Printf("Enter %d elem", n)
  fmt.Println()
  for i:=0; i<n; i++ {
    fmt.Scan(&a[i])
  }
  c := make([]int, n)
  for i:=0; i<n; i++ {
    count := 0
    for j:=i+1; j<n; j++ {
      if a[i]==a[j] {
        count++
      }
      c[i] = count

    }
  }
  index := 0
  for i:=0; i<n-1; i++ {
    if c[i]<c[i+1] {
      index = i+1
    }
  }
  l,sl := findBig(c)

  if l==sl{
    fmt.Println("Mode doesnt exists")
  }else{
    fmt.Println("Mode is : ", a[index])
  }

}
