#include <iostream>
#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ArrayList.hpp"
#include "Integer.hpp"
#include "String.hpp"
#include "NullPointerException.hpp"
#include "InitializeException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testArrayList_String() {
  //[ArrayList<String> Test Start]

      //[ArrayList<String> Test {add(char *val)} Start]
      while(1) {
          ArrayList<String> list = ArrayList<String>::New();
          list->add(String::New("a"));
          list->add(String::New("b"));
          list->add(String::New("c"));
          if(!list->get(0)->sameAs("a")
          || !list->get(1)->sameAs("b")
          || !list->get(2)->sameAs("c")) {
              TEST_FAIL("[ArrayList<String> Test {add(char * val)} case1]");
              break;
          }

          int size = list->size();
          String pp;
          list->add(pp);
          if(list->size() == size) {
            TEST_FAIL("[ArrayList<String> Test {add(char * val)} case2]");
            break;
          }

          TEST_OK("[ArrayList<String> Test {add(char * val)}]");
          break;
      }

      //[ArrayList<String> Test {add(std::string v)} Start]
      while(1) {
          ArrayList<String> list = ArrayList<String>::New();

          std::string s1("a");
          std::string s2("b");
          std::string s3("c");

          list->add(String::New(s1));
          list->add(String::New(s2));
          list->add(String::New(s3));

          if(!list->get(0)->sameAs("a")
          || !list->get(1)->sameAs("b")
          || !list->get(2)->sameAs("c")) {
              TEST_FAIL("[ArrayList<String> Test {add(std::string val) case1]");
              break;
          }

          TEST_OK("[ArrayList<String> Test {add(std::string val)]");
          break;
      }

      //[ArrayList<String> Test {add(String val)} Start]
      while(1) {
        ArrayList<String> list = ArrayList<String>::New();
        list->add(String::New("a"));
        list->add(String::New("b"));
        list->add(String::New("c"));
        if(!list->get(0)->sameAs("a")
        || !list->get(1)->sameAs("b")
        || !list->get(2)->sameAs("c")) {
            TEST_FAIL("[ArrayList<String> Test {add(String val)} case1]");
            break;
        }

        TEST_OK("[ArrayList<String> Test {add(String val)}]");
        break;
      }

      //[ArrayList<String> Test {add(ArrayList<String> list)} Start]
      while(1) {
        ArrayList<String> list = ArrayList<String>::New();
        list->add(String::New("a"));
        list->add(String::New("b"));

        ArrayList<String> list2 = ArrayList<String>::New();
        list2->add(String::New("c"));
        list2->add(String::New("d"));

        list->add(list2);

        if(!list->get(0)->sameAs("a")
        || !list->get(1)->sameAs("b")
        || !list->get(2)->sameAs("c")
        || !list->get(3)->sameAs("d")) {
            TEST_FAIL("[ArrayList<String> Test {add(ArrayList<String> list)}]");
            break;
        }

        TEST_OK("[ArrayList<String> Test {add(ArrayList<String> list)}]");
        break;
      }

      //[ArrayList<String> Test {clear()} Start]
      while(1) {
        ArrayList<String> list = ArrayList<String>::New();
        list->add(String::New("1"));
        int size = list->size();
        list->clear();
        if(list->size() != 0 || size != 1) {
          TEST_FAIL("[ArrayList<String> Test {clear()}]");
          break;
        }

        TEST_OK("[ArrayList<String> Test {clear()}]");
        break;
      }

      //[ArrayList<String> Test {remove(int index)} Start]
      while(1) {
        ArrayList<String> list = ArrayList<String>::New();
        list->add(String::New("a"));
        list->add(String::New("b"));
        list->add(String::New("c"));

        String v = list->removeAt(1);
        if(!v->sameAs("b")) {
          TEST_FAIL("[ArrayList<String> Test {remove(int index)} case1]");
          break;
        }

        if(list->size() != 2) {
          TEST_FAIL("[ArrayList<String> Test {remove(int index)} case2]");
          break;
        }

        bool isException = false;
        try {
            v = list->removeAt(5);
        } catch(ArrayIndexOutOfBoundsException e) {
            isException = true;
        }

        if(!isException) {
          TEST_FAIL("[ArrayList<String> Test {remove(int index)} case3]");
          break;
        }

        v = list->removeAt(0);
        v = list->removeAt(0);
        isException = false;
        try {
            v = list->removeAt(0);
            v = list->removeAt(0);
        } catch(ArrayIndexOutOfBoundsException e) {
           isException = true;
        }

        if(v == nullptr || !isException) {
          TEST_FAIL("[ArrayList<String> Test {remove(int index)} case4]");
          break;
        }

        isException = false;
        try {
            v = list->removeAt(-1);
        } catch(ArrayIndexOutOfBoundsException e) {
            isException = true;
        }

        if(!isException) {
          TEST_FAIL("[ArrayList<String> Test {remove(int index)} case5]");
          break;
        }

        TEST_OK("[ArrayList<String> Test {remove(int index)}]");
        break;
      }

      //[ArrayList<String> Test {remove(String v)} Start]
      while(1) {
        ArrayList<String> list = ArrayList<String>::New();
        list->add(String::New("a"));
        list->add(String::New("b"));
        list->add(String::New("c"));

        int result = list->remove("a");
        if(result == -1) {
          TEST_FAIL("[ArrayList<String> Test {remove(String v)} case1]");
          break;
        }

        if(list->size() != 2) {
          TEST_FAIL("[ArrayList<String> Test {remove(String v)} case2]");
          break;
        }

        String s;
        result = list->remove(s);
        if(result != -1) {
          TEST_FAIL("[ArrayList<String> Test {remove(String v)} case3]");
          break;
        }

        if(list->size() != 2) {
          TEST_FAIL("[ArrayList<String> Test {remove(String v)} case4]");
          break;
        }

        TEST_OK("[ArrayList<String> Test {remove(String v)}]");
        break;
      }

      //[ArrayList<String> Test {indexOf(String v)} Start]
      while(1) {
        ArrayList<String> list = ArrayList<String>::New();
        list->add(String::New("a"));
        list->add(String::New("b"));
        list->add(String::New("c"));

        if(list->indexOf("a") < 0
        ||list->indexOf("b") < 0
        ||list->indexOf("c") < 0) {
          TEST_FAIL("[ArrayList<String> Test {indexOf(String v)} case1]");
          break;
        }

        String s;
        int index = list->indexOf(s);
        if(list->indexOf(s) != -1) {
          TEST_FAIL("[ArrayList<String> Test {indexOf(String v)} case2]");
          break;
        }

        if(list->indexOf("d") != -1) {
          TEST_FAIL("[ArrayList<String> Test {indexOf(String v)} case3]");
          break;
        }

        TEST_OK("[ArrayList<String> Test {indexOf(String v)}]");
        break;
      }
      //[ArrayList<String> Test {set(int index,String val)} Start]
      while(1) {
        ArrayList<String> list = ArrayList<String>::New();
        list->add(String::New("a"));
        list->add(String::New("b"));
        list->add(String::New("c"));

        list->set(0,"d");
        if(!list->get(0)->sameAs("d")
        || !list->get(1)->sameAs("b")
        || !list->get(2)->sameAs("c")) {
            TEST_FAIL("[ArrayList<String> Test {set(int index,String val)} case1]");
            break;
        }

        bool isException = false;
        try {
          list->set(100,"a");
        } catch(ArrayIndexOutOfBoundsException e) {
             isException = true;
        }

        if(!isException) {
          TEST_FAIL("[ArrayList<String> Test {set(int index,String val)} case2]");
          break;
        }

        isException = false;
        try {
             list->set(-1,"a");
        } catch(ArrayIndexOutOfBoundsException e) {
             isException = true;
        }

        if(!isException) {
          TEST_FAIL("[ArrayList<String> Test {set(int index,String val)} case3]");
          break;
        }

        TEST_OK("[ArrayList<String> Test {set(int index,String val)}]");
        break;
      }

      //[ArrayList<String> Test {get(int index)} Start]
      while(1) {
        ArrayList<String> list = ArrayList<String>::New();
        list->add(String::New("a"));
        list->add(String::New("b"));
        list->add(String::New("c"));
        if(!list->get(0)->sameAs("a")
        ||!list->get(1)->sameAs("b")
        ||!list->get(2)->sameAs("c")) {
          TEST_FAIL("[ArrayList<String> Test {get(int index)} case1]");
          break;
        }

        bool isException = false;
        try {
          list->get(-1);
        } catch(ArrayIndexOutOfBoundsException e) {
           isException = true;
        }

        if(!isException) {
            TEST_FAIL("[ArrayList<String> Test {get(int index)} case2]");
            break;
        }

        isException = false;
        try {
          String str2 = list->get(1000);
        } catch(ArrayIndexOutOfBoundsException e) {
             isException = true;
        }

        if(!isException) {
          TEST_FAIL("[ArrayList<String> Test {get(int index)} case3]");
          break;
        }

        TEST_OK("[ArrayList<String> Test {get(int index)}]");
        break;
      }
      //[ArrayList<String> Test {insert(int index,String val)} Start]
      while(1) {
        ArrayList<String> list = ArrayList<String>::New();
        list->add(String::New("a"));
        list->add(String::New("b"));
        list->add(String::New("c"));

        list->insert(1,String::New("d"));
        if(!list->get(0)->sameAs("a")
        ||!list->get(1)->sameAs("d")
        ||!list->get(2)->sameAs("b")
        ||!list->get(3)->sameAs("c")) {
          TEST_FAIL("[ArrayList<String> Test {insert(int index,String val)} case1]");
          break;
        }

        bool isException = false;
        try {
            list->insert(50,String::New("d"));
        } catch(ArrayIndexOutOfBoundsException e) {
               isException = true;
        }

        if(!isException) {
          TEST_FAIL("[ArrayList<String> Test {insert(int index,String val)} case2]");
          break;
        }

        isException = false;
        try {
            list->insert(-1,String::New("d"));
        }catch(ArrayIndexOutOfBoundsException e) {
            isException = true;
        }

        if(!isException) {
          TEST_FAIL("[ArrayList<String> Test {insert(int index,String val)} case3]");
          break;
        }

        TEST_OK("[ArrayList<String> Test {insert(int index,String val)}]");
        break;
      }

      //[ArrayList<String> Test {insert(int index,char* val)} Start]
      while(1) {
        ArrayList<String> list = ArrayList<String>::New();
        list->add(String::New("a"));
        list->add(String::New("b"));
        list->add(String::New("c"));

        list->insert(1,String::New("d"));
        if(!list->get(0)->sameAs("a")
        ||!list->get(1)->sameAs("d")
        ||!list->get(2)->sameAs("b")
        ||!list->get(3)->sameAs("c")) {
          TEST_FAIL("[ArrayList<String> Test {insert(int index,char* val)} case1]");
          break;
        }

        bool isException = false;
        try {
            int result = list->insert(50,String::New("d"));
        } catch(ArrayIndexOutOfBoundsException e) {
           isException = true;
        }

        if(!isException) {
          TEST_FAIL("[ArrayList<String> Test {insert(int index,char* val)} case2]");
          break;
        }

        isException = false;
        try {
            list->insert(-1,String::New("d"));
        } catch(ArrayIndexOutOfBoundsException e) {
            isException = true;
        }

        if(!isException) {
          TEST_FAIL("[ArrayList<String> Test {insert(int index,char* val)} case3]");
          break;
        }

        TEST_OK("[ArrayList<String> Test {insert(int index,char* val)}]");
        break;
      }

      //[ArrayList<String> Test {insert(int index,std::string val)} Start]
      while(1) {
        ArrayList<String> list = ArrayList<String>::New();
        list->add(String::New(std::string("a")));
        list->add(String::New(std::string("b")));
        list->add(String::New(std::string("c")));

        list->insert(1,String::New(std::string("d")));
        if(!list->get(0)->sameAs(std::string("a"))
        ||!list->get(1)->sameAs(std::string("d"))
        ||!list->get(2)->sameAs(std::string("b"))
        ||!list->get(3)->sameAs(std::string("c"))) {
          TEST_FAIL("[ArrayList<String> Test {insert(int index,std::string val)} case1]");
          break;
        }

        bool isException = false;
        try {
            list->insert(50,String::New(std::string("d")));
        } catch(ArrayIndexOutOfBoundsException e) {
             isException = true;
        }

        if(!isException) {
          TEST_FAIL("[ArrayList<String> Test {insert(int index,std::string val)} case2]");
          break;
        }

        isException = false;
        try {
            list->insert(-1,String::New(std::string("d")));
        } catch(ArrayIndexOutOfBoundsException e) {
            isException = true;
        }

        if(!isException) {
          TEST_FAIL("[ArrayList<String> Test {insert(int index,std::string val)} case3]");
          break;
        }

        TEST_OK("[ArrayList<String> Test {insert(int index,std::string val)}]");
        break;
      }

      //[ArrayList<String> Test {insert(int index,ArrayList<String> list)} Start]
      while(1) {
        ArrayList<String> list = ArrayList<String>::New();
        list->add(String::New("a"));
        list->add(String::New("b"));
        list->add(String::New("c"));

        ArrayList<String> list2 = ArrayList<String>::New();
        list2->add(String::New("d"));
        list2->add(String::New("e"));

        list->insert(2,list2);
        if(!list->get(0)->sameAs("a")
        ||!list->get(1)->sameAs("b")
        ||!list->get(2)->sameAs("d")
        ||!list->get(3)->sameAs("e")
        ||!list->get(4)->sameAs("c")){
          TEST_FAIL("[ArrayList<String> Test {insert(int index,ArrayList<String> list)} case1]");
          break;
        }

        bool isException = false;
        try {
             list->insert(200,list2);
        } catch(ArrayIndexOutOfBoundsException e) {
             isException = true;
        }

        if(!isException) {
          TEST_FAIL("[ArrayList<String> Test {insert(int index,ArrayList<String> list)} case2]");
          break;
        }

        isException = false;
        try {
            list->insert(-1,list2);
        } catch(ArrayIndexOutOfBoundsException e) {
            isException = true;
        }

        if(!isException) {
          TEST_FAIL("[ArrayList<String> Test {insert(int index,ArrayList<String> list)} case3]");
          break;
        }

        int size = list->size();
        ArrayList<String> list3 = ArrayList<String>::New();
        list->insert(0,list3);

        if(size != list->size()) {
          TEST_FAIL("[ArrayList<String> Test {insert(int index,ArrayList<String> list)} case4]");
          break;
        }

        TEST_OK("[ArrayList<String> Test {insert(int index,ArrayList<String> list)}]");
        break;
      }

      //[ArrayList<String> Test {insert(int index,ArrayList<String> list,int length)} Start]
      while(1) {
        ArrayList<String> list = ArrayList<String>::New();
        list->add(String::New("a"));
        list->add(String::New("b"));
        list->add(String::New("c"));

        ArrayList<String> list2 = ArrayList<String>::New();
        list2->add(String::New("d"));
        list2->add(String::New("e"));
        list2->add(String::New("f"));

        list->insert(2,list2,2);
        //TEST_FAIL("list->get(0) is %s \n",list->get(0)->toChars());
        //TEST_FAIL("list->get(1) is %s \n",list->get(1)->toChars());
        //TEST_FAIL("list->get(2) is %s \n",list->get(2)->toChars());
        //TEST_FAIL("list->get(3) is %s \n",list->get(3)->toChars());
        //TEST_FAIL("list->get(4) is %s \n",list->get(4)->toChars());
        if(!list->get(0)->sameAs("a")
        ||!list->get(1)->sameAs("b")
        ||!list->get(2)->sameAs("d")
        ||!list->get(3)->sameAs("e")
        ||!list->get(4)->sameAs("c")){
          TEST_FAIL("[ArrayList<String> Test {insert(int index,ArrayList<String> list,int length)} case1]");
          break;
        }


        list->clear();
        list->add(String::New("a"));
        list->add(String::New("b"));
        list->add(String::New("c"));
        bool isException1 = false;
        try {
            list->insert(2,list2,100);
        }catch(ArrayIndexOutOfBoundsException e) {
            isException1 = true;
        }

        if(!isException1) {
            TEST_FAIL("[ArrayList<String> Test {insert(int index,ArrayList<String> list,int length)} case2]");
        }
        //TEST_FAIL("list->get(0) is %s \n",list->get(0)->toChars());
        //TEST_FAIL("list->get(1) is %s \n",list->get(1)->toChars());
        //TEST_FAIL("list->get(2) is %s \n",list->get(2)->toChars());
        //TEST_FAIL("list->get(3) is %s \n",list->get(3)->toChars());
        //TEST_FAIL("list->get(4) is %s \n",list->get(4)->toChars());
        //TEST_FAIL("list->get(5) is %s \n",list->get(5)->toChars());

        if(!list->get(0)->sameAs("a")
        ||!list->get(1)->sameAs("b")
        ||!list->get(2)->sameAs("c")){
          TEST_FAIL("[ArrayList<String> Test {insert(int index,ArrayList<String> list,int length)}]");
          break;
        }

        TEST_OK("[ArrayList<String> Test {insert(int index,ArrayList<String> list,int length)}]");
        break;
      }

  //[ArrayList<String> Test {insertFirst(String val)} Start]
  while(1){
    ArrayList<String> list = ArrayList<String>::New();
    list->add(String::New("a"));
    list->add(String::New("b"));
    list->add(String::New("c"));

    list->insertFirst(String::New("d"));
    if(!list->get(0)->sameAs("d")
    ||!list->get(1)->sameAs("a")
    ||!list->get(2)->sameAs("b")
    ||!list->get(3)->sameAs("c")){
      TEST_FAIL("[ArrayList<String> Test {insertFirst(String val)} case1]");
      break;
    }

    String str1;
    int size = list->size();
    list->insertFirst(str1);
    if(list->size() == size) {
      TEST_FAIL("[ArrayList<String> Test {insertFirst(String val)} case2]");
      break;
    }

    TEST_OK("[ArrayList<String> Test {insertFirst(String val)}]");
    break;
  }

  //[ArrayList<String> Test {insertFirst(const char * val)} Start]
  while(1){
    ArrayList<String> list = ArrayList<String>::New();
    list->add(String::New("a"));
    list->add(String::New("b"));
    list->add(String::New("c"));

    list->insertFirst(String::New("d"));
    if(!list->get(0)->sameAs("d")
    ||!list->get(1)->sameAs("a")
    ||!list->get(2)->sameAs("b")
    ||!list->get(3)->sameAs("c")){
      TEST_FAIL("[ArrayList<String> Test {insertFirst(const char * val)} case1]");
      break;
    }

    String str1;
    int size = list->size();
    list->insertFirst(str1);
    if(list->size() == size) {
      TEST_FAIL("[ArrayList<String> Test {insertFirst(const char * val)} case2]");
      break;
    }

    TEST_OK("[ArrayList<String> Test {insertFirst(const char * val)}]");
    break;
  }

  //[ArrayList<String> Test {insertFirst(ArrayList<String> list)} Start]
  while(1) {
    ArrayList<String> list = ArrayList<String>::New();
    list->add(String::New("a"));
    list->add(String::New("b"));
    list->add(String::New("c"));

    ArrayList<String> list2 = ArrayList<String>::New();
    list2->add(String::New("e"));
    list2->add(String::New("f"));
    list2->add(String::New("g"));

    list->insertFirst(list2);
    if(!list->get(0)->sameAs("e")
    ||!list->get(1)->sameAs("f")
    ||!list->get(2)->sameAs("g")
    ||!list->get(3)->sameAs("a")
    ||!list->get(4)->sameAs("b")
    ||!list->get(5)->sameAs("c")){
      //TEST_FAIL("list->get(0) is %s \n",list->get(0)->toChars());
      //TEST_FAIL("list->get(1) is %s \n",list->get(1)->toChars());
      //TEST_FAIL("list->get(2) is %s \n",list->get(2)->toChars());
      //TEST_FAIL("list->get(3) is %s \n",list->get(3)->toChars());
      //TEST_FAIL("list->get(4) is %s \n",list->get(4)->toChars());
      //TEST_FAIL("list->get(5) is %s \n",list->get(5)->toChars());
      TEST_FAIL("[ArrayList<String> Test {insertFirst(ArrayList<String> list)} case1]");
      break;
    }
/*
    ArrayList<String> list3;
    int size = list->size();
    list->add(list3);
    if(size != list->size()) {
      TEST_FAIL("[ArrayList<String> Test {insertFirst(ArrayList<String> list)} case2]");
      break;
    }
*/
    TEST_OK("[ArrayList<String> Test {insertFirst(ArrayList<String> list)}]");
    break;
  }
  //[ArrayList<String> Test {insertLast(String v)} Start]
  while(1) {
    ArrayList<String> list = ArrayList<String>::New();
    list->add(String::New("a"));
    list->add(String::New("b"));
    list->add(String::New("c"));

    list->insertLast(String::New("d"));
    if(!list->get(0)->sameAs("a")
    ||!list->get(1)->sameAs("b")
    ||!list->get(2)->sameAs("c")
    ||!list->get(3)->sameAs("d")){
      TEST_FAIL("[ArrayList<String> Test {insertLast(String v)} case1]");
      break;
    }

    String s;
    int size = list->size();
    list->insertLast(s);
    if(size == list->size()) {
      TEST_FAIL("[ArrayList<String> Test {insertLast(String v)} case2]");
      break;
    }
    TEST_OK("[ArrayList<String> Test {insertLast(String v)}]");
    break;
  }
  //[ArrayList<String> Test {insertLast(const char *s)} Start]
  while(1) {
    ArrayList<String> list = ArrayList<String>::New();
    list->add(String::New("a"));
    list->add(String::New("b"));
    list->add(String::New("c"));

    list->insertLast(String::New("d"));
    if(!list->get(0)->sameAs("a")
    ||!list->get(1)->sameAs("b")
    ||!list->get(2)->sameAs("c")
    ||!list->get(3)->sameAs("d")){
      TEST_FAIL("[ArrayList<String> Test {insertLast(const char * s)} case1]");
      break;
    }
/*
    char *p = nullptr;
    int size = list->size();
    try {
      list->insertLast(String::New(p));
      TEST_FAIL("[ArrayList<String> Test {insertLast(const char *s )} case2]");
    } catch(InitializeException e) {}
*/
    TEST_OK("[ArrayList<String> Test {insertLast(const char *s)}]");
    break;
  }
  //[ArrayList<String> Test {insertLast(ArrayList<String> list)} Start]
  while(1) {
    ArrayList<String> list = ArrayList<String>::New();
    list->add(String::New("a"));
    list->add(String::New("b"));
    list->add(String::New("c"));

    ArrayList<String> list2 = ArrayList<String>::New();
    list2->add(String::New("e"));
    list2->add(String::New("f"));
    list2->add(String::New("g"));

    list->insertLast(list2);
    if(!list->get(0)->sameAs("a")
    ||!list->get(1)->sameAs("b")
    ||!list->get(2)->sameAs("c")
    ||!list->get(3)->sameAs("e")
    ||!list->get(4)->sameAs("f")
    ||!list->get(5)->sameAs("g")){
      TEST_FAIL("[ArrayList<String> Test {insertLast(ArrayList<String> list)} case1]");
      break;
    }

/*
    int size = list->size();
    ArrayList<String> list3;
    list->insertLast(list3);
    if(size != list->size()) {
      TEST_FAIL("[ArrayList<String> Test {insertLast(ArrayList<String> list)} case2]");
      break;
    }
*/
    TEST_OK("[ArrayList<String> Test {insertLast(ArrayList<String> list)}]");
    break;
  }
  //[ArrayList<String> Test {size()} Start]
  while(1) {
    ArrayList<String> list = ArrayList<String>::New();
    list->add(String::New("a"));
    if(list->size() != 1) {
      TEST_FAIL("[ArrayList<String> Test {size()} case1]");
      break;
    }

    list->clear();
    if(list->size() != 0) {
      TEST_FAIL("[ArrayList<String> Test {size()} case0]");
      break;
    }

    TEST_OK("[ArrayList<String> Test {size()}]");
    break;
  }

  //[ArrayList<String> Test {getIterator()} Start]
  while(1) {
    ArrayList<String> list = ArrayList<String>::New();
    list->add(String::New("a"));
    if(list->getIterator()== nullptr) {
      TEST_FAIL("[ArrayList<String> Test {getIterator()} case0]");
      break;
    }

    TEST_OK("[ArrayList<String> Test {getIterator()}]");
    break;
  }
  //--[_ListIterator<String> Test {_ListIterator(ArrayList<String> list)} Start]
  while(1) {
    ArrayList<String> list = ArrayList<String>::New();
    list->add(String::New("a"));
    list->add(String::New("b"));
    list->add(String::New("c"));
    list->add(String::New("d"));

    auto iterator = ArrayListIterator<String>::New(list);
    int index = 0;
    bool isOk = true;
    while(iterator->hasValue()) {
      if(!iterator->getValue()->equals(list->get(index))) {
        isOk = false;
        break;
      }
      iterator->next();
      index++;
    }

    if(!isOk) {
      TEST_FAIL("[ArrayList<String> Test {_ListIterator(ArrayList<String> list)} case0]");
      break;
    }

    TEST_OK("[ArrayList<String> Test {_ListIterator(ArrayList<String> list)}]");
    break;
  }

  //--[_ListIterator<String> Test {_ListIterator(_ArrayList<String> *list)} Start]
  while(1) {
    ArrayList<String> list = ArrayList<String>::New();
    list->add(String::New("a"));
    list->add(String::New("b"));
    list->add(String::New("c"));
    list->add(String::New("d"));

    auto iterator = list->getIterator();
    int index = 0;
    bool isOk = true;
    while(iterator->hasValue()) {
      if(!iterator->getValue()->equals(list->get(index))) {
        isOk = false;
        break;
      }
      iterator->next();
      index++;
    }

    if(!isOk) {
      TEST_FAIL("[ArrayList<String> Test {_ListIterator(_ArrayList<String> *list)} case0]");
      break;
    }

    TEST_OK("[ArrayList<String> Test {_ListIterator(_ArrayList<String> *list)}]");
    break;
  }

  //--[_ListIterator<String> Test {remove()} Start]
  while(1) {
    ArrayList<String> list = ArrayList<String>::New();
    list->add(String::New("a"));
    list->add(String::New("b"));
    list->add(String::New("c"));
    list->add(String::New("d"));
    list->add(String::New("e"));
    auto iterator = list->getIterator();
    while(iterator->hasValue()) {
      if(iterator->getValue()->sameAs("c")) {
        iterator->remove();
      }else {
        iterator->next();
      }
    }

    if(list->size() != 4) {
        TEST_FAIL("[_ListIterator<String> Test {remove()} case0]");
        break;
    }

    if(!list->get(0)->sameAs("a") ||!list->get(1)->sameAs("b")
      ||!list->get(2)->sameAs("d")||!list->get(3)->sameAs("e")) {
        TEST_FAIL("[_ListIterator<String> Test {remove()} case2]");
        break;
    }

    TEST_OK("[_ListIterator<String> Test {remove()} case3]");
    break;
  }
}
