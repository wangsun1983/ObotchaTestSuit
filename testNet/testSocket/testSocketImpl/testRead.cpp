#include <stdio.h>

#include "DatagramSocketImpl.hpp"
#include "SocketBuilder.hpp"
#include "SocketMonitor.hpp"
#include "Handler.hpp"
#include "Inet4Address.hpp"
#include "TestLog.hpp"
#include "NetEvent.hpp"
#include "NetPort.hpp"
#include "FileOutputStream.hpp"

using namespace obotcha;

void testRead() {
    while(1) {
      //createFile
      File file = createFile("./tmp/data.txt");
      file->removeAll();
      file->createNewFile();

      FileOutputStream stream = createFileOutputStream(createFile("./tmp/data.txt"));
      String content = createString("hello world");
      stream->open();
      stream->write(content->toByteArray());
      stream->close();

      //testRead
      int fd = open("./tmp/data.txt",O_CREAT|O_CREAT);
      FileDescriptor desc = createFileDescriptor(fd);
      SocketImpl impl = createSocketImpl(desc);
      ByteArray data = impl->read();
      if(data == nullptr) {
        TEST_FAIL("SocketImpl testRead case1");
        break;
      }

      if(!data->toString()->equals("hello world")) {
        TEST_FAIL("SocketImpl testRead case2");
      }

      lseek(fd, 0, SEEK_SET);
      ByteArray data1 = createByteArray(4);
      int len = impl->read(data1);
      if(len != 4) {
        TEST_FAIL("SocketImpl testRead case3");
        break;
      }

      if(!data1->toString()->equals("hell")) {
        TEST_FAIL("SocketImpl testRead case4");
        break;
      }

      lseek(fd, 0, SEEK_SET);
      ByteArray data2 = createByteArray(32);
      data2[0] = 1;
      data2[1] = 2;
      int len2 = impl->read(data2,2,4);
      if(len2 != 4) {
        TEST_FAIL("SocketImpl testRead case5");
        break;
      }

      if(data2[0] != 1 || data2[1] != 2 || data2[2] != 'h' || data2[3] != 'e' || data2[4] != 'l' || data2[5] != 'l') {
        TEST_FAIL("SocketImpl testRead case6");
        break;
      }
      break;
    }

    TEST_OK("SocketImpl testRead case100");
}
