package main

import (
    //"fmt"
    "golang.org/x/net/websocket"
    "../../../../../common"
    "log"
    "strconv"
    "os"
    "io"
    //"io/ioutil"
)

//export GOPATH=/home/test/wangsl/mysource/src/Obotcha/ObotchaTestSuite/3rdparty/go/

func main() {
    port := testnet.GetEnvPort()
    origin := "http://localhost/"
    url := "ws://localhost:" + strconv.Itoa(port) + "/mytest"
    
    ws, err := websocket.Dial(url, "", origin)
    if err != nil {
        log.Fatal(err)
    }
    
	buf := make([]byte, 1024)
    
    f, _ := os.Open("./tmp/testdata")
    
    for {
        // 将文件中读取的byte存储到buf中
		n, err := f.Read(buf)
		if err != nil && err != io.EOF {
			log.Fatal(err)
		}
		if n == 0 {
			break
		}
        ws.Write(buf[0:n])
	}
    
    ws.Close()
}
