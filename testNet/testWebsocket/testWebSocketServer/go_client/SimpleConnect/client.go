package main

import (
    //"fmt"
    "golang.org/x/net/websocket"
    "../../../../../common"
    "log"
    //"fmt"
    "strconv"
)

//export GOPATH=/home/sunliwang/mysource/Obotcha/ObotchaTestSuite/common
//export GOPATH=/home/test/wangsl/mysource/src/Obotcha/ObotchaTestSuite/3rdparty/go/src

func main() {
    port := testnet.GetEnvPort()
    //fmt.Println("port is ",port)

    origin := "http://localhost/"
    url := "ws://localhost:" + strconv.Itoa(port) + "/mytest"
    
    ws, err := websocket.Dial(url, "", origin)
    if err != nil {
        log.Fatal(err)
    }
    
    if _, err := ws.Write([]byte("Hello, World")); err != nil {
        log.Fatal(err)
    }

    //ws.Close()
    //var msg = make([]byte, 512)
    //var n int
    //if n, err = ws.Read(msg); err != nil {
    //    log.Fatal(err)
    //}
    //fmt.Printf("Received: %s.\n", msg[:n])
}
