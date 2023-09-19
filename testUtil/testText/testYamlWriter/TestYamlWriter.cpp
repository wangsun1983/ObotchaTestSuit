#include <stdio.h>
#include <unistd.h>

#include "YamlReader.hpp"
#include "YamlValue.hpp"
#include "YamlWriter.hpp"
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

void testYamlWriter() {
    YamlValue value = createYamlValue();
    value->set(createString("name"),S("wang"));
    value->set(S("job"),S("developer"));
    value->set(S("skill"),S("Elite"));
    value->set(S("employed"),S("true"));

    YamlValue foods = createYamlValue();
    foods->pushBack(S("Apple"));
    foods->pushBack(S("Orange"));
    foods->pushBack(S("Strawberry"));
    foods->pushBack(S("Mango"));
    value->set(S("foods"),foods);

    YamlValue languages = createYamlValue();
    languages->set(S("ruby"),S("Elite"));
    languages->set(S("python"),S("Elite"));
    languages->set(S("dotnet"),S("Lame"));
    value->set(S("languages"),languages);

    YamlValue hobbies = createYamlValue();
    hobbies->set(S("football"),S("like"));
    hobbies->set(S("basketball"),S("Elite"));
    hobbies->set(S("sleep"),S("dislike"));
    value->set(S("hobbies"),hobbies);

    YamlWriter w = createYamlWriter(createFile("./tmp/tmp.yaml"));
    w->write(value);


    TestData data = createTestData();
    data->name = "wang";
    data->job = "developer";
    data->skill = "Elite";
    data->employed = true;

    data->foods = createArrayList<String>();
    data->foods->add(createString("Apple"));
    data->foods->add(createString("Orange"));
    data->foods->add(createString("Strawberry"));
    data->foods->add(createString("Mango"));

    data->languages = createLanaguage();
    data->languages->ruby = "Elite";
    data->languages->python = "Elite";
    data->languages->dotnet = "Lame";

    data->hobbies = createHashMap<String,String>();
    data->hobbies->put(S("football"),S("like"));
    data->hobbies->put(S("basketball"),S("Elite"));
    data->hobbies->put(S("sleep"),S("dislike"));

    YamlReader r = createYamlReader()->loadFile(createFile("./tmp/tmp.yaml"));
    auto node = r->parse();
    TestData v2 = createTestData();
    node->reflectTo(v2);
    
    if(!data->name->equals(v2->name)) {
        TEST_FAIL("[TestYamlWriter Import case1]");
    }

    if(!data->job->equals(v2->job)) {
        TEST_FAIL("[TestYamlWriter Import case2]");
    }

    if(!data->skill->equals(v2->skill)) {
        TEST_FAIL("[TestYamlWriter Import case2_1]");
    }

    if(data->employed != v2->employed) {
        TEST_FAIL("[TestYamlWriter Import case3]");
    }

    if(!data->foods->get(0)->equals(v2->foods->get(0))
        ||!data->foods->get(1)->equals(v2->foods->get(1))
        ||!data->foods->get(2)->equals(v2->foods->get(2))
        ||!data->foods->get(3)->equals(v2->foods->get(3))) {
		printf("food[0] is %s,read food[0] is %s \n",data->foods->get(0)->toChars(),v2->foods->get(0)->toChars());
        TEST_FAIL("[TestYamlWriter Import case5]");
    }


    if(!data->hobbies->get("basketball")->equals(v2->hobbies->get("basketball"))
        ||!data->hobbies->get("football")->equals(v2->hobbies->get("football"))
        ||!data->hobbies->get("sleep")->equals(v2->hobbies->get("sleep"))) {
        TEST_FAIL("[TestYamlWriter Import case7]");
    }

    TEST_OK("[TestYamlWrite case100]");
}
