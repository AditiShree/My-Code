package main 

import (
    "fmt"
)

func makeRed(n,d int) (int,int) {
    small := 0
    if n>d{
      small = d
    }else{
      small = n
    }
    for i:=2; i<=small; i++ {
      if (n%i==0)&&(d%i==0){
        n = n/i
        d = d/i
      }  
    }
    return n,d
}

func checkSame(arr []int) []int {
  for i:=0; i<len(arr); i++ {
    for j:=0; j<len(arr); j++ {
      if arr[i]==arr[j]{
        //x := j+1
        arr = arr[:j+copy(arr[j:], arr[j+1:])]
      }
    }
  }
  return arr
}

func main() {

    var n1, d1, n2, d2, a, b int
    count := 0
    p := 10010101
    q := 11111117
    
    aa := make([]int, 0)
    bb := make([]int, 0)
    
    for a,b:=1,2; a<(p+q); a,b = a+1,b+1 {
        n1 = p-a
        d1 = q+b
        n2 = p+b
        d2 = q-a
        n1,d1 = makeRed(n1,d1)
        n2,d2 = makeRed(n2,d2)
        if (n1==n2)&&(d1==d2) {
            
            aa = append(aa, a)
            bb = append(bb, b)
            count++
        }
    }

    aa = checkSame(aa)
    bb = checkSame(bb)
    
    fmt.Println(aa)
    fmt.Println(bb)
    sum := 0
    for i:=0; i<count; i++ {
        sum = sum + aa[i] + bb[i]
    }
    
    fmt.Println(sum)

}