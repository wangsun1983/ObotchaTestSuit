#include <thread>

#include "Thread.hpp"
#include "TimeWatcher.hpp"

using namespace obotcha;

int total = 0;

int main() {
    TimeWatcher watcher = createTimeWatcher();
    for(int i = 0; i < 1024;i++) {
      Thread t = createThread([&watcher]{
        watcher->start();
      });
      t->start();
      t->join();
      total += watcher->stop();
    }

    printf("Obotcha total is %d \n",total);
    total = 0;
    for(int i = 0; i < 1024;i++) {
      std::thread t([]{
        watcher->start();
      });

      t.join();
      total += watcher->stop();
    }

    printf("C++ total is %d \n",total);
}
