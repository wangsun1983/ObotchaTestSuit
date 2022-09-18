package main
import (
    //"bufio"
    "fmt"
    "net"
    //"os"
    //"strings"
    "strconv"
    "../../../../../common"
)

func main() {
    port := testnet.GetEnvPort()
    url := "127.0.0.1:" + strconv.Itoa(port);
    fmt.Println("url is ",url)

    conn,_ := net.Dial("tcp",url)
    //fmt.Println(err)

    conn.Write([]byte("hello world"));
    var buffer[128]byte

    n,_ := conn.Read(buffer[:])
    //fmt.Println(err2)

    var content = string(buffer[0:n])

    for i:=0;i<50;i++ {
        conn.Write([]byte(content))
    }
}

