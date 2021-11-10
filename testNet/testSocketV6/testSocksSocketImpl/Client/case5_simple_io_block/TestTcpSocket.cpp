#include "DatagramSocketImpl.hpp"
#include "SocketBuilder.hpp"
#include "SocketMonitor.hpp"
#include "Handler.hpp"
#include "Inet6Address.hpp"
#include "TimeWatcher.hpp"

using namespace obotcha;

int messageCount = 0;
int disconnectCount = 0;

Mutex disconnectMutex = createMutex();
Condition disconnectCond = createCondition();

String message = createString("");

int main() {
    InetAddress addr = createInet6Address(1222);
    Socket client = createSocketBuilder()->setAddress(addr)->newSocket();

    int ret = client->connect();

    String resp = createString("hello server");
    client->getOutputStream()->write(resp->toByteArray());

    int count = 0;
    TimeWatcher watcher = createTimeWatcher();
    bool isFirst = false;

    while(count < 1024) {
      ByteArray data = createByteArray(128);
      watcher->start();
      int len = client->getInputStream()->read(data);
      long interval = watcher->stop();

      if(len == 0) {
        break;
      }

      if(interval < 500 || interval > 505) {
        if(!isFirst) {
          printf("---TestSocket IO Block test2 [FAILED]---,interval is %ld,len is %ld\n",interval,len);
        }
        isFirst = false;
      }
      count++;
    }
    client->close();

    printf("---TestSocket IO Block test2 [OK]---\n");
    return 0;
}