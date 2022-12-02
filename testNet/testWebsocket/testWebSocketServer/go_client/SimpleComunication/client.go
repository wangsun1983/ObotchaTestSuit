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
    //fmt.Println("port is ",port)
    var hit = 0
    
    origin := "http://localhost/"
    url := "ws://localhost:" + strconv.Itoa(port) + "/mytest"
    
    for i:= 0;i<256;i++ {
        ws, err := websocket.Dial(url, "", origin)
        if err != nil {
            log.Fatal(err)
        }
        websocket.Message.Send(ws, []byte("Hello,Server"))
        var message string
        websocket.Message.Receive(ws, &message)
        if message == "Hello,Client" {
            ws.Close()
            hit++
        }
    }
    
    if hit == 256 {
        ws, _ := websocket.Dial(url, "", origin)
        websocket.Message.Send(ws, []byte("Finish"))
    }
}
