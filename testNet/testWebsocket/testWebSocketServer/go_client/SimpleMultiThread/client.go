package main

import (
    "fmt"
    "../../../../../3rdparty/go/src/golang.org/x/net/websocket"
    "../../../../../common"
    "log"
    "sync"
    "time"
    "strconv"
)

var wg sync.WaitGroup

func doSend(id int) {
  port := testnet.GetEnvPort()
  origin := "http://localhost/"
  url := "ws://localhost:" + strconv.Itoa(port) + "/mytest"

  fmt.Println("start: " ,id)
  for i:= 0;i<80;i++ {
      ws, err := websocket.Dial(url, "", origin)
      if err != nil {
          log.Fatal(err)
      }
      
      if _, err := ws.Write([]byte("Hello, World")); err != nil {
          log.Fatal(err)
      }
      ws.Close()
  }
  wg.Done()
  fmt.Println("finish :", id)
}

func main() {
  wg.Add(128)
  for i:= 0;i<128;i++ {
    go doSend(i)
  }
  wg.Wait()
  time.Sleep(5 * time.Second) 

}
