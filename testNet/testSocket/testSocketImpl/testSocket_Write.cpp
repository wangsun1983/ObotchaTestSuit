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

using namespace obotcha;

void testSocketWrite() {
    File delfile1 = createFile("./tmp/write1.txt");
    File delfile2 = createFile("./tmp/write2.txt");
    File delfile3 = createFile("./tmp/write3.txt");
    delfile1->removeAll();
    delfile2->removeAll();
    delfile3->removeAll();
    
    while(1) {
        File file1 = createFile("./tmp/write1.txt");
        file1->createNewFile();
        auto fd = st(File)::Open(createString("./tmp/write1.txt"));
        SocketImpl impl = createSocketImpl(fd);
        
        ByteArray data = createByteArray(32);
        for(int i = 0;i < 32;i++) {
            data[i] = i;
        }
        impl->write(data);
        
        FileInputStream stream = createFileInputStream(createString("./tmp/write1.txt"));
        stream->open();
        ByteArray data2 = createByteArray(64);
        stream->read(data2);
        for(int i = 0;i < 32;i++) {
            if(data2[i] != i) {
                TEST_FAIL("SocketImpl write case1,data is %d,expect is %d",data2[i],i);
            }
        }
        
        impl->close();
        stream->close();
        break;
    }
    
    while(1) {
        File file1 = createFile("./tmp/write2.txt");
        file1->createNewFile();
        auto fd = st(File)::Open(createString("./tmp/write2.txt"));
        SocketImpl impl = createSocketImpl(fd);
        
        ByteArray data = createByteArray(32);
        for(int i = 0;i < 32;i++) {
            data[i] = i;
        }
        impl->write(data,2,12);
        
        FileInputStream stream = createFileInputStream(createString("./tmp/write2.txt"));
        stream->open();
        ByteArray data2 = createByteArray(64);
        int size = stream->read(data2);
        if(size != 12) {
            TEST_FAIL("SocketImpl write case2,size is %d,expect is %d",size,12);
        }
        
        for(int i = 0;i < 12;i++) {
            if(data2[i] != i+2) {
                TEST_FAIL("SocketImpl write case3,data is %d,expect is %d",data2[i],i);
            }
        }
        
        impl->close();
        stream->close();
        break;
    }
    
    while(1) {
        File file1 = createFile("./tmp/write3.txt");
        file1->createNewFile();
        auto fd = st(File)::Open(createString("./tmp/write3.txt"));
        SocketImpl impl = createSocketImpl(fd);
        
        ByteArray data = createByteArray(32);
        for(int i = 0;i < 32;i++) {
            data[i] = i;
        }
        impl->write(data,2,64);
        
        FileInputStream stream = createFileInputStream(createString("./tmp/write3.txt"));
        stream->open();
        ByteArray data2 = createByteArray(64);
        int size = stream->read(data2);
        if(size != 30) {
            TEST_FAIL("SocketImpl write case4,size is %d,expect size is %d",size,30);
        }
        
        for(int i = 0;i < 30;i++) {
            if(data2[i] != i+2) {
                TEST_FAIL("SocketImpl write case5,data is %d,expect is %d",data2[i],i);
            }
        }
        
        impl->close();
        stream->close();
        break;
    }
    

    TEST_OK("SocketImpl write case100");
}
