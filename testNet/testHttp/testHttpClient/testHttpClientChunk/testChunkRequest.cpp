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

void testHttpClientChunk() {
  File file = createFile("data");

  if(!file->exists()) {
    file->createNewFile();
      for(int i = 0;i<32;i++) {
      FileOutputStream stream = createFileOutputStream(file);
      stream->open(st(OutputStream)::Append);
      String data = createString(st(System)::currentTimeMillis());
      for(int j = 0;j < 32;j++) {
        data = data->append(createString(st(System)::currentTimeMillis()));
      }
      stream->write(data->toByteArray());
      stream->close();
    }
  }

  int port = getEnvPort();
  printf("port is %d \n",port);

  String url = createString("http://127.0.0.1:")->append(createString(port),"/test");
  printf("chunk,url is %s \n",url->toChars());

  HttpGet get = createHttpGet(url);
  HttpClient client = createHttpClient();
  printf("start get \n");
  HttpResponse response = client->execute(get);

  //check response 
  ByteArray data = response->getEntity()->getChunk()->getInputStream()->readAll();
  if(!data->toString()->equals("finish")) {
    printf("data is %s \n",data->toString()->toChars());
    TEST_FAIL("testHttpClient ChunkTransfer case1");
  }

  TEST_OK("testHttpClient ChunkTransfer case100");
}
