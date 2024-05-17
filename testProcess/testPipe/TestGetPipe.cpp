#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "Log.hpp"
#include "Pipe.hpp"
#include "ByteArray.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testGetPipe() {

  Pipe pip = Pipe::New();
  if(pip->getReadChannel() <= 0) {
    TEST_FAIL("[Pipe Test {getPipe()} case1]");
  }
  
  if(pip->getWriteChannel() <= 0) {
    TEST_FAIL("[Pipe Test {getPipe()} case2]");
  }
  
  char p[32] = {'h','e','l','\0'};
  write(pip->getWriteChannel(),p,sizeof(p));
  
  char q[32] = {0};
  read(pip->getReadChannel(),q,32);
  
  if(q[0] != 'h' || q[1] != 'e' || q[2] != 'l') {
      TEST_FAIL("[Pipe Test {getPipe()} case3]");
  }
  
  if(strlen(q) != 3) {
      TEST_FAIL("[Pipe Test {getPipe()} case4]");
  }
  
  pip->close();
  TEST_OK("[Pipe Test {getPipe()} case100]");

}
