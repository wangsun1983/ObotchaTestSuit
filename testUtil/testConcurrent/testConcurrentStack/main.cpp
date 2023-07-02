#include <stdio.h>
#include <unistd.h>


extern void testConcurrentStack_Size();
extern void testConcurrentStack_Push();
extern void testConcurrentStack_Pop();
extern void testConcurrentStack_SyncReadAction();
extern void testConcurrentStack_SyncWriteAction();
extern void testConcurrentStack_Clear();

int main() {
  testConcurrentStack_Clear();
  testConcurrentStack_SyncWriteAction();
  testConcurrentStack_SyncReadAction();
  testConcurrentStack_Pop();
  testConcurrentStack_Size();
  testConcurrentStack_Push();
  return 0;
}
