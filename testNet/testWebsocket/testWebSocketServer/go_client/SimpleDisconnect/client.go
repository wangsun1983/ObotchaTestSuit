package main

import (
    //"fmt"
    "golang.org/x/net/websocket"
    "../../../../../common"
    "log"
    "strconv"
    //"io"
    //"bufio"
    //"os"
)

//export GOPATH=/home/test/wangsl/mysource/src/Obotcha/ObotchaTestSuite/3rdparty/go/
//export GOPATH=/home/test/wangsl/mysource/src/Obotcha/ObotchaTestSuite/3rdparty/go

func main() {
    port := testnet.GetEnvPort()

    origin := "http://localhost/"
    url := "ws://localhost:" + strconv.Itoa(port) + "/mytest"
    
    for i:= 0;i<256;i++ {
        ws, err := websocket.Dial(url, "", origin)
        if err != nil {
            log.Fatal(err)
        }
        websocket.Message.Send(ws, []byte("Hello, World"))
        ws.Close()
    }
}
