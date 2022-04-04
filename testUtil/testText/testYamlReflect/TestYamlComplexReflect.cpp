#include <stdio.h>
#include <unistd.h>

#include "YamlReader.hpp"
#include "YamlValue.hpp"
#include "Log.hpp"
#include "TestLog.hpp"
#include "Reflect.hpp"
#include "YamlWriter.hpp"

using namespace obotcha;

DECLARE_CLASS(Student) {
public:
    String name;
    int age;
    bool tall;
    DECLARE_REFLECT_FIELD(Student,name,age,tall);
};

DECLARE_CLASS(ClassRoom) {
public:
    String classname;
    ArrayList<Student> students;
    HashMap<String,Student> maps;
    DECLARE_REFLECT_FIELD(ClassRoom,classname,students,maps);
};

void testReflectComplex() {
    Student a = createStudent();
    a->name = "i am a";
    a->age = 12;
    a->tall = true;

    Student b = createStudent();
    b->name = "i am b";
    b->age = 13;
    b->tall = false;

    ClassRoom room = createClassRoom();
    room->classname = "class one";
    room->students = createArrayList<Student>();
    room->students->add(a);
    room->students->add(b);

    room->maps = createHashMap<String,Student>();
    room->maps->put("good",a);
    room->maps->put("normal",b);

    YamlValue v = createYamlValue();
    v->importFrom(room);

    YamlWriter w = createYamlWriter(createFile("./tmp/complex.yaml"));
    w->write(v);

    //do check
    YamlReader r = createYamlReader(createFile("./tmp/complex.yaml"));
    auto result = r->parse();
    ClassRoom ro = createClassRoom();
    result->reflectTo(ro);

    if(!room->classname->equals(ro->classname)) {
        TEST_FAIL("[TestYamlReflectComplex case1]");
        return;
    }

    auto v1 = room->students->get(0);
    auto v2 = room->students->get(1);

    auto p1 = ro->students->get(0);
    auto p2 = ro->students->get(1);

    if(!v1->name->equals(p1->name)) {
        TEST_FAIL("[TestYamlReflectComplex case2]");
        return;
    }

    if(v1->age != p1->age) {
        TEST_FAIL("[TestYamlReflectComplex case3]");
        return;
    }

    if(v1->tall != p1->tall) {
        TEST_FAIL("[TestYamlReflectComplex case4]");
        return;
    }

    if(!v2->name->equals(p2->name)) {
        TEST_FAIL("[TestYamlReflectComplex case5]");
        return;
    }

    if(v2->age != p2->age) {
        TEST_FAIL("[TestYamlReflectComplex case6]");
        return;
    }

    if(v2->tall != p2->tall) {
        TEST_FAIL("[TestYamlReflectComplex case7]");
        return;
    }

    v1 = room->maps->get("good");
    v2 = room->maps->get("normal");

    p1 = ro->maps->get("good");
    p2 = ro->maps->get("normal");

    if(!v1->name->equals(p1->name)) {
        TEST_FAIL("[TestYamlReflectComplex case8]");
        return;
    }

    if(v1->age != p1->age) {
        TEST_FAIL("[TestYamlReflectComplex case9]");
        return;
    }

    if(v1->tall != p1->tall) {
        TEST_FAIL("[TestYamlReflectComplex case10]");
        return;
    }

    if(!v2->name->equals(p2->name)) {
        TEST_FAIL("[TestYamlReflectComplex case11]");
        return;
    }

    if(v2->age != p2->age) {
        TEST_FAIL("[TestYamlReflectComplex case12]");
        return;
    }

    if(v2->tall != p2->tall) {
        TEST_FAIL("[TestYamlReflectComplex case13]");
        return;
    }

    TEST_OK("[TestYamlReflectComplex case100]");
}
