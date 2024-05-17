#include <stdio.h>
#include <unistd.h>

#include "ByteRingArray.hpp"
#include "Calendar.hpp"
#include "CountDownLatch.hpp"
#include "Handler.hpp"
#include "HttpCookie.hpp"
#include "HttpResponse.hpp"
#include "HttpServer.hpp"
#include "HttpServerBuilder.hpp"
#include "HttpStatus.hpp"
#include "Inet4Address.hpp"
#include "Message.hpp"
#include "NetPort.hpp"
#include "System.hpp"
#include "TestLog.hpp"
#include "TimeZone.hpp"

using namespace obotcha;

CountDownLatch latch = CountDownLatch::New(1);
int count = 0;

long setExpires = 0;

DECLARE_CLASS(MyHttpListener) IMPLEMENTS(HttpListener){
    
    void onHttpMessage(st(Net)::Event event,
                                            HttpLinker client,
                                            HttpResponseWriter w,
                                            HttpPacket msg){
        switch (event){
            case st(Net)::Event::Connect : {
            // connectlatch->countDown();
            } break;

            case st(Net)::Event::Message:
            {
                if (count == 0)
                {
                    // first message to send response with cookie
                    HttpResponse response = HttpResponse::New();
                    HttpCookie cookie1 = HttpCookie::New("test2_tag1", "test2_value1");
                    cookie1->setPropertySecure(true);
                    cookie1->setPropertyHttpOnly(true);
                    cookie1->setPropertyPath("path123");
                    // cookie1->setPropertyDomain("domain123");
                    Calendar c = Calendar::New(); //->getDateTime()
                    // c->add(st(Calendar)::DayOfMonth,1);
                    printf("time zone is %d \n", st(TimeZone)::GetZone());
                    setExpires = (c->toTimeMillis()) / 1000 + 10;

                    // cookie1->setPropertyExpires(HttpDate::New(c->getGmtDateTime()));
                    cookie1->setPropertyMaxAge(10);

                    // HttpCookie cookie2 = HttpCookie::New("test2_tag2","test2_value2");
                    response->getHeader()->addCookie(cookie1);
                    // response->getHeader()->addCookie(cookie2);
                    response->getHeader()->setResponseStatus(st(HttpStatus)::Ok);
                    w->write(response);
                    count++;
                }
                else if (count == 1)
                {
                    // TODO
                    HttpEntity entity = msg->getEntity();
                    auto content = entity->getContent()->toString();
                    HttpUrlEncodedValue encodedValue = HttpUrlEncodedValue::New(content);
                    auto map = encodedValue->getValues();

                    auto v1 = map->get(String::New("test2_tag1"));
                    if (v1 == nullptr || !v1->sameAs("test2_value1"))
                    {
                        TEST_FAIL("TestHttpResponseWriter Cookie Property MaxAges test1");
                    }

                    auto v2 = map->get(String::New("path"));
                    if (v2 == nullptr || !v2->sameAs("path123"))
                    {
                        TEST_FAIL("TestHttpResponseWriter Cookie Property MaxAges test2");
                    }

                    auto v3 = map->get(String::New("expires"));
                    if (v3->toBasicLong() != setExpires)
                    {
                        TEST_FAIL("TestHttpResponseWriter Cookie Property MaxAges test3");
                    }

                    HttpResponse response = HttpResponse::New();
                    response->getHeader()->setResponseStatus(st(HttpStatus)::Ok);
                    w->write(response);
                    // count = 0;
                    latch->countDown();
                    count = 0;
                }
                break;
            }
            break;

            case st(Net)::Event::Disconnect:
            {
            }
            break;
        }
    }
};

int main()
{
    MyHttpListener listener = MyHttpListener::New();
    int port = getEnvPort();
    HttpServer server = nullptr;
    while (1)
    {
        server = HttpServerBuilder::New()
                     ->setAddress(Inet4Address::New(port))
                     ->setListener(listener)
                     ->build();
        if (server->start() == -1)
        {
            port++;
            continue;
        }
        setEnvPort(port);
        break;
    }
    latch->await();
    server->close();
    sleep(1);

    TEST_OK("TestHttpResponseWriter Cookie Property MaxAges test100");
}
