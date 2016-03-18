//Pgm to check if a reg exp is empty or not
//Assume Q is phi while input
package main

import(
  "fmt"
//  "os"
)

func brkt()  {

}

func exec(r string) bool {
  i := 0
  c := 0
  br := 0
  for i<len(r)-1  {
    x := string(r[i])
    y := string(r[i+1])
    fmt.Println(x, "  ", y)

    if x=="(" {
      br++
      for x!=")"{

      }
    }

    if x!="+" {

      if x=="Q" && y!="*" {
        c = c+1

      }

    }

    if x=="+" {
      if c>0 {
        c = 0
      }else{

        //os.Exit(0)
        return false
      }
    }

    i++
  }
  return true
}

func main() {
  var r string
  fmt.Println("Enter the regular expression")
  fmt.Scan(&r)

  



  ok := exec(r)




  if ok{
    fmt.Println("the reg exp is empty")
  }else{
    fmt.Println("reg exp is nt empty")
  }
  //fmt.Println(len(r))

}
