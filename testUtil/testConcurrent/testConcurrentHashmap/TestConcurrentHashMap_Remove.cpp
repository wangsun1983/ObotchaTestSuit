#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ConcurrentHashMap.hpp"
#include "Integer.hpp"
#include "TestLog.hpp"
#include "TimeWatcher.hpp"

using namespace obotcha;

void testConcurrentHashMap_Remove() {
    while(1) {
        ConcurrentHashMap<String,String> maps = ConcurrentHashMap<String,String>::New();
      
        for(int i = 0;i < 1024*32;i++) {
            maps->put(String::New(i),String::New(i));
        }

        Thread t1 = Thread::New([&]{
            for(int i = 0;i < 1024*32;i++) {
                maps->remove(String::New(i));
            }
        });
        
        Thread t2 = Thread::New([&]{
            for(int i = 0;i < 1024*32;i++) {
                maps->remove(String::New(i));
            }
        });
        
        Thread t3 = Thread::New([&]{
            for(int i = 0;i < 1024*32;i++) {
                maps->remove(String::New(i));
            }
        });
        
        Thread t4 = Thread::New([&]{
            for(int i = 0;i < 1024*32;i++) {
                maps->remove(String::New(i));
            }
        });
        
        t1->start();
        t2->start();
        t3->start();
        t4->start();
        
        t1->join();
        t2->join();
        t3->join();
        t4->join();
        
        if(maps->size() != 0) {
            TEST_FAIL("ConcurrentHashMap Remove case1,size is %d",maps->size());
        }
        break;
    }
    
    while(1) {
        ConcurrentHashMap<String,String> maps = ConcurrentHashMap<String,String>::New();
        maps->put(String::New("a"),String::New("b"));
        
        Thread t1 = Thread::New([&]{
            maps->syncReadAction([&] {
                if(maps->size() != 1) {
                    TEST_FAIL("ConcurrentHashMap Remove case2,size is %d",maps->size());
                }
                usleep(300*1000);
            }); 
        });
        
        Thread t2 = Thread::New([&]{
            usleep(100*1000);
            TimeWatcher watcher = TimeWatcher::New();
            watcher->start();
            maps->remove(String::New("a"));
            auto ret = watcher->stop();
            if(ret < 195 || ret > 305) {
                TEST_FAIL("ConcurrentHashMap Remove case3,ret is %d",ret);
            }
        });
        
        t1->start();
        t2->start();
        
        t1->join();
        t2->join();
        
        if(maps->size() != 0) {
            TEST_FAIL("ConcurrentHashMap Remove case4,size is %d",maps->size());
        }
        break;
    }

    TEST_OK("ConcurrentHashMap Remove case100");
}
