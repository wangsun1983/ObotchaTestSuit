#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Sha.hpp"
#include "String.hpp"
#include "ByteArray.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void test_sha256() {

    Sha sha1 = createSha(SHA_256);
    //String encrypt(String str);
    while(1) {
        String s = createString("hello world");
        String s1 = sha1->encodeContent(s->toByteArray());
        if(s1 == nullptr ||s1->size() <=0) {
            TEST_FAIL("[TestSha Test {Sha256:encrypt(String)} case1]");
            break;
        }

        TEST_OK("[TestSha Test {Sha256:encrypt(String)} case1]");
        break;
    }


    //String encrypt(File);
    while(1) {
        File f = createFile("test_data.file");
        String s1 = sha1->encodeFile(f);
        if(s1 == nullptr ||s1->size() <=0) {
            TEST_FAIL("[TestSha Test {Sha256:encrypt(File)} case1]");
            break;
        }

        if(!s1->sameAs("6fc8ed2e78684172d2eb63bfd25879622632c1d250307b3b0fbd7574cba8df25")) {
            TEST_FAIL("[TestSha Test {Sha256:encrypt(File)} case2]");
            break;
        }

        TEST_OK("[TestSha Test {Sha256:encrypt(File)} case3]");
        break;
    }


    //ByteArray encryptRawData(ByteArray);
    while(1) {
        ByteArray data = createByteArray(64);
        for(int i = 0;i<64;i++) {
            data[i] = i;
        }

        ByteArray s1 = sha1->encryptRawData(data);
        if(s1 == nullptr ||s1->size() <=0) {
            TEST_FAIL("[TestSha Test {Sha256:encryptRawData(ByteArray)} case1]");
            break;
        }

        TEST_OK("[TestSha Test {Sha256:encryptRawData(ByteArray)} case2]");
        break;
    }
}
