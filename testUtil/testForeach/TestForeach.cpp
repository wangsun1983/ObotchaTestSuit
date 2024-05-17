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

    ArrayList<String> list = ArrayList<String>::New();
    list->add(String::New("a"));
    list->add(String::New("c"));
    list->add(String::New("b"));

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

    HashMap<String,String> map = HashMap<String,String>::New();
    map->put(String::New("key1"),String::New("val1"));
    map->put(String::New("key2"),String::New("val2"));
    map->put(String::New("key3"),String::New("val3"));
    
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

    ConcurrentQueue<String> queue = ConcurrentQueue<String>::New();
    queue->add(String::New("aa"));
    queue->add(String::New("bb"));
    queue->add(String::New("cc"));
    
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
