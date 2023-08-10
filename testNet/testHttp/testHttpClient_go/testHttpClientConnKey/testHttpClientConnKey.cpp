#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAcceptCh.hpp"
#include "HttpClient.hpp"
#include "HttpUrl.hpp"
#include "HttpGet.hpp"
#include "HttpClientConnManager.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testHttpClientConnKey() {
  HashMap<HttpClientConnKey,String> maps = createHashMap<HttpClientConnKey,String>();
  
  HttpClientConnKey key1 = createHttpClientConnKey(1,createString("1"),createString("1"),8888);
  maps->put(key1,createString("key1"));

  String s1 = maps->get(createHttpClientConnKey(1,createString("1"),createString("1"),8888));
  if(s1 == nullptr || !s1->sameAs("key1")) {
    TEST_FAIL("[testHttpClientConnKey test Parse case1]");
  }

  maps->put(createHttpClientConnKey(1,createString("1"),createString("1"),8888),createString("key2"));
  s1 = maps->get(createHttpClientConnKey(1,createString("1"),createString("1"),8888));
  if(s1 == nullptr || !s1->sameAs("key2")) {
    TEST_FAIL("[testHttpClientConnKey test Parse case2]");
  }

  String sx = maps->get(createHttpClientConnKey(2,createString("1"),createString("1"),8888));
  if(sx != nullptr) {
    TEST_FAIL("[testHttpClientConnKey test Parse case8],sx is %s \n",sx->toChars());
  }

  TEST_OK("[testHttpClientConnKey test Parse case100]");
}
