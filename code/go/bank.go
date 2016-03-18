package main

import (
  "fmt"
)

func checkDone(done []int) bool {
  count := 0
  for i:=0; i<len(done); i++ {
    if done[i]==1 {
      count++
    }
  }

  if count==len(done){
    return true
  }
  return false
}

func main() {
  alloc := make([][]int, 5)
  for i:=0; i<5; i++{
    alloc[i] = make([]int, 3)
  }

  max := make([][]int, 5)
  for i:=0; i<5; i++{
    max[i] = make([]int, 3)
  }

  need := make([][]int, 5)
  for i:=0; i<5; i++{
    need[i] = make([]int, 3)
  }

  fmt.Println("Enter the allocation matrix")
  for i:=0; i<5; i++ {
    fmt.Println("Process  ",i)
    for j:=0; j<3; j++ {
      fmt.Println("For ", j, " - ")
      fmt.Scan(&alloc[i][j])
    }
  }

  fmt.Println("Enter the maximum matrix")
  for i:=0; i<5; i++ {
    fmt.Println("Process  ",i)
    for j:=0; j<3; j++ {
      fmt.Println("For ", j, " - ")
      fmt.Scan(&max[i][j])
    }
  }



  fmt.Println("Its the need matrix")
  for i:=0; i<5; i++ {
    fmt.Println("Process  ",i)
    for j:=0; j<3; j++ {
      need[i][j] = max[i][j] - alloc[i][j]
      fmt.Println("Need[",i,"][",j,"] = ", need[i][j])
    }
  }

  avail := make([]int, 3)
  fmt.Println("Enter each available resources")
  for i:=0; i<3; i++ {
    fmt.Scan(&avail[i])
  }

  done := make([]int, 5)
  safe := make([]int, 0)

  ok := checkDone(done)

  for ok!=true {
    for i:=0; i<5; i++ {
      count := 0
      if done[i]!=1{
        for j:=0; j<3; j++ {
          if need[i][j]<=avail[j] {
            fmt.Printf("Its the need[%d][%d] = %d", i, j, need[i][j])
            fmt.Println()
            count++
          }
        }

        if count==3{
          done[i] = 1
          fmt.Println("Its done i : ", i)
          safe = append(safe, i)
          for j:=0; j<3; j++ {
            avail[j] = avail[j] + alloc[i][j]
          }
        }
      }
    }
    fmt.Println("Its done array", done)
    ok = checkDone(done)
  }

  fmt.Println("Safety order is : ")
  fmt.Println(safe)
}
