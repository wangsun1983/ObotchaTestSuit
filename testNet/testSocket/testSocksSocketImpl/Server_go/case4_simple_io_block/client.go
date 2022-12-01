package main
import (
    //"bufio"
    "fmt"
    "net"
    //"os"
    //"strings"
    "time"
    "strconv"
    "../../../../../common"
)

func main() {
    port := testnet.GetEnvPort()
    url := "127.0.0.1:" + strconv.Itoa(port);
    fmt.Println("url is ",url)

    conn,err := net.Dial("tcp",url)
    fmt.Println("connect err is",err)
    
for i:= 0;i<512;i++ {
        fmt.Println("i send a data")
        time.Sleep(time.Duration(100)*time.Millisecond)
        conn.Write([]byte("hello world"))
    }

    time.Sleep(time.Duration(30)*time.Second)
}