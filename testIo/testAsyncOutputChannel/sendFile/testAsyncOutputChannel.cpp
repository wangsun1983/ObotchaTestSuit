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

using namespace obotcha;

CountDownLatch latch = CountDownLatch::New(1);

DECLARE_CLASS(MyListener) IMPLEMENTS(SocketListener) {
public:
    void onSocketMessage(st(Net)::Event event,Socket,ByteArray) {
//      if(event == st(NetEvent)::Disconnect) {
//        latch->countDown();
//      }
    }
};

int main() {
    //create testFile;
    //createSampleFile(File::New("./tmp/testdata"),1024*1024*4);

    int port = getEnvPort();
    Socket s = SocketBuilder::New()
                ->setAddress(Inet4Address::New(port))
                ->newSocket();

    s->connect();

    SocketMonitor monitor = SocketMonitor::New();
    monitor->bind(s,MyListener::New());

    OutputStream stream = s->getOutputStream();

    long index = 0;

    File file = File::New("./tmp/testdata");

    FileInputStream inputstream = FileInputStream::New(file);
    inputstream->open();

    while(1) {
        ByteArray data = ByteArray::New(1024*4);
        int length = inputstream->read(data);
        index += length;
        data->quickShrink(length);
        stream->write(data);
        data->quickRestore();
        if(index >= file->length()) {
            break;
        }
    }
    
    Thread t = Thread::New([]{
        while(1) {
            sleep(5);
            File datafile = File::New("./tmp/testdata");
            File rcvfile = File::New("./tmp/file");
            if(datafile->length() != rcvfile->length()) {
                printf("datafile size is %ld,rcvfile size is %ld \n",
                        datafile->length(),rcvfile->length());
            } else {
                return;
            }
        }
        
    });

    t->start();
    t->join();
    
    Md md5 = Md::New();
    String v1 = md5->encodeFile(File::New("./tmp/testdata"));
    String v2 = md5->encodeFile(File::New("./tmp/file"));
    
    if(!v1->equals(v2)) {
        TEST_FAIL("testAsyncOutputChannel case1");
    }
    
    TEST_OK("testAsyncOutputChannel case1");
}
