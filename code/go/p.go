package main
import (
    "fmt"
    "os"
)



func main() {
    var n int
    fmt.Scan(&n)
    //fmt.Println(n)
    if n<1 || n>10 {
        os.Exit(0)
    }


    s := make([]string, 10)
    /*for i:=0; i<n; i++ {
        s[i] = make([]string, 10)

    }*/


    /*for i:=0; i<n; i++ {
        for j:=0; j<10; j++ {
            fmt.Scan(&s[i][j])
            fmt.Println(s[i][j])
        }
    }*/


    /*var p []string
    for i:=0; i<n; i++ {
        fmt.Scan(&p)
        s[i] = p
        fmt.Println(s[i])
    }*/

    for i:=0; i<10; i++ {
        fmt.Scan(s)
        fmt.Println(s)
    }


    /*flag := 1
    for i:=0; i<n; i++ {
        for j:=0; j<10; j++ {
            x,_ := strconv.Atoi(s[i][j])
            if j>=0 && j<=4 {
                if x<65 || x>90 {
                    flag = 0
                    continue
                }
            }else if j>=5 && j<=8 {
                if x<48 || x>57 {
                    flag = 0
                    continue
                }
            }else if j==9{
                if x<65 || x>90 {
                    flag = 0
                    continue
                }
            }
        }

        if flag==0 {
            fmt.Println("NO")
        }else{
            fmt.Println("YES")
        }
    }*/


}
