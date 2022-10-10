#include <stdio.h>
#include <unistd.h>

#include "ConcurrentQueue.hpp"

extern void testConcurrentLinkedList_MultiThread_Case1();
extern void testConcurrentLinkedList_MultiThread_Case2();

using namespace obotcha;

int main() {
  testConcurrentLinkedList_MultiThread_Case1();
  testConcurrentLinkedList_MultiThread_Case2();
  return 0;
}
