#include <stdio.h>
#include <unistd.h>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"
#include "ByteRingArray.hpp"

using namespace obotcha;

extern void testReadNext();
extern void test_pop();
//extern void testPopAll();
extern void testReadableLength();
extern void testMove();
extern void testReadLittleEndian();
extern void testReadBigEndian();
extern void testIsDrained();

int main() {
  testIsDrained();
  testReadLittleEndian();
  testReadBigEndian();
  //test_readnext();
  //testPopAll();
  testReadNext();
  testReadableLength();
  test_pop();
  testMove();
}
