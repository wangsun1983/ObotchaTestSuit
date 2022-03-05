package main

import (
  "fmt"
  "io"
  "net/http"
  "strings"
  "../../../../common"
  "strconv"
)

func main() {
  port := testnet.GetEnvPort()
  url := "http://127.0.0.1:" + strconv.Itoa(port) + "/mytest"

  resp, err := http.Post(url, "application/json", strings.NewReader("{}"))
  if err != nil {
    panic(err)
  }

  defer resp.Body.Close()

  fmt.Printf("response: %T\n", resp)
  fmt.Printf("response.Body: %T\n", resp.Body)

  data := make([]byte, 128)
  //index := 0
  var acceptString string

  for {
    readN, err := resp.Body.Read(data)
    
    if readN > 0 {
      //fmt.Print(string(data[:readN]))
      acceptString += string(data[:readN])
    }

    if err == io.EOF {
      break
    }
    if err != nil {
      panic(err)
    }
  }

  if acceptString == "hello1hello2hello3" {
    fmt.Println("ok!!!!!")
    http.Post(url, "application/json", strings.NewReader("ok"))
  } else {
    fmt.Println("failed!!!!!")
    http.Post(url, "application/json", strings.NewReader("failed"))
  }

  fmt.Println("done")
}
