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
    //createSampleFile(File::New("./tmp/testdata"),1024*1024*32);

    int port = getEnvPort();
    
    Socket s =SocketBuilder::New()
                ->setAddress(Inet4Address::New(port))
                ->newSocket();
    
    int ret = s->connect();
    printf("connect ret is %d \n",ret);

    SocketMonitor monitor = SocketMonitor::New();
	printf("trace0 \n");
    monitor->bind(s,MyListener::New());
	printf("trace1 \n");
    OutputStream stream = s->getOutputStream();
    stream->open();
	printf("trace2 \n");
    long index = 0;

    File file = File::New("./tmp/testdata");

    FileInputStream inputstream = FileInputStream::New(file);
    inputstream->open();
	printf("trace3 \n");
    while(1) {
        ByteArray data = ByteArray::New(1024*4);
		printf("trace1 \n");
        int length = inputstream->read(data);
        index += length;
        data->quickShrink(length);
        stream->write(data);
        data->quickRestore();
        if(index >= file->length()) {
            break;
        }
    }
    
    Thread t = Thread::New([&stream]{
        int formsize = 0;
        int sameCount = 5;
        while(1) {
            File datafile = File::New("./tmp/testdata");
            File rcvfile = File::New("./tmp/file");
            
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
    
    Md md5 = Md::New();
    String v1 = md5->encodeFile(File::New("./tmp/testdata"));
    
    auto result_file = File::New("./tmp/file");
    
    if(!result_file->exists()) {
        TEST_FAIL("testAsyncOutputChannel close case1");
    } else {
        String v2 = md5->encodeFile(File::New("./tmp/file"));
        
        if(!v1->equals(v2)) {
            TEST_FAIL("testAsyncOutputChannel close case2")
        }    
    }
    port++;
    setEnvPort(port);
    TEST_OK("testAsyncOutputChannel close case100");
}
