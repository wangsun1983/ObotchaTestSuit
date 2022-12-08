#include <iostream>
#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ArrayList.hpp"
#include "Integer.hpp"
#include "String.hpp"
#include "Base64.hpp"
#include "Log.hpp"
#include "FileInputStream.hpp"
#include "TestLog.hpp"

using namespace obotcha;

int main() {
  //decode(String)/encode(String)
  while(1) {
      String abc = "hello world";
      Base64 base64 = createBase64();
      String r1 = base64->encode(abc);
      String r2 = base64->decode(r1);
      if(!r2->equals(abc)) {
          TEST_FAIL("[ByteArray Test {decode(String)/encode(String)} case1],r2 is %s",r2->toChars());
          break;
      }

      //aGVsbG8gd29ybGQ=
      if(!r1->equals("aGVsbG8gd29ybGQ=")) {
          TEST_FAIL("[ByteArray Test {decode(String)/encode(String)} case2]");
          break;
      }

      TEST_OK("[ByteArray Test {decode(String)/encode(String)} case3]");
      break;
  }

  //decode(ByteArray)/encode(ByteArray)
  while(1) {
      ByteArray array = createByteArray(32);
      array->fill('a');

      Base64 base64 = createBase64();
      //TEST_FAIL("encode array is %s,size is %d\n",array->toValue(),array->size());
      ByteArray r1 = base64->encode(array);

      ByteArray r2 = base64->decode(r1);
      //TEST_FAIL("r2 is %s,r2 size is %d \n",r2->toValue(),r2->size());

      for(int i = 0;i<32;i++) {
        if(r2->at(i) != array->at(i)) {
          //TEST_FAIL("r2[%d] is %d,array[%d] is %d \n",i,r2->at(i),i,array->at(i));
          TEST_FAIL("[ByteArray Test {decode(ByteArray)/encode(ByteArray)} case1]");
          break;
       }
      }

      String str1 = array->toString();
      String str2 = r2->toString();

      if(!str1->equals(str2)) {
          TEST_FAIL("[ByteArray Test {decode(ByteArray)/encode(ByteArray)} case2]");
          break;
      }

      TEST_OK("[ByteArray Test {decode(ByteArray)/encode(ByteArray)} case3]");
      break;
  }

  //encode(File)
  while(1) {
      Base64 base64 = createBase64();
      File f = createFile("testData.file");

      ByteArray r1 = base64->encode(f);
      ByteArray r2 = base64->decode(r1);

      FileInputStream stream = createFileInputStream(f);
      stream->open();
      ByteArray fcontent = stream->readAll();
      //TEST_FAIL("fcontent is %s \n",fcontent->toValue());
      int size = fcontent->size();
      //TEST_FAIL("encode file size is %d \n",size);

      for(int index = 0;index <size;index++) {
        if(r2->at(index) != fcontent->at(index)) {
            //TEST_FAIL("r2[%d] is %d,array[%d] is %d \n",index,r2->at(index),index,fcontent->at(index));
            TEST_FAIL("[ByteArray Test {encode(File)} case1]");
            break;
        }
      }

      TEST_OK("[ByteArray Test {encode(File)} case2]");
      break;
  }

  //encode(File)
  while(1) {
      Base64 base64 = createBase64();
      String content = createString("<<?\?\?>>");
      ByteArray encode = base64->encodeBase64Url(content->toByteArray());
      if(!encode->toString()->equals("PDw_Pz8-Pg")) {
          TEST_FAIL("[ByteArray Test {encode(File)} case3]");
      }

      ByteArray decode = base64->decodeBase64Url(encode);
      if(!decode->toString()->equals("<<?\?\?>>")) {
          TEST_FAIL("[ByteArray Test {encode(File)} case4]");
      }

      break;
  }

  TEST_OK("[ByteArray Test {encode(File)} case100]");

}
