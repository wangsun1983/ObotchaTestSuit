#include "HttpPacketParser.hpp"

using namespace obotcha;

extern void testHttpParse();
extern void testMultiMessageParse();
extern void testChunkOneByteParse();
extern void testMultiPartOneByteParse();
extern void simpleTest();
extern void testChunkTailingOneByteParse();

int main() {
  //testMultiMessageParse();
  //testChunkOneByteParse();
  //testMultiPartOneByteParse();
  testHttpParse();
  //testChunkTailingOneByteParse();
  //simpleTest();
  return 0;
}
