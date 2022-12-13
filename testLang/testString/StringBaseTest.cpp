#include <stdio.h>
#include <iostream>
#include <type_traits>

#include <string.h>
#include "String.hpp"
#include "ArrayList.hpp"
#include "NullPointerException.hpp"
#include "ArrayIndexOutOfBoundsException.hpp"
#include "NullPointerException.hpp"
#include "TransformException.hpp"
#include "InitializeException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void basetest() {

  while(1) {
    String str1 = createString();
    if(str1->size() != 0) {
        TEST_FAIL("BaseTest String construct test1");
        break;
    }

    TEST_OK("BaseTest String construct test1");
    break;
  }

  //test _String(std::string v);
  while(1) {
    std::string v("abc");
    String str = createString(v);
    if(str->size() != 3) {
        TEST_FAIL("BaseTest String construct test3");
        break;
    }

    if(!str->equals("abc")) {
        TEST_FAIL("BaseTest String construct test4");
        break;
    }

    TEST_OK("BaseTest String construct test5");
    break;
  }

  //_String(String v);
  while(1) {
    std::string v("abc");
    String str = createString(v);
    String str2 = createString(str);
    if(str2->size() != 3) {
        TEST_FAIL("BaseTest String construct test6");
        break;
    }

    if(!str2->equals("abc")) {
        TEST_FAIL("BaseTest String construct test7");
        break;
    }

    //String str3;
    //try {
    //    String str4 = createString(str3);
    //    TEST_FAIL("BaseTest String construct test8");
    //} catch(NullPointerException e) {

    //}

    TEST_OK("BaseTest String construct test8");
    break;
  }

  //_String(const char *v);
  while(1) {
    String str = createString("abc");
    if(str->size() != 3) {
        TEST_FAIL("BaseTest String construct test9");
        break;
    }

    if(!str->equals("abc")) {
        TEST_FAIL("BaseTest String construct test10");
        break;
    }

    //bool isException = false;
    //try {
    //    String str2 = createString((const char *)nullptr);
    //} catch(InitializeException e) {
    //    isException = true;
    //}

    //if(!isException) {
    //  TEST_FAIL("BaseTest String construct test11");
    //  break;
    //}

    TEST_OK("BaseTest String construct test12");
    break;
  }

  //_String::_String(char *v,int start,int length)
  while(1) {
    String str = createString("abc",1,2);
    if(!str->equals("bc")) {
        TEST_FAIL("BaseTest String construct test13");
        break;
    }

    String str2 = createString("abc",2,1);
    if(!str2->equals("c")) {
        TEST_FAIL("BaseTest String construct test14");
        break;
    }

    bool isException = false;
    try {
      String str3 = createString("abc",2,2);
    } catch(...) {
      isException = true;
    }

    if(!isException) {
      TEST_FAIL("BaseTest String construct test15");
      break;
    }

    TEST_OK("BaseTest String construct test16");
    break;
  }

  //_String(Integer v);
  while(1) {
    Integer v1 = createInteger(123);
    String str1 = createString(v1);
    if(!str1->equals("123")) {
      TEST_FAIL("BaseTest String construct test17");
      break;
    }

    //Integer v2;
    //bool isException = false;
    //try {
    //    String str2 = createString(v2);
    //} catch(InitializeException e) {
    //    isException = true;
    //}

    //if(!isException) {
    //  TEST_FAIL("BaseTest String construct test18");
    //  break;
    //}
    TEST_OK("BaseTest String construct test18");
    break;
  }

  //_String::_String(Boolean v)
  while(1) {
    Boolean v1 = createBoolean(true);
    String str1 = createString(v1);
    if(!str1->equals("true")) {
      TEST_FAIL("BaseTest String construct test19");
      break;
    }

    Boolean v2 = createBoolean(false);
    String str2 = createString(v2);
    if(!str2->equals("false")) {
      TEST_FAIL("BaseTest String construct test20");
      break;
    }

    //Boolean v3;
    //bool isException = false;
    //try {
    //    String str3 = createString(v3);
    //}catch(InitializeException e) {
    //    isException = true;
    //}

    //if(!isException) {
    //  TEST_FAIL("BaseTest String construct test21");
    //  break;
    //}

    TEST_OK("BaseTest String construct test22");
    break;
  }

  //_String(Float v);
  while(1) {
    Float v1 = createFloat(1.2f);
    String str1 = createString(v1);
    if(!str1->contains("1.2")) {
      TEST_FAIL("BaseTest String construct test23");
      break;
    }

    Float v2 = createFloat(1.3f);
    String str2 = createString(v2);
    if(!str2->contains("1.")) {
      TEST_FAIL("BaseTest String construct test24");
      break;
    }

    //Float v3;
    //bool isException = false;
    //try {
    //    String str3 = createString(v3);
    //}catch(InitializeException e) {
    //    isException = true;
    //}

    //if(!isException) {
    //  TEST_FAIL("BaseTest String construct test25");
    //  break;
    //}

    TEST_OK("BaseTest String construct test26");
    break;
  }

  //    _String(Double v);
  while(1) {
    Double v1 = createDouble(1.2);
    String str1 = createString(v1);
    if(!str1->equals("1.2")) {
      TEST_FAIL("BaseTest String construct test27");
      break;
    }

    Double v2 = createDouble(1.3);
    String str2 = createString(v2);
    if(!str2->equals("1.3")) {
      TEST_FAIL("BaseTest String construct test28");
      break;
    }

    /*
    Double v3;
    bool isException = false;
    try {
        String str3 = createString(v3);
    }catch(InitializeException e) {
        isException = true;
    }

    if(!isException) {
      TEST_FAIL("BaseTest String construct test29");
      break;
    }*/

    TEST_OK("BaseTest String construct test30");
    break;
  }

  //_String(Long v);
  while(1) {
    Long v1 = createLong(1234567);
    String str1 = createString(v1);
    if(!str1->equals("1234567")) {
      TEST_FAIL("BaseTest String construct test31");
      break;
    }

    Long v2 = createLong(345678);
    String str2 = createString(v2);
    if(!str2->equals("345678")) {
      TEST_FAIL("BaseTest String construct test32");
      break;
    }
/*
    Long v3;
    bool isException = false;
    try {
        String str3 = createString(v3);
    }catch(InitializeException e) {
        isException = true;
    }

    if(!isException) {
      TEST_FAIL("BaseTest String construct test33");
      break;
    }
*/
    TEST_OK("BaseTest String construct test34");
    break;
  }

  //_String(int v);
  while(1) {
    int v = 100;
    String s = createString(v);
    if(!s->equals("100")) {
      TEST_FAIL("BaseTest String construct test35");
      break;
    }

    TEST_OK("BaseTest String construct test36");
    break;
  }

  //_String(bool v);
  while(1) {
    bool v = false;
    String s = createString(v);
    if(!s->equals("false")) {
      TEST_FAIL("BaseTest String construct test37");
      break;
    }

    bool v2 = true;
    String s2 = createString(v2);
    if(!s2->equals("true")) {
      TEST_FAIL("BaseTest String construct test38");
      break;
    }

    TEST_OK("BaseTest String construct test39");
    break;
  }

  //_String(float v);
  while(1) {
    float v = 100.1f;
    String s = createString(v);
    if(!s->contains("100.")) {
      TEST_FAIL("BaseTest String construct test40");
      break;
    }

    TEST_OK("BaseTest String construct test41");
    break;
  }

  //_String(double v);
  while(1) {
    double v = 100.01;
    String s = createString(v);
    if(!s->equals("100.01")) {
      TEST_FAIL("BaseTest String construct test42");
      break;
    }

    TEST_OK("BaseTest String construct test43");
    break;
  }

  //_String(long v);
  while(1) {
    long v = 100011;
    String s = createString(v);
    if(!s->equals("100011")) {
      TEST_FAIL("BaseTest String construct test44");
      break;
    }

    TEST_OK("BaseTest String construct test45");
    break;
  }

  //test replaceAll()
  while(1) {
      String str = createString("AaAbAc");
      String str2 = str->replaceAll("A","t");
      //TEST_FAIL("BaseTest after replace is %s \n",str2->toChars());
      if(!str2->equals("tatbtc")) {
        TEST_FAIL("BaseTest String replaceAll test1");
        break;
      }

      TEST_OK("BaseTest String replaceAll test1");
      break;
  }

  //void split(String v,T t);
  while(1) {
    String abc1 = "1,2,3,4,5";
    ArrayList<String> list = abc1->split(",");
    if(list->size() != 5) {
      TEST_FAIL("BaseTest String split test1");
      break;
    }

    if(!list->get(0)->equals("1")
      ||!list->get(1)->equals("2")
      ||!list->get(2)->equals("3")
      ||!list->get(3)->equals("4")
      ||!list->get(4)->equals("5")) {
      TEST_FAIL("BaseTest String split test2");
      break;
    }

    String abc2 = "a,b,c";
    ArrayList<String> list2 = abc2->split("||");

    if(list2 != nullptr && list2->size() != 0) {
      TEST_FAIL("BaseTest String split test3");
      break;
    }

#if 0
    //this case cannot be excuted
    String abc3;
    ArrayList<String> list3 = createArrayList<String>();
    abc3->split("||",list3);
    if(list3->size() != 0) {
      TEST_FAIL("BaseTest String split test4");
      break;
    }
#endif

    TEST_OK("BaseTest String split test5");
    break;

  }

  //const char * toChars();
  while(1) {
    String abc = "hello world";
    const char *p = abc->toChars();
    if(strcmp(p,"hello world") != 0) {
      TEST_FAIL("BaseTest String toChars test1");
      break;
    }

    TEST_OK("BaseTest String toChars test1");
    break;
  }

  //String subString(int start,int length);
  while(1) {
    String abc = "helloworld";
    String str = abc->subString(1,3);
    if(!str->equals("ell")) {
      TEST_FAIL("BaseTest String subString test1");
      break;
    }

    String str2 = nullptr;
    try {
        abc->subString(20,30);
    } catch(...){}

    if(str2 != nullptr) {
      TEST_FAIL("BaseTest String subString test2");
      break;
    }

    String str3 = nullptr;
    try {
      str3 = abc->subString(1,100);
    }catch(...) {}

    if(str3 != nullptr) {
      TEST_FAIL("BaseTest String subString test3");
      break;
    }

    String str4 = abc->subString(5,2);
    if(!str4->equals("wo")) {
      TEST_FAIL("BaseTest String subString test4");
      break;
    }

    TEST_OK("BaseTest String subString test");
    break;

  }

  //char charAt(int index);
  while(1) {
    String abc = "hello world";
    //char *p = abc->toChars();
    if(abc->charAt(1) != 'e') {
      TEST_FAIL("BaseTest String charAt test1");
      break;
    }

    bool isException = false;
    try {
        abc->charAt(90);
    } catch(ArrayIndexOutOfBoundsException e) {
        isException = true;
    }

    if(!isException) {
      TEST_FAIL("BaseTest String charAt test2");
      break;
    }

    TEST_OK("BaseTest String charAt test3");
    break;
  }

  //bool contains(String val);
  while(1) {
    String abc = "abcd";
    if(!abc->contains("bc")) {
      TEST_FAIL("BaseTest String contains test1 ");
      break;
    }
/*
    String abc2;
    try {
        if(abc->contains(abc2)) {
            TEST_FAIL("BaseTest String contains test2 ");
            break;
        } else {
            TEST_FAIL("BaseTest String contains test2 ");
            break;
        }
    } catch(NullPointerException e) {

    }
*/
    TEST_OK("BaseTest String contains test3");
    break;
  }

  //String trim();
  while(1) {
    String abc = " a b c ";
    String abc2 = abc->trim();
    if(abc2->equals(abc)) {
      TEST_FAIL("BaseTest String trim test1");
      break;
    }

    if(!abc2->equals("a b c")) {
      TEST_FAIL("BaseTest String trim test2");
      break;
    }

    TEST_OK("BaseTest String trim test3");
    break;
  }

  //String trimALl()
  while(1) {
    String abc = " a b c d ";
    String abc2 = abc->trimAll();
    if(!abc2->equals("abcd")) {
      TEST_FAIL("BaseTest String trimAll test1");
      break;
    }
    TEST_OK("BaseTest String trimALL test1");
    break;
  }

  //int size();
  while(1) {
    String abc = "abcd";
    if(abc->size() != 4) {
      TEST_FAIL("BaseTest String size test1");
      break;
    }

    String abc2 = "";
    //TEST_FAIL("BaseTest abc2 size is %d \n",abc2->size());
    if(abc2->size() != 0) {
      TEST_FAIL("BaseTest String size test2");
      break;
    }

#if 0
//null point cannot access
    String abc3 = nullptr;
    if(abc->size() != 0) {
      TEST_FAIL("BaseTest String size test3");
      break;
    }
#endif

    TEST_OK("BaseTest String size test3");
    break;
  }

  //int indexOf(String v);
  while(1) {
    String abc = "abcde";
    int index = abc->indexOf("cd");
    if(index != 2) {
      TEST_FAIL("BaseTest String indexOf test1");
      break;
    }

    index = abc->indexOf("q");
    if(index != -1) {
      TEST_FAIL("BaseTest String indexOf test2");
      break;
    }
/*
    index = abc->indexOf(nullptr);
    if(index != -1) {
      TEST_FAIL("BaseTest String indexOf test3");
      break;
    }
*/
    TEST_OK("BaseTest String indexOf test4");
    break;
  }

  //    void append(String s);
  while(1) {
    String abc = "abcd";
    String abc2 = "efg";
    String abc3 = abc->append(abc2);

    if(!abc3->equals("abcdefg")) {
      TEST_FAIL("BaseTest String append test1");
      break;
    }


    String abc6 = "a";
    String abc7 = abc6->append(nullptr);
    if(!abc7->equals("a")) {
      TEST_FAIL("BaseTest String append test3");
      break;
    }

    TEST_OK("BaseTest String append test3");
    break;

  }


  //    String append(const char *p);
  while(1) {
      String abc = "aaa";
      const char* t1 = "b";
      String r1 = abc->append(t1);
      if(!r1->equals("aaab")) {
        TEST_FAIL("BaseTest String append test4");
        break;
      }
      if(!abc->equals("aaa")) {
        TEST_FAIL("BaseTest String append test5");
        break;
      }

      TEST_OK("BaseTest String append test5");
      break;
  }


  //Integer toInteger();
  while(1) {
    String abc ="123";
    Integer t1 = abc->toInteger();

    if(!t1->equals(123)) {
      TEST_FAIL("BaseTest String toInteger test1");
      break;
    }

    String abc2 = "abc";
    Integer t2 = abc2->toInteger();
    if(t2 != nullptr) {
      TEST_FAIL("BaseTest String toInteger test2");
      break;
    }

    TEST_OK("BaseTest String toInteger test3");
    break;
  }

  //Boolean toBoolean();
  while(1) {
    String abc = "true";
    Boolean b1 = abc->toBoolean();
    if(!b1->toValue()) {
        TEST_FAIL("BaseTest String toBoolean test1");
        break;
    }

    String abc2 = "false";
    Boolean b2 = abc2->toBoolean();
    if(b2->toValue()) {
        TEST_FAIL("BaseTest String toBoolean test2");
        break;
    }

    String abc3 = "aaa";
    Boolean b3 = abc3->toBoolean();
    if(b3 != nullptr) {
      TEST_FAIL("BaseTest String toBoolean test3");
      break;
    }

    TEST_OK("BaseTest String toBoolean test4");
    break;
  }

  //Float toFloat();
  while(1) {
    String abc = "1.234567";
    Float f = abc->toFloat();
    if(f->toValue() != 1.23457) {
       TEST_FAIL("BaseTest String toFloat test1");
       break;
    }

    String abc2 = "a";
    Float f2 = abc2->toFloat();
    if(f2 != nullptr) {
      TEST_FAIL("BaseTest String toFloat test2");
      break;
    }

    TEST_OK("BaseTest String toFloat test3");
    break;
  }

  //    Double toDouble();
  while(1) {
    String abc = "1.23689575";
    Double f = abc->toDouble();
    //std::out<<"double f is "<<f<<std::endl;
    //TEST_FAIL("BaseTest double f is %lf \n",f->toValue());
    if(f->toValue() != 1.23689575) {
      //TODO
       TEST_FAIL("BaseTest String toDouble test1");
       break;
    }

    String abc2 = "a";
    Double f2 = abc2->toDouble();
    if(f2 != nullptr) {
      TEST_FAIL("BaseTest String toDouble test2");
      break;
    }

    TEST_OK("BaseTest String toDouble test3");
    break;
  }

  //     int toBasicInt();
  while(1) {
    String abc = "123";
    int val = abc->toBasicInt();
    if(val != 123) {
      TEST_FAIL("BaseTest String toBasicInt test1");
      break;
    }

    String abc2 = "1a b";
    try{
        int val2 = abc2->toBasicInt();
        TEST_FAIL("BaseTest String toBasicInt test2");
    } catch(TransformException e) {}

    TEST_OK("BaseTest String toBasicInt test3");
    break;
  }

  //    bool toBasicBool();
  while(1) {
    String abc = "true";
    bool val = abc->toBasicBool();
    if(!val) {
      TEST_FAIL("BaseTest String toBasicBool test1");
      break;
    }

    String abc2 = "True";
    bool val2 = abc2->toBasicBool();
    if(!val2) {
      TEST_FAIL("BaseTest String toBasicBool test2");
      break;
    }

    String abc3 = "false";
    bool val3 = abc3->toBasicBool();
    if(val3) {
      TEST_FAIL("BaseTest String toBasicBool test3");
      break;
    }

    String abc4 = "fAlse";
    bool val4 = abc4->toBasicBool();
    if(val4) {
      TEST_FAIL("BaseTest String toBasicBool test4");
      break;
    }

    String abc5 = "ggg";
    try {
    bool val5 = abc5->toBasicBool();
       TEST_FAIL("BaseTest String toBasicBool test5");
    } catch(TransformException e) {

    }

    TEST_OK("BaseTest String toBasicBool test6");
    break;
  }

  //float toBasicFloat();
  while(1) {
    String abc1 = "1.222";
    float v1 = abc1->toBasicFloat();
    if(v1 != 1.222f) {
      TEST_FAIL("BaseTest String toBasicFloat test1");
      break;
    }

    String abc2 = "1";
    float v2 = abc2->toBasicFloat();
    if(v2 != 1.0f) {
      TEST_FAIL("BaseTest String toBasicFloat test2");
      break;
    }

    String abc3 = "1ab";
    try {
        float v3 = abc3->toBasicFloat();
        TEST_FAIL("BaseTest String toBasicFloat test3");
    } catch(TransformException e) {}

    TEST_OK("BaseTest String toBasicFloat test4");
    break;
  }

  //double toBasicDouble();
  while(1) {
    String abc1 = "1.222";
    double v1 = abc1->toBasicDouble();
    if(v1 != 1.222) {
      TEST_FAIL("BaseTest String toBasicDouble test1");
      break;
    }

    String abc2 = "1";
    double v2 = abc2->toBasicDouble();
    if(v2 != 1.0) {
      TEST_FAIL("BaseTest String toBasicDouble test2");
      break;
    }

    String abc3 = "1ab";
    try {
        double v3 = abc3->toBasicDouble();
        TEST_FAIL("BaseTest String toBasicDouble test3");
    } catch(TransformException e) {}

    TEST_OK("BaseTest String toBasicDouble test4");
    break;
  }

  //    static String valueOf(Integer v);
  while(1) {
    Integer v1 = createInteger(100);
    String a1 = createString(v1);
    if(!a1->equals("100")) {
      TEST_FAIL("BaseTest String valueOf test1");
      break;
    }
/*
    Integer v2;
    String a2 = createString(v2);
    if(a2 != nullptr) {
      TEST_FAIL("BaseTest String valueOf test2");
      break;
    }
*/
    TEST_OK("BaseTest String valueOf test3");
    break;
  }

  //    static String valueOf(Boolean v);
  while(1) {
    Boolean v1 = createBoolean(true);
    String a1 = createString(v1);
    if(!a1->equals("true")) {
      TEST_FAIL("BaseTest String valueOf test3");
      break;
    }

    Boolean v2 = createBoolean(false);
    String a2 = createString(v2);
    if(!a2->equals("false")) {
      TEST_FAIL("BaseTest String valueOf test4");
      break;
    }
/*
    Boolean v3;
    String a3 = createString(v3);
    if(a3 != nullptr) {
      TEST_FAIL("BaseTest String valueOf test5");
      break;
    }
*/
    TEST_OK("BaseTest String valueOf test6");
    break;
  }

  //static String valueOf(Double v);
  while(1) {
    Double v1 = createDouble(100);
    String a1 = createString(v1);
    if(!a1->equals("100")) {
      //TODO
      TEST_FAIL("BaseTest String valueOf test7");
      break;
    }

/*
    Double v2;
    String a2 = createString(v2);
    if(a2 != nullptr) {
      TEST_FAIL("BaseTest String valueOf test8");
      break;
    }
*/
    TEST_OK("BaseTest String valueOf test9");
    break;
  }


  //static String valueOf(Float v);
  while(1) {
    Float v1 = createFloat(100);
    String a1 = createString(v1);
    if(!a1->equals("100")) {
      TEST_FAIL("BaseTest String valueOf test10");
      break;
    }
/*
    Float v2;
    String a2 = createString(v2);
    if(a2 != nullptr) {
      TEST_FAIL("BaseTest String valueOf test11");
      break;
    }
*/
    TEST_OK("BaseTest String valueOf test12");
    break;
  }

  //static String valueOf(int v);
  while(1) {
    int i = -1;
    String v1 = createString(i);
    if(!v1->equals("-1")) {
      TEST_FAIL("BaseTest String valueOf test13");
      break;
    }

    int i2 = 10;
    String v2 = createString(i2);
    if(!v2->equals("10")) {
      TEST_FAIL("BaseTest String valueOf test14");
      break;
    }

    TEST_OK("BaseTest String valueOf test15");
    break;
  }

  //  static String valueOf(bool v);
  while(1) {
    bool i = false;
    String v1 = createString(i);
    if(!v1->equals("false")) {
      TEST_FAIL("BaseTest String valueOf test16");
      break;
    }

    bool i2 = true;
    String v2 = createString(i2);
    if(!v2->equals("true")) {
      TEST_FAIL("BaseTest String valueOf test17");
      break;
    }

    TEST_OK("BaseTest String valueOf test18");
    break;
  }

  //  static String valueOf(double v);
  while(1) {
    double i = -1.0;
    String v1 = createString(i);
    if(!v1->equals("-1")) {
      TEST_FAIL("BaseTest String valueOf test19");
      break;
    }

    double i2 = 10;
    String v2 = createString(i2);
    //TEST_FAIL("BaseTest v2 is %s \n",v2->toChars());
    if(!v2->equals("10")) {
      TEST_FAIL("BaseTest String valueOf test20");
      break;
    }

    TEST_OK("BaseTest String valueOf test21");
    break;
  }

  //  static String valueOf(float v);
  while(1) {
    float i = -1.0f;
    String v1 = createString(i);
    if(!v1->equals("-1")) {
      TEST_FAIL("BaseTest String valueOf test22");
      break;
    }

    float i2 = 10;
    String v2 = createString(i2);
    //TEST_FAIL("BaseTest v2 is %s \n",v2->toChars());
    if(!v2->equals("10")) {
      TEST_FAIL("BaseTest String valueOf test23");
      break;
    }

    TEST_OK("BaseTest String valueOf test24");
    break;
  }

  //  static String valueOf(char *p);
  while(1) {
    const char *p1 = "abc";
    String s1 = createString(p1);
    if(!s1->equals("abc")) {
      TEST_FAIL("BaseTest String valueOf test25");
      break;
    }

    const char *p2 = nullptr;
    String s2 = nullptr;

    try {
      s2 = createString(p2);
    } catch(...) {}
    
    if(s2 != nullptr) {
        TEST_FAIL("BaseTest String valueOf test26");
        break;
    }

    TEST_OK("BaseTest String valueOf test27");
    break;
  }

  //equals(String s);
  while(1) {
    String s1 = "abc";
    String s2 = "abc";
    if(!s1->equals(s2)) {
      TEST_FAIL("BaseTest String equals test1 ");
      break;
    }

    String s3 = "dd";
    if(s1->equals(s3)) {
      TEST_FAIL("BaseTest String equals test2 ");
      break;
    }
/*
    String s4;
    if(s1->equals(s4)) {
      TEST_FAIL("BaseTest String equals test3 ");
      break;
    }
*/
    TEST_OK("BaseTest String equals test4 ");
    break;
  }

  //equals(String s);
  while(1) {
    String s1 = "abc";
    std::string s2 = "abc";
    if(!s1->equals(s2)) {
      TEST_FAIL("BaseTest String equals test5 ");
      break;
    }

    std::string s3 = "dd";
    if(s1->equals(s3)) {
      TEST_FAIL("BaseTest String equals test6 ");
      break;
    }

    std::string s4;
    if(s1->equals(s4)) {
      TEST_FAIL("BaseTest String equals test7 ");
      break;
    }

    TEST_OK("BaseTest String equals test8 ");
    break;
  }

  //  bool equals(const char *s);
  while(1) {
    String s1 = "abc";
    const char * s2 = "abc";
    if(!s1->equals(s2)) {
      TEST_FAIL("BaseTest String equals test9 ");
      break;
    }

    const char *s3 = "dd";
    if(s1->equals(s3)) {
      TEST_FAIL("BaseTest String equals test10 ");
      break;
    }
/*
    const char *s4 = nullptr;
    if(s1->equals(s4)) {
      TEST_FAIL("BaseTest String equals test11 ");
      break;
    }
*/
    TEST_OK("BaseTest String equals test12 ");
    break;
  }

  //std::string getStdString();
  //while(1) {
    //TODO
  //}

  //String toLowerCase();
  while(1) {
    String abc = "123AbC";
    String t1 = abc->toLowerCase();
    if(!t1->equals("123abc")) {
      TEST_FAIL("BaseTest String toLowerCase test1 ");
      break;
    }

    String abc2 = "123";
    String t2 = abc2->toLowerCase();
    if(!t2->equals("123")) {
      TEST_FAIL("BaseTest String toLowerCase test2 ");
      break;
    }

    String abc3 = "123 ABD";
    String t3 = abc3->toLowerCase();
    if(!t3->equals("123 abd")) {
      TEST_FAIL("BaseTest String toLowerCase test3 ");
      break;
    }

    TEST_OK("BaseTest String toLowerCase test4 ");
    break;
  }

  //    String toUpperCase();
  while(1) {
    String abc = "abc";
    String t1 = abc->toUpperCase();
    //TEST_FAIL("BaseTest t1 is %s \n",t1->toChars());
    if(!t1->equals("ABC")) {
      TEST_FAIL("BaseTest String toUpperCase test1 ");
      break;
    }

    String abc2 = "123";
    String t2 = abc2->toUpperCase();
    if(!t2->equals("123")) {
      TEST_FAIL("BaseTest String toUpperCase test2 ");
      break;
    }

    String abc3 = "123 abc";
    String t3 = abc3->toUpperCase();
    if(!t3->equals("123 ABC")) {
      TEST_FAIL("BaseTest String toUpperCase test3 ");
      break;
    }

    TEST_OK("BaseTest String toUpperCase test4 ");
    break;
  }

  //test replaceFirst()
  while(1) {
      String str = createString("AaAbAc");
      String str2 = str->replaceFirst("A","t");
      //TEST_FAIL("BaseTest after replace is %s \n",str2->toChars());
      if(!str2->equals("taAbAc")) {
        TEST_FAIL("BaseTest String replaceFirst test1");
        break;
      }

      TEST_OK("BaseTest String replaceFirst test1");
      break;
  }


  //test equalsIgnoreCase()
  while(1) {
      String str = createString("AaAbAc");
      if(!str->equalsIgnoreCase("aaabAC")) {
        TEST_FAIL("BaseTest String equalsIgnoreCase test1");
        break;
      }
/*
      String str2;
      try {
          str->equalsIgnoreCase(str2);
          TEST_FAIL("BaseTest String equalsIgnoreCase test2");
      } catch(NullPointerException e) {}
*/
      TEST_OK("BaseTest String equalsIgnoreCase test3");
      break;
  }

  //int indexOfIgnoreCase(String str);
  while(1) {
     String str1 = createString("aabbccdd");
     String str2 = createString("AA");
     if(str1->indexOfIgnoreCase(str2) != 0) {
       TEST_FAIL("BaseTest String indexOfIgnoreCase test1");
       break;
     }
/*
     String str3;
     try {
       str1->indexOfIgnoreCase(str3);
       TEST_FAIL("BaseTest String indexOfIgnoreCase test2");
     } catch(NullPointerException e) {}
*/
     TEST_OK("BaseTest String indexOfIgnoreCase test3");
     break;
  }

  //containsIgnoreCase
  while(1) {
      String str = createString("AaAbAc");
      if(!str->containsIgnoreCase("ab")) {
        TEST_FAIL("BaseTest String containsIgnoreCase test1");
        break;
      }

      if(str->containsIgnoreCase("dd")) {
        TEST_FAIL("BaseTest String containsIgnoreCase test2");
        break;
      }

      TEST_OK("BaseTest String containsIgnoreCase test1");
      break;
  }

  //isEmpty()
  while(1) {
    String abc = "";
    if(!abc->isEmpty()) {
      TEST_FAIL("BaseTest String isEmpty test1");
      break;
    }

    TEST_OK("BaseTest String isEmpty test2");
    break;
  }

  //    bool endsWith(String s);
  while(1) {
    String abc = "abc";
    if(!abc->endsWith("c")) {
      TEST_FAIL("BaseTest String endsWith test1");
      break;
    }

    if(abc->endsWith("f")) {
      TEST_FAIL("BaseTest String endsWith test2");
      break;
    }
/*
    try {
      abc->endsWith(nullptr);
      TEST_FAIL("BaseTest String endsWith test3");
    } catch(NullPointerException e) {}
*/
    TEST_OK("BaseTest String endsWith test4");
    break;
  }

  //    int lastIndexOf(String v);
  while(1) {
    String abc = "aabbccaaaa";
    int index = abc->lastIndexOf("aa");
    //TEST_FAIL("BaseTest index is %d \n",index);
    if(index != 9) {
      TEST_FAIL("BaseTest String lastIndexof test1");
      break;
    }

    int index2 = abc->lastIndexOf("zz");
    if(index2 != -1) {
      TEST_FAIL("BaseTest String lastIndexof test2");
      break;
    }
/*
    try {
        abc->lastIndexOf(nullptr);
        TEST_FAIL("BaseTest String lastIndexof test3");
    } catch(NullPointerException e) {}
*/
    TEST_OK("BaseTest String lastIndexof test4");
    break;
  }

  //  bool startsWith(String v);
  while(1) {
    String abc = "aabbccaa";
    if(!abc->startsWith("aa")) {
      TEST_FAIL("BaseTest String startsWith test1");
      break;
    }

    if(abc->startsWith("bb")) {
      TEST_FAIL("BaseTest String startsWith test2");
      break;
    }
/*
    try {
        abc->startsWith(nullptr);
        TEST_FAIL("BaseTest String startsWith test3");
    } catch(NullPointerException e) {}
*/
    TEST_OK("BaseTest String startsWith test4");
    break;
  }

}
