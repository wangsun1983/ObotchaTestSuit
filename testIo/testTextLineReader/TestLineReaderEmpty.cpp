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

void testTextLineReaderEmpty() {
  while(1) {
      String str1 = "f\n\nggf";
      TextLineReader reader = TextLineReader::New(str1);
      auto line = reader->readLine();
      if(line->size() != 1 || !line->sameAs("f")) {
          TEST_FAIL("[TextLineReader Empty case1]");
      }
      
      auto line2 = reader->readLine();
      if(line2->size() != 0) {
          TEST_FAIL("[TextLineReader Empty case2]");
      }
      
      auto line3 = reader->readLine();
      if(line3->size() != 3 || !line3->sameAs("ggf")) {
          TEST_FAIL("[TextLineReader Empty case3]");
      }
      break;
  }
  
  TEST_OK("[TextLineReader Empty case100]");
}
