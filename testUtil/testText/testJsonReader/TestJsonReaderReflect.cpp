#include <stdio.h>
#include <unistd.h>
#include <iostream>

#include "JsonWriter.hpp"
#include "JsonReader.hpp"
#include "JsonValue.hpp"
#include "File.hpp"
#include "Reflect.hpp"

#include "Log.hpp"
#include "TestLog.hpp"


using namespace obotcha;

DECLARE_CLASS(MyReflectData) {
public:
    int a;
    double d;
    DECLARE_REFLECT_FIELD(MyReflectData,a,d)
};

int testreflect() {
    JsonReader mReader = createJsonReader()->loadFile(createFile("reflect.json"));
    //MyReflectData data = mReader->reflect<st(MyReflectData)>();
    MyReflectData data = createMyReflectData();
    mReader->get()->reflectTo(data);
    //std::cout<<"a is "<<data->a<<";d is "<<data->d;
    return 0;
}
