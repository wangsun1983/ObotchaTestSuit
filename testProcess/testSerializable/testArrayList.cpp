#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Reflect.hpp"
#include "String.hpp"
#include "Serializable.hpp"
#include "Reflect.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(MyTestArrayListMember) IMPLEMENTS(Serializable) {
public:
    String m1;
    int m2;

    bool equals(MyTestArrayListMember s) {
        return m1->equals(s->m1) && m2 == s->m2;        
    }

    DECLARE_REFLECT_FIELD(MyTestArrayListMember,m1,m2);
};

DECLARE_CLASS(MyTestDataList) IMPLEMENTS(Serializable) {
public:
    ArrayList<MyTestArrayListMember> ll;

    DECLARE_REFLECT_FIELD(MyTestDataList,ll);
};

void testOrpcArrayList() {
    MyTestDataList list = createMyTestDataList();
    list->ll = createArrayList<MyTestArrayListMember>();

    MyTestArrayListMember member1 = createMyTestArrayListMember();
    member1->m1 = createString("str1");
    member1->m2 = 1;

    MyTestArrayListMember member2 = createMyTestArrayListMember();
    member2->m1 = createString("str2");
    member2->m2 = 2;

    list->ll->add(member1);
    list->ll->add(member2);

    ByteArray array = list->serialize();

    MyTestDataList list2 = createMyTestDataList();
    list2->deserialize(array);

    
    if(list2->ll->size() != list->ll->size()) {
        TEST_FAIL("testSerializable ArrayList case1");
    }

    for(int i = 0;i < list->ll->size();i++) {
        auto data1 = list->ll->get(i);
        auto data2 = list2->ll->get(i);
        if(!data1->equals(data2)) {
            TEST_FAIL("testSerializable ArrayList case2");
            break;
        }
    }

    TEST_OK("testSerializable ArrayList case100");
}
