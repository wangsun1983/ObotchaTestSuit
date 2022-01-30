#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Uint16.hpp"
#include "StrongPointer.hpp"
#include "String.hpp"
#include "LineReader.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testLineReader() {
  //readLine();
  while(1) {
      String str = createString("hello\nworld\nni\nhao");
      LineReader reader = createLineReader(str);
      if(!reader->readLine()->equals(createString("hello"))) {
          TEST_FAIL("[LineReader Test {readLine()} case1]");
          break;
      }

      if(!reader->readLine()->equals(createString("world"))) {
          TEST_FAIL("[LineReader Test {readLine()} case2]");
          break;
      }

      if(!reader->readLine()->equals(createString("ni"))) {
          TEST_FAIL("[LineReader Test {readLine()} case3]");
          break;
      }

      if(!reader->readLine()->equals(createString("hao"))) {
          TEST_FAIL("[LineReader Test {readLine()} case4]");
          break;
      }

      TEST_OK("[LineReader Test {readLine()} case5]");
      break;
  }

  //reset
  while(1) {
      String str = createString("hello\nworld\nni\nhao");
      LineReader reader = createLineReader(str);
      if(!reader->readLine()->equals(createString("hello"))) {
          TEST_FAIL("[LineReader Test {reset()} case1]");
          break;
      }

      if(!reader->readLine()->equals(createString("world"))) {
          TEST_FAIL("[LineReader Test {reset()} case2]");
          break;
      }

      if(!reader->readLine()->equals(createString("ni"))) {
          TEST_FAIL("[LineReader Test {reset()} case3]");
          break;
      }

      if(!reader->readLine()->equals(createString("hao"))) {
          TEST_FAIL("[LineReader Test {reset()} case4]");
          break;
      }

      reader->reset();
      if(!reader->readLine()->equals(createString("hello"))) {
          TEST_FAIL("[LineReader Test {reset()} case5]");
          break;
      }

      if(!reader->readLine()->equals(createString("world"))) {
          TEST_FAIL("[LineReader Test {reset()} case6]");
          break;
      }

      if(!reader->readLine()->equals(createString("ni"))) {
          TEST_FAIL("[LineReader Test {reset()} case7]");
          break;
      }

      if(!reader->readLine()->equals(createString("hao"))) {
          TEST_FAIL("[LineReader Test {reset()} case8]");
          break;
      }

      TEST_OK("[LineReader Test {readLine()} case9]");
      break;
  }

  //read file
  while(1) {
    LineReader reader = createLineReader(createFile("./tmp/base_data"));
    if(!reader->readLine()->equals(createString("hello"))) {
        TEST_FAIL("[LineReader Test {readLine()} case10]");
        break;
    }

    if(!reader->readLine()->equals(createString("world"))) {
        TEST_FAIL("[LineReader Test {readLine()} case11]");
        break;
    }

    if(!reader->readLine()->equals(createString("ni"))) {
        TEST_FAIL("[LineReader Test {readLine()} case12]");
        break;
    }

    if(!reader->readLine()->equals(createString("hao"))) {
        TEST_FAIL("[LineReader Test {readLine()} case13]");
        break;
    }

    TEST_OK("[LineReader Test {readLine()} case14]");
    break;
  }

  //reset file
  while(1) {
      LineReader reader = createLineReader(createFile("./tmp/base_data"));
      if(!reader->readLine()->equals(createString("hello"))) {
          TEST_FAIL("[LineReader Test {reset()} case15]");
          break;
      }

      if(!reader->readLine()->equals(createString("world"))) {
          TEST_FAIL("[LineReader Test {reset()} case16]");
          break;
      }

      if(!reader->readLine()->equals(createString("ni"))) {
          TEST_FAIL("[LineReader Test {reset()} case17]");
          break;
      }

      if(!reader->readLine()->equals(createString("hao"))) {
          TEST_FAIL("[LineReader Test {reset()} case18]");
          break;
      }

      reader->reset();
      if(!reader->readLine()->equals(createString("hello"))) {
          TEST_FAIL("[LineReader Test {reset()} case19]");
          break;
      }

      if(!reader->readLine()->equals(createString("world"))) {
          TEST_FAIL("[LineReader Test {reset()} case20]");
          break;
      }

      if(!reader->readLine()->equals(createString("ni"))) {
          TEST_FAIL("[LineReader Test {reset()} case21]");
          break;
      }

      if(!reader->readLine()->equals(createString("hao"))) {
          TEST_FAIL("[LineReader Test {reset()} case22]");
          break;
      }

      TEST_OK("[LineReader Test {readLine()} case23]");
      break;
  }

  TEST_OK("[LineReader Test {readLine()} case100]");
}
