#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderSecFetchMode.hpp"
#include "Math.hpp"
#include "TestLog.hpp"
#include "HttpChunkParser.hpp"

using namespace obotcha;

void testParse() {
  char *content =
      "25\r\n"
      "This is the data in the first chunk\r\n"
      "1C\r\n"
      "and this is the second one\r\n"
      "3\r\n"
      "con"
      "8\r\n"
      "sequence"
      "0\r\n"
      "\r\n";

  char *result = 
      "This is the data in the first chunk\r\nand this is the second one\r\nconsequence";

  ByteRingArray array = ByteRingArray::New(1024);
  ByteArray data = ByteArray::New((byte *)content,strlen(content));
  array->push(data);

  ByteRingArrayReader reader = ByteRingArray::New(array);
  HttpChunkParser parser = HttpChunkParser::New(reader);
  HttpChunk rs = parser->doParse();
  if(!rs->getData()->toString()->sameAs(result)) {
    TEST_FAIL("HttpHeaderSecFetchMode test Parse case1,rs is %s \n",rs->getData()->toString()->toChars());
  }

  TEST_OK("HttpHeaderSecFetchMode test Parse case100");
}
