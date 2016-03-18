package main
import (
    "fmt"
    "os"
    //"bufio"
)

func checkN(n int) int {
    if n>=1 && n<=100{
        return n
    }else{
        os.Exit(0)
        return 0
    }
}

func checkS(s string, n int) string {
    if len(s)!=n{
        os.Exit(0)
        return ""
    }else{
        return s
    }
}

func checkK(k int) int {
    if k>=0 && k<=100{
        return k
    }else{
        os.Exit(0)
        return 0
    }
}

func main() {
    var s string
    var n,k,p,x int
    //a := []int{}
    a := make([]int, 0)

    fmt.Scan(&n)
    n = checkN(n)


    fmt.Scan(&s)
    s = checkS(s,n)

    fmt.Scan(&k)
    k = checkK(k)
    for i:=0; i<len(s); i++{
        p = int(s[i])
        if p == 32 {
            os.Exit(0)
        }
    }
    for i:=0; i<len(s); i++{
        p = int(s[i])
        fmt.Printf("%c%d", s[i],p)
        fmt.Println()
        if (p>=65 && p<=90) || (p>=97 && p<=122) {

            p = p+k

            if p > 90 && p<97{
                x = p-90
                p = 64 + x
            }

            if p > 122{
                x = p - 122
                p = 96 + x
            }
            a = append(a, p)
           //fmt.Println(a)
        }else{
            a = append(a, p)
        }

    }

    for i:=0; i<len(a); i++ {
        fmt.Printf("%c",a[i])
    }

}
