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

using namespace obotcha;

int main() {
  printf("---[ByteArray Test Start]--- \n");
  //decode(String)/encode(String)
  while(1) {
      String abc = "hello world";
      Base64 base64 = createBase64();
      String r1 = base64->encode(abc);
      String r2 = base64->decode(r1);
      if(!r2->equals(abc)) {
          printf("---[ByteArray Test {decode(String)/encode(String)} case1] [FAILED]--- \n");
          break;
      }

      //aGVsbG8gd29ybGQ=
      if(!r1->equals("aGVsbG8gd29ybGQ=")) {
          printf("---[ByteArray Test {decode(String)/encode(String)} case2] [FAILED]--- \n");
          printf("r1 is %s \n",r1->toChars());
          break;
      }

      printf("---[ByteArray Test {decode(String)/encode(String)} case3] [Success]--- \n");
      break;
  }

  //decode(ByteArray)/encode(ByteArray)
  while(1) {
      ByteArray array = createByteArray(32);
      array->fill('a');

      Base64 base64 = createBase64();
      //printf("encode array is %s,size is %d\n",array->toValue(),array->size());
      ByteArray r1 = base64->encode(array);

      ByteArray r2 = base64->decode(r1);
      //printf("r2 is %s,r2 size is %d \n",r2->toValue(),r2->size());

      for(int i = 0;i<32;i++) {
        if(r2->at(i) != array->at(i)) {
          //printf("r2[%d] is %d,array[%d] is %d \n",i,r2->at(i),i,array->at(i));
          printf("---[ByteArray Test {decode(ByteArray)/encode(ByteArray)} case1] [FAILED]--- \n");
          break;
       }
      }

      String str1 = array->toString();
      String str2 = r2->toString();

      if(!str1->equals(str2)) {
          printf("---[ByteArray Test {decode(ByteArray)/encode(ByteArray)} case2] [FAILED]--- \n");
          break;
      }

      printf("---[ByteArray Test {decode(ByteArray)/encode(ByteArray)} case3] [Success]--- \n");
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
      //printf("fcontent is %s \n",fcontent->toValue());
      int size = fcontent->size();
      //printf("encode file size is %d \n",size);

      for(int index = 0;index <size;index++) {
        if(r2->at(index) != fcontent->at(index)) {
            //printf("r2[%d] is %d,array[%d] is %d \n",index,r2->at(index),index,fcontent->at(index));
            printf("---[ByteArray Test {encode(File)} case1] [FAILED]--- \n");
            break;
        }
      }

      printf("---[ByteArray Test {encode(File)} case2] [Success]--- \n");
      break;
  }

  //encode(File)
  while(1) {
      Base64 base64 = createBase64();
      String content = createString("<<?\?\?>>");
      ByteArray encode = base64->encodeBase64Url(content->toByteArray());
      if(!encode->toString()->equals("PDw_Pz8-Pg")) {
          printf("---[ByteArray Test {encode(File)} case3] [FAILED]--- \n");
      }

      ByteArray decode = base64->decodeBase64Url(encode);
      if(!decode->toString()->equals("<<?\?\?>>")) {
          printf("---[ByteArray Test {encode(File)} case4] [FAILED]--- \n");
      }
      
      break;
  }

}
