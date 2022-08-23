#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Long.hpp"
#include "StrongPointer.hpp"
#include "InitializeException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testLongWithCRLF() {
  
  //dec
  while(1) {
      char p[4] = {'8','\r','\n',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseDecLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF test1");
          break;
      }

      if(t->toValue() != 8) {
          TEST_FAIL("Long Parse With CRLF test2");
          break;
      }
      break;
  }

  while(1) {
      char p[4] = {'\r','8',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseDecLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF AHEAD test1");
          break;
      }

      if(t->toValue() != 8) {
          TEST_FAIL("Long Parse With CRLF AHEAD test2");
          break;
      }
      break;
  }

  while(1) {
      char p[4] = {' ','8',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseDecLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF AHEAD test2");
          break;
      }

      if(t->toValue() != 8) {
          TEST_FAIL("Long Parse With CRLF AHEAD test3");
          break;
      }
      break;
  }

  while(1) {
      char p[4] = {'8',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseDecLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF AHEAD test4");
          break;
      }

      if(t->toValue() != 8) {
          TEST_FAIL("Long Parse With CRLF AHEAD test5");
          break;
      }
      break;
  }

  while(1) {
      char p[4] = {'8','\r',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseDecLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF test3");
          break;
      }

      if(t->toValue() != 8) {
          TEST_FAIL("Long Parse With CRLF test4");
          break;
      }
      break;
  }

  while(1) {
      char p[4] = {'8','\n',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseDecLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF test5");
          break;
      }

      if(t->toValue() != 8) {
          TEST_FAIL("Long Parse With CRLF test6");
          break;
      }
      break;
  }

  while(1) {
      char p[5] = {'8','\n','\r','\n',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseDecLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF test7");
          break;
      }

      if(t->toValue() != 8) {
          TEST_FAIL("Long Parse With CRLF test8");
          break;
      }
      break;
  }

  while(1) {
      char p[5] = {'8','\n','\r','9',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseDecLong(s);
      if(t != nullptr) {
          TEST_FAIL("Long Parse With CRLF test9");
          break;
      }
      break;
  }

  //with \r \n ahead
  //dec
  while(1) {
      char p[7] = {'\r','\n','8','\r','\n',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseDecLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF test1_1");
          break;
      }

      if(t->toValue() != 8) {
          TEST_FAIL("Long Parse With CRLF test2_1");
          break;
      }
      break;
  }

  while(1) {
      char p[7] = {'\r','8','\r','\n',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseDecLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF test3_1");
          break;
      }

      if(t->toValue() != 8) {
          TEST_FAIL("Long Parse With CRLF test4_1");
          break;
      }
      break;
  }

  while(1) {
      char p[7] = {'\n','8','\r','\n',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseDecLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF test5_1");
          break;
      }

      if(t->toValue() != 8) {
          TEST_FAIL("Long Parse With CRLF test6_1");
          break;
      }
      break;
  }

  while(1) {
      char p[10] = {'\r','\n','\r','8','\r','\n',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseDecLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF test7_1");
          break;
      }

      if(t->toValue() != 8) {
          TEST_FAIL("Long Parse With CRLF test8_1");
          break;
      }
      break;
  }

  while(1) {
      char p[10] = {'\n','8','\n','\r','9',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseDecLong(s);
      if(t != nullptr) {
          TEST_FAIL("Long Parse With CRLF test9_1");
          break;
      }
      break;
  }

  //with " " ahead
  //dec
  while(1) {
      char p[7] = {' ',' ','8',' ',' ',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseDecLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF test1_2");
          break;
      }

      if(t->toValue() != 8) {
          TEST_FAIL("Long Parse With CRLF test2_2");
          break;
      }
      break;
  }

  while(1) {
      char p[7] = {' ','8',' ',' ',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseDecLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF test3_2");
          break;
      }

      if(t->toValue() != 8) {
          TEST_FAIL("Long Parse With CRLF test4_2");
          break;
      }
      break;
  }

  while(1) {
      char p[7] = {' ','8',' ',' ',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseDecLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF test5_2");
          break;
      }

      if(t->toValue() != 8) {
          TEST_FAIL("Long Parse With CRLF test6_2");
          break;
      }
      break;
  }

  while(1) {
      char p[10] = {' ',' ',' ','8',' ',' ',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseDecLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF test7_2");
          break;
      }

      if(t->toValue() != 8) {
          TEST_FAIL("Long Parse With CRLF test8_2");
          break;
      }
      break;
  }

  while(1) {
      char p[10] = {' ','8',' ',' ','9',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseDecLong(s);
      if(t != nullptr) {
          TEST_FAIL("Long Parse With CRLF test9_2");
          break;
      }
      break;
  }

  //hex
  while(1) {
      char p[4] = {'8','\r','\n',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseHexLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF test10");
          break;
      }

      if(t->toValue() != 0x8) {
          TEST_FAIL("Long Parse With CRLF test11");
          break;
      }
      break;
  }

  while(1) {
      char p[4] = {'8',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseHexLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF AHEAD test1");
          break;
      }

      if(t->toValue() != 0x8) {
          TEST_FAIL("Long Parse With CRLF AHEAD test2");
          break;
      }
      break;
  }

  while(1) {
      char p[4] = {'\r','\n','8',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseHexLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF AHEAD test3");
          break;
      }

      if(t->toValue() != 0x8) {
          TEST_FAIL("Long Parse With CRLF AHEAD test4");
          break;
      }
      break;
  }

  while(1) {
      char p[4] = {' ','8',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseHexLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF AHEAD test5");
          break;
      }

      if(t->toValue() != 0x8) {
          TEST_FAIL("Long Parse With CRLF AHEAD test6");
          break;
      }
      break;
  }

  while(1) {
      char p[4] = {'8','\r',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseHexLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF test12");
          break;
      }

      if(t->toValue() != 0x8) {
          TEST_FAIL("Long Parse With CRLF test13");
          break;
      }
      break;
  }

  while(1) {
      char p[4] = {'8','\n',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseHexLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF test14");
          break;
      }

      if(t->toValue() != 0x8) {
          TEST_FAIL("Long Parse With CRLF test15");
          break;
      }
      break;
  }

  while(1) {
      char p[5] = {'8','\n','\r','\n',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseHexLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF test16");
          break;
      }

      if(t->toValue() != 0x8) {
          TEST_FAIL("Long Parse With CRLF test17");
          break;
      }
      break;
  }

  while(1) {
      char p[5] = {'8','\n','\r','9',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseHexLong(s);
      if(t != nullptr) {
          TEST_FAIL("Long Parse With CRLF test18,t is %x",t->toValue());
          break;
      }
      break;
  }

  ///////
  while(1) {
      char p[5] = {'\r','8','\r','\n',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseHexLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF test10_1");
          break;
      }

      if(t->toValue() != 0x8) {
          TEST_FAIL("Long Parse With CRLF test11_1");
          break;
      }
      break;
  }

  while(1) {
      char p[5] = {'\r','8','\r',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseHexLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF test12_1");
          break;
      }

      if(t->toValue() != 0x8) {
          TEST_FAIL("Long Parse With CRLF test13_1");
          break;
      }
      break;
  }

  while(1) {
      char p[4] = {'\n','8','\n',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseHexLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF test14_1");
          break;
      }

      if(t->toValue() != 0x8) {
          TEST_FAIL("Long Parse With CRLF test15_1");
          break;
      }
      break;
  }

  while(1) {
      char p[8] = {'\r','\n','8','\n','\r','\n',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseHexLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF test16_1");
          break;
      }

      if(t->toValue() != 0x8) {
          TEST_FAIL("Long Parse With CRLF test17_1");
          break;
      }
      break;
  }

  while(1) {
      char p[10] = {'\r','\n','8','\n','\r','9',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseHexLong(s);
      if(t != nullptr) {
          TEST_FAIL("Long Parse With CRLF test18,t is %x",t->toValue());
          break;
      }
      break;
  }


  //hex with 0x
  while(1) {
      char p[6] = {'0','x','8','\r','\n',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseHexLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF test19");
          break;
      }

      if(t->toValue() != 0x8) {
          TEST_FAIL("Long Parse With CRLF test20");
          break;
      }
      break;
  }

  //hex with 0x
  while(1) {
      char p[6] = {'0','x','8',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseHexLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF AHEAD test1");
          break;
      }

      if(t->toValue() != 0x8) {
          TEST_FAIL("Long Parse With CRLF AHEAD test2");
          break;
      }
      break;
  }

  while(1) {
      char p[10] = {'\r','\n','0','x','8',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseHexLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF AHEAD test3");
          break;
      }

      if(t->toValue() != 0x8) {
          TEST_FAIL("Long Parse With CRLF AHEAD test4");
          break;
      }
      break;
  }

  while(1) {
      char p[10] = {' ','\n','0','x','8',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseHexLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF AHEAD test5");
          break;
      }

      if(t->toValue() != 0x8) {
          TEST_FAIL("Long Parse With CRLF AHEAD test6");
          break;
      }
      break;
  }

  while(1) {
      char p[6] = {'0','x','8','\r',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseHexLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF test21");
          break;
      }

      if(t->toValue() != 0x8) {
          TEST_FAIL("Long Parse With CRLF test22");
          break;
      }
      break;
  }

  while(1) {
      char p[6] = {'0','x','8','\n',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseHexLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF test23");
          break;
      }

      if(t->toValue() != 0x8) {
          TEST_FAIL("Long Parse With CRLF test24");
          break;
      }
      break;
  }

  while(1) {
      char p[7] = {'0','x','8','\n','\r','\n',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseHexLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF test25");
          break;
      }

      if(t->toValue() != 0x8) {
          TEST_FAIL("Long Parse With CRLF test26");
          break;
      }
      break;
  }

  while(1) {
      char p[7] = {'0','x','8','\n','\r','9',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseHexLong(s);
      if(t != nullptr) {
          TEST_FAIL("Long Parse With CRLF test27,t is %x",t->toValue());
          break;
      }
      break;
  }

  //hex with 0x
  while(1) {
      char p[10] = {' ','\r','0','x','8','\r','\n',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseHexLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF test27_2");
          break;
      }

      if(t->toValue() != 0x8) {
          TEST_FAIL("Long Parse With CRLF test27_3");
          break;
      }
      break;
  }

  while(1) {
      char p[10] = {' ','\r','0','x','8',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseHexLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF test27_4");
          break;
      }

      if(t->toValue() != 0x8) {
          TEST_FAIL("Long Parse With CRLF test27_5");
          break;
      }
      break;
  }

  while(1) {
      char p[10] = {'\n',' ','0','x','8',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseHexLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF test27_6");
          break;
      }

      if(t->toValue() != 0x8) {
          TEST_FAIL("Long Parse With CRLF test27_7");
          break;
      }
      break;
  }


  //oct
  while(1) {
      char p[5] = {'1','0','\r','\n',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseOctLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF test28");
          break;
      }

      if(t->toValue() != 8) {
          TEST_FAIL("Long Parse With CRLF test29");
          break;
      }
      break;
  }

  while(1) {
      char p[5] = {'1','0',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseOctLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF AHEAD test28");
          break;
      }

      if(t->toValue() != 8) {
          TEST_FAIL("Long Parse With CRLF AHEAD test29");
          break;
      }
      break;
  }

    while(1) {
      char p[5] = {'\r','1','0',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseOctLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF AHEAD test30");
          break;
      }

      if(t->toValue() != 8) {
          TEST_FAIL("Long Parse With CRLF AHEAD test31");
          break;
      }
      break;
  }

  while(1) {
      char p[5] = {'1','0','\r',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseOctLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF test30");
          break;
      }

      if(t->toValue() != 8) {
          TEST_FAIL("Long Parse With CRLF test31");
          break;
      }
      break;
  }

  while(1) {
      char p[5] = {'1','0','\n',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseOctLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF test32");
          break;
      }

      if(t->toValue() != 8) {
          TEST_FAIL("Long Parse With CRLF test33");
          break;
      }
      break;
  }

  while(1) {
      char p[7] = {'1','0','\n','\r','\n',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseOctLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF test34");
          break;
      }

      if(t->toValue() != 8) {
          TEST_FAIL("Long Parse With CRLF test35");
          break;
      }
      break;
  }

  while(1) {
      char p[7] = {'1','0','\n','\r','9',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseOctLong(s);
      if(t != nullptr) {
          TEST_FAIL("Long Parse With CRLF test36");
          break;
      }
      break;
  }

  //////
  //oct
  while(1) {
      char p[10] = {' ','\r','\n','1','0','\r','\n',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseOctLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF test28_1");
          break;
      }

      if(t->toValue() != 8) {
          TEST_FAIL("Long Parse With CRLF test29_1");
          break;
      }
      break;
  }

  while(1) {
      char p[10] = {' ','\n','1','0','\r',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseOctLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF test30_1");
          break;
      }

      if(t->toValue() != 8) {
          TEST_FAIL("Long Parse With CRLF test31_1");
          break;
      }
      break;
  }

  while(1) {
      char p[10] = {'\r','1','0','\n',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseOctLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF test32_1");
          break;
      }

      if(t->toValue() != 8) {
          TEST_FAIL("Long Parse With CRLF test33_1");
          break;
      }
      break;
  }

  while(1) {
      char p[10] = {' ',' ','1','0','\n','\r','\n',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseOctLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF test34_1");
          break;
      }

      if(t->toValue() != 8) {
          TEST_FAIL("Long Parse With CRLF test35_1");
          break;
      }
      break;
  }

  while(1) {
      char p[10] = {'\r',' ','1','0','\n','\r','9',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseOctLong(s);
      if(t != nullptr) {
          TEST_FAIL("Long Parse With CRLF test36_1");
          break;
      }
      break;
  }

  //hex
  while(1) {
      char p[7] = {'1','0','\n','\r',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseHexLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF test37");
          break;
      }

      if(t->toValue() != 16) {
          TEST_FAIL("Long Parse With CRLF test38");
          break;
      }
      break;
  }

  //binary
  while(1) {
      char p[7] = {'1','0','\n','\r',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseBinaryLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF test39");
          break;
      }

      if(t->toValue() != 2) {
          TEST_FAIL("Long Parse With CRLF test40");
          break;
      }
      break;
  }

    //binary
  while(1) {
      char p[7] = {'b','1','0','\n','\r',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseBinaryLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF test40");
          break;
      }

      if(t->toValue() != 2) {
          TEST_FAIL("Long Parse With CRLF test41");
          break;
      }
      break;
  }  

    //binary
  while(1) {
      char p[7] = {'b','1','0',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseBinaryLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF test42");
          break;
      }

      if(t->toValue() != 2) {
          TEST_FAIL("Long Parse With CRLF test43,t is %d",t->toValue());
          break;
      }
      break;
  } 

    //binary
  while(1) {
      char p[10] = {'\r','\n',' ','b','1','0',0};
      String s = createString((const char * )p);
      Long t = st(Long)::parseBinaryLong(s);
      if(t == nullptr) {
          TEST_FAIL("Long Parse With CRLF test44");
          break;
      }

      if(t->toValue() != 2) {
          TEST_FAIL("Long Parse With CRLF test45");
          break;
      }
      break;
  } 


  TEST_OK("Long Parse With CRLF test100");



}
