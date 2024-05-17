#include "DatagramSocketImpl.hpp"
#include "SocketBuilder.hpp"
#include "SocketMonitor.hpp"
#include "Handler.hpp"
#include "Inet4Address.hpp"
#include "TimeWatcher.hpp"
#include "TestLog.hpp"
#include "NetPort.hpp"
#include "NetEvent.hpp"

using namespace obotcha;

int messageCount = 0;
int disconnectCount = 0;

Mutex disconnectMutex = Mutex::New();
Condition disconnectCond = Condition::New();

String message = String::New("");

int main() {
    int port = getEnvPort();

    InetAddress addr = Inet4Address::New(port);
    Socket client = SocketBuilder::New()->setAddress(addr)->newSocket();

    int ret = client->connect();

    String resp = String::New("hello server");
    client->getOutputStream()->write(resp->toByteArray());

    int count = 0;
    TimeWatcher watcher = TimeWatcher::New();
    bool isFirst = false;

    while(count < 1024) {
      ByteArray data = ByteArray::New(128);
      watcher->start();
      int len = client->getInputStream()->read(data);
      long interval = watcher->stop();

      if(len == 0) {
        break;
      }

      if(interval < 495 || interval > 505) {
        if(!isFirst) {
          TEST_FAIL("TestSocket case5_simple_io_block test2,interval is %ld,len is %ld",interval,len);
        }
        isFirst = false;
      }
      count++;
    }
    client->close();

    port++;
    setEnvPort(port);

    TEST_OK("TestSocket case5_simple_io_block test100");
    return 0;
}