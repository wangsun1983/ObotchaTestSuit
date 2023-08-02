#include <unistd.h>

#include "Filament.hpp"
#include "ArrayList.hpp"
#include "FilaRoutine.hpp"
#include "CountDownLatch.hpp"
#include "TestLog.hpp"
#include "Inet4Address.hpp"
#include "NetPort.hpp"
#include "Socket.hpp"
#include "SocketBuilder.hpp"

using namespace std;
using namespace obotcha;

CountDownLatch latch = createCountDownLatch(3);

void doConnect() {
  int port = getEnvPort();
  InetAddress addr = createInet4Address(port);
  Socket client = createSocketBuilder()->setAddress(addr)->newSocket();
  int ret = client->connect();
  InputStream input = client->getInputStream();
  ByteArray data = createByteArray(64);
  int len = input->read(data);
  if(len != 11) {
    TEST_FAIL("Filament SimpleConnect case1");
  }

  if(!data->toString()->sameAs("hello world")) {
    TEST_FAIL("Filament SimpleConnect case2");
  }
}

int main(void) {
    FilaRoutine croutine = createFilaRoutine();
    croutine->start();

    croutine->execute([] {
        doConnect();
        latch->countDown();
    });

    croutine->execute([] {
        doConnect();
        latch->countDown();
    });

    croutine->execute([] {
        doConnect();
        latch->countDown();
    });

    latch->await();
    TEST_OK("Filament simple lambda case100");
  }
