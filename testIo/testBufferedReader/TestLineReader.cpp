#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Uint16.hpp"
#include "StrongPointer.hpp"
#include "String.hpp"
#include "BufferedReader.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testBufferedReader() {
  //readLine();
  while(1) {
      String str = createString("hello\nworld\nni\nhao");
      BufferedReader reader = createBufferedReader(str);
      if(!reader->readLine()->equals(createString("hello"))) {
          TEST_FAIL("[BufferedReader Test {readLine()} case1]");
          break;
      }

      if(!reader->readLine()->equals(createString("world"))) {
          TEST_FAIL("[BufferedReader Test {readLine()} case2]");
          break;
      }

      if(!reader->readLine()->equals(createString("ni"))) {
          TEST_FAIL("[BufferedReader Test {readLine()} case3]");
          break;
      }

      if(!reader->readLine()->equals(createString("hao"))) {
          TEST_FAIL("[BufferedReader Test {readLine()} case4]");
          break;
      }

      TEST_OK("[BufferedReader Test {readLine()} case5]");
      break;
  }

  //reset
  while(1) {
      String str = createString("hello\nworld\nni\nhao");
      BufferedReader reader = createBufferedReader(str);
      if(!reader->readLine()->equals(createString("hello"))) {
          TEST_FAIL("[BufferedReader Test {reset()} case1]");
          break;
      }

      if(!reader->readLine()->equals(createString("world"))) {
          TEST_FAIL("[BufferedReader Test {reset()} case2]");
          break;
      }

      if(!reader->readLine()->equals(createString("ni"))) {
          TEST_FAIL("[BufferedReader Test {reset()} case3]");
          break;
      }

      if(!reader->readLine()->equals(createString("hao"))) {
          TEST_FAIL("[BufferedReader Test {reset()} case4]");
          break;
      }

      reader->reset();
      if(!reader->readLine()->equals(createString("hello"))) {
          TEST_FAIL("[BufferedReader Test {reset()} case5]");
          break;
      }

      if(!reader->readLine()->equals(createString("world"))) {
          TEST_FAIL("[BufferedReader Test {reset()} case6]");
          break;
      }

      if(!reader->readLine()->equals(createString("ni"))) {
          TEST_FAIL("[BufferedReader Test {reset()} case7]");
          break;
      }

      if(!reader->readLine()->equals(createString("hao"))) {
          TEST_FAIL("[BufferedReader Test {reset()} case8]");
          break;
      }

      TEST_OK("[BufferedReader Test {readLine()} case9]");
      break;
  }

  //read file
  while(1) {
    BufferedReader reader = createBufferedReader(createFile("./tmp/base_data"));
    if(!reader->readLine()->equals(createString("hello"))) {
        TEST_FAIL("[BufferedReader Test {readLine()} case10]");
        break;
    }

    if(!reader->readLine()->equals(createString("world"))) {
        TEST_FAIL("[BufferedReader Test {readLine()} case11]");
        break;
    }

    if(!reader->readLine()->equals(createString("ni"))) {
        TEST_FAIL("[BufferedReader Test {readLine()} case12]");
        break;
    }

    if(!reader->readLine()->equals(createString("hao"))) {
        TEST_FAIL("[BufferedReader Test {readLine()} case13]");
        break;
    }

    TEST_OK("[BufferedReader Test {readLine()} case14]");
    break;
  }

  //reset file
  while(1) {
      BufferedReader reader = createBufferedReader(createFile("./tmp/base_data"));
      if(!reader->readLine()->equals(createString("hello"))) {
          TEST_FAIL("[BufferedReader Test {reset()} case15]");
          break;
      }

      if(!reader->readLine()->equals(createString("world"))) {
          TEST_FAIL("[BufferedReader Test {reset()} case16]");
          break;
      }

      if(!reader->readLine()->equals(createString("ni"))) {
          TEST_FAIL("[BufferedReader Test {reset()} case17]");
          break;
      }

      if(!reader->readLine()->equals(createString("hao"))) {
          TEST_FAIL("[BufferedReader Test {reset()} case18]");
          break;
      }

      reader->reset();
      if(!reader->readLine()->equals(createString("hello"))) {
          TEST_FAIL("[BufferedReader Test {reset()} case19]");
          break;
      }

      if(!reader->readLine()->equals(createString("world"))) {
          TEST_FAIL("[BufferedReader Test {reset()} case20]");
          break;
      }

      if(!reader->readLine()->equals(createString("ni"))) {
          TEST_FAIL("[BufferedReader Test {reset()} case21]");
          break;
      }

      if(!reader->readLine()->equals(createString("hao"))) {
          TEST_FAIL("[BufferedReader Test {reset()} case22]");
          break;
      }

      TEST_OK("[BufferedReader Test {readLine()} case23]");
      break;
  }

  //lines
  while(1) {
      BufferedReader reader = createBufferedReader(createFile("./tmp/base_data"));
      ArrayList<String> lines = reader->lines();
      if(lines->size() != 4) {
        TEST_FAIL("[BufferedReader Test {reset()} case24]");
        break;
      }

      auto iterator = lines->getIterator();
      std::string vv[] =  {"hello","world","ni","hao"};
      int index = 0;
      while(iterator->hasValue()) {
        String v = iterator->getValue();
        if(!v->equals(createString(vv[index]))) {
          TEST_FAIL("[BufferedReader Test {reset()} case25],v is %s,vv is %s",v->toChars(),vv[index].c_str());
        }
        index++;
        iterator->next();
      }
      break;
  }

  TEST_OK("[BufferedReader Test {readLine()} case100]");
}
