package main

import(
    "fmt"

)

type list struct {
  data int
  next *list
}

/**************

UNLIKE C WHERE WE USE DOT(.) OPERATOR FOR VALUES AND ARROW(->) OPERATOR
FOR POINTERS
GOLANG USES ONLY DOT(.) OPERATOR N IT IDENTIFIES ITSELF ITS VALUE

**************/
func main() {
  //*, *curr list
  //headPtr = new list
  //headPtr -> data = 4
  headPtr := new(list)
  headPtr.data = 4
  headPtr.next = new(list)
  curr := headPtr.next
  curr.data = 5
  curr.next = new(list)
  curr = curr.next
  curr.data = 6
  curr.next = nil

  curr = headPtr

  for i:=0; i<3; i++ {
    fmt.Println(curr.data)
    curr = curr.next
  }


}
