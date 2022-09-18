package main
import (
    //"bufio"
    "fmt"
    "net"
    "os"
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

    f,_ := os.Open("./data")
    
    buf := make([]byte,1024)
    for {
        n,_ := f.Read(buf)
        //fmt.Println("n is ",n)
        if n == 0 {
            break;
        }

        n,_ = conn.Write(buf);
        //fmt.Println("err is ",err,"n is ",n)

        time.Sleep(time.Duration(10)*time.Microsecond)
    }
}