#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>


//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "String.hpp"
#include "ByteArray.hpp"
#include "StrongPointer.hpp"
#include "ArrayIndexOutOfBoundsException.hpp"
#include "Error.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testByteArrayslice() {

  while(1) {
      ByteArray data1 = createByteArray(5);
      data1[0] = 0x10;
      data1[1] = 0x11;
      data1[2] = 0x12;
      data1[3] = 0x13;
      data1[4] = 0x14;
      
      data1->slice(2,2);
      if(data1[0] != 0x12 ||data1[1] != 0x13) {
        TEST_FAIL("testByteArrayslice case1");
      }
      
      if(data1->size() != 2) {
        TEST_FAIL("testByteArrayslice case2");
      }
      
      char testData[4];
      memcpy(testData,data1->toValue(),data1->size());
      if(testData[0] != 0x12 ||testData[1] != 0x13) {
        TEST_FAIL("testByteArrayslice case3");
      }
      
      ByteArray data2 = createByteArray(data1);
      if(data2->size() != 2) {
        TEST_FAIL("testByteArrayslice case4");
      }
      
      if(data2[0] != 0x12 ||data2[1] != 0x13) {
        TEST_FAIL("testByteArrayslice case5");
      }
      
      auto p1 = data1->toValue();
      if(p1[0] != 0x12 ||p1[1] != 0x13) {
        TEST_FAIL("testByteArrayslice case6");
      }
      
      data1->quickShrink(1);
      if(data1->size() != 1) {
        TEST_FAIL("testByteArrayslice case7");
      }
      
      if(data1[0] != 0x12) {
        TEST_FAIL("testByteArrayslice case8"); 
      }
      
      data1->quickRestore();
      if(data1->size() != 5) {
        TEST_FAIL("testByteArrayslice case9");   
      }
      
      if(data1[0] != 0x10 ||data1[1] != 0x11|| data1[2] != 0x12||
        data1[3] != 0x13 ||data1[4] != 0x14) {
            TEST_FAIL("testByteArrayslice case10");   
      }
      break;
  }
  
  while(1) {
      ByteArray data1 = createByteArray(5);
      data1[0] = 0x10;
      data1[1] = 0x11;
      data1[2] = 0x12;
      data1[3] = 0x13;
      data1[4] = 0x14;
      
      data1->slice(1,2);
      if(data1->isEmpty()) {
        TEST_FAIL("testByteArrayslice case11");     
      }
      
      data1->fill(0x01);
      if(data1[0] != 0x01 || data1[1] != 0x01){
          TEST_FAIL("testByteArrayslice case11");      
      }
      
      data1->quickRestore();
      if(data1[0] != 0x10 || data1[1] != 0x01 ||data1[2] != 0x01
        ||data1[3] != 0x13 ||data1[4] != 0x14) {
        TEST_FAIL("testByteArrayslice case12");       
      }
      break;
  }
  
  while(1) {
      ByteArray data1 = createByteArray(5);
      data1[0] = 0x10;
      data1[1] = 0x11;
      data1[2] = 0x12;
      data1[3] = 0x13;
      data1[4] = 0x14;
      
      data1->slice(1,2);
      data1->fill(0,2,0x02);
      if(data1[0] != 0x02 || data1[1] != 0x02){
          TEST_FAIL("testByteArrayslice case13");      
      }
      
      data1->quickRestore();
      if(data1[0] != 0x10 || data1[1] != 0x02 ||data1[2] != 0x02
        ||data1[3] != 0x13 ||data1[4] != 0x14) {
        TEST_FAIL("testByteArrayslice case14");       
      }
      break;
  }
  
  while(1) {
      ByteArray data1 = createByteArray(5);
      data1[0] = 0x10;
      data1[1] = 0x11;
      data1[2] = 0x12;
      data1[3] = 0x13;
      data1[4] = 0x14;
      
      data1->slice(1,2);
      
      byte arr[2] = {0x02,0x02};
      
      data1->fillFrom(arr,0,2);
      if(data1[0] != 0x02 || data1[1] != 0x02){
          TEST_FAIL("testByteArrayslice case15");      
      }
      
      data1->quickRestore();
      if(data1[0] != 0x10 || data1[1] != 0x02 ||data1[2] != 0x02
        ||data1[3] != 0x13 ||data1[4] != 0x14) {
        TEST_FAIL("testByteArrayslice case16");       
      }
      break;
  }
  
  while(1) {
      ByteArray data1 = createByteArray(5);
      data1[0] = 0x10;
      data1[1] = 0x11;
      data1[2] = 0x12;
      data1[3] = 0x13;
      data1[4] = 0x14;
      
      data1->slice(1,2);
      data1->growTo(3);
      if(data1->size() != 3) {
          TEST_FAIL("testByteArrayslice case17,size is %d",data1->size()); 
      }
      
      data1->fill(0x01);
      
      data1->quickRestore();
      if(data1[0] != 0x10 || data1[1] != 0x01 ||data1[2] != 0x01
        ||data1[3] != 0x01 ||data1[4] != 0x14) {
        TEST_FAIL("testByteArrayslice case17");       
      }
      break;
  }
  
  while(1) {
      ByteArray data1 = createByteArray(5);
      data1[0] = 0x10;
      data1[1] = 0x11;
      data1[2] = 0x12;
      data1[3] = 0x13;
      data1[4] = 0x14;
      
      data1->slice(1,2);
      data1->growTo(8);
      if(data1->size() != 8) {
          TEST_FAIL("testByteArrayslice case18,size is %d",data1->size()); 
      }
      
      data1->quickRestore();
      if(data1->size() != 9) {
          TEST_FAIL("testByteArrayslice case18_1,size is %d",data1->size()); 
      }
      break;
  }
  
  while(1) {
      ByteArray data1 = createByteArray(6);
      data1[0] = 0x10;
      data1[1] = 0x11;
      data1[2] = 0x12;
      data1[3] = 0x13;
      data1[4] = 0x14;
      data1[5] = 0x15;
      
      data1->slice(1,2);
      data1->growTo(5);
      if(data1->size() != 5) {
          TEST_FAIL("testByteArrayslice case19,size is %d",data1->size()); 
      }
      
      data1->quickRestore();
      if(data1->size() != 6) {
          TEST_FAIL("testByteArrayslice case20,size is %d",data1->size()); 
      }
      break;
  }
  
  while(1) {
      ByteArray data1 = createByteArray(5);
      data1[0] = 0x10;
      data1[1] = 0x11;
      data1[2] = 0x12;
      data1[3] = 0x13;
      data1[4] = 0x14;
      
      data1->slice(1,2);
      data1->growTo(3);
      
      data1->quickRestore();
      if(data1[0] != 0x10 || data1[1] != 0x11 ||data1[2] != 0x12
        ||data1[3] != 0x00 ||data1[4] != 0x14) {
        TEST_FAIL("testByteArrayslice case21");       
      }
      break;
  }
  
  while(1) {
      ByteArray data1 = createByteArray(5);
      data1[0] = 0x10;
      data1[1] = 0x11;
      data1[2] = 0x12;
      data1[3] = 0x13;
      data1[4] = 0x14;
      
      data1->slice(1,2);
      data1->growTo(8);
      
      data1->quickRestore();
      if(data1[0] != 0x10 || data1[1] != 0x11 ||data1[2] != 0x12
        ||data1[3] != 0x00 ||data1[4] != 0x0 || data1[5] != 0x0
        ||data1[6] != 0x0 || data1[7] != 0x0) {
        TEST_FAIL("testByteArrayslice case22");       
      }
      break;
  }
  
  while(1) {
      ByteArray data1 = createByteArray(5);
      data1[0] = 0x10;
      data1[1] = 0x11;
      data1[2] = 0x12;
      data1[3] = 0x13;
      data1[4] = 0x14;
      
      data1->slice(1,2);
      data1->growBy(2);
      
      if(data1->size() != 4) {
        TEST_FAIL("testByteArrayslice case23");
      }
      
      data1->quickRestore();
      
      if(data1[0] != 0x10 || data1[1] != 0x11 ||data1[2] != 0x12
        ||data1[3] != 0x00 ||data1[4] != 0x0) {
        TEST_FAIL("testByteArrayslice case24");
      }
      break;
  }
  
  while(1) {
      ByteArray data1 = createByteArray(5);
      data1[0] = 0x10;
      data1[1] = 0x11;
      data1[2] = 0x12;
      data1[3] = 0x13;
      data1[4] = 0x14;
      
      data1->slice(1,2);
      data1->growBy(5);
      
      if(data1->size() != 7) {
        TEST_FAIL("testByteArrayslice case25,size is %d",data1->size());
      }
      
      data1->quickRestore();
      
      if(data1->size() != 8) {
         TEST_FAIL("testByteArrayslice case26,size is %d",data1->size()); 
      }
      if(data1[0] != 0x10 || data1[1] != 0x11 ||data1[2] != 0x12
        ||data1[3] != 0x00 ||data1[4] != 0x0 || data1[5] != 0x0) {
        TEST_FAIL("testByteArrayslice case26");
      }
      break;
  }
  
  while(1) {
      ByteArray data1 = createByteArray(5);
      data1[0] = 0x10;
      data1[1] = 0x11;
      data1[2] = 0x12;
      data1[3] = 0x13;
      data1[4] = 0x14;
      
      ByteArray data2 = createByteArray(5);
      data2[0] = 0x20;
      data2[1] = 0x21;
      data2[2] = 0x22;
      data2[3] = 0x23;
      data2[4] = 0x24;
      
      data1->slice(1,2);
      data2->slice(1,2);
      
      auto data1_p = data1.get_pointer();
      data1->append(data2);
      if(data1_p != data1.get_pointer()) {
          TEST_FAIL("testByteArrayslice case27");
      }
      
      data1->quickRestore();
      if(data1->size() != 5) {
          TEST_FAIL("testByteArrayslice case28,size is %d",data1->size());
      }
      
      if(data1[0] != 0x10 || data1[1] != 0x11 ||data1[2] != 0x12
        ||data1[3] != 0x21 ||data1[4] != 0x22 ) {
        TEST_FAIL("testByteArrayslice case28");
      }
      break;   
  }
  
  while(1) {
      ByteArray data1 = createByteArray(5);
      data1[0] = 0x10;
      data1[1] = 0x11;
      data1[2] = 0x12;
      data1[3] = 0x13;
      data1[4] = 0x14;
      
      ByteArray data2 = createByteArray(5);
      data2[0] = 0x20;
      data2[1] = 0x21;
      data2[2] = 0x22;
      data2[3] = 0x23;
      data2[4] = 0x24;
      
      data1->slice(2,3);
      auto data1_p = data1.get_pointer();
      
      data1->append(data2);
      if(data1->size() != 8) {
          TEST_FAIL("testByteArrayslice case29");
      }
      
      if(data1[0] != 0x12 || data1[1] != 0x13 || data1[2] != 0x14
        ||data1[3] != 0x20 || data1[4] != 0x21 || data1[5] != 0x22
        ||data1[6] != 0x23 || data1[7] != 0x24) {
        TEST_FAIL("testByteArrayslice case30");    
      }
      
      data1->quickRestore();
      if(data1->size() != 10) {
          TEST_FAIL("testByteArrayslice case31");    
      }
      
      if(data1_p != data1.get_pointer()) {
          TEST_FAIL("testByteArrayslice case32");    
      }
      break;
  }

  while(1) {
    ByteArray data1 = createByteArray(5);
    data1[0] = 0x10;
    data1[1] = 0x11;
    data1[2] = 0x12;
    data1[3] = 0x13;
    data1[4] = 0x14;
    
    ByteArray data2 = createByteArray(5);
    data2[0] = 0x20;
    data2[1] = 0x21;
    data2[2] = 0x22;
    data2[3] = 0x23;
    data2[4] = 0x24;
    
    data1->slice(3,1);
    data2->slice(2,2);
    
    auto data1_p = data1.get_pointer();
    data1->append(data2);
    if(data1->size() != 3) {
        TEST_FAIL("testByteArrayslice case33,size is %d",data1->size());    
    }
    
    if(data1[0] != 0x13 || data1[1] != 0x22 || data1[2] != 0x23) {
        TEST_FAIL("testByteArrayslice case34");    
    }
    
    data1->quickRestore();
    if(data1->size() != 6) {
        TEST_FAIL("testByteArrayslice case35");    
    }
    
    if(data1[0] != 0x10 || data1[1] != 0x11 || data1[2] != 0x12
      ||data1[3] != 0x13 || data1[4] != 0x22 || data1[5] != 0x23) {
        TEST_FAIL("testByteArrayslice case31");    
    }
    break;
  }
  
  while(1) {
    ByteArray data1 = createByteArray(1);
    data1[0] = 0x11;
    data1->slice(0,1);
    if(data1->size() != 1) {
        TEST_FAIL("testByteArrayslice case32");    
    }
    
    ByteArray data2 = createByteArray(1);
    data2[0] = 0x21;
    data2->slice(0,1);
    auto data1_p = data1.get_pointer();
    
    data1->append(data2);
    if(data1_p != data1.get_pointer()) {
        TEST_FAIL("testByteArrayslice case34");   
    }
    
    if(data1->size() != 2) {
        TEST_FAIL("testByteArrayslice case35");   
    }

    if(data1[0] != 0x11 || data1[1] != 0x21) {
        TEST_FAIL("testByteArrayslice case36");   
    }
    break;
  }
  
  while(1) {
      ByteArray data1 = createByteArray(5);
      data1[0] = 0x10;
      data1[1] = 0x11;
      data1[2] = 0x12;
      data1[3] = 0x13;
      data1[4] = 0x14;
      data1->slice(1,2);
      
      auto data2 = data1->clone();
      
      if(data2->size() != 2) {
        TEST_FAIL("testByteArrayslice case37");   
      }
      
      if(data2[0] != 0x11 || data2[1] != 0x12) {
        TEST_FAIL("testByteArrayslice case38");   
      }
      break;
  }
  
  while(1) {
      ByteArray data1 = createByteArray(5);
      data1[0] = 0x10;
      data1[1] = 0x11;
      data1[2] = 0x12;
      data1[3] = 0x13;
      data1[4] = 0x14;
      data1->slice(1,2);
      
      if(!data1->isOverflow(1,3)) {
          TEST_FAIL("testByteArrayslice case38");   
      }
      
      if(!data1->isOverflow(2,3)) {
          TEST_FAIL("testByteArrayslice case39");   
      }
      
      data1->quickRestore();
      if(data1->isOverflow(1,3)) {
          TEST_FAIL("testByteArrayslice case40");   
      }
      
      if(data1->isOverflow(2,3)) {
          TEST_FAIL("testByteArrayslice case41");   
      }
      break;
  }
  
  while(1) {
      ByteArray data1 = createByteArray(5);
      data1[0] = 'a';
      data1[1] = 'b';
      data1[2] = 'c';
      data1[3] = 'd';
      data1[4] = 'e';
      
      data1->slice(1,2);
      auto str = data1->toString();
      if(!str->sameAs("bc")) {
          TEST_FAIL("testByteArrayslice case42");   
      }
      
      data1->quickRestore();
      str = data1->toString();
      if(!str->sameAs("abcde")) {
          TEST_FAIL("testByteArrayslice case43");   
      }
      
      break;
  }
  
  while(1) {
      ByteArray data1 = createByteArray(5);
      data1[0] = 0x10;
      data1[1] = 0x11;
      data1[2] = 0x12;
      data1[3] = 0x13;
      data1[4] = 0x14;
      
      ByteArray data2 = createByteArray(5);
      data2[0] = 0x20;
      data2[1] = 0x21;
      data2[2] = 0x22;
      data2[3] = 0x23;
      data2[4] = 0x24;
      
      data1->slice(1,2);
      data2->slice(1,2);
      
      st(ByteArray)::Combine(data1,data2);
      if(data1->size() != 4) {
          TEST_FAIL("testByteArrayslice case44");   
      }
      
      if(data1[0] != 0x11 || data1[1] != 0x12 || data1[2] != 0x21
        ||data1[3] != 0x22) {
          TEST_FAIL("testByteArrayslice case45");   
      }
      break;
  }
  
  while(1) {
      ByteArray data1 = createByteArray(5);
      data1[0] = 0x10;
      data1[1] = 0x11;
      data1[2] = 0x12;
      data1[3] = 0x13;
      data1[4] = 0x14;
      
      ByteArray data2 = createByteArray(5);
      data2[0] = 0x10;
      data2[1] = 0x11;
      data2[2] = 0x12;
      data2[3] = 0x13;
      data2[4] = 0x14;
      
      data1->slice(1,2);
      data2->slice(1,2);
      if(!data1->equals(data2)) {
          TEST_FAIL("testByteArrayslice case46");   
      }
      
      data2->quickRestore();
      data2->slice(2,2);
      if(data1->equals(data2)) {
          TEST_FAIL("testByteArrayslice case47");   
      }
      
      data2->quickRestore();
      if(data1->equals(data2)) {
          TEST_FAIL("testByteArrayslice case48");   
      }
      break;
  }
  
  while(1) {
      ByteArray data1 = createByteArray(5);
      data1[0] = 0x10;
      data1[1] = 0x11;
      data1[2] = 0x12;
      data1[3] = 0x13;
      data1[4] = 0x14;
      
      data1->slice(1,2);
      if(data1[0] != 0x11) {
        TEST_FAIL("testByteArrayslice case49");     
      }
      
      try {
          data1[2] = 0x22;
          TEST_FAIL("testByteArrayslice case50");   
      } catch(...) {}
      break;
  }
  
  while(1) {
      ByteArray data1 = createByteArray(5);
      data1[0] = 0x10;
      data1[1] = 0x11;
      data1[2] = 0x12;
      data1[3] = 0x13;
      data1[4] = 0x14;
      
      data1->slice(1,2);
      data1->clear();
      if(data1->size() != 5) {
          TEST_FAIL("testByteArrayslice case51");   
      }
      
      for(int i = 0;i < data1->size();i++) {
          if(data1[i] != 0) {
              TEST_FAIL("testByteArrayslice case52");  
          }
      }
      break;
  }
  
  while(1) {
      ByteArray data1 = createByteArray(5);
      data1[0] = 0x10;
      data1[1] = 0x11;
      data1[2] = 0x12;
      data1[3] = 0x13;
      data1[4] = 0x14;
      
      data1->slice(2);
      if(data1->size() != 3) {
          TEST_FAIL("testByteArrayslice case53");  
      }
      
      if(data1[0] != 0x12 || data1[1] != 0x13 || data1[2] != 0x14) {
          TEST_FAIL("testByteArrayslice case54");  
      }
      
      data1->quickShrink(2);
      if(data1->size() != 2) {
          TEST_FAIL("testByteArrayslice case55");  
      }
      
      try {
          data1[2] = 0x1;
          TEST_FAIL("testByteArrayslice case56");
      } catch(...) {}
      
      if(data1[0] != 0x12 || data1[1] != 0x13) {
          TEST_FAIL("testByteArrayslice case57");
      }
      break;
  }
  
  while(1) {
      ByteArray data1 = createByteArray(5);
      data1[0] = 0x10;
      data1[1] = 0x11;
      data1[2] = 0x12;
      data1[3] = 0x13;
      data1[4] = 0x14;
      data1->slice(4);
      if(data1->size() != 1) {
          TEST_FAIL("testByteArrayslice case58");
      }
      break;
  }
  
  while(1) {
      ByteArray data1 = createByteArray(5);
      data1[0] = 0x10;
      data1[1] = 0x11;
      data1[2] = 0x12;
      data1[3] = 0x13;
      data1[4] = 0x14;
      data1->slice(0);
      if(data1->size() != 5) {
          TEST_FAIL("testByteArrayslice case59");
      }
      
      if(data1[0] != 0x10 || data1[1] != 0x11 || data1[2] != 0x12
        || data1[3] != 0x13 || data1[4] != 0x14){
          TEST_FAIL("testByteArrayslice case60");
      }
      break;
  }
  
  while(1) {
      ByteArray data1 = createByteArray(5);
      data1[0] = 0x10;
      data1[1] = 0x11;
      data1[2] = 0x12;
      data1[3] = 0x13;
      data1[4] = 0x14;
      try {
        data1->slice(5);
        TEST_FAIL("testByteArrayslice case61");
      } catch(...) {}
      
      break;
  }
  
  while(1) {
      ByteArray data1 = createByteArray(5);
      data1[0] = 0x10;
      data1[1] = 0x11;
      data1[2] = 0x12;
      data1[3] = 0x13;
      data1[4] = 0x14;
      
      data1->slice(1,2);
      ByteArray data2 = createByteArray(data1->toValue(),data1->size());
      
      if(data2->size() != 2) {
          TEST_FAIL("testByteArrayslice case62");
      }
      
      if(data1[0] != 0x11 || data1[1] != 0x12){
          TEST_FAIL("testByteArrayslice case63");
      }
      break;
  }
  TEST_OK("testByteArrayslice case100");
}
