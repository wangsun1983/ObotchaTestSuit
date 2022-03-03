package main

import (
    "crypto/tls"
    "log"
    "../../../../../common"
    "strconv"
    "crypto/x509"
  	"fmt"
  	"io/ioutil"
)

func main() {
    log.SetFlags(log.Lshortfile)

    pool := x509.NewCertPool()
    caCertPath := "server.crt"
    //调用ca.crt文件
    caCrt, err := ioutil.ReadFile(caCertPath)
    if err != nil {
      fmt.Println("ReadFile err:", err)
      return
    }
    //解析证书
    pool.AppendCertsFromPEM(caCrt)

    conf := &tls.Config{
        RootCAs: pool,
    }

    port := testnet.GetEnvPort()
    url := "127.0.0.1:" + strconv.Itoa(port);

    conn, err := tls.Dial("tcp",url, conf)
    if err != nil {
        log.Println(err)
        return
    }
    defer conn.Close()

    n, err := conn.Write([]byte("hi\n"))
    if err != nil {
        log.Println(n, err)
        return
    }

    buf := make([]byte, 100)
    n, err = conn.Read(buf)
    if err != nil {
        log.Println(n, err)
        return
    }

    conn.Write(buf)

    println(string(buf[:n]))
}
