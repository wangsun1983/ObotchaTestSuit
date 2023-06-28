#include <stdio.h>
#include <unistd.h>

#include "ConcurrentQueue.hpp"

extern void testConcurrentLinkedList_MultiThread_Case1();
extern void testConcurrentLinkedList_MultiThread_Case2();
extern void testConcurrentLinkedList_PeekFirst();
extern void testConcurrentLinkedList_peekLast();
extern void testConcurrentLinkedList_size();
extern void testConcurrentLinkedList_toArray();
extern void testConcurrentLinkedList_putFirst();
extern void testConcurrentLinkedList_putLast();
extern void testConcurrentLinkedList_remove();
extern void testConcurrentLinkedList_removeAt();

using namespace obotcha;

int main() {
  testConcurrentLinkedList_removeAt();
  testConcurrentLinkedList_remove();
  testConcurrentLinkedList_putLast();
  testConcurrentLinkedList_putFirst();
  testConcurrentLinkedList_toArray();
  testConcurrentLinkedList_size();
  testConcurrentLinkedList_PeekFirst();
  testConcurrentLinkedList_peekLast();
  testConcurrentLinkedList_MultiThread_Case1();
  testConcurrentLinkedList_MultiThread_Case2();
  return 0;
}
