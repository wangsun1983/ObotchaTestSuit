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
#include "LruCache.hpp"

using namespace obotcha;

void testLruCache() {

    while(1) {
      LruCache<String,String> cache = createLruCache<String,String>(16);
      cache->put(createString("a"),createString("this is a"));
      cache->put(createString("b"),createString("this is b"));
      cache->put(createString("c"),createString("this is c"));
      
      ArrayList<String> tags = createArrayList<String>();
      tags->add(createString("c"));
      tags->add(createString("b"));
      tags->add(createString("a"));
      
      ArrayList<String> values = createArrayList<String>();
      values->add(createString("this is c"));
      values->add(createString("this is b"));
      values->add(createString("this is a"));
      
      auto iterator = cache->getIterator();
      int count = 0;
      ForEveryOne(pair,cache) {
      	if(!pair->getKey()->equals(tags->get(count))) {
      		TEST_FAIL("ForEveryOne LruCache case1");
      	}
      	
      	if(!pair->getValue()->equals(values->get(count))) {
      		TEST_FAIL("ForEveryOne LruCache case2");
      	}
      	count++;
      }
      break;
    }

    while(1) {
      LruCache<String,String> cache = createLruCache<String,String>(16);
      int count = 0;
      ForEveryOne(s,cache) {
        count++;
      }

      if(count != 0) {
        TEST_FAIL("ForEveryOne LruCache case3");
      }
      break;
    }
	
	while(1) {
	  LruCache<String,String> cache = createLruCache<String,String>(16);
	  cache->put(createString("a"),createString("this is a"));
	  cache->put(createString("b"),createString("this is b"));
	  cache->put(createString("c"),createString("this is c"));
	  int count = 0;
	  ForEveryOne(s,cache) {
	    count++;
	  }
	
	  if(count != 3) {
	    TEST_FAIL("ForEveryOne LruCache case4");
	  }
	  break;
	}

    TEST_OK("ForEveryOne LruCache case100");
}
