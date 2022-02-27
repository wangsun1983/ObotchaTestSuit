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

  req, err := http.NewRequest("POST", url, strings.NewReader("hello"))
  if err != nil {
      // handle error
  }

  req.Header.Set("tag1", "value1")
  req.Header.Set("tag2", "value2")
  client.Do(req)
}
