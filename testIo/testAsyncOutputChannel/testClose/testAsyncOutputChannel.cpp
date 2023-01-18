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
#include "AsyncOutputChannel.hpp"
#include "AsyncOutputChannelPool.hpp"
#include "FileDescriptor.hpp"
#include "ForEveryOne.hpp"

using namespace obotcha;

void testAsyncOutputChannel() {

    ArrayList<AsyncOutputChannel> list = createArrayList<AsyncOutputChannel>();
    AsyncOutputChannelPool pool = createAsyncOutputChannelPool();
    for(int i = 1024;i < 1024*5;i++) {
        FileDescriptor fd = createFileDescriptor(i);
        auto c = pool->createChannel(fd,nullptr);
        list->add(c);
    }
    
    if(pool->isChannelsEmpty()) {
        TEST_FAIL("testAsyncOutputChannel close channel case1");
    }
    
    usleep(1000*50);
    ForEveryOne(c,list) {
        c->close();
    }
    
    usleep(1000*100);
    if(!pool->isChannelsEmpty()) {
        TEST_FAIL("testAsyncOutputChannel close channel case2");
    }
    
    TEST_OK("testAsyncOutputChannel close channel case100");
}
