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

    ForEveryOne(s,list) {
      printf("s is %s \n",s->toChars());
    }

    HashMap<String,String> map = createHashMap<String,String>();
    map->put(createString("key1"),createString("val1"));
    map->put(createString("key2"),createString("val2"));
    map->put(createString("key3"),createString("val3"));

    ForEveryOne(m,map) {
      printf("key is %s,value is %s \n",m->getKey()->toChars(),m->getValue()->toChars());
    }

    ConcurrentQueue<String> queue = createConcurrentQueue<String>();
    queue->add(createString("aa"));
    queue->add(createString("bb"));
    queue->add(createString("cc"));

    ForEveryOne(ss,queue) {
      printf("ss is %s \n",ss->toChars());
    }

    TEST_OK("[testForeach case100]");
}
