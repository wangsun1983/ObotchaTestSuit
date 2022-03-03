#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpChunk.hpp"
#include "Math.hpp"

#include "TestLog.hpp"

using namespace obotcha;

void testHttpChunkInputStream() {

  ByteArray data = createByteArray(8);
  for(int i = 0; i < 8 ;i++) {
    data[i] = i;
  }

  while(1) {
    HttpChunkInputStream stream = createHttpChunkInputStream(data);

    ByteArray rs = createByteArray(32);
    int len = stream->read(rs);
    if(len != 8) {
      TEST_FAIL("[HttpChunkInputStream test case1],len is %d",len);
      break;
    }

    for(int i = 0; i < 8 ;i++) {
      if(rs[i] != i) {
        TEST_FAIL("[HttpChunkInputStream test case2,i is %d,data is %d]",i,rs[i]);
        break;
      }
    }
    break;
  }

  while(1) {
    HttpChunkInputStream stream = createHttpChunkInputStream(data);
    ByteArray rs = createByteArray(32);
    rs[0] = 22;
    rs[1] = 11;
    rs[2] = 11;
    rs[3] = 11;
    rs[4] = 11;

    int len = stream->read(rs,3);
    if(len != 8) {
      TEST_FAIL("[HttpChunkInputStream test case3],len is %d",len);
      break;
    }

    if(rs[0] != 22 || rs[1] != 11 || rs[2] != 11) {
      TEST_FAIL("[HttpChunkInputStream test case4]");
      break;
    }

    for(int i = 0;i < 8;i++) {
      if(rs[i + 3] != i) {
        TEST_FAIL("[HttpChunkInputStream test case5,rs[%d] is %d]",i+4,i);
      }
    }
    break;
  }

  while(1) {
    HttpChunkInputStream stream = createHttpChunkInputStream(data);
    ByteArray rs = createByteArray(32);
    rs[0] = 22;
    rs[1] = 11;
    rs[2] = 11;
    rs[3] = 11;
    rs[4] = 11;
    rs[5] = 33;

    int len = stream->read(rs,3,2);
    if(len != 2) {
      TEST_FAIL("[HttpChunkInputStream test case6],len is %d",len);
      break;
    }

    if(rs[0] != 22 || rs[1] != 11 || rs[2] != 11) {
      TEST_FAIL("[HttpChunkInputStream test case7]");
      break;
    }

    for(int i = 0;i < 2;i++) {
      if(rs[i + 3] != i) {
        TEST_FAIL("[HttpChunkInputStream test case8,rs[%d] is %d",i+3,i);
      }
    }

    if(rs[5] != 33) {
      TEST_FAIL("[HttpChunkInputStream test case9");
    }
    break;
  }


  while(1) {
    ByteArray data1 = createByteArray(3);
    data1[0] = 1;
    data1[1] = 11;
    data1[2] = 22;
    HttpChunkInputStream stream = createHttpChunkInputStream(data1);

    ByteArray data2 = createByteArray(2);
    int len = stream->read(data2);
    if(len != 2) {
      TEST_FAIL("[HttpChunkInputStream test case10");
    }

    if(data2[0] != 1 || data2[1] != 11) {
      TEST_FAIL("[HttpChunkInputStream test case11");
    }
   
    break;
  }

  while(1) {
    ByteArray data1 = createByteArray(3);
    data1[0] = 1;
    data1[1] = 11;
    data1[2] = 22;
    HttpChunkInputStream stream = createHttpChunkInputStream(data1);

    ByteArray data2 = createByteArray(2);
    data2[0] = 9;
    data2[1] = 10;
    int len = stream->read(data2,1);
    if(len != 1) {
      TEST_FAIL("[HttpChunkInputStream test case12");
    }

    if(data2[0] != 9 || data2[1] != 1) {
      TEST_FAIL("[HttpChunkInputStream test case13");
    }
   
    break;
  }

  while(1) {
    ByteArray data1 = createByteArray(3);
    data1[0] = 1;
    data1[1] = 11;
    data1[2] = 22;
    HttpChunkInputStream stream = createHttpChunkInputStream(data1);

    ByteArray data2 = createByteArray(6);
    data2[0] = 9;
    data2[1] = 10;
    data2[2] = 10;
    data2[3] = 10;
    data2[4] = 10;
    data2[5] = 10;
    
    int len = stream->read(data2,1,5);
    if(len != 3) {
      TEST_FAIL("[HttpChunkInputStream test case14");
    }

    if(data2[0] != 9 || data2[1] != 1 || data2[2] != 11 || data2[3] != 22 || data2[4] != 10) {
      TEST_FAIL("[HttpChunkInputStream test case15");
    }
   
    break;
  }

  TEST_OK("[HttpChunkInputStream test case100]");

}
