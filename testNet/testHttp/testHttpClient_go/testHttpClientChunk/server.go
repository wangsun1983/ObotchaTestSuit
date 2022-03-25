package main

import (
  "fmt"
  "net/http"
  "time"
  "os"
  "../../../../common"
  "strconv"
)

func close() {
  port := testnet.GetEnvPort()
  port = port + 1
  //testnet.SetEnvPort(port)

  time.Sleep(time.Duration(1)*time.Second)
  os.Exit(0);
}

func main() {
  port := testnet.GetEnvPort()
  fmt.Println("port is ",port)

  http.HandleFunc("/", func(writer http.ResponseWriter, request *http.Request) {
      flusher, ok := writer.(http.Flusher)
      if !ok {
        panic("expected http.ResponseWriter to be an http.Flusher")
      }

      for i := 0; i < 16; i++ {
        fmt.Fprintf(writer, "hello,i am client,number: %d\n", i)
        flusher.Flush()
        //time.Sleep(time.Second)
      }

      go close()
  })

  http.ListenAndServe(":" + strconv.Itoa(port), nil)
}
