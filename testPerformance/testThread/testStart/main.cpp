#include "Thread.hpp"
#include "TimeWatcher.hpp"

using namespace obotcha;

int total = 0;

int main() {
    TimeWatcher watcher = TimeWatcher::New();
    for(int i = 0; i < 1024;i++) {
      watcher->start();
      Thread t = Thread::New([&watcher]{
        total += watcher->stop();
      });
      t->start();
      t->join();
    }

    printf("Obotcha total is %d \n",total);
    total = 0;
    for(int i = 0; i < 1024;i++) {
      watcher->start();
      std::thread t([&watcher]{
        total += watcher->stop();
      });
      t.join();
    }

    printf("C++ total is %d \n",total);
}
