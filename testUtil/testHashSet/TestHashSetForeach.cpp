#include <stdio.h>
#include <unistd.h>
#include <vector>

#include "HashSet.hpp"
#include "HashMap.hpp"
#include "TestLog.hpp"
#include "ForEveryOne.hpp"

using namespace obotcha;

void testHashSetForeach() {

    //case string
    HashSet<String> set = createHashSet<String>();
    set->add(createString("abc"));
    set->add(createString("abc"));
    set->add(createString("abc1"));
    set->add(createString("abc2"));
    set->add(createString("abc3"));

    std::vector<std::string> list;
    list.push_back("abc");
    list.push_back("abc1");
    list.push_back("abc2");
    list.push_back("abc3");

    int index = 0;
    ForEveryOne(ss,set) {
      if(ss->equals("abc") || ss->equals("abc1")
        ||ss->equals("abc2") || ss->equals("abc3")) {
          index++;
          continue;
        }
        TEST_FAIL("testHashSetForeach,case1");
    }

    if(index != 4) {
      TEST_FAIL("testHashSetForeach,case2 is %d",index);
    }

    TEST_OK("testHashSetForeach base test100");
}
