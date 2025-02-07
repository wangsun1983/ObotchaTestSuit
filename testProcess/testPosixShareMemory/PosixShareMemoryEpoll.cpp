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
  st(ShareMemory)::Create("shareMemoryabc1122",32);
  ShareMemory memory = ShareMemory::New("shareMemoryabc1122",32,st(ShareMemory)::Type::WriteRead);
  EPollObserver mPoll = EPollObserver::New();
  printf("channel is %d \n",memory->getChannel());
  mPoll->addObserver(
    memory->getChannel(), EPOLLIN | EPOLLRDHUP | EPOLLHUP,
    [](int fd, uint32_t events) {
          if(events&EPOLLIN != 0) {
              printf("i get a value \n");
          }
          return st(IO)::Epoll::Result::Ok;
    });
  
  memory->write(String::New("hello")->toByteArray());
  sleep(1);
}
