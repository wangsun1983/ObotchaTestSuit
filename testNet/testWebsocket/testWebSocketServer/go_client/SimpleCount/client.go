package main

import (
    //"fmt"
    "golang.org/x/net/websocket"
    "../../../../../common"
    //"log"
    "strconv"
    "fmt"
    "time"
)

func main() {
    port := testnet.GetEnvPort()
    origin := "http://localhost/"
    url := "ws://localhost:" + strconv.Itoa(port) + "/mytest"

    for i:= 0;i<16*1024;i++ {
        ws, err := websocket.Dial(url, "", origin)
        if err != nil {
            //log.Fatal(err)
            fmt.Println("connect fail,err is ",err)
        }
        
        if _, err := ws.Write([]byte("Hello, World")); err != nil {
            //log.Fatal(err)
            fmt.Println("write fail,err is ",err)
        }

        ws.Close()
    }

    time.Sleep(5 * time.Second) 
    
    //var msg = make([]byte, 512)
    //var n int
    //if n, err = ws.Read(msg); err != nil {
    //    log.Fatal(err)
    //}
    //fmt.Printf("Received: %s.\n", msg[:n])
}
