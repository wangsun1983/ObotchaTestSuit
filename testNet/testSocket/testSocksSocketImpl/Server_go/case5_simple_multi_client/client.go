package main

import (
    "fmt"
    "log"
    "net"
    "sync"
    "../../../../../common"
    "strconv"
    "time"
)

var wg sync.WaitGroup

func doClientTest() {
  count := 1024
  port := testnet.GetEnvPort()
  for;count > 0; {
    //fmt.Println("trace1");
    conn, err := net.Dial("tcp", ":" + strconv.Itoa(port))
    if err != nil {
        log.Fatal(err)
    }
    //fmt.Println("trace2");
    conn.Write([]byte("hello world"))
    //fmt.Println("trace3");
    count = count - 1
    conn.Close()
  }
  wg.Done()
}

func main() {
  wg.Add(12)
  for i := 0; i < 12;i++ {
    go doClientTest()
  }
  wg.Wait()
  time.Sleep(5 * time.Second)
  fmt.Println("finish!!!")
}
