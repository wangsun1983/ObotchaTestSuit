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
    fmt.Println("main trace1");
    pool := x509.NewCertPool()
    caCertPath := "server.crt"
    //调用ca.crt文件
    fmt.Println("main trace2");
    caCrt, err := ioutil.ReadFile(caCertPath)
    if err != nil {
      fmt.Println("ReadFile err:", err)
      return
    }
    fmt.Println("main trace3");
    //解析证书
    pool.AppendCertsFromPEM(caCrt)
    fmt.Println("main trace3");
    conf := &tls.Config{
        RootCAs: pool,
    }
    fmt.Println("main trace4");
    port := testnet.GetEnvPort()
    url := "127.0.0.1:" + strconv.Itoa(port);

    conn, err := tls.Dial("tcp",url, conf)
    if err != nil {
        log.Println(err)
        return
    }
    defer conn.Close()
    fmt.Println("main trace5");
    
    n, err := conn.Write([]byte("hi\n"))
    if err != nil {
        log.Println(n, err)
        return
    }
    fmt.Println("main trace6");
    buf := make([]byte, 100)
    n, err = conn.Read(buf)
    if err != nil {
        log.Println(n, err)
        return
    }
    fmt.Println("main trace7");
    conn.Write(buf)

    println(string(buf[:n]))
}
