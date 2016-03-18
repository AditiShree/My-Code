//Among two arrays find the common elements among them
package main
import(
  "fmt"
)

func main() {
  var a,b int
  fmt.Println("Enter no of elem of both arrays")
  fmt.Scan(&a, &b)

  fmt.Printf("Enter %d elem of aa slice", a)
  fmt.Println()
  aa := make([]int, a)
  for i:=0; i<a; i++ {
    fmt.Scan(&aa[i])
  }

  fmt.Printf("Enter %d elem of bb slice", b)
  fmt.Println()
  bb := make([]int, b)
  for i:=0; i<b; i++ {
    fmt.Scan(&bb[i])
  }

  cc := make([]int, 0)
  for i:=0; i<len(aa); i++ {
    for j:=0; j<len(bb); j++ {
      if aa[i]==bb[j] {
        cc = append(cc, aa[i])
      }
    }
  }

  fmt.Println(cc)
}
