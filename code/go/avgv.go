package main

import (
    "fmt"
    "math"
)

func main() {
   var dist,avgv float64
   var a, v, t1, t2, t3 float64
  
   
   dist = float64(math.Pow(10,20))
   
   partd := dist/3
   
   a = 150
   v = math.Sqrt(2*a*partd) 
   t1 = v/a
   t2 = partd/v
   t3 = t1
   avgv = dist/(t1+t2+t3)
   fmt.Println(int64(avgv))
   
}