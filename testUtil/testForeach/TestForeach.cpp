#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "UUID.hpp"
#include "Log.hpp"
#include "ArrayList.hpp"
#include "String.hpp"
#include "TestLog.hpp"
#include "HashMap.hpp"
#include "TestLog.hpp"
#include "ForEveryOne.hpp"
#include "ConcurrentQueue.hpp"

using namespace obotcha;

void testForeach() {

    ArrayList<String> list = createArrayList<String>();
    list->add(createString("a"));
    list->add(createString("c"));
    list->add(createString("b"));

    //ForEveryOne(s,list) {
    //  printf("s is %s \n",s->toChars());
    //}
    int count = 0;
    ForEveryOne(s,list) {
        if(!s->equals(list->get(count))) {
            TEST_FAIL("TestForEveryOne case1");
        }
        count++;
    }
    
    if(count != list->size()) {
        TEST_FAIL("TestForEveryOne case2");
    }

    HashMap<String,String> map = createHashMap<String,String>();
    map->put(createString("key1"),createString("val1"));
    map->put(createString("key2"),createString("val2"));
    map->put(createString("key3"),createString("val3"));
    
    count = 0;
    ForEveryOne(m,map) {
        String key = m->getKey();
        if(!map->get(key)->equals(m->getValue())) {
            TEST_FAIL("TestForEveryOne case3");
        }
        count++;
    }
    if(count != list->size()) {
        TEST_FAIL("TestForEveryOne case4");
    }

    ConcurrentQueue<String> queue = createConcurrentQueue<String>();
    queue->add(createString("aa"));
    queue->add(createString("bb"));
    queue->add(createString("cc"));
    
    count = 0;
    ForEveryOne(ss,queue) {
        if(!ss->equals(queue->get(count))) {
            TEST_FAIL("TestForEveryOne case5");
        }
        count++;
    }
    
    if(count != queue->size()) {
        TEST_FAIL("TestForEveryOne case6");
    }

    TEST_OK("[testForeach case100]");
}
