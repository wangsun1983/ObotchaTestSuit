#include <stdio.h>

#include "File.hpp"
#include "FileInputStream.hpp"
#include "FileNotFoundException.hpp"
#include "Md.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testFileInputStreamReadNode() {
  while(1) {
    //proc/sys/fs/mqueue/msg_max
    FileInputStream stream = FileInputStream::New("/proc/sys/fs/mqueue/msg_max");
    ByteArray data = ByteArray::New(32);
    stream->open();
    int len = stream->read(data);
    String value = data->toString();
    int v = value->toBasicInt();

    int fd = open("/proc/sys/fs/mqueue/msg_max",O_RDONLY);
    char buff[32] = {0};
    read(fd,buff,32);
    int v2 = atoi(buff);
    if(v != v2) {
      TEST_FAIL("testFileInputNodeRead test1,v is %d,v2 is %d ",v,v2);
    }

    break;
  }

  TEST_OK("testFileInputNodeRead test100");
}
