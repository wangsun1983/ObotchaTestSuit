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
#include "Md.hpp"
#include "AsyncOutputChannelPool.hpp"
#include "BlockingQueue.hpp"
#include "FileDescriptor.hpp"
#include "CountDownLatch.hpp"
#include "Handler.hpp"
#include "Md.hpp"

using namespace obotcha;

CountDownLatch latch = createCountDownLatch(1);

DECLARE_CLASS(MyHandler) IMPLEMENTS(Handler) {
public:
    void handleMessage(Message msg) {
        File f = createFile("./tmp/file");
        if(f->length() != filesize) {
            filesize = f->length();
            this->sendEmptyMessageDelayed(0,1000*5);
            count = 0;
        } else {
            count++;
            this->sendEmptyMessageDelayed(0,1000*5);
        }
        
        if(count == 3) {
            latch->countDown();
        }
        printf("filesize is %ld \n",f->length());
    }

private:
    int count = 0;
    size_t filesize = 0;
};

DECLARE_CLASS(ServerListener) IMPLEMENTS(SocketListener) {

public:
  _ServerListener() {
    File f = createFile("./tmp/file");
    f->removeAll();
    stream = createFileOutputStream("./tmp/file");
    stream->open(O_APPEND);
  }
  
  void onSocketMessage(st(Net)::Event event,Socket s,ByteArray data) {
    switch(event) {
      case st(Net)::Event::Message: {
        stream->write(data);
        usleep(1000*100);
      }
    }
  }
  
private:
  FileOutputStream stream;
};

int main() {
    //create socket server
    createSampleFile(createFile("./tmp/testdata"),1024*1024*16);
    MyHandler h = createMyHandler();
    h->sendEmptyMessageDelayed(0,1000*5);
    int port = getEnvPort();
    InetAddress addr = createInet4Address(port);
    ServerSocket sock = createSocketBuilder()->setAddress(addr)->newServerSocket();
    int result = sock->bind();
    SocketMonitor monitor = createSocketMonitor();
    ServerListener l = createServerListener();
    monitor->bind(sock,l);
    
    
    addr = createInet4Address(port);
    Socket client = createSocketBuilder()->setAddress(addr)->newSocket();
    client->connect();
    
    Socket client2 = createSocketBuilder()->setAddress(addr)->newSocket();
    client2->connect();
    
    auto pool1 = createAsyncOutputChannelPool();
    auto outputstream = client->getOutputStream();
    auto socketoutput = Cast<SocketOutputStream>(outputstream);
    auto channel1 = pool1->createChannel(client->getFileDescriptor(),socketoutput->getSocket());
    
    auto pool2 = createAsyncOutputChannelPool();
    auto outputstream2 = client2->getOutputStream();
    auto socketoutput2 = Cast<SocketOutputStream>(outputstream2);
    auto channel2 = pool1->createChannel(client2->getFileDescriptor(),socketoutput->getSocket());
    
    pool2->addChannel(channel1);
    pool1->close();
    
    printf("pool1 is %lx,pool2 is %lx \n",pool1.get_pointer(),pool2.get_pointer());
    FileInputStream stream = createFileInputStream("./tmp/testdata");
    stream->open();
    ByteArray data = createByteArray(1024*4);
    while(1) {
        if(stream->read(data) > 0) {
            channel1->write(data);
        } else {
            break;
        }
    }
    
    latch->await();
    Md md = createMd();
    auto ori = md->encodeFile(createFile("./tmp/testdata"));
    auto test = md->encodeFile(createFile("./tmp/file"));
    if(!ori->sameAs(test)) {
        TEST_FAIL("AsyncOutputChannelPool addChannel case1");
    }
    TEST_OK("AsyncOutputChannelPool addChannel case100");
    return 0;
}
