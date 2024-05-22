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

CountDownLatch latch = CountDownLatch::New(1);

DECLARE_CLASS(MyHandler) IMPLEMENTS(Handler) {
public:
    void handleMessage(Message msg) {
        File f = File::New("./tmp/file");
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
    File f = File::New("./tmp/file");
    f->removeAll();
    stream = FileOutputStream::New("./tmp/file");
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
    createSampleFile(File::New("./tmp/testdata"),1024*1024*16);
    MyHandler h = MyHandler::New();
    h->sendEmptyMessageDelayed(0,1000*5);
    int port = getEnvPort();
    InetAddress addr = Inet4Address::New(port);
    ServerSocket sock = SocketBuilder::New()->setAddress(addr)->newServerSocket();
    int result = sock->bind();
    SocketMonitor monitor = SocketMonitor::New();
    ServerListener l = ServerListener::New();
    monitor->bind(sock,l);
    
    
    addr = Inet4Address::New(port);
    Socket client = SocketBuilder::New()->setAddress(addr)->newSocket();
    client->connect();
    
    Socket client2 = SocketBuilder::New()->setAddress(addr)->newSocket();
    client2->connect();
    
    auto pool1 = AsyncOutputChannelPool::New();
    auto outputstream = client->getOutputStream();
    auto socketoutput = Cast<SocketOutputStream>(outputstream);
    auto channel1 = st(AsyncOutputChannelPool)::CreateChannel(client->getFileDescriptor(),socketoutput->getSocket());
    
    auto pool2 = AsyncOutputChannelPool::New();
    auto outputstream2 = client2->getOutputStream();
    auto socketoutput2 = Cast<SocketOutputStream>(outputstream2);
    auto channel2 = st(AsyncOutputChannelPool)::CreateChannel(client2->getFileDescriptor(),socketoutput->getSocket());
    
    pool2->add(channel1);
    pool1->close();
    
    printf("pool1 is %lx,pool2 is %lx \n",pool1.get_pointer(),pool2.get_pointer());
    FileInputStream stream = FileInputStream::New("./tmp/testdata");
    stream->open();
    ByteArray data = ByteArray::New(1024*4);
    while(1) {
        if(stream->read(data) > 0) {
            channel1->write(data);
        } else {
            break;
        }
    }
    
    latch->await();
    Md md = Md::New();
    auto ori = md->encodeFile(File::New("./tmp/testdata"));
    auto test = md->encodeFile(File::New("./tmp/file"));
    if(!ori->sameAs(test)) {
        TEST_FAIL("AsyncOutputChannelPool addChannel case1");
    }
    TEST_OK("AsyncOutputChannelPool addChannel case100");
    return 0;
}
