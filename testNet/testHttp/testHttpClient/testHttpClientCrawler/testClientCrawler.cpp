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
#include "TestLog.hpp"

using namespace obotcha;

const char *testUrl[] = {
  "https://www.tusvisionai.com/",
  "https://www.jianshu.com/",
  "https://www.sina.com.cn/",
  "https://vip.iqiyi.com/cps_pc.html",
  "https://www.taobao.com/",
  "https://pages.tmall.com/",
  "https://cn.bing.com/dict/?mkt=zh-cn",
  "https://tv.cctv.com/",
  "http://www.people.com.cn/",
  "http://www.xinhuanet.com/",
  nullptr,
};

void testClientCrawler() {
  int i = 0;
  for(i = 0;testUrl[i] != nullptr;i++) {
    printf("==============start do [%s]============\n",testUrl[i]);
    HttpGet get = createHttpGet(testUrl[i]);
    HttpClient client = createHttpClient();
    HttpResponse response = client->execute(get);
    if(response->getEntity() != nullptr) {
      printf("entity is %s \n",response->getEntity()->getContent()->toString()->toChars());
    }
  }

  TEST_OK("[testHttpClientCrawler test Parse case100]");

}
