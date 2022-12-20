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

CountDownLatch latch = createCountDownLatch(1);

DECLARE_CLASS(MyListener) IMPLEMENTS(SocketListener) {
public:
    void onSocketMessage(int event,Socket,ByteArray) {
//      if(event == st(NetEvent)::Disconnect) {
//        latch->countDown();
//      }
    }
};

int main() {
    //create testFile;
    createSampleFile(createFile("./tmp/testdata"),1024*1024*32);

    int port = getEnvPort();
    Socket s = createSocketBuilder()
                ->setAddress(createInet4Address(port))
                ->newSocket();

    s->connect();

    SocketMonitor monitor = createSocketMonitor();
    monitor->bind(s,createMyListener());

    OutputStream stream = s->getOutputStream();
    stream->open();

    long index = 0;

    File file = createFile("./tmp/testdata");

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
    
    Thread t = createThread([&stream]{
        int formsize = 0;
        int sameCount = 5;
        while(1) {
            if(formsize == 0) {
                stream->close();
            }
            File datafile = createFile("./tmp/testdata");
            File rcvfile = createFile("./tmp/file");
            
            printf("datafile size is %ld,rcvfile size is %ld \n",
                    datafile->length(),rcvfile->length());
            
            if(formsize != rcvfile->length()) {
                formsize = rcvfile->length();
            } else {
                sameCount--;
                if(sameCount == 0) {
                    return;
                }
            }
            sleep(1);
        }
        
    });

    t->start();
    t->join();
    
    Md md5 = createMd();
    String v1 = md5->encrypt(createFile("./tmp/testdata"));
    String v2 = md5->encrypt(createFile("./tmp/file"));
    
    if(v1->equals(v2)) {
        TEST_FAIL("testAsyncOutputChannel close case1")
    }
    
    TEST_OK("testAsyncOutputChannel close case100");
}
