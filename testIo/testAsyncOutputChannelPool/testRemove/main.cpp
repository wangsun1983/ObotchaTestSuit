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

using namespace obotcha;

BlockingQueue<AsyncOutputChannel> channelQueue = createBlockingQueue<AsyncOutputChannel>();
CountDownLatch latch = createCountDownLatch(2);

int main() {
    while(1) {
        AsyncOutputChannelPool pool = createAsyncOutputChannelPool();
        Thread t1 = createThread([&pool]{
            for(int i = 10;i<1024*128;i++) {
                FileDescriptor fd = createFileDescriptor(i);
                auto c = pool->createChannel(fd,nullptr);
                channelQueue->putFirst(c);
            }
            channelQueue->putFirst(nullptr);
            latch->countDown();
        });
        t1->start();
        
        Thread t2 = createThread([&pool]{
            while(1) {
                auto c = channelQueue->takeLast();
                if(c == nullptr) {
                    break;
                }
                pool->remove(c);
            }
            latch->countDown();
        });
        t2->start();
        t1->join();
        t2->join();
        latch->await();
        
        if(!pool->isEmpty()) {
            TEST_FAIL("testAsyncOutputChannel testRemove case1");
        }
        break;
    }
    TEST_OK("testAsyncOutputChannel testRemove case100");
}
