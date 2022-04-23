#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <functional>

#include "Thread.hpp"
#include "Runnable.hpp"
#include "Uint8.hpp"
#include "String.hpp"
#include "ArrayList.hpp"
#include "Reflect.hpp"
#include "Uint8.hpp"
#include "XmlDocument.hpp"
#include "XmlReader.hpp"
#include "XmlWriter.hpp"
#include "TestLog.hpp"
#include "IniValue.hpp"
#include "IniWriter.hpp"
#include "IniReader.hpp"
#include "JsonValue.hpp"
#include "JsonReader.hpp"
#include "JsonWriter.hpp"
#include "TestLog.hpp"

using namespace obotcha;


DECLARE_CLASS(MyInfo) {
public:
  String name;
  int age;
  ArrayList<String> list;
  HashMap<String,String> map;

  DECLARE_REFLECT_FIELD(MyInfo,name,age,list,map);
};

void testReflectNullItems() {
  JsonValue value = createJsonValue();
  MyInfo info = createMyInfo();
  info->age = 12;

  value->importFrom(info);

  JsonWriter writer = createJsonWriter(createString("./abc.json"));
  writer->write(value);

  JsonReader reader = createJsonReader(createFile("./abc.json"));
  JsonValue value2 = reader->get();

  MyInfo info2 = createMyInfo();
  value2->reflectTo(info2);

  if(info2->age != 12) {
    TEST_FAIL("[JsonReflect NullItems case1]");
  }
  
  TEST_OK("[JsonReflect NullItems case100]");
}
