package main

import(
    "fmt"
    "strconv"
)

var a []int

/*func push(p int)  {
  a = append(a, p)

}*/

func pop() int {
  x := a[len(a)-1]
  a = a[0:len(a)-1]
  return x
}



func main() {
  var op1, op2 int
  var b []string
  fmt.Scan(&b)
  k := 0


  for i:=0; i<=len(b); i++ {
    r,_ := strconv.Atoi(b[i])
    if r>=48 && r<=57 {
      k = k*10 + r
    }else if r==44 {
      a = append(a, k)
    }else {
      if r==43 {
        op1=pop()
        op2=pop()
        a = append(a, op1+op2)
      }

      if r==45 {
        op1=pop()
        op2=pop()
        a = append(a, op1-op2)
      }
      if r==42 {
        op1=pop()
        op2=pop()
        a = append(a, op1*op2)
      }
      if r==47 {
        op1=pop()
        op2=pop()
        a = append(a, op1/op2)
      }

    }




    }



}
