#include <stdio.h>

#include "Md.hpp"
#include "File.hpp"
#include "TestLog.hpp"

using namespace obotcha;

int test_md2() {
    File f = createFile("test_data.file");
    // String encrypt(File);
    while(1) {
        Md md = createMd(st(Md)::Md2);
        String result = md->encrypt(f);
#ifndef OPENSSL_NO_MD2
        if(result != nullptr) {
            TEST_FAIL("[TestMd5 Test {Md2:encrypt(File)} case1]");
            break;
        }
#else
        if(result == nullptr || result->size() == 0) {
            TEST_FAIL("[TestMd5 Test {Md2:encrypt(File)} case1]");
            break;
        }
#endif
        TEST_OK("[TestMd5 Test {Md2:encrypt(File)} case2]");
        break;

    }

    //String encrypt(String);
    while(1) {
        Md md = createMd(st(Md)::Md2);
        String str = createString("hello world");
        String result = md->encrypt(str);
#ifndef OPENSSL_NO_MD2
        if(result != nullptr) {
            TEST_FAIL("[TestMd5 Test {Md2:encrypt(String)} case1]");
            break;
        }
#else
        if(result == nullptr || result->size() == 0) {
            TEST_FAIL("[TestMd5 Test {Md2:encrypt(String)} case1]");
            break;
        }
#endif
        TEST_OK("[TestMd5 Test {Md2:encrypt(String)} case2]");
        break;

    }

    return 0;
}
