#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Reflect.hpp"
#include "String.hpp"
#include "Reflect.hpp"

using namespace obotcha;
extern int testProcessMutex();
extern int testThreadMutex();
extern int testLockTimeout();
extern int testTryLock();

int main() {
  if(testProcessMutex() == -1) {
	  return 0;
  }
  
  if(testThreadMutex() == -1) {
	  return 0;
  }
  
  if(testLockTimeout() == -1) {
	  return 0;
  }
  // printf("process mutex trace4 \n");
  // if(testTryLock() == -1) {
	 //  return 0;
  // }
  
  return 0;
}
