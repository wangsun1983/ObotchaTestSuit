#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAcceptCh.hpp"
#include "HttpConnection.hpp"
#include "HttpUrl.hpp"
#include "HttpPost.hpp"
#include "TestLog.hpp"
#include "System.hpp"
#include "NetPort.hpp"
#include "HttpMultiPart.hpp"
#include "Md.hpp"

using namespace obotcha;

void testMultipartRequest() {
  File file = createFile("./tmp/data");

  if(!file->exists()) {
    file->createNewFile();
      for(int i = 0;i<32;i++) {
      FileOutputStream stream = createFileOutputStream(file);
      stream->open(st(IO)::FileControlFlags::Append);
      String data = createString(st(System)::CurrentTimeMillis());
      for(int j = 0;j < 32;j++) {
        data = data->append(createString(st(System)::CurrentTimeMillis()));
      }
      stream->write(data->toByteArray());
      stream->close();
    }
  }

  int port = getEnvPort();
  printf("port is %d \n",port);

  String url = createString("http://127.0.0.1:")->append(createString(port),"/test");
  HttpPost post = createHttpPost(url);

  HttpMultiPart multipart = createHttpMultiPart();
  multipart->addFile(createFile("./tmp/data"),createString("haha"));
  //multipart->addContent(createString("key1"),createString("value1"));

  post->getEntity()->setMultiPart(multipart);

  HttpConnection client = createHttpConnection(url);
  client->connect();
  HttpResponse response = client->execute(post);
  if(response == nullptr) {
	  printf("no response!!!! \n");
	  return;
  }
  
  //check response 
  ByteArray data = response->getEntity()->getContent();
  if(!data->toString()->sameAs("finish")) {
    TEST_FAIL("testHttpClient testMultipartRequest case1");
  }

  //check file
  Md md = createMd();
  String encrypt1 = md->encodeFile(createFile("./tmp/data"));
  String encrypt2 = md->encodeFile(createFile("./tmp/file1.text"));
  if(!encrypt1->sameAs(encrypt2)) {
    TEST_FAIL("testHttpClient testMultipartRequest case2");
  }
  
  port++;
  setEnvPort(port);
  TEST_OK("testHttpClient testMultipartRequest case100");
}