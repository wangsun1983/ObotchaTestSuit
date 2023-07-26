#include <stdio.h>

#include "Md.hpp"
#include "File.hpp"
#include "TestLog.hpp"

using namespace obotcha;

int test_md5() {
    File f = createFile("test_data.file");
    // String encrypt(File);
    while(1) {
        Md md = createMd(st(Md)::Md5);
        String result = md->encodeFile(f);

        if(result == nullptr || result->size() == 0) {
            TEST_FAIL("[TestMd5 Test {Md5:encrypt(File)} case1]");
            break;
        }

        if(!result->sameAs("b1203a74f727d920322d388b279c3b2c")) {
            TEST_FAIL("[TestMd5 Test {Md5:encrypt(File)} case1]");
            break;
        }

        TEST_OK("[TestMd5 Test {Md5:encrypt(File)} case2]");
        break;

    }

    //String encrypt(String);
    while(1) {
        Md md = createMd(st(Md)::Md5);
        String str = createString("hello world");
        String result = md->encodeContent(str->toByteArray());

        if(result == nullptr || result->size() == 0) {
            TEST_FAIL("[TestMd5 Test {Md5:encrypt(String)} case1]");
            break;
        }

        TEST_OK("[TestMd5 Test {Md5:encrypt(String)} case2]");
        break;
    }

    return 0;
}
