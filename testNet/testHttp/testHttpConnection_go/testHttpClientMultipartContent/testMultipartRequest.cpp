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
#include "HttpGet.hpp"

using namespace obotcha;

void testMultipartContentRequest() {
  int port = getEnvPort();
  printf("port is %d \n",port);

  String url = createString("http://127.0.0.1:")->append(createString(port),"/test");
  HttpPost post = createHttpPost(url);
  HttpConnection client = createHttpConnection(url);
  int ret = client->connect();
  printf("ret is %d \n",ret);
  HttpMultiPart multipart = createHttpMultiPart();
  multipart->addContent("tag1","value1");
  multipart->addContent("tag2","value2");
  multipart->addContent("tag3","value3");
  post->getEntity()->setMultiPart(multipart);
  
  auto response = client->execute(post);
  ByteArray data = response->getEntity()->getContent();
  String value = createString("tag1value1tag2value2tag3value3");
  String acceptValue = data->toString();
  if(value->size() != acceptValue->size()) {
    TEST_FAIL("testHttpClient testMultipartContentRequest case1");
  }
  
  if(!acceptValue->contains("tag1") ||
     !acceptValue->contains("tag2") ||
     !acceptValue->contains("tag3") ||   
     !acceptValue->contains("value1") ||   
     !acceptValue->contains("value2") ||
     !acceptValue->contains("value3")) {
    TEST_FAIL("testHttpClient testMultipartContentRequest case2");     
  }
  //check file
  port++;
  setEnvPort(port);
  TEST_OK("testHttpClient testMultipartContentRequest case100");
}
