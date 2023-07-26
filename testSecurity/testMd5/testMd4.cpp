#include <stdio.h>

#include "Md.hpp"
#include "File.hpp"
#include "TestLog.hpp"

using namespace obotcha;

int test_md4() {
    File f = createFile("test_data.file");
    // String encrypt(File);
    while(1) {
        Md md = createMd(st(Md)::Md4);
        String result = md->encodeFile(f);

        if(result == nullptr || result->size() == 0) {
            TEST_FAIL("[TestMd5 Test {Md4:encrypt(File)} case1]");
            break;
        }

        TEST_OK("[TestMd5 Test {Md4:encrypt(File)} case2]");
        break;

    }

    //String encrypt(String);
    while(1) {
        Md md = createMd(st(Md)::Md4);
        String str = createString("hello world");
        String result = md->encodeContent(str->toByteArray());

        if(result == nullptr || result->size() == 0) {
            TEST_FAIL("[TestMd5 Test {Md4:encrypt(String)} case1]");
            break;
        }

        TEST_OK("[TestMd5 Test {Md4:encrypt(String)} case2]");
        break;
    }

    return 0;
}
