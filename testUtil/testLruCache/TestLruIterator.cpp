#include <iostream>
#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ArrayList.hpp"
#include "Integer.hpp"
#include "String.hpp"
#include "LruCache.hpp"
#include "TestLog.hpp"

using namespace obotcha;

int testLruIteator() {
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
		while(iterator->hasValue()) {
			if(!iterator->getKey()->equals(tags->get(count))) {
				TEST_FAIL("LruCache Iterator case1");
			}
			
			if(!iterator->getValue()->equals(values->get(count))) {
				TEST_FAIL("LruCache Iterator case2");
			}
			count++;
			iterator->next();
		}
		break;
	}
	
	while(1) {
		LruCache<String,String> cache = createLruCache<String,String>(16);
		cache->put(createString("a"),createString("this is a"));
		cache->put(createString("b"),createString("this is b"));
		cache->put(createString("c"),createString("this is c"));
		
		ArrayList<String> tags = createArrayList<String>();
		tags->add(createString("c"));
		tags->add(createString("a"));
		
		ArrayList<String> values = createArrayList<String>();
		values->add(createString("this is c"));
		values->add(createString("this is a"));
		
		auto iterator = cache->getIterator();
		while(iterator->hasValue()) {
			if(iterator->getKey()->sameAs("b")) {
				iterator->remove();
			}
			iterator->next();
		}
		
		if(cache->size() != 2) {
			TEST_FAIL("LruCache Iterator case3");
		}
		
		int count = 0;
		iterator = cache->getIterator();
		while(iterator->hasValue()) {
			if(!iterator->getKey()->equals(tags->get(count))) {
				TEST_FAIL("LruCache Iterator case4");
			}
			
			if(!iterator->getValue()->equals(values->get(count))) {
				TEST_FAIL("LruCache Iterator case5");
			}
			count++;
			iterator->next();
		}
		break;
	}
	
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
		while(iterator->hasValue()) {
			if(!iterator->getItem()->getKey()->equals(tags->get(count))) {
				TEST_FAIL("LruCache Iterator case6");
			}
			
			if(!iterator->getItem()->getValue()->equals(values->get(count))) {
				TEST_FAIL("LruCache Iterator case7");
			}
			count++;
			iterator->next();
		}
		break;
	}
	
	
	TEST_OK("LruCache Iterator case100");
	return 0;
}
