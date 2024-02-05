#include "AtomicBoolean.hpp"
#include "Thread.hpp"
#include "TimeWatcher.hpp"
#include "TestLog.hpp"

using namespace obotcha;

int main() {
    AtomicBoolean value = createAtomicBoolean(false);
    Thread t1 = createThread([&value] {
        st(Thread)::Sleep(1000);
        value->set(true);
    });
    
    Thread t2 = createThread([&value] {
        while(!value->get()) {
            
        }
    });
    
    t1->start();
    t2->start();
    
    TimeWatcher w = createTimeWatcher();
    w->start();
    t1->join();
    t2->join();
    
    auto interval = w->stop();
    
    if(interval < 995 || interval > 1005) {
        TEST_FAIL("AtomicBoolean test case1");
    }
    
    TEST_OK("AtomicBoolean test case100");
    return 0;
}
