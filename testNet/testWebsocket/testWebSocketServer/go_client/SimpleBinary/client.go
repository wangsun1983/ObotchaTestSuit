package main

import (
    //"fmt"
    "golang.org/x/net/websocket"
    "../../../../../common"
    "log"
    "strconv"
    "io"
    "bufio"
    "os"
)

//export GOPATH=/home/test/wangsl/mysource/src/Obotcha/ObotchaTestSuite/3rdparty/go/
//export GOPATH=/home/test/wangsl/mysource/src/Obotcha/ObotchaTestSuite/3rdparty/go

func main() {
    port := testnet.GetEnvPort()
    //fmt.Println("port is ",port)

    origin := "http://localhost/"
    url := "ws://localhost:" + strconv.Itoa(port) + "/mytest"
    
    ws, err := websocket.Dial(url, "", origin)
    if err != nil {
        log.Fatal(err)
    }
    
	//data, err := ioutil.ReadFile("./tmp/data")
    //ws.Write(data)
    
    fi, err := os.Open("./tmp/data")
    r := bufio.NewReader(fi)
    buf := make([]byte, 1024)
    for {
        n, err := r.Read(buf)
        if err != nil && err != io.EOF {
            panic(err)
        }
 
        if n == 0 {
            break
        }
        
        websocket.Message.Send(ws, buf[:n])
    }


    //read file

}
