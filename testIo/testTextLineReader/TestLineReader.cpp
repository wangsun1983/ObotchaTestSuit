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

void testTextLineReader() {
  //readLine();
  while(1) {
      String str = String::New("hello\nworld\nni\nhao");
      TextLineReader reader = TextLineReader::New(str);
      if(!reader->readLine()->equals(String::New("hello"))) {
          TEST_FAIL("[TextLineReader Test {readLine()} case1]");
          break;
      }

      if(!reader->readLine()->equals(String::New("world"))) {
          TEST_FAIL("[TextLineReader Test {readLine()} case2]");
          break;
      }

      if(!reader->readLine()->equals(String::New("ni"))) {
          TEST_FAIL("[TextLineReader Test {readLine()} case3]");
          break;
      }

      if(!reader->readLine()->equals(String::New("hao"))) {
          TEST_FAIL("[TextLineReader Test {readLine()} case4]");
          break;
      }

      TEST_OK("[TextLineReader Test {readLine()} case5]");
      break;
  }

  //reset
  while(1) {
      String str = String::New("hello\nworld\nni\nhao");
      TextLineReader reader = TextLineReader::New(str);
      if(!reader->readLine()->equals(String::New("hello"))) {
          TEST_FAIL("[TextLineReader Test {reset()} case1]");
          break;
      }

      if(!reader->readLine()->equals(String::New("world"))) {
          TEST_FAIL("[TextLineReader Test {reset()} case2]");
          break;
      }

      if(!reader->readLine()->equals(String::New("ni"))) {
          TEST_FAIL("[TextLineReader Test {reset()} case3]");
          break;
      }

      if(!reader->readLine()->equals(String::New("hao"))) {
          TEST_FAIL("[TextLineReader Test {reset()} case4]");
          break;
      }

      reader->reset();
      if(!reader->readLine()->equals(String::New("hello"))) {
          TEST_FAIL("[TextLineReader Test {reset()} case5]");
          break;
      }

      if(!reader->readLine()->equals(String::New("world"))) {
          TEST_FAIL("[TextLineReader Test {reset()} case6]");
          break;
      }

      if(!reader->readLine()->equals(String::New("ni"))) {
          TEST_FAIL("[TextLineReader Test {reset()} case7]");
          break;
      }

      if(!reader->readLine()->equals(String::New("hao"))) {
          TEST_FAIL("[TextLineReader Test {reset()} case8]");
          break;
      }

      TEST_OK("[TextLineReader Test {readLine()} case9]");
      break;
  }

  //read file
  while(1) {
    TextLineReader reader = TextLineReader::New(File::New("./tmp/base_data"));
    if(!reader->readLine()->equals(String::New("hello"))) {
        TEST_FAIL("[TextLineReader Test {readLine()} case10]");
        break;
    }

    if(!reader->readLine()->equals(String::New("world"))) {
        TEST_FAIL("[TextLineReader Test {readLine()} case11]");
        break;
    }

    if(!reader->readLine()->equals(String::New("ni"))) {
        TEST_FAIL("[TextLineReader Test {readLine()} case12]");
        break;
    }

    if(!reader->readLine()->equals(String::New("hao"))) {
        TEST_FAIL("[TextLineReader Test {readLine()} case13]");
        break;
    }

    TEST_OK("[TextLineReader Test {readLine()} case14]");
    break;
  }

  //reset file
  while(1) {
      TextLineReader reader = TextLineReader::New(File::New("./tmp/base_data"));
      if(!reader->readLine()->equals(String::New("hello"))) {
          TEST_FAIL("[TextLineReader Test {reset()} case15]");
          break;
      }

      if(!reader->readLine()->equals(String::New("world"))) {
          TEST_FAIL("[TextLineReader Test {reset()} case16]");
          break;
      }

      if(!reader->readLine()->equals(String::New("ni"))) {
          TEST_FAIL("[TextLineReader Test {reset()} case17]");
          break;
      }

      if(!reader->readLine()->equals(String::New("hao"))) {
          TEST_FAIL("[TextLineReader Test {reset()} case18]");
          break;
      }

      reader->reset();
      if(!reader->readLine()->equals(String::New("hello"))) {
          TEST_FAIL("[TextLineReader Test {reset()} case19]");
          break;
      }

      if(!reader->readLine()->equals(String::New("world"))) {
          TEST_FAIL("[TextLineReader Test {reset()} case20]");
          break;
      }

      if(!reader->readLine()->equals(String::New("ni"))) {
          TEST_FAIL("[TextLineReader Test {reset()} case21]");
          break;
      }

      if(!reader->readLine()->equals(String::New("hao"))) {
          TEST_FAIL("[TextLineReader Test {reset()} case22]");
          break;
      }

      TEST_OK("[TextLineReader Test {readLine()} case23]");
      break;
  }

  //lines
  while(1) {
      TextLineReader reader = TextLineReader::New(File::New("./tmp/base_data"));
      ArrayList<String> lines = reader->lines();
      if(lines->size() != 4) {
        TEST_FAIL("[TextLineReader Test {reset()} case24]");
        break;
      }

      auto iterator = lines->getIterator();
      std::string vv[] =  {"hello","world","ni","hao"};
      int index = 0;
      while(iterator->hasValue()) {
        String v = iterator->getValue();
        if(!v->equals(String::New(vv[index]))) {
          TEST_FAIL("[TextLineReader Test {reset()} case25],v is %s,vv is %s",v->toChars(),vv[index].c_str());
        }
        index++;
        iterator->next();
      }
      break;
  }

  TEST_OK("[TextLineReader Test {readLine()} case100]");
}
