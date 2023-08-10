#include <stdio.h>
#include <unistd.h>

#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "WebSocketServer.hpp"
#include "WebSocketListener.hpp"
#include "Mutex.hpp"
#include "Condition.hpp"
#include "AutoLock.hpp"
#include "WebSocketProtocol.hpp"
#include "WebSocketComposer.hpp"
#include "File.hpp"
#include "FileOutputStream.hpp"
#include "AtomicInteger.hpp"
#include "CountDownLatch.hpp"
#include "WebSocketServerBuilder.hpp"
#include "System.hpp"
#include "Md.hpp"
#include "Inet4Address.hpp"

#include "TestLog.hpp"
#include "NetEvent.hpp"
#include "NetPort.hpp"

using namespace obotcha;

CountDownLatch latch = createCountDownLatch(1);

DECLARE_CLASS(MyWsListener) IMPLEMENTS(WebSocketListener) {
public:
    _MyWsListener() {
        File f = createFile("./tmp/rcvfile");
        if(f->exists()) {
            f->removeAll();
        }
        f->createNewFile();

        stream = createFileOutputStream(f);
        stream->open();
    }

    int onData(WebSocketFrame message,WebSocketLinker client) {
        stream->write(message->getData());
        return 0;
    }

    int onConnect(WebSocketLinker client) {
        return 0;
    }

    int onDisconnect(WebSocketLinker client) {
        latch->countDown();
        return 0;
    }

    int onPong(WebSocketLinker client) {
        return 0;
    }

    int onPing(WebSocketLinker client) {
        return 0;
    }

private:
    FileOutputStream stream;
};



int main() {
    MyWsListener l = createMyWsListener();

    int port = getEnvPort();
    InetAddress address = createInet4Address(port);
    printf("address is %s,r port is %d \n",address->toString()->toChars(),port);
    WebSocketServer server = createWebSocketServerBuilder()
                            ->setInetAddr(address)
                            ->addListener("mytest",l)
                            ->build();

    server->start();

    latch->await();

/*
    //check md5
    Md md5 = createMd();
    String base = md5->encodeFile(createFile("./tmp/data"));
    String rcv = md5->encodeFile(createFile("./tmp/rcvfile"));
    if(!base->equals(rcv)) {
        TEST_FAIL("WebSocketServer SimpleFile test1");
    }
*/
    port++;
    setEnvPort(port);
    server->close();

    TEST_OK("WebSocketServer SimpleFile test100");
}
