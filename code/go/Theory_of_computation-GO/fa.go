package main

import (
  "fmt"
)

//s is the state which we are finding e-closure of
func closure(s int, nfa [][][]int) []int {
  a := make([]int, 0)
  a = append(a, s)
  for i := 0;  i< len(nfa[s][0]); i++ {
    a = append(a, nfa[s][0][i])
  }
  return a
}

func sort(a []int) []int {
  var tmp int
  for i:=0; i<len(a)-1; i++ {
    for j:=0; j<len(a)-1-i; j++ {
      //fmt.Println(j,"   ", j+1)
      if a[j]>a[j+1] {
          tmp = a[j]
          a[j] = a[j+1]
          a[j+1] = tmp
      }
    }
  }
  return a
}

func reduce(a []int) []int {
  temp := make([]int, 0)
  temp = append(temp, a[0])
  for i:=1; i<len(a); i++ {
    add := 0
    for j:=0; j<len(temp); j++ {
      if a[i] == temp[j] {
        add = 1
      }
    }
    if add==0{
      temp = append(temp, a[i])
    }
  }
  temp = sort(temp)
  return temp
}

//func to check if teo slices are equal
func equal(nw []int, old []int) bool {

    count := 0
    if len(nw) == len(old) {
      for j:=0; j<len(nw); j++ {
        if nw[j] == old[j] {
          count++
          }
      }
      if count==len(nw){
        return true
      }
    }
  return false
}

//to check if dfa already contains the new state
func checkState(nw []int, old [][]int) bool {
  for i:=0; i<len(old); i++ {
    for j:=0; j<len(nw); j++ {
      if equal(old[i],nw){
        return false
      }
    }

  }
  return true
}

func main() {
  var n,a,initN int

  fmt.Println("Enter the no of states of e-nfa")
  fmt.Scan(&n)
  ns := make([]int, n)

  //fmt.Println("Enter all states")
  for i:=0; i<n; i++ {
    ns[i] = i
  }

  fmt.Println("Enter no of input symbols")
  fmt.Scan(&a)
  a = a+1
  ip := make([]int, a)
  for i:=0; i<a; i++ {
    ip[i] = i
  }

  ntt := make([][][]int, n)

  for i:=0; i<n; i++{
    ntt[i] = make([][]int, a)
    for j:=0; j<a; j++ {
      fmt.Printf("Enter number of elem for transition frm %d on ip symbol %d ",i,j)
      fmt.Println()
      temp := 0
      fmt.Scan(&temp)
      ntt[i][j] = make([]int, temp)
      fmt.Printf("Enter each %d states",temp)
      fmt.Println()
      for q:=0; q<temp; q++ {
        fmt.Scan(&ntt[i][j][q])
      }
    }
  }

  fmt.Println("Enter the initial state")
  fmt.Scan(&initN)
  temp := 0
  fmt.Println("Enter the no of final states")
  fmt.Scan(&temp)
  endN := make([]int, temp)
  fmt.Printf("Enter each %d final states", temp)
  fmt.Println()
  for i:=0; i<temp; i++ {
    fmt.Scan(&endN[i])
  }

  fmt.Println("Its user input e-nfa ")
  //'i' is for each state, 'j' is for each input symbol, 'k' is for each state in each transition
  for i:=0; i<n; i++ {
    fmt.Print(i," - ")
    for j:=0; j<a; j++ {
      fmt.Print(" ",j," : ")

      for k:=0; k<len(ntt[i][j]); k++ {
        fmt.Printf("%d, ", ntt[i][j][k])
      }
      fmt.Println()
    }
    fmt.Println()
    fmt.Println()
  }



  frst := closure(initN, ntt)
  frst=reduce(frst)
  fmt.Println(frst)

  //its slice of state of dfa
  std := make([][]int, 50)

  //Count is for counting no of states of dfa
  count := 1
  std[0] = frst
  //fmt.Println("Its frst elem of dfa   ", std[0])
  dtt := make([][][]int, 50)
  for i:= 0;  i< 50; i++ {
    dtt[i]=make([][]int,50)
  }
  for i:=0;i<50;i++{
    for j:= 0; j < count; j++ {
      dtt[i][j]=make([]int,50)
    }
  }


  //dtt[0] = ntt[0]
  done := 0
  aa := make([]int, 0)
  for done!=count{
    frst = frst[:]
    aa = aa[:]
    frst = std[done]
    //i is the input symbol
    for i:=1; i<a; i++ {
      //'j' is the each elem in eclose of init state
      for j:=0; j<len(frst); j++ {
        // k is transition for each elem in e close on each input symbol
        for k:=0; k<len(ntt[frst[j]][i]); k++ {
          aa = append(aa, ntt[frst[j]][i][k])

        }
      }
      aa = reduce(aa)
      finalaa := make([]int, 0)
      //Its for finding e closure of each elem on transition on each symbol
      for p:=0; p<len(aa); p++ {
        tmp := closure(aa[p], ntt)
        for q:=0; q<len(tmp); q++ {
          finalaa = append(finalaa, tmp[q])
        }

      }
      finalaa = reduce(finalaa)
      finalaa = sort(finalaa)
      dtt[done][i-1] = finalaa
      ok := checkState(finalaa, std)
      if ok{
        std[count] = finalaa
        count++
      }
      fmt.Println(aa)
    }
    done++
  }

  fmt.Println("Its dfa")

  for i:=0; i<count; i++ {
    fmt.Println(std[i])
    for j:=1; j<a; j++ {
      fmt.Print(" ", j," : ")
      for k:=0; k<len(dtt[i][j-1]); k++{
        fmt.Print(dtt[i][j-1][k], ", ")
      }
      fmt.Println()
    }
    fmt.Println()
    fmt.Println()
  }

}
