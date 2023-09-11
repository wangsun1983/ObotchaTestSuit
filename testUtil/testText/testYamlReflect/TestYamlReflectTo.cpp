#include <stdio.h>
#include <unistd.h>

#include "YamlReader.hpp"
#include "YamlValue.hpp"
#include "Log.hpp"
#include "TestLog.hpp"
#include "Reflect.hpp"

using namespace obotcha;

/*
name: Example Developer
job: Developer
skill: Elite
employed: True
foods:
    - Apple
    - Orange
    - Strawberry
    - Mango
languages:
    ruby: Elite
    python: Elite
    dotnet: Lame
*/

DECLARE_CLASS(Lanaguage) {
public:
    String ruby;
    String python;
    String dotnet;

    DECLARE_REFLECT_FIELD(Lanaguage,ruby,python,dotnet)
};

DECLARE_CLASS(TestData) {
public:
    String name;
    String job;
    String skill;
    bool employed;
    ArrayList<String> foods;
    Lanaguage languages;
    HashMap<String,String> hobbies;
    DECLARE_REFLECT_FIELD(TestData,name,job,skill,employed,foods,languages,hobbies)
};

void testReflectTo() {
    YamlReader r = createYamlReader()->loadFile(createFile("./test.yaml"));
    auto value = r->parse();
    TestData data = createTestData();
    value->reflectTo(data);
    if(!data->name->sameAs("Example Developer")) {
        TEST_FAIL("[TestYamlReflect reflectTo case1]");
    }

    if(!data->job->sameAs("Developer")) {
        TEST_FAIL("[TestYamlReflect reflectTo case2]");
    }

    if(!data->skill->sameAs("Elite")) {
        TEST_FAIL("[TestYamlReflect reflectTo case3]");
    }

    if(!data->employed) {
        TEST_FAIL("[TestYamlReflect reflectTo case4]");
    }

    if(data->foods->size() != 4) {
        TEST_FAIL("[TestYamlReflect reflectTo case5,size is %d",data->foods->size());
    }

    if(!data->foods->get(0)->sameAs("Apple") ||
        !data->foods->get(1)->sameAs("Orange") ||
        !data->foods->get(2)->sameAs("Strawberry") ||
        !data->foods->get(3)->sameAs("Mango")) {
        TEST_FAIL("[TestYamlReflect reflectTo case6");
    }

    if(!data->languages->ruby->sameAs("Elite") ||
        !data->languages->python->sameAs("Elite") ||
        !data->languages->dotnet->sameAs("Lame")) {
        TEST_FAIL("[TestYamlReflect reflectTo case7");
    }

    if(data->hobbies->size() != 3) {
        TEST_FAIL("[TestYamlReflect reflectTo case8");
    }

    if(!data->hobbies->get("footabll")->sameAs("like")
        ||!data->hobbies->get("basketball")->sameAs("like")
        ||!data->hobbies->get("sleep")->sameAs("dislike")) {
        TEST_FAIL("[TestYamlReflect reflectTo case9");
    }

    TEST_OK("[TestYamlReflect reflectTo case100]");
}
