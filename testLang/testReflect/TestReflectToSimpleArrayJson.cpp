#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <type_traits>

#include "Object.hpp"
#include "StrongPointer.hpp"
#include "Reflect.hpp"
#include "String.hpp"
#include "Math.hpp"
#include "Field.hpp"
#include "JsonWriter.hpp"
#include "JsonReader.hpp"
#include "TestLog.hpp"

using namespace obotcha;

DECLARE_CLASS(IntArray) {
public:
  ArrayList<Integer> intlists;
  ArrayList<Long> longlists;
  ArrayList<Boolean> boollists;
  ArrayList<Double> doublelists;
  ArrayList<Float> floatlists;
  ArrayList<Uint8> uint8lists;
  ArrayList<Uint16> uint16lists;
  ArrayList<Uint32> uint32lists;
  ArrayList<Uint64> uint64lists;
  ArrayList<String> stringlists;
  DECLARE_REFLECT_FIELD(IntArray,intlists,longlists,boollists,
                        doublelists,floatlists,uint8lists,uint16lists,
                      uint32lists,uint64lists,stringlists)
};

void testReflectToSimpleArrayJson() {
  //test1
  while(1) {
    IntArray data = IntArray::New();
    data->intlists = ArrayList<Integer>::New();
    data->intlists->add(Integer::New(1));
    data->intlists->add(Integer::New(2));

    data->longlists = ArrayList<Long>::New();
    data->longlists->add(Long::New(1));
    data->longlists->add(Long::New(2));

    data->boollists = ArrayList<Boolean>::New();
    data->boollists->add(Boolean::New(true));
    data->boollists->add(Boolean::New(false));

    data->doublelists = ArrayList<Double>::New();
    data->doublelists->add(Double::New(1.1));
    data->doublelists->add(Double::New(2.2));

    data->floatlists = ArrayList<Float>::New();
    data->floatlists->add(Float::New(1.1));
    data->floatlists->add(Float::New(2.2));

    data->uint8lists = ArrayList<Uint8>::New();
    data->uint8lists->add(Uint8::New(1));
    data->uint8lists->add(Uint8::New(2));

    data->uint16lists = ArrayList<Uint16>::New();
    data->uint16lists->add(Uint16::New(1));
    data->uint16lists->add(Uint16::New(2));

    data->uint32lists = ArrayList<Uint32>::New();
    data->uint32lists->add(Uint32::New(1));
    data->uint32lists->add(Uint32::New(2));

    data->uint64lists = ArrayList<Uint64>::New();
    data->uint64lists->add(Uint64::New(1));
    data->uint64lists->add(Uint64::New(2));

    data->stringlists = ArrayList<String>::New();
    data->stringlists->add(String::New("a"));
    data->stringlists->add(String::New("b"));

    JsonValue jvalue = JsonValue::New();
    jvalue->importFrom(data);
    JsonWriter jwriter = JsonWriter::New("output3.json");
    jwriter->write(jvalue);

    JsonReader reader = JsonReader::New()->loadFile(File::New("output3.json"));
    JsonValue readValue = reader->get();

    IntArray rdata3 = IntArray::New();
    readValue->reflectTo(rdata3);

    if(rdata3->intlists == nullptr || rdata3->intlists->size() != 2) {
      TEST_FAIL("Reflect ArrayList To File test1");
      break;
    }
    //intlists
    Integer v0 = rdata3->intlists->get(0);
    if(v0 == nullptr || v0->toValue() != 1) {
      TEST_FAIL("Reflect ArrayList To File test2");
      break;
    }

    Integer v1 = rdata3->intlists->get(1);
    if(v1 == nullptr || v1->toValue() != 2) {
      TEST_FAIL("Reflect ArrayList To File test3");
      break;
    }

    //longlists
    Long vv1 = rdata3->longlists->get(0);
    if(vv1 == nullptr || vv1->toValue() != 1) {
      TEST_FAIL("Reflect ArrayList To File test4");
      break;
    }

    Long vv2 = rdata3->longlists->get(1);
    if(vv2 == nullptr || vv2->toValue() != 2) {
      TEST_FAIL("Reflect ArrayList To File test5");
      break;
    }

    //ArrayList<Boolean> boollists;
    Boolean vv3 = rdata3->boollists->get(0);
    if(vv3 == nullptr || vv3->toValue() != true) {
      TEST_FAIL("Reflect ArrayList To File test6");
      break;
    }

    Boolean vv4 = rdata3->boollists->get(1);
    if(vv4 == nullptr || vv4->toValue() != false) {
      TEST_FAIL("Reflect ArrayList To File test7");
      break;
    }

    //ArrayList<Double> doublelists;
    Double doubleValue = rdata3->doublelists->get(0);
    if(doubleValue == nullptr || doubleValue->toValue() != 1.1) {
      TEST_FAIL("Reflect ArrayList To File test7_1");
      break;
    }

    Double doubleValue2 = rdata3->doublelists->get(1);
    if(doubleValue2 == nullptr || doubleValue2->toValue() != 2.2) {
      TEST_FAIL("Reflect ArrayList To File test7_2");
      break;
    }

    //ArrayList<Float> floatlists;
    Float floatValue = rdata3->floatlists->get(0);
    if(floatValue == nullptr || st(Float)::Compare(floatValue->toValue(),1.1) != 0) {
      TEST_FAIL("Reflect ArrayList To File test7_3");
      break;
    }

    Float floatValue2 = rdata3->floatlists->get(1);
    if(floatValue2 == nullptr || st(Float)::Compare(floatValue2->toValue(),2.2) != 0) {
      TEST_FAIL("Reflect ArrayList To File test7_4");
      break;
    }

    //ArrayList<Uint8> uint8lists;
    Uint8 vv5 = rdata3->uint8lists->get(0);
    if(vv5 == nullptr || vv5->toValue() != 1) {
      TEST_FAIL("Reflect ArrayList To File test8");
      break;
    }

    Uint8 vv6 = rdata3->uint8lists->get(1);
    if(vv6 == nullptr || vv6->toValue() != 2) {
      TEST_FAIL("Reflect ArrayList To File test9");
      break;
    }

    //ArrayList<Uint16> uint16lists;
    Uint16 vv7 = rdata3->uint16lists->get(0);
    if(vv7 == nullptr || vv7->toValue() != 1) {
      TEST_FAIL("Reflect ArrayList To File test10");
      break;
    }

    Uint16 vv8 = rdata3->uint16lists->get(1);
    if(vv8 == nullptr || vv8->toValue() != 2) {
      TEST_FAIL("Reflect ArrayList To File test11");
      break;
    }

    //ArrayList<Uint32> uint32lists;
    Uint32 v4 = rdata3->uint32lists->get(0);
    if(v4 == nullptr || v4->toValue() != 1) {
      TEST_FAIL("Reflect ArrayList To File test12");
      break;
    }

    Uint32 v5 = rdata3->uint32lists->get(1);
    if(v5 == nullptr || v5->toValue() != 2) {
      TEST_FAIL("Reflect ArrayList To File test13");
      break;
    }

    //ArrayList<Uint64> uint64lists;
    Uint64 v6 = rdata3->uint64lists->get(0);
    if(v6 == nullptr || v6->toValue() != 1) {
      TEST_FAIL("Reflect ArrayList To File test14");
      break;
    }

    Uint64 v7 = rdata3->uint64lists->get(1);
    if(v7 == nullptr || v7->toValue() != 2) {
      TEST_FAIL("Reflect ArrayList To File test15");
      break;
    }

    //ArrayList<String> stringlists;
    String v8 = rdata3->stringlists->get(0);
    if(v8 == nullptr || !v8->sameAs("a")) {
      TEST_FAIL("Reflect ArrayList To File test16");
      break;
    }

    String v9 = rdata3->stringlists->get(1);
    if(v9 == nullptr || !v9->sameAs("b")) {
      TEST_FAIL("Reflect ArrayList To File test17");
      break;
    }

    TEST_OK("Reflect ArrayList To File test18");
    break;
  }
}
