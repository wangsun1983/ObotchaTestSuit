#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Uint16.hpp"
#include "StrongPointer.hpp"
#include "String.hpp"
#include "TextLineReader.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testTextLineReaderNewLine() {

  //\n
  while(1) {
      String str1 = "f\n";
      TextLineReader reader = TextLineReader::New(str1);
      auto line = reader->readLine();
      if(line->size() != 1 || !line->sameAs("f")) {
          TEST_FAIL("[TextLineReader NewLine case1]");
      }
      break;
  }
  
  //\r\n
  while(1) {
      String str2 = "f\r\ngf\r\n";
      TextLineReader reader2 = TextLineReader::New(str2);
      auto line2 = reader2->readLine();
      if(line2->size() != 1 || !line2->sameAs("f")) {
          TEST_FAIL("[TextLineReader NewLine case2]");
      }
      
      line2 = reader2->readLine();
      if(line2->size() != 2 || !line2->sameAs("gf")) {
          TEST_FAIL("[TextLineReader NewLine case3]");
      }
      break;
  }
  
  //\n
  while(1) {
      String str1 = "f\nf2";
      TextLineReader reader = TextLineReader::New(str1);
      auto line = reader->readLine();
      if(line->size() != 1 || !line->sameAs("f")) {
          TEST_FAIL("[TextLineReader NewLine case4]");
      }
      
      line = reader->readLine();
      if(line->size() != 2 || !line->sameAs("f2")) {
          TEST_FAIL("[TextLineReader NewLine case5]");
      }
      break;
  }
  
  TEST_OK("[TextLineReader NewLine case100]");
}
