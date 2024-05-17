#include <stdio.h>
#include <unistd.h>

#include "YamlReader.hpp"
#include "YamlValue.hpp"
#include "Log.hpp"
#include "TestLog.hpp"
#include "Reflect.hpp"
#include "YamlWriter.hpp"
#include "YamlReader.hpp"
#include "YamlValue.hpp"

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

DECLARE_CLASS(Skill) {
public:
    String ruby;
    String python;
    String dotnet;

    DECLARE_REFLECT_FIELD(Skill,ruby,python,dotnet)
};

DECLARE_CLASS(Worker) {
public:
    String name;
    String job;
    bool employed;
    bool tall;
    ArrayList<String> foods;
    Skill skills;
    HashMap<String,String> hobbies;
    DECLARE_REFLECT_FIELD(Worker,name,job,skills,employed,foods,tall,hobbies)
};

void testImportFrom() {
    Worker data = Worker::New();
    data->name = String::New("wang");
    data->job = String::New("engineer");
    data->employed = true;
    data->tall = false;
    data->foods = ArrayList<String>::New();
    data->foods->add(String::New("apple"));
    data->foods->add(String::New("pear"));
    data->foods->add(String::New("bread"));

    data->skills = Skill::New();
    data->skills->ruby = String::New("good");
    data->skills->python = String::New("very good");
    data->skills->dotnet = String::New("just so so");

    data->hobbies = HashMap<String,String>::New();
    data->hobbies->put("basketball","like");
    data->hobbies->put("football","unlike");
    data->hobbies->put("sleep","like");

    YamlValue value = YamlValue::New();
    value->importFrom(data);

    YamlWriter w = YamlWriter::New(File::New("./tmp/import.yaml"));
    w->write(value);

    //
    YamlReader r = YamlReader::New()->loadFile(File::New("./tmp/import.yaml"));
    auto node = r->parse();
    Worker v2 = Worker::New();
    node->reflectTo(v2);

    if(!data->name->equals(v2->name)) {
        TEST_FAIL("[TestYamlReflect Import case1]");
    }

    if(!data->job->equals(v2->job)) {
        TEST_FAIL("[TestYamlReflect Import case2]");
    }

    if(data->employed != v2->employed) {
        TEST_FAIL("[TestYamlReflect Import case3]");
    }

    if(data->tall != v2->tall) {
        TEST_FAIL("[TestYamlReflect Import case4]");
    }

    if(!data->foods->get(0)->equals(v2->foods->get(0))
        ||!data->foods->get(1)->equals(v2->foods->get(1))
        ||!data->foods->get(2)->equals(v2->foods->get(2))) {
        TEST_FAIL("[TestYamlReflect Import case5]");
    }

    if(!data->skills->ruby->equals(v2->skills->ruby)
        ||!data->skills->python->equals(v2->skills->python)
        ||!data->skills->dotnet->equals(v2->skills->dotnet)) {
        TEST_FAIL("[TestYamlReflect Import case6]");
    }

    if(!data->hobbies->get("basketball")->equals(v2->hobbies->get("basketball"))
        ||!data->hobbies->get("football")->equals(v2->hobbies->get("football"))
        ||!data->hobbies->get("sleep")->equals(v2->hobbies->get("sleep"))) {
        TEST_FAIL("[TestYamlReflect Import case7]");
    }


    TEST_OK("[TestYamlReflect Import case100]");
}
