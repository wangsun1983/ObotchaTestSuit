#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "StrongPointer.hpp"
#include "ShareMemory.hpp"
#include "EPollObserver.hpp"

using namespace obotcha;

//do not support ????
void testShareMemoryEpoll() {
  ShareMemory memory = createShareMemory("shareMemoryabc1122",32,st(ShareMemory)::WriteRead);
  EPollObserver mPoll = createEPollObserver();
  printf("channel is %d \n",memory->getChannel());
  mPoll->addObserver(
    memory->getChannel(), EPOLLIN | EPOLLRDHUP | EPOLLHUP,
    [](int fd, uint32_t events) {
          if(events&EPOLLIN != 0) {
              printf("i get a value \n");
          }
          return st(IO)::Epoll::Result::Ok;
    });
  
  memory->write(createString("hello")->toByteArray());
  sleep(1);
}
