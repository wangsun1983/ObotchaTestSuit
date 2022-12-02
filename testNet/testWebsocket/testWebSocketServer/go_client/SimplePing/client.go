package main

import (
    //"fmt"
    "golang.org/x/net/websocket"
    "../../../../../common"
    "strconv"
    "time"
)

//export GOPATH=/home/test/wangsl/mysource/src/Obotcha/ObotchaTestSuite/3rdparty/go/
//export GOPATH=/home/test/wangsl/mysource/src/Obotcha/ObotchaTestSuite/3rdparty/go

func main() {
    port := testnet.GetEnvPort()
    
    origin := "http://localhost/"
    url := "ws://localhost:" + strconv.Itoa(port) + "/mytest"
    
    ws, _ := websocket.Dial(url, "", origin)
    websocket.Message.Send(ws, []byte("Hello,Server"))
    
    var message string
    websocket.Message.Receive(ws, &message)
   
    time.Sleep(1*time.Second)
}
