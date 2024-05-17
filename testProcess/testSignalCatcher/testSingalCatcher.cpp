#include <stdio.h>
#include <unistd.h>
#include <signal.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "Log.hpp"
#include "Pipe.hpp"
#include "ByteArray.hpp"
#include "SignalCatcher.hpp"
#include "CountDownLatch.hpp"
#include "TestLog.hpp"

using namespace obotcha;

CountDownLatch latch = CountDownLatch::New(2);

DECLARE_CLASS(SigListner) IMPLEMENTS(SignalListener) {
public:
    void onSignal(int sig) {
        latch->countDown();
    }
};

void testSignalCatcher() {
    SignalCatcher cat = st(SignalCatcher)::getInstance();
    cat->regist(10,SigListner::New());
    cat->regist(10,SigListner::New());

    kill(getpid(),SIGUSR1);

    latch->await();

    TEST_OK("SignalCatch test case1");
}
