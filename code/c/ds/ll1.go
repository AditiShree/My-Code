package main
import (
  "fmt"
)

type LinkedList struct {
  data int
  next *LinkedList
}

var head, tail *LinkedList = nil,nil
//head = tail := nil


func (temp *LinkedList) Add(x int) {
  //temp := new(LinkedList)
  if head==nil {
    head.data = x
    head.next = nil
    tail = head
  }else{
    temp.data = x
    temp.next = nil
    tail.next = temp
  }
}

func (temp *LinkedList) Delete(x int) int {
  temp2 := new(LinkedList)
  if head==nil{
    fmt.Println("no elem in ll")

  }else if head.data==x {
    head = head.next
    //temp = head
  }else if head.next==nil{
    fmt.Println("no such element")
    return 0
    }else{
      temp2 = head
      temp = temp2.next
      for temp.next!=nil{
        if temp.data==x{
          temp2.next = temp.next
          return 0
        }else{
          temp2 = temp
          temp = temp.next
        }


    }
    fmt.Println("no such elem")
    return 0
  }
  return 0
}

func (temp *LinkedList) Print()  {
  if head==nil{
    fmt.Println("empty")
  }else{
    temp = head
    for temp.next!=nil{
      fmt.Println()
      fmt.Println(temp.data)
      temp = temp.next
    }
    fmt.Println(temp.data)
  }
}

func main() {
  var choice, elem int
  //temp = &LinkedList
  x := 1
  for  x>0 {
    fmt.Println("enter choice")
    fmt.Println("1.Add elem")
    fmt.Println("2.Delete elem")
    fmt.Println("3.Print elem")
    fmt.Println("4.Exit")
    fmt.Scan(&choice)

    if choice==1{
      fmt.Println("enter no to b appended")
      fmt.Scan(&elem)
      Add(elem)
    }else if choice==2 {
      fmt.Println("enter elem to be deleted ")
      fmt.Scan(&elem)
      Delete(elem)
    }else if choice==3 {
      Print()
    }else{
      x = 0
    }
  }







}
