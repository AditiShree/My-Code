
//Program to check membership of an explicit string with given dfa

package main

import(
  "fmt"
)

func main() {
  var s, ip int
  fmt.Println("Enter the no of states of dfa")
  fmt.Scan(&s)

  fmt.Println("Enter the no of input symbols")
  fmt.Scan(&ip)

  //[i]->state of dfa, [j]->each Input symbol of dfa, [k]-> transition state
  dfa := make([][]int, s)
  for i:=0; i<s; i++ {
    dfa[i] = make([]int, ip)
    for j:=0; j<ip; j++ {
      fmt.Printf("Enter the state on transition from state %d on input %d", i, j)
      fmt.Println()
      temp := 0
      fmt.Scan(&temp)
      dfa[i][j] = temp
    }
  }

  fmt.Println("Its dfa")
  for i:=0; i<s; i++ {
    fmt.Println()
    fmt.Println("State: ",i,"-")
    for j:=0; j<ip; j++ {
      fmt.Print("Input: ", j, " -> ")
      fmt.Print(dfa[i][j])
      fmt.Println()
    }
  }

  var start, nend int
  fmt.Println("Enter the starting state")
  fmt.Scan(&start)

  fmt.Println("Enter the no of ending states")
  fmt.Scan(&nend)

  fmt.Printf("Enter each %d state", nend)
  fmt.Println()
  end := make([]int, nend)
  for i:=0; i<nend; i++ {
    fmt.Scan(&end[i])
    }

  ok := 0
  for ok!=1{
      var str string
      fmt.Println("Enter the string explicitly to be checked ")
      fmt.Scan(&str)

      //nxtS is next state && p is starting state
      var p, nxtS int
      //declare frst symbol of string as input to the starting state of dfa
      p = start
      //fmt.Println(p)
      //fmt.Println("Len of str : ", len(str))
      for i:=0; i<len(str); i++ {
        //  fmt.Println(str[i]-48)
          nxtS = dfa[p][str[i]-48]
          p = nxtS

        }

      count := 0
      for i:=0; i<nend; i++ {
        if nxtS==end[i] {
          count++
        }
      }

      if count==1{
        fmt.Println("YES")
      }else{
        fmt.Println("NO")
      }
      fmt.Println("Do you want to check another string--y or n")
      var x string
      fmt.Scan(&x)
      if x=="n"{
        ok = 1
      }
  }
}
