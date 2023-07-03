#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "StrongPointer.hpp"
#include "System.hpp"
#include "File.hpp"
#include "TestLog.hpp"

using namespace obotcha;

#define CPU_NUMS 12

int normalTest() {
  //static long int CurrentTimeMillis();
  while(1) {
    long int times = st(System)::CurrentTimeMillis();
    if(times <= 0) {
      TEST_FAIL("System CurrentTimeMillis test1");
      break;
    }

    TEST_OK("System CurrentTimeMillis test1");
      break;
    break;
  }

  //static int availableProcessors();
  while(1) {
    int num = st(System)::AvailableProcessors();
    if(num != CPU_NUMS) {
        TEST_FAIL("System availableProcessors test1");
        break;
    }

    TEST_OK("System availableProcessors test1");
    break;
  }

  //static int onlineProcessors();
  while(1) {
    int num = st(System)::OnlineProcessors();
    if(num != CPU_NUMS) {
        TEST_FAIL("System Test test1");
        break;
    }

    TEST_OK("System Test test1");
    break;
  }

  //String executeForResult(String cmd);
  while(1) {
    String cmd = "ls -la";
    String result = st(System)::ExecuteForResult(cmd);
    if(result->size() < 10) {
      TEST_FAIL("System executeForResult test1");
      break;
    }

    TEST_OK("System executeForResult test1");
    break;
  }

  //String execute
  while(1) {
      File file = createFile("abc");
      if(file->exists()) {
        file->removeAll();
      }

      if(file->exists()) {
        TEST_FAIL("System execute test1");
        break;
      }

      String cmd = "mkdir abc";
      st(System)::Execute(cmd);
      if(!file->exists()) {
        TEST_FAIL("System execute test2");
        break;
      }

      TEST_OK("System execute test1");
      break;
  }
  return 0;
  //while(1){}
}
