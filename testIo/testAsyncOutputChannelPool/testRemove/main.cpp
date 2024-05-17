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

BlockingQueue<AsyncOutputChannel> channelQueue = BlockingQueue<AsyncOutputChannel>::New();
CountDownLatch latch = CountDownLatch::New(2);

int main() {
    while(1) {
        AsyncOutputChannelPool pool = AsyncOutputChannelPool::New();
        Thread t1 = Thread::New([&pool]{
            for(int i = 10;i<1024*128;i++) {
                FileDescriptor fd = FileDescriptor::New(i);
                auto c = st(AsyncOutputChannelPool)::CreateChannel(fd,nullptr);
                pool->add(c);
                channelQueue->putFirst(c);
            }
            channelQueue->putFirst(nullptr);
            latch->countDown();
        });
        t1->start();
        
        Thread t2 = Thread::New([&pool]{
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
        usleep(1000*1000);
        if(!pool->isEmpty()) {
            TEST_FAIL("testAsyncOutputChannel testRemove case1,size is %d",pool->size());
        }
        break;
    }
    TEST_OK("testAsyncOutputChannel testRemove case100");
}
