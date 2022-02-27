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

  req, err := http.NewRequest("GET", url, strings.NewReader("hello"))
  cookie1 := http.Cookie{Name: "tag1", Value: "value1"}
  req.AddCookie(&cookie1)

  cookie2 := http.Cookie{Name: "tag2", Value: "value2"}
  req.AddCookie(&cookie2)

  if err != nil {
      // handle error
  }

  client.Do(req)
}
