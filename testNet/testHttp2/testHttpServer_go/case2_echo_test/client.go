package main

import (
  "crypto/tls"
  //"fmt"
  "io/ioutil"
  "log"
  "net"
  "net/http"
  //"strings"

  "../../../3rdparty/go/src/golang.org/x/net/http2"
)

//export GOPATH=/home/sunliwang/mysource/Obotcha/ObotchaTestSuite/3rdparty/go
//https://github.com/golang/net.git
//https://github.com/golang/text.git

func main() {
  client := http.Client{
       Transport: &http2.Transport{
          AllowHTTP: true,
          DialTLS: func(network, addr string, cfg *tls.Config) (net.Conn, error) {
            return net.Dial(network, addr)
          },
       },
  }

  resp, err := client.Get("http://localhost:1265")
  if err != nil {
    log.Fatalf("请求失败: %s", err)
  }

  defer resp.Body.Close()

  body, err := ioutil.ReadAll(resp.Body)

  if err != nil {
    log.Fatalf("读取响应失败: %s", err)
  }

  log.Fatalf("读取响应: %s", body)
}
