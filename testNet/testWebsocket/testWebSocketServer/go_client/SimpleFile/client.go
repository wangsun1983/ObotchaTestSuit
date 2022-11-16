package main

import (
    //"fmt"
    "golang.org/x/net/websocket"
    "../../../../../common"
    "log"
    "strconv"
    "io/ioutil"
)

//export GOPATH=/home/test/wangsl/mysource/src/Obotcha/ObotchaTestSuite/3rdparty/go/

func main() {
    port := testnet.GetEnvPort()
    //fmt.Println("port is ",port)

    origin := "http://localhost/"
    url := "ws://localhost:" + strconv.Itoa(port) + "/mytest"
    
    ws, err := websocket.Dial(url, "", origin)
    if err != nil {
        log.Fatal(err)
    }
    
	data, err := ioutil.ReadFile("./tmp/data")
    ws.Write(data)

    //read file

}
