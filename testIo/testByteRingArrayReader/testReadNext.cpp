#include <stdio.h>
#include <unistd.h>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"
#include "ByteRingArray.hpp"
#include "ByteRingArrayReader.hpp"
#include "TestLog.hpp"

using namespace obotcha;


void testReadNext() {
  //case1
  //data:[1(start/end),2,3,4,5]
  while(1) {
    ByteRingArray ringarray = ByteRingArray::New(5);
    ringarray->push(1);
    ringarray->push(2);
    ringarray->push(3);
    ringarray->push(4);
    ringarray->push(5);
    byte v1;
    byte v2;
    byte v3;
    byte v4;
    byte v5;
    int startIndex = ringarray->getStartIndex();
    int endIndex = ringarray->getEndIndex();
    ByteRingArrayReader reader = ByteRingArrayReader::New(ringarray);
    if(reader->readNext(v1) != st(IO)::Reader::Result::HasContent) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext} case1]");
        return;
    }
    if(v1 != 1) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext} case1_1]");
        return;
    }
    if(reader->readNext(v2) != st(IO)::Reader::Result::HasContent) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext} case2]");
        return;
    }
    if(v2 != 2) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext} case2_1]");
        return;
    }
    if(reader->readNext(v3) != st(IO)::Reader::Result::HasContent) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext} case3]");
        return;
    }
    if(v3 != 3) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext} case3_1]");
        return;
    }
    if(reader->readNext(v4) != st(IO)::Reader::Result::HasContent) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext} case4]");
        return;
    }
    if(v4 != 4) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext} case4_1]");
        return;
    }

    if(reader->readNext(v5) != st(IO)::Reader::Result::HasContent) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext} case5]");
        return;
    }
    if(v5 != 5) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext} case5_1]");
        return;
    }
    byte end;
    if(reader->readNext(end) != st(IO)::Reader::Result::NoContent) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext} case6]");
        return;
    }
    ByteArray popdata = reader->pop();
    if(popdata->size() != 5) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext} case7]");
        return;
    }
    if(popdata[0]!= 1 ||popdata[1] != 2||popdata[2] != 3||popdata[3] != 4||popdata[4] != 5) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext} case8]");
        return;
    }

    TEST_OK("[ByteRingArrayReader Test {testReadNext} case9]");
    break;
  }

  //case2
  //data:[1(end),2(start),3,4,5]
  while(1) {
    ByteRingArray ringarray = ByteRingArray::New(5);
    ringarray->push(1);
    ringarray->push(2);
    ringarray->push(3);
    ringarray->push(4);
    ringarray->push(5);
    byte v1;
    byte v2;
    byte v3;
    byte v4;
    byte v5;
    ringarray->setEndIndex(1);
    ringarray->setSize(5);

    ByteRingArrayReader reader = ByteRingArrayReader::New(ringarray);
    if(reader->readNext(v1) != st(IO)::Reader::Result::HasContent) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition2} case1]");
        return;
    }
    if(v1 != 2) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition2} case1_1] [FAIL],v is %d",v1);
        return;
    }

    if(reader->readNext(v2) != st(IO)::Reader::Result::HasContent) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition2} case2]");
        return;
    }
    if(v2 != 3) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition2} case2_1]");
        return;
    }

    if(reader->readNext(v3) != st(IO)::Reader::Result::HasContent) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition2} case3]");
        return;
    }
    if(v3 != 4) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition2} case3_1]");
        return;
    }

    if(reader->readNext(v4) != st(IO)::Reader::Result::HasContent) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition2} case4]");
        return;
    }
    if(v4 != 5) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition2} case4_1]");
        return;
    }

    if(reader->readNext(v5) != st(IO)::Reader::Result::HasContent) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition2} case4_2]");
        return;
    }
    if(v5 != 1) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition2} case4_3] [FAIL],v5 is %d",v5);
        return;
    }

    byte end;
    auto result = reader->readNext(end);
    if(result != st(IO)::Reader::Result::NoContent) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition2} case6]");
        return;
    }

    ByteArray popdata = reader->pop();
    if(popdata->size() != 5) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition2} case7]");
        return;
    }

    if(popdata[0]!= 2 ||popdata[1] != 3||popdata[2] != 4||popdata[3] != 5 ||popdata[4] != 1) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition2} case8]");
        return;
    }

    TEST_OK("[ByteRingArrayReader Test {testReadNext condition2} case7]");
    break;
  }

  //case3
  //data:[1(end),2,3(start),4,5]
  while(1) {
    ByteRingArray ringarray = ByteRingArray::New(5);
    ringarray->push(1);
    ringarray->push(2);
    ringarray->push(3);
    ringarray->push(4);
    ringarray->push(5);
    byte v1;
    byte v2;
    byte v3;
    byte v4;
    byte v5;
    ringarray->setEndIndex(0);
    ringarray->setSize(3);

    ByteRingArrayReader reader = ByteRingArrayReader::New(ringarray);
    if(reader->readNext(v1) != st(IO)::Reader::Result::HasContent) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition3} case1]");
        return;
    }
    if(v1 != 3) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition3} case1_1]");
        return;
    }

    if(reader->readNext(v2) != st(IO)::Reader::Result::HasContent) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition3} case2]");
        return;
    }
    if(v2 != 4) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition3} case2_1]");
        return;
    }

    if(reader->readNext(v3) != st(IO)::Reader::Result::HasContent) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition3} case3]");
        return;
    }
    if(v3 != 5) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition3} case3_1]");
        return;
    }

    byte end;
    if(reader->readNext(end) != st(IO)::Reader::Result::NoContent) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition3} case6]");
        return;
    }

    ByteArray popdata = reader->pop();
    if(popdata->size() != 3) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition3} case7]");
        return;
    }

    if(popdata[0]!= 3 ||popdata[1] != 4||popdata[2] != 5) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition3} case8]");
        return;
    }

    TEST_OK("[ByteRingArrayReader Test {testReadNext condition3} case7]");
    break;
  }

  //case4
  //data:[1(end),2,3,4(start),5]
  while(1) {
    ByteRingArray ringarray = ByteRingArray::New(5);
    ringarray->push(1);
    ringarray->push(2);
    ringarray->push(3);
    ringarray->push(4);
    ringarray->push(5);
    byte v1;
    byte v2;
    byte v3;
    byte v4;
    byte v5;
    ringarray->setEndIndex(0);
    ringarray->setSize(2);

    ByteRingArrayReader reader = ByteRingArrayReader::New(ringarray);
    if(reader->readNext(v1) != st(IO)::Reader::Result::HasContent) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition4} case1]");
        return;
    }
    if(v1 != 4) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition4} case1_1]");
        return;
    }

    if(reader->readNext(v2) != st(IO)::Reader::Result::HasContent) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition4} case2]");
        return;
    }
    if(v2 != 5) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition4} case2_1]");
        return;
    }

    byte end;
    if(reader->readNext(end) != st(IO)::Reader::Result::NoContent) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition4} case6]");
        return;
    }

    ByteArray popdata = reader->pop();
    if(popdata->size() != 2) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition4} case7]");
        return;
    }

    if(popdata[0]!= 4 ||popdata[1] != 5) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition4} case8]");
        return;
    }

    TEST_OK("[ByteRingArrayReader Test {testReadNext condition4} case7]");
    break;
  }

  //case5
  //data:[1(end),2,3,4,5(start)]
  while(1) {
    ByteRingArray ringarray = ByteRingArray::New(5);
    ringarray->push(1);
    ringarray->push(2);
    ringarray->push(3);
    ringarray->push(4);
    ringarray->push(5);
    byte v1;
    byte v2;
    byte v3;
    byte v4;
    byte v5;

    ringarray->setEndIndex(0);
    ringarray->setSize(1);

    ByteRingArrayReader reader = ByteRingArrayReader::New(ringarray);
    if(reader->readNext(v1) != st(IO)::Reader::Result::HasContent) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition5} case1]");
        return;
    }
    if(v1 != 5) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition5} case1_1]");
        return;
    }

    byte end;
    if(reader->readNext(end) != st(IO)::Reader::Result::NoContent) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition5} case6]");
        return;
    }

    ByteArray popdata = reader->pop();
    if(popdata->size() != 1) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition5} case7]");
        return;
    }

    if(popdata[0]!= 5) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition5} case8]");
        return;
    }

    TEST_OK("[ByteRingArrayReader Test {testReadNext condition5} case7]");
    break;
  }

  //case5
  //data:[1,2(end/start),3,4,5]
  while(1) {
    ByteRingArray ringarray = ByteRingArray::New(5);
    ringarray->push(1);
    ringarray->push(2);
    ringarray->push(3);
    ringarray->push(4);
    ringarray->push(5);
    byte v1;
    byte v2;
    byte v3;
    byte v4;
    byte v5;
    ringarray->setEndIndex(1);
    ringarray->setSize(5);

    ByteRingArrayReader reader = ByteRingArrayReader::New(ringarray);
    if(reader->readNext(v1) != st(IO)::Reader::Result::HasContent) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition6} case1]");
        return;
    }
    if(v1 != 2) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition6} case1_1]");
        return;
    }

    if(reader->readNext(v2) != st(IO)::Reader::Result::HasContent) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition6} case2]");
        return;
    }
    if(v2 != 3) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition6} case2_1]");
        return;
    }

    if(reader->readNext(v3) != st(IO)::Reader::Result::HasContent) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition6} case3]");
        return;
    }
    if(v3 != 4) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition6} case3_1]");
        return;
    }

    if(reader->readNext(v4) != st(IO)::Reader::Result::HasContent) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition6} case4]");
        return;
    }
    if(v4 != 5) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition6} case4_1]");
        return;
    }

    if(reader->readNext(v5) != st(IO)::Reader::Result::HasContent) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition6} case5]");
        return;
    }
    if(v5 != 1) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition6} case5_1]");
        return;
    }

    byte end;
    if(reader->readNext(end) != st(IO)::Reader::Result::NoContent) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition6} case6]");
        return;
    }

    ByteArray popdata = reader->pop();
    if(popdata->size() != 5) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition6} case7]");
        return;
    }

    if(popdata[0]!= 2 ||popdata[1]!= 3||popdata[2]!= 4||popdata[3]!= 5||popdata[4]!= 1) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition6} case8]");
        return;
    }

    TEST_OK("[ByteRingArrayReader Test {testReadNext condition6} case8]");
    break;
  }

  //case6
  //data:[1,2(end),3(start),4,5]
  while(1) {
    ByteRingArray ringarray = ByteRingArray::New(5);
    ringarray->push(1);
    ringarray->push(2);
    ringarray->push(3);
    ringarray->push(4);
    ringarray->push(5);
    byte v1;
    byte v2;
    byte v3;
    byte v4;
    byte v5;
    ringarray->setEndIndex(1);
    ringarray->setSize(4);

    ByteRingArrayReader reader = ByteRingArrayReader::New(ringarray);
    if(reader->readNext(v1) != st(IO)::Reader::Result::HasContent) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition7} case1]");
        return;
    }
    if(v1 != 3) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition7} case1_1]");
        return;
    }

    if(reader->readNext(v2) != st(IO)::Reader::Result::HasContent) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition7} case2]");
        return;
    }
    if(v2 != 4) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition7} case2_1]");
        return;
    }

    if(reader->readNext(v3) != st(IO)::Reader::Result::HasContent) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition7} case3]");
        return;
    }
    if(v3 != 5) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition7} case3_1]");
        return;
    }

    if(reader->readNext(v4) != st(IO)::Reader::Result::HasContent) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition7} case4]");
        return;
    }
    if(v4 != 1) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition7} case4_1]");
        return;
    }

    byte end;
    if(reader->readNext(end) != st(IO)::Reader::Result::NoContent) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition7} case6]");
        return;
    }

    ByteArray popdata = reader->pop();
    if(popdata->size() != 4) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition7} case7]");
        return;
    }

    if(popdata[0]!= 3 ||popdata[1]!= 4||popdata[2]!= 5||popdata[3]!= 1) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition7} case8]");
        return;
    }

    TEST_OK("[ByteRingArrayReader Test {testReadNext condition7} case8]");
    break;
  }

  //case7
  //data:[1,2(end),3,4(start),5]
  while(1) {
    ByteRingArray ringarray = ByteRingArray::New(5);
    ringarray->push(1);
    ringarray->push(2);
    ringarray->push(3);
    ringarray->push(4);
    ringarray->push(5);
    byte v1;
    byte v2;
    byte v3;
    byte v4;
    byte v5;
    ringarray->setEndIndex(1);
    ringarray->setSize(3);

    ByteRingArrayReader reader = ByteRingArrayReader::New(ringarray);
    if(reader->readNext(v1) != st(IO)::Reader::Result::HasContent) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition8} case1]");
        return;
    }
    if(v1 != 4) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition8} case1_1]");
        return;
    }

    if(reader->readNext(v2) != st(IO)::Reader::Result::HasContent) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition8} case2]");
        return;
    }
    if(v2 != 5) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition8} case2_1]");
        return;
    }

    if(reader->readNext(v3) != st(IO)::Reader::Result::HasContent) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition8} case3]");
        return;
    }
    if(v3 != 1) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition8} case3_1]");
        return;
    }

    byte end;
    if(reader->readNext(end) != st(IO)::Reader::Result::NoContent) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition8} case6]");
        return;
    }

    ByteArray popdata = reader->pop();
    if(popdata->size() != 3) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition8} case7]");
        return;
    }

    if(popdata[0]!= 4 ||popdata[1]!= 5||popdata[2]!= 1) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition8} case8]");
        return;
    }

    TEST_OK("[ByteRingArrayReader Test {testReadNext condition8} case8]");
    break;
  }

  //case7
  //data:[1,2(end),3,4,5(start)]
  while(1) {
    ByteRingArray ringarray = ByteRingArray::New(5);
    ringarray->push(1);
    ringarray->push(2);
    ringarray->push(3);
    ringarray->push(4);
    ringarray->push(5);
    byte v1;
    byte v2;
    byte v3;
    byte v4;
    byte v5;
    ringarray->setEndIndex(1);
    ringarray->setSize(2);

    ByteRingArrayReader reader = ByteRingArrayReader::New(ringarray);
    if(reader->readNext(v1) != st(IO)::Reader::Result::HasContent) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition9} case1]");
        return;
    }
    if(v1 != 5) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition9} case1_1]");
        return;
    }

    if(reader->readNext(v2) != st(IO)::Reader::Result::HasContent) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition9} case2]");
        return;
    }
    if(v2 != 1) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition9} case2_1]");
        return;
    }

    byte end;
    if(reader->readNext(end) != st(IO)::Reader::Result::NoContent) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition9} case6]");
        return;
    }

    ByteArray popdata = reader->pop();
    if(popdata->size() != 2) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition9} case7]");
        return;
    }

    if(popdata[0]!= 5 ||popdata[1]!= 1) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition9} case8]");
        return;
    }

    TEST_OK("[ByteRingArrayReader Test {testReadNext condition9} case8]");
    break;
  }

  //case8
  //data:[1(start),2(end),3,4,5]
  while(1) {
    ByteRingArray ringarray = ByteRingArray::New(5);
    ringarray->push(1);
    ringarray->push(2);
    ringarray->push(3);
    ringarray->push(4);
    ringarray->push(5);
    byte v1;
    byte v2;
    byte v3;
    byte v4;
    byte v5;
    ringarray->setEndIndex(1);
    ringarray->setSize(1);

    ByteRingArrayReader reader = ByteRingArrayReader::New(ringarray);
    if(reader->readNext(v1) != st(IO)::Reader::Result::HasContent) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition10} case1]");
        return;
    }
    if(v1 != 1) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition10} case1_1]");
        return;
    }

    byte end;
    if(reader->readNext(end) != st(IO)::Reader::Result::NoContent) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition10} case6]");
        return;
    }

    ByteArray popdata = reader->pop();
    if(popdata->size() != 1) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition10} case7]");
        return;
    }

    if(popdata[0]!= 1) {
        TEST_FAIL("[ByteRingArrayReader Test {testReadNext condition10} case8]");
        return;
    }

    TEST_OK("[ByteRingArrayReader Test {testReadNext condition10} case8]");
    break;
  }

}
