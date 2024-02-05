#include <stdio.h>
#include <unistd.h>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"

using namespace obotcha;

extern void testHandler();
extern void testSendMessageDelayed();
extern void testHasMessage();
extern void testHandlerSize();
extern void testHandlerMultiSend();
extern void testHandlerRemove();
extern void testHandlerLambda();
extern void testHandlerRemoveRunnable();
extern void testHandlerSendAtFront();
extern void testHandlerSendDelayed();
extern void testHandlerLooper();
extern void testHandlerLooperQuit();
extern void testHandlerStress();
extern void testHandlerSendToTarget();
extern void testHandlerFrontMessage();
extern void testHandlerRemoveEqualMessage();

int main() {
  testHandlerRemoveEqualMessage();   
  testHandlerFrontMessage();
  testHandlerSendToTarget();
  testHandlerStress();
  testHandlerLooperQuit();
  testHandlerLooper();
  testHandlerLambda();
  testHandlerRemove();
  testHandlerMultiSend();
  testHandlerSize();
  testHandler();
  testSendMessageDelayed();
  testHasMessage();
  testHandlerRemoveRunnable();
  testHandlerSendAtFront();
  testHandlerSendDelayed();
  return 0;
}
