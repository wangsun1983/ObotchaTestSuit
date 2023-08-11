#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAcceptCh.hpp"
#include "HttpClient.hpp"
#include "HttpUrl.hpp"
#include "HttpPost.hpp"
#include "TestLog.hpp"
#include "System.hpp"
#include "NetPort.hpp"
#include "HttpMultiPart.hpp"
#include "HttpGet.hpp"
#include "Md.hpp"

using namespace obotcha;

const char *result =
      "hello,i am client,number: 0\n"
      "hello,i am client,number: 1\n"
      "hello,i am client,number: 2\n"
      "hello,i am client,number: 3\n"
      "hello,i am client,number: 4\n"
      "hello,i am client,number: 5\n"
      "hello,i am client,number: 6\n"
      "hello,i am client,number: 7\n"
      "hello,i am client,number: 8\n"
      "hello,i am client,number: 9\n"
      "hello,i am client,number: 10\n"
      "hello,i am client,number: 11\n"
      "hello,i am client,number: 12\n"
      "hello,i am client,number: 13\n"
      "hello,i am client,number: 14\n"
      "hello,i am client,number: 15\n";

void testHttpClientChunk() {
  int port = getEnvPort();
  printf("port is %d \n",port);

  String url = createString("http://127.0.0.1:")->append(createString(port),"/test");
  printf("url is %s \n",url->toChars());
  HttpGet get = createHttpGet(url);
  HttpClient client = createHttpClient();
  HttpResponse response = client->execute(get);
  
  usleep(1000*1000);
  //check response 
  auto chunk = response->getEntity()->getChunk();
  if(chunk == nullptr) {
	  printf("chunk is null \n");
  } else {
	  printf("chunk is not null \n");
  }
  ByteArray data = response->getEntity()->getChunk()->getInputStream()->readAll();
  if(!data->toString()->sameAs(result)) {
    //printf("i aacept data is \n%s||||\nexptect:\n%s|||\n",data->toString()->toChars(),result);
    //printf("data size is %d,result size is %d \n",data->toString()->size(),strlen(result));
    char *p = (char *)data->toValue();
    int index = 0;
    while(*p == *result) {
      p++;
      result++;
      index++;
    }

    printf("p is %x,result is %x,index is %d \n",p[0],result[0],index);
    TEST_FAIL("testHttpClient ChunkTransfer case1");
  }
  port++;
  setEnvPort(port);

  TEST_OK("testHttpClient ChunkTransfer case100");
}
