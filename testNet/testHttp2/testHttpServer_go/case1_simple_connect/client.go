package main

import (
  "crypto/tls"
  "fmt"
  "io/ioutil"
  "log"
  "net"
  "net/http"
  "golang.org/x/net/http2"
  "../../../../common"
  //"strings"
  "strconv"
  "time"
)

//export GOPATH=/home/sunliwang/mysource/Obotcha/ObotchaTestSuite/3rdparty/go
//https://github.com/golang/net.git
//https://github.com/golang/text.git

func main() {
  port := testnet.GetEnvPort()
  url := "http://127.0.0.1:" + strconv.Itoa(port) + "/aaa"
  for i:= 0; i < 1;i++ {
    client(url)
  }
}

func client(url string) {
  log.SetFlags(log.Llongfile)
  tr := &http2.Transport{ //可惜服务端 退化成了 http1.x
      AllowHTTP: true, //充许非加密的链接
      // TLSClientConfig: &tls.Config{
      //  InsecureSkipVerify: true,
      // },
      DialTLS: func(netw, addr string, cfg *tls.Config) (net.Conn, error) {
          return net.Dial(netw, addr)
      },
  }

  httpClient := http.Client{Transport: tr}
  fmt.Println("start")
  //resp, err := httpClient.Post(url,"text/plain", strings.NewReader("hello this is client"))
  resp, err := httpClient.Get(url)
  //fmt.Println("start2")
  if err != nil {
      log.Fatal(err)
  }
  defer resp.Body.Close()
  fmt.Println("status code is ",resp.StatusCode)
  
  if resp.StatusCode != http.StatusOK {
      fmt.Println("resp StatusCode:", resp.StatusCode)
      return
  }

  body, err := ioutil.ReadAll(resp.Body)
  if err != nil {
      log.Fatal(err)
  }

  fmt.Println("resp.Body:\n", string(body))
  
  time.Sleep(time.Duration(1)*time.Second)
}