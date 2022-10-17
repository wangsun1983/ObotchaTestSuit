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
#include "Random.hpp"

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
    createSampleFile(createFile("./data"),1024*1024*16);
    int count = 1024*32;
    auto rand = createRandom();
    SocketMonitor monitor = createSocketMonitor();

    AsyncOutputChannel c = createAsyncOutputChannel(nullptr,nullptr);

    while(count > 0) {
        int port = 2007;//getEnvPort();
        for(int i = 0; i < 1024;i++) {
            Socket s = createSocketBuilder()
                    ->setAddress(createInet4Address(port))
                    ->newSocket();
            printf("start bind trace0\n");
            s->connect();
            printf("start bind trace1\n");
            monitor->bind(s,createMyListener());

            //c->dump();

            printf("start bind trace2\n");

            OutputStream stream = s->getOutputStream();

            long index = 0;

            File file = createFile("data");

            FileInputStream inputstream = createFileInputStream(file);
            try {
                inputstream->open();
            } catch(Exception e) {
                printf("error!!!!!! \n");
                sleep(1000000);
            }

            int count = rand->nextInt(1,1024);
            //printf("count is %d \n",count);
            for(int j = 0;j < count;j++) {
                ByteArray data = createByteArray(1024*4);
                int length = inputstream->read(data);
                index += length;
                //printf("leng is %d \n",length);
                data->quickShrink(length);
                stream->write(data);
                data->quickRestore();
                if(index >= file->length()) {
                    break;
                }  
            }
            
            s->close();
            inputstream->close();
            c->dump();
            monitor->dump();
            //usleep(1000000*rand->nextInt(10,20));
        }
        count--;

    }

    printf("end \n");

}
