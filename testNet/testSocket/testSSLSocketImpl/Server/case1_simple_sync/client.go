package main

import (
    "crypto/tls"
    "log"
    "../../../../../common"
    "strconv"
    "fmt"
)

func main() {
    log.SetFlags(log.Lshortfile)

    conf := &tls.Config{
        InsecureSkipVerify: true,
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
