#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "Log.hpp"
#include "FifoPipe.hpp"
#include "ByteArray.hpp"
#include "TestLog.hpp"
#include "Error.hpp"
#include "EPollObserver.hpp"
#include "CountDownLatch.hpp"

using namespace obotcha;

void testFifoPipeAsync() {

  st(FifoPipe)::Create("mytestasync");
  FifoPipe fifo = FifoPipe::New("mytestasync",st(FifoPipe)::Type::AsyncRead);
  CountDownLatch latch = CountDownLatch::New(1);

  EPollObserver mPoll = EPollObserver::New();
  mPoll->addObserver(
    fifo->getChannel(), EPOLLIN | EPOLLRDHUP | EPOLLHUP,
    [latch](int fd, uint32_t events) {
          if(events&EPOLLIN != 0) {
              char buff[1024] = {0};
              int len = read(fd,buff,1024);
              if(len != 11) {
                TEST_FAIL("[FifoPipe Test {AsyncWrite/AsyncRead()} case1],len is %d",len);
              }

              String str = String::New((const char *)buff);
              printf("i get str is %s \n",str->toChars());
              if(!str->sameAs("hello world")) {
                TEST_FAIL("[FifoPipe Test {AsyncWrite/AsyncRead()} case2]");
              }
              latch->countDown();
          }
          return st(IO)::Epoll::Result::Ok;
    });

  Thread t = Thread::New([] {
    FifoPipe fifo = FifoPipe::New("mytestasync",st(FifoPipe)::Type::AsyncWrite);
    String str = String::New("hello world");
    fifo->write(str->toByteArray());
  });
  t->start();

  latch->await();

  mPoll->close();
  //fifo->clear();
  TEST_OK("[FifoPipe Test {AsyncWrite/AsyncRead()()} case100]");
}
