#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Reflect.hpp"
#include "String.hpp"
#include "Serializable.hpp"
#include "Reflect.hpp"
#include "HashMap.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(Member1) IMPLEMENTS(Serializable) {
public:
    int v1;
    bool v2;
    bool equals(Member1 s) {
        return v1 == s->v1 && v2 == s->v2;
    }

    DECLARE_REFLECT_FIELD(Member1,v1,v2);
};

DECLARE_CLASS(Member2) IMPLEMENTS(Serializable) {
public:
    String v1;
    Integer v2;
    
    bool equals(Member2 s) {
        return v1->equals(s->v1) && v2->toValue() == s->v2->toValue();
    }

    DECLARE_REFLECT_FIELD(Member2,v1,v2);
};

DECLARE_CLASS(AllMember) IMPLEMENTS(Serializable) {
public:
    Member1 m1;
    Member2 m2;

    bool equals(AllMember s) {
        return m1->equals(s->m1) && m2->equals(s->m2);
    }

    DECLARE_REFLECT_FIELD(AllMember,m1,m2);
};

void testInnerClass() {
    AllMember allmem = createAllMember();
    allmem->m1 = createMember1();
    allmem->m1->v1 = 123;
    allmem->m1->v2 = false;

    allmem->m2 = createMember2();
    allmem->m2->v1 = createString("hello world");
    allmem->m2->v2 = createInteger(223);

    ByteArray data = allmem->serialize();

    AllMember rs = createAllMember();
    rs->deserialize(data);

    if(!rs->equals(allmem)) {
        TEST_FAIL("testSerializable testInnerClass case1");
    }

    TEST_OK("testSerializable testInnerClass case100");
}
