package main
import(
    "fmt"

)

//var top int
//top = -1
var a []int

func pop()  {
  if len(a)==0 {
    fmt.Println("no elem in stack to pop")
  }else{
    a = a[0:len(a)-1]
  }
}

func push()  {
  var x int
  fmt.Println("enter elem to be pushed")
  fmt.Scan(&x)
  a = append(a,x)
}

func print()  {

    fmt.Println(a)

}

func main() {
  var choice int
  p:=1
  for p!=0{
    fmt.Println("enter choice")
    fmt.Println("1.Push   2.Pop   3.Print   4.Exit")
    fmt.Scan(&choice)

    if choice==1{
      push()
    }else if choice==2{
        pop()
      }else if choice==3 {
        print()
      }else if choice==4{
        p = 0
      }
    }


}
