#include "DatagramSocketImpl.hpp"
#include "SocketBuilder.hpp"
#include "SocketMonitor.hpp"
#include "Handler.hpp"
#include "Inet4Address.hpp"
#include "TestLog.hpp"
#include "NetEvent.hpp"
#include "SocksSocketImpl.hpp"
#include "Socket.hpp"
#include "SSLSocksSocketImpl.hpp"
#include "File.hpp"
#include "FileInputStream.hpp"
#include "FileOutputStream.hpp"

using namespace obotcha;

void testSocketRead() {
    File file1 = createFile("./tmp/readdata.txt");
    if(!file1->exists()) {
        file1->createNewFile();
        FileOutputStream output = createFileOutputStream(file1);
        output->open();
        
        ByteArray data = createByteArray(64);
        for(int i = 0 ;i < 64;i++) {
            data[i] = i;
        }
        output->write(data);
        output->flush();
    }
    
    while(1) {
        auto fd = st(File)::open(createString("./tmp/readdata.txt"));
        SocketImpl impl = createSocketImpl(fd);
        ByteArray data = createByteArray(32);
        
        int size = impl->read(data);
        if(size != 32) {
            TEST_FAIL("SocketImpl read case1");
        }
        
        for(int i = 0 ;i < 32;i++) {
            if(data[i] != i) {
                TEST_FAIL("SocketImpl read case2");
            }
        }
        break;
    }
    
    while(1) {
        auto fd = st(File)::open(createString("./tmp/readdata.txt"));
        SocketImpl impl = createSocketImpl(fd);
        ByteArray data = createByteArray(32);
        
        int size = impl->read(data,2,12);
        data[0] = 22;
        data[1] = 23;
        
        if(size != 12) {
            TEST_FAIL("SocketImpl read case3");
        }
        
        if(data[0] != 22) {
            TEST_FAIL("SocketImpl read case4");
        }
        
        if(data[1] != 23) {
            TEST_FAIL("SocketImpl read case5");
        }
        
        for(int i = 2 ;i < 12;i++) {
            if(data[i] != i-2) {
                TEST_FAIL("SocketImpl read case6,data is %d,expect is %d",data[i],i - 2);
            }
        }
        break;
    }
    
    while(1) {
        auto fd = st(File)::open(createString("./tmp/readdata.txt"));
        SocketImpl impl = createSocketImpl(fd);
        ByteArray data = createByteArray(32);
        
        int size = impl->read(data,2,128);
        data[0] = 22;
        data[1] = 23;
        
        if(size != 30) {
            TEST_FAIL("SocketImpl read case7");
        }
        
        if(data[0] != 22) {
            TEST_FAIL("SocketImpl read case8");
        }
        
        if(data[1] != 23) {
            TEST_FAIL("SocketImpl read case9");
        }
        
        for(int i = 2 ;i < 30;i++) {
            if(data[i] != i-2) {
                TEST_FAIL("SocketImpl read case10,data is %d,expect is %d",data[i],i - 2);
            }
        }
        break;
    }
    
    while(1) {
        auto fd = createFileDescriptor(123);
        SocketImpl impl = createSocketImpl(fd);
        auto ret = impl->read();
        if(ret != nullptr) {
            TEST_FAIL("SocketImpl read case11");
        }
        break;
    }
    
    TEST_OK("SocketImpl read case100");
}
