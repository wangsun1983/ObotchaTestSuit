package main

import (
    //"fmt"
    //"io/ioutil"
    "net/http"
    "strings"
    "../../../../common"
    //"log"
    //"fmt"
    "strconv"
)

func main() {
  client := &http.Client{}
  port := testnet.GetEnvPort()
  url := "http://127.0.0.1:" + strconv.Itoa(port) + "/mytest"

  req, err := http.NewRequest("GET", url, strings.NewReader("tag1=value1&tag2=value2"))
  if err != nil {
      // handle error
  }

  client.Do(req)
}
