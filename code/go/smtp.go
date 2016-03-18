package main

import (
	"log"
	"net/smtp"
)

func main() {
	addr := "smtp.gmail.com:465"
	a := smtp.PlainAuth(
		"",
		"jst4ref@gmail.com",
		"kiranisgreat",
		"smtp.gmail.com",
	)
	from := "jst4ref@gmail.com"
	to := []string{"mailofvishwakiran@gmail.com"}
	msg := []byte("You've Got Mail!")
	if err := smtp.SendMail(addr, a, from, to, msg); err != nil {
		log.Fatal(err)
	}
}