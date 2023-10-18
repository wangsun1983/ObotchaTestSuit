#include <stdio.h>
#include <unistd.h>
#include <signal.h>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"
#include "ByteRingArray.hpp"
#include "HttpServer.hpp"
#include "HttpPacketWriter.hpp"
#include "HttpCookie.hpp"
#include "HttpResponse.hpp"
#include "HttpStatus.hpp"
#include "HttpServerBuilder.hpp"
#include "Inet4Address.hpp"
#include "CountDownLatch.hpp"
#include "Md.hpp"
#include "HttpConnection.hpp"
#include "HttpGet.hpp"

#include "TestLog.hpp"
#include "NetPort.hpp"
#include "NetEvent.hpp"

using namespace obotcha;

int value = 0;

DECLARE_CLASS(MyHandler) IMPLEMENTS(Handler) {
public:
	void handleMessage(Message msg) {
		switch(msg->what) {
			case 1:
			value = 1234;
			HttpResponse response = Cast<HttpResponse>(msg->data);
			auto response_data = response->getEntity()->getContent()->toString();
			if(!response_data->sameAs("hello")) {
				TEST_FAIL("HttpConnection simple connect msg case1");
			}
			break;
		}
	}
};

int main() {
  int port = getEnvPort();
  String url = createString("http://127.0.0.1:")->append(createString(port),"/test");
  HttpConnection c = createHttpConnection(url);
  int ret = c->connect();
  
  MyHandler handler = createMyHandler();
  auto message = handler->obtainMessage(1);
  
  HttpGet httpget = createHttpGet(url);
  httpget->getEntity()->setContent(createString("hello")->toByteArray());
  c->execute(httpget,message);
  usleep(1000*100);
  if(value != 1234) {
	TEST_FAIL("HttpConnection simple connect msg case2");
  }

  TEST_OK("HttpConnection simple connect msg case100");
  port++;
  setEnvPort(port);
  return 0;

}
