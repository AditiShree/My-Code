package main

import(
  "fmt"
)

func check(s int, as []int) bool {
  for i:=0; i<len(as); i++ {
    if as[i]==s {
      return true
    }
  }
  return false
}

func statedfa(s1, s2, ip int,  dfa [][]int) (int, int) {
  var p1, p2 int
  p1 = dfa[s1][ip]
  p2 = dfa[s2][ip]
  return p1, p2
}

func swap(p1, p2 int) (int, int) {
  return p2, p1
}

func main() {
  var s, ip, ast int
  fmt.Println("Enter the no of states of dfa")
  fmt.Scan(&s)
  fmt.Println("Enter the no of input symbols in dfa")
  fmt.Scan(&ip)

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
    fmt.Printf("State %d - ", i)
    fmt.Println()
    for j:=0; j<ip; j++ {
      fmt.Println("input ", j , " - ",dfa[i][j])
    }
    fmt.Println()
  }

  fmt.Println("Enter the no of accepting states of dfa")
  fmt.Scan(&ast)
  fmt.Printf("Enter each %d states", ast)
  fmt.Println()
  as := make([]int, ast)
  for i:=0; i<ast; i++ {
    fmt.Scan(&as[i])
  }

  t := make([][]int, s)
  for i:=0; i<s; i++ {
    t[i] = make([]int, s)
  }

  for i:=0; i<s; i++ {
    for j:=i+1; j<s; j++ {
      ib := check(i, as)
      jb := check(j, as)

      if ib && jb {
        t[i][j] = 0
      }

      if (!ib && jb) || (ib && !jb) {
        t[i][j] = 1
      }

      }
  }

  /*for i:=0; i<s; i++ {
    fmt.Printf("State %d - ", i)
    fmt.Println()
    for j:=0; j<s; j++ {
      fmt.Println(t[i][j])
    }
    fmt.Println()
  }*/

  var p1, p2, x int
  x = (s*s-3*s+2)/2
  for x!=0{
  for i:=0; i<s; i++ {
    for j:=i+1; j<s; j++ {
    //  fmt.Println()
      for k:=0; k<ip; k++ {
        //fmt.Printf("t[%d][%d] = %d ",i,j, t[i][j] )
      //  fmt.Println()
        if t[i][j]!=1{
            p1, p2 = statedfa(i, j, k, dfa)
            //fmt.Println("Its transition state", p1, p2)
            if p1>p2{
              p1, p2 = swap(p1,p2)
            }
            if t[p1][p2]==1 {
              t[i][j] = 1
            //  fmt.Printf("Its t[%d][%d] ", i, j)
            }
        }
      }

    }
  }
  x--
}
  fmt.Println("Its table filling")
  for i:=0; i<s; i++ {
    fmt.Printf("state %d", i)
    fmt.Println()
    for j:=0; j<s; j++ {
      fmt.Println(t[i][j])
    }
    fmt.Println()
  }


  fmt.Println("Pair of states that not distinguishable")
  for i:=0; i<s; i++ {
    for j:=i+1; j<s; j++ {
      if t[i][j]==0{
        fmt.Println(i,"  ", j)
      }
    }
  }


}
