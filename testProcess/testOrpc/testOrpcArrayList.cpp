#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Reflect.hpp"
#include "String.hpp"
#include "Serializable.hpp"
#include "Reflect.hpp"

using namespace obotcha;

DECLARE_CLASS(MyTestArrayListMember) IMPLEMENTS(Serializable) {
public:
    String m1;
    int m2;
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

    ByteArray array = list->toByteArray();

    MyTestDataList list2 = createMyTestDataList();
    list2->import(array);

    MyTestArrayListMember member1_X = list2->ll->get(0);
    printf("m1 is %s,m2 is %d \n",member1_X->m1->toChars(),member1_X->m2);
}
