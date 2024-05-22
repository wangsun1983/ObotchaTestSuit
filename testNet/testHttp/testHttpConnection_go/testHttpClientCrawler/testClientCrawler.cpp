#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAcceptCh.hpp"
#include "HttpConnection.hpp"
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
  //"https://tv.cctv.com/",
  "http://www.people.com.cn/",
  "http://www.xinhuanet.com/",
  nullptr,
};

void testClientCrawler() {
  int i = 0;
  for(i = 0;testUrl[i] != nullptr;i++) {
    printf("==============start do [%s]============\n",testUrl[i]);
    HttpGet get = HttpGet::New(testUrl[i]);
    HttpConnection client = HttpConnection::New(testUrl[i]);
    client->connect();
    HttpResponse response = client->execute(get);


    HttpUrl url = HttpUrl::New(testUrl[i]);
    String path = String::New("./tmp/");
    File logfile = File::New(path->append(url->getHost()));
    logfile->createNewFile();
    
    auto output = FileOutputStream::New(logfile);
    output->open();

    if(response->isChunked()) {
      HttpChunk chunk = response->getEntity()->getChunk();
      if(chunk->getData() == nullptr) {
        TEST_FAIL("testHttpClientCrawler test Parse case1,url is %s",testUrl[i]);
      } else {
        output->write(chunk->getData());
      }
    } else {
      ByteArray data = response->getEntity()->getContent();
      if(data == nullptr) {
        TEST_FAIL("testHttpClientCrawler test Parse case2,url is %s",testUrl[i]);
      } else {
        output->write(data);
      }
    }

  }

  TEST_OK("testHttpClientCrawler test Parse case100");

}
