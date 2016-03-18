package main 

import (
	"fmt"
	//"os"
	//"bufio"
)

func main() {
	var s string
	fmt.Println("Enter a string")
	fmt.Scan(&s)
	//x := bufio.NewReader(os.Stdin)
	//p,_ := x.ReadString('\n')
	fmt.Println(s)
}