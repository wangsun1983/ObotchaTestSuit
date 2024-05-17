#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "HashMap.hpp"
#include "Boolean.hpp"
#include "Boolean.hpp"
#include "Math.hpp"
#include "TestLog.hpp"
#include "Float.hpp"

using namespace obotcha;

void testHashMapFloatFloat() {
    while(1) {
      HashMap<float,Float> map = HashMap<float,Float>::New();
      map->put(1.1,Float::New(100.01));
      float v = map->get(1.1)->toValue();
      if(st(Float)::Compare(v,100.01) != 0) {
        TEST_FAIL("[HashMap<float,float>} test1],v is %f ",v);
        break;
      }
      break;
    }

    while(1) {
      HashMap<float,Float> map = HashMap<float,Float>::New();
      map->put(1.1,Float::New(100.01));
      auto v = map->get(2.1);
      if(v != nullptr) {
        TEST_FAIL("[HashMap<float,float>} test2] ");
        break;
      }
      break;
    }

    while(1) {
      HashMap<float,Float> map = HashMap<float,Float>::New();
      map->put(1.1,Float::New(100.01));
      map->put(1.1,Float::New(200.01));
      map->put(2.1,Float::New(100.01));
      if(map->size() != 2) {
        TEST_FAIL("[HashMap<float,float>} test3] ");
        break;
      }

      float v1 = map->get(1.1)->toValue();
      float v2 = map->get(2.1)->toValue();

      if(st(Float)::Compare(v1,200.01) != 0
      || st(Float)::Compare(v2,100.01) != 0) {
        TEST_FAIL("[HashMap<float,float>} test4],v1 is %f,v2 is %f ",v1,v2);
        break;
      }
      break;
    }

    TEST_OK("[HashMap<float,float>} test100]");
}
