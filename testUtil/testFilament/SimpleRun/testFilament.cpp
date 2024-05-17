#include <unistd.h>

#include "Filament.hpp"
#include "ArrayList.hpp"
#include "FilaRoutine.hpp"
#include "CountDownLatch.hpp"
#include "TestLog.hpp"

using namespace std;
using namespace obotcha;

CountDownLatch latch = CountDownLatch::New(150);

DECLARE_CLASS(MyRun1) IMPLEMENTS(Filament) {
public:
    void run() {
        for(int i = 0;i<50;i++) {
            latch->countDown();
            poll(NULL, 0, 500);
        }
    }
};

DECLARE_CLASS(MyRun2) IMPLEMENTS(Filament) {
public:
    void run() {
        for(int i = 0;i<50;i++) {
            latch->countDown();
            poll(NULL, 0, 1000);
        }
    }
};

DECLARE_CLASS(MyRun3) IMPLEMENTS(Filament) {
public:
    void run() {
        for(int i = 0;i<50;i++) {
            latch->countDown();
            poll(NULL, 0, 200);
        }
    }
};

int main(void) {
    ArrayList<Filament> list = ArrayList<Filament>::New();
    MyRun1 f1 = MyRun1::New();
    MyRun2 f2 = MyRun2::New();
    MyRun3 f3 = MyRun3::New();

    FilaRoutine croutine = FilaRoutine::New();
    croutine->start();

    croutine->execute(f1);
    croutine->execute(f2);
    croutine->execute(f3);
    latch->await();
    TEST_OK("Filament simple run case100");
  }
