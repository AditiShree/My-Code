package main

import(
  "fmt"
)

func check(a, aa []int, tmp int) ([]int, int) {
  for i:=0; i<len(aa); i++ {
    count := 0
    for j:=0; j<len(a); j++ {
      if aa[i]==a[j] {
        count++
      }
    }
    if count==0{
      a = append(a, aa[i])
      tmp++
    }
  }
  return a,tmp
}

func main() {
  var n int
  fmt.Println("Enter the no of nodes")
  fmt.Scan(&n)

  g := make([][]int, n)

  for i:=0; i<n ;i++ {
    g[i] = make([]int, n)
  }

  fmt.Println("Enter the connected nodes")
  for i:=0; i<n ;i++ {
    for j:=i; j<n; j++ {
      fmt.Printf("Enter the connection from %d to %d", i, j)
      fmt.Println()
      x :=0
      fmt.Scan(&x)
      g[i][j] = x
      g[j][i] = x
    }
  }

  for i:=-1; i<n ;i++ {
    if i==-1{
      fmt.Print("   ")
      for j:=0; j<n; j++ {
        fmt.Print(j, "  ")

      }
      fmt.Println()
    }else{
      fmt.Print(i,"  ")
      for j:=0; j<n; j++ {
        fmt.Print(g[i][j], "  ")
      }
      fmt.Println()
    }
  }

  fmt.Println("Enter the starting node of dfs")
  var init int
  fmt.Scan(&init)

  a := make([]int, 1)
  a[0] = init
  aa := make([]int, 0)

  tmp := 1
  for tmp!=0 {
    aa = aa[:]
    for p:=0; p<len(a); p++ {
      for i:=0; i<n; i++ {
        //aa = aa[:]
        if g[a[p]][i]==1 {
          aa = append(aa, i)
        }
        a,tmp = check(a, aa, tmp)
        tmp--
      }
    }
  }

fmt.Println(a)




}
