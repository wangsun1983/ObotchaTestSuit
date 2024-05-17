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
		LruCache<String,String> cache = LruCache<String,String>::New(16);
		cache->put(String::New("a"),String::New("this is a"));
		cache->put(String::New("b"),String::New("this is b"));
		cache->put(String::New("c"),String::New("this is c"));
		
		ArrayList<String> tags = ArrayList<String>::New();
		tags->add(String::New("c"));
		tags->add(String::New("b"));
		tags->add(String::New("a"));
		
		ArrayList<String> values = ArrayList<String>::New();
		values->add(String::New("this is c"));
		values->add(String::New("this is b"));
		values->add(String::New("this is a"));
		
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
		LruCache<String,String> cache = LruCache<String,String>::New(16);
		cache->put(String::New("a"),String::New("this is a"));
		cache->put(String::New("b"),String::New("this is b"));
		cache->put(String::New("c"),String::New("this is c"));
		
		ArrayList<String> tags = ArrayList<String>::New();
		tags->add(String::New("c"));
		tags->add(String::New("a"));
		
		ArrayList<String> values = ArrayList<String>::New();
		values->add(String::New("this is c"));
		values->add(String::New("this is a"));
		
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
		LruCache<String,String> cache = LruCache<String,String>::New(16);
		cache->put(String::New("a"),String::New("this is a"));
		cache->put(String::New("b"),String::New("this is b"));
		cache->put(String::New("c"),String::New("this is c"));
		
		ArrayList<String> tags = ArrayList<String>::New();
		tags->add(String::New("c"));
		tags->add(String::New("b"));
		tags->add(String::New("a"));
		
		ArrayList<String> values = ArrayList<String>::New();
		values->add(String::New("this is c"));
		values->add(String::New("this is b"));
		values->add(String::New("this is a"));
		
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
