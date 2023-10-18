#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Reflect.hpp"
#include "String.hpp"
#include "Reflect.hpp"

using namespace obotcha;
extern int testProcessCondition();
extern int testWaitTimeout();
extern int testNotify();
extern int testNotifyAll();
extern int testNotifyInThread();
extern int testNotifyAllInThread();

int main() {
  if(testProcessCondition() == -1) {
	  return 0;
  }
  
  if(testWaitTimeout() == -1) {
  	  return 0;
  }
  
  if(testNotify() == -1) {
	  return 0;
  }
  
  if(testNotifyAll() == -1) {
	  return 0;
  }
  
  if(testNotifyInThread() == -1) {
	  return 0;
  }
  
  if(testNotifyAllInThread() == -1) {
	  return 0;
  }
  
  return 0;
}
