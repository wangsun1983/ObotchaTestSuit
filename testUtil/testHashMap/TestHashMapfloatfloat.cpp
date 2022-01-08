#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "HashMap.hpp"
#include "Boolean.hpp"
#include "Boolean.hpp"
#include "Math.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testHashMapFloatFloat() {
    while(1) {
      HashMap<float,float> map = createHashMap<float,float>();
      map->put(1.1,100.01);
      float v = map->get(1.1);
      if(st(Math)::compareFloat(v,100.01) != st(Math)::AlmostEqual) {
        TEST_FAIL("[HashMap<float,float>} test1],v is %f ",v);
        break;
      }
      break;
    }

    while(1) {
      HashMap<float,float> map = createHashMap<float,float>();
      map->put(1.1,100.01);
      bool isExcpetion = false;
      try {
        map->get(2.1);
      } catch(...) {
        isExcpetion = true;
      }

      if(!isExcpetion) {
        TEST_FAIL("[HashMap<float,float>} test2] ");
        break;
      }
      break;
    }

    while(1) {
      HashMap<float,float> map = createHashMap<float,float>();
      map->put(1.1,100.01);
      map->put(1.1,200.01);
      map->put(2.1,100.01);
      if(map->size() != 2) {
        TEST_FAIL("[HashMap<float,float>} test3] ");
        break;
      }

      float v1 = map->get(1.1);
      float v2 = map->get(2.1);

      if(st(Math)::compareFloat(v1,200.01) != st(Math)::AlmostEqual
      || st(Math)::compareFloat(v2,100.01) != st(Math)::AlmostEqual) {
        TEST_FAIL("[HashMap<float,float>} test4],v1 is %f,v2 is %f ",v1,v2);
        break;
      }
      break;
    }

    TEST_OK("[HashMap<float,float>} test100]");
}
