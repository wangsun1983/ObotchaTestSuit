#include "SocketBuilder.hpp"
#include "SocketMonitor.hpp"
#include "File.hpp"
#include "FileInputStream.hpp"
#include "TestLog.hpp"
#include "NetPort.hpp"
#include "Inet4Address.hpp"
#include "CountDownLatch.hpp"
#include "Md.hpp"
#include "SampleFile.hpp"
#include "NetEvent.hpp"

using namespace obotcha;

CountDownLatch latch = createCountDownLatch(1);

DECLARE_CLASS(MyListener) IMPLEMENTS(SocketListener) {
public:
    void onSocketMessage(int event,Socket,ByteArray) {
      if(event == st(NetEvent)::Disconnect) {
        latch->countDown();
      }
    }
};

int main() {
    //create testFile;
    createSampleFile(createFile("./temp/data"),1024*1024*16);

    int port = 2007;//getEnvPort();
    Socket s = createSocketBuilder()
                ->setAddress(createInet4Address(port))
                ->newSocket();

    s->connect();

    SocketMonitor monitor = createSocketMonitor();
    monitor->bind(s,createMyListener());

    OutputStream stream = s->getOutputStream();

    long index = 0;

    File file = createFile("./temp/data");

    FileInputStream inputstream = createFileInputStream(file);
    inputstream->open();

    while(1) {
        ByteArray data = createByteArray(1024*4);
        int length = inputstream->read(data);
        index += length;
        data->quickShrink(length);
        stream->write(data);
        data->quickRestore();
        if(index >= file->length()) {
            break;
        }
    }

    printf("index is %ld \n",index);
    latch->await();

}
