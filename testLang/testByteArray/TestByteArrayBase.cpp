#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "ByteArray.hpp"
#include "StrongPointer.hpp"
#include "ArrayIndexOutOfBoundsException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

struct MyData {
  int i;
  int j;
};

void basetest() {
    while(1) {
        //Test Construct
        ByteArray array1 = createByteArray(16);

        byte *p = array1->toValue();
        for(int index = 0;index<16;index++) {
            if(p[index] != 0) {
              TEST_FAIL("ByteArray construct test1");
              break;
            }
        }

        byte *v = (byte *)malloc(16);
        memset(v,8,16);
        ByteArray array2 = createByteArray(v,16);
        byte *p2 = array2->toValue();
        bool isOk = true;
        for(int index = 0;index<16;index++) {
            if(p2[index] != 8) {
              TEST_FAIL("ByteArray construct test2");
              isOk = false;
              break;
            }
        }

        free(v);

        if(isOk) {
            TEST_OK("ByteArray construct ");
        }
        break;
    }

    while(1) {
        //test clear
        byte *v = (byte *)malloc(16);
        memset(v,8,16);
        ByteArray array1 = createByteArray(v,16);
        array1->clear();
        byte *p2 = array1->toValue();
        bool isOk = true;
        for(int index = 0;index<16;index++) {
            if(p2[index] != 0) {
              TEST_FAIL("ByteArray clear test1 ");
              isOk = false;
              break;
            }
        }

        free(v);

        if(isOk) {
            TEST_OK("ByteArray clear ");
        }
        break;
    }

    while(1) {
        //test toValue
        byte *v = (byte *)malloc(16);
        memset(v,8,16);
        ByteArray array1 = createByteArray(v,16);
        array1->clear();
        byte *p2 = array1->toValue();
        bool isOk = true;
        for(int index = 0;index<16;index++) {
            if(p2[index] != 0) {
              TEST_FAIL("ByteArray toValue test1 ");
              isOk = false;
              break;
            }
        }

        free(v);

        if(isOk) {
            TEST_OK("ByteArray toValue ");
        }
        break;
    }

    while(1) {
        //test size
        byte *v = (byte *)malloc(16);
        memset(v,8,16);
        ByteArray array1 = createByteArray(v,16);

        if(array1->size() != 16) {
            TEST_FAIL("ByteArray size test1 ");
            break;
        }

        free(v);

        TEST_OK("ByteArray size ");
        break;
    }

    while(1) {
        //test isEmpty
        ByteArray t = createByteArray(16);
        if(t->isEmpty()) {
            TEST_FAIL("ByteArray isEmpty ");
            break;
        }

        TEST_OK("ByteArray isEmpty ");
        break;
    }

    while(1) {
        //test at
        byte *v = (byte *)malloc(16);
        memset(v,8,16);
        ByteArray array1 = createByteArray(v,16);
        byte *p = array1->toValue();
        bool isOk = true;
        for(int index = 0;index<16;index++) {
            if(p[index] != array1->at(index)) {
                isOk = false;
                TEST_FAIL("ByteArray at ");
                break;
            }
        }

        if(isOk) {
          TEST_OK("ByteArray at ");
        }
        free(v);
        break;
    }

    while(1) {
        //test at
        byte *v = (byte *)malloc(16);
        memset(v,8,16);
        ByteArray array1 = createByteArray(v,16);
        array1->fill(9);

        byte *p = array1->toValue();
        bool isOk = true;
        for(int index = 0;index<16;index++) {
            if(p[index] != 9) {
                isOk = false;
                TEST_FAIL("ByteArray fill ");
                break;
            }
        }

        if(isOk) {
          TEST_OK("ByteArray fill ");
        }

        free(v);
        break;
    }

    //bool fill(byte v,int index);
    while(1) {

      ByteArray buff2 = createByteArray(6);
      buff2->fill(2,2,3);
      if(buff2->at(0) != 0
        ||buff2->at(1) != 0
        ||buff2->at(2) != 3
        ||buff2->at(3) != 3
        ||buff2->at(4) != 0
        ||buff2->at(5) != 0) {
          TEST_FAIL("ByteArray fill test 4");
          break;
      }

      ByteArray buff3 = createByteArray(6);
      try {
        buff3->fill(100,2,3);
        TEST_FAIL("ByteArray fill test 5");
      } catch(ArrayIndexOutOfBoundsException e) {}

      ByteArray buff4 = createByteArray(6);
      try {
        buff4->fill(0,200,3);
        TEST_FAIL("ByteArray fill test 6");
      }catch(ArrayIndexOutOfBoundsException e) {}

      TEST_OK("ByteArray fill test 7");
      break;
    }

    //_ByteArray(T t);
    while(1) {
      MyData t;
      t.i = 100;
      t.j = 120;
      ByteArray arr = createByteArray((const byte *) &t,sizeof(struct MyData));
      struct MyData * t1 = (struct MyData *)arr->toValue();
      if(t1->i != t.i
        ||t1->j != t.j) {
          TEST_FAIL("ByteArray construct<template> test 1");
          break;
      }

      TEST_OK("ByteArray construct<template> test 2");
      break;
    }

    //char at(int);
    while(1) {
      ByteArray array = createByteArray(2);
      try{
        int value = array->at(3);
        TEST_FAIL("ByteArray at()) test 1");
        break;
      } catch(ArrayIndexOutOfBoundsException e){
        //TEST_FAIL("exception is %s \n",e->getErrInfo()->toChars());
      }

      TEST_OK("ByteArray at()) test 2");
      break;
    }

}
