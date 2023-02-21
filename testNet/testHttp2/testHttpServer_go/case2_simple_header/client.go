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
  "strings"
  "strconv"
  "time"
)

//export GOPATH=/home/sunliwang/mysource/Obotcha/ObotchaTestSuite/3rdparty/go
//export GOPATH=/home/test/wangsl/mysource/src/Obotcha/Obotcha-master/ObotchaTestSuite/3rdparty/go/
//https://github.com/golang/net.git
//https://github.com/golang/text.git

var content = "hh"

func main() {
  port := testnet.GetEnvPort()
  fmt.Println("port is ",port)
  url := "http://127.0.0.1:" + strconv.Itoa(8080) + "/aaa"  
  client(url)
  clientpost(url)
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
  fmt.Println("header is ",resp.Header)
  
  v1 := resp.Header["Mytest1"]
  v2 := resp.Header["Mytest2"]
  fmt.Println("v1 is",v1)
  
  content = fmt.Sprintf("%s=%s,%s=%s","mytest1",v1,"mytest2",v2)
  fmt.Println("content is ",content)
  
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

func clientpost(url string) {
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
  resp, err := httpClient.Post(url,"text/plain", strings.NewReader(content))
  //resp, err := httpClient.Get(url)
  //fmt.Println("start2")
  if err != nil {
      log.Fatal(err)
  }
  defer resp.Body.Close()

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