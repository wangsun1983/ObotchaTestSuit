#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Sha.hpp"
#include "String.hpp"
#include "ByteArray.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void test_sha1() {

    Sha sha1 = Sha::New(st(Sha)::Type::Sha1);
    //String encrypt(String str);

    while(1) {
        String s = String::New("hello world");
        String s1 = sha1->encodeContent(s->toByteArray());
        if(s1 == nullptr ||s1->size() <=0) {
            TEST_FAIL("[TestSha Test {Sha1:encrypt(String)} case1]");
            break;
        }

        TEST_OK("[TestSha Test {Sha1:encrypt(String)} case1]");
        break;
    }


    //String encrypt(File);
    while(1) {
        File f = File::New("test_data.file");
        String s1 = sha1->encodeFile(f);
        if(s1 == nullptr ||s1->size() <=0) {
            TEST_FAIL("[TestSha Test {Sha1:encrypt(File)} case1]");
            break;
        }

        if(!s1->sameAs("87f46b278d51870d1b83f420f38438589250e4f5")) {
            TEST_FAIL("[TestSha Test {Sha1:encrypt(File)} case2]");
            TEST_FAIL("s1 is %s \n",s1->toChars());
            break;
        }

        TEST_OK("[TestSha Test {Sha1:encrypt(File)} case3]");
        break;
    }


    //ByteArray encryptRawData(ByteArray);
    while(1) {
        ByteArray data = ByteArray::New(64);
        for(int i = 0;i<64;i++) {
            data[i] = i;
        }

        ByteArray s1 = sha1->encryptRawData(data);
        if(s1 == nullptr ||s1->size() <=0) {
            TEST_FAIL("[TestSha Test {Sha1:encryptRawData(ByteArray)} case1]");
            break;
        }

        TEST_OK("[TestSha Test {Sha1:encryptRawData(ByteArray)} case2]");
        break;
    }
}
