package main

import (
    "fmt"

)

func main() {
    t := make([]float64, 2)
    n := 0
    t[0],t[1] = 0,1
    var i int64

    for i=2; i<=999999999999999999999; i++ {
        t = append(t, i+t[i-1])
    }

    x := float64(t[999999999999999999999])/float64(999999999999999999999)

    fmt.Println(x)

}