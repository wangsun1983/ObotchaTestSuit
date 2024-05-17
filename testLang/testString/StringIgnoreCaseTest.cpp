#include <stdio.h>
#include <iostream>
#include <type_traits>

#include <string.h>
#include "String.hpp"
#include "ArrayList.hpp"
#include "NullPointerException.hpp"
#include "ArrayIndexOutOfBoundsException.hpp"
#include "NullPointerException.hpp"
#include "TransformException.hpp"
#include "NullPointerException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void ignorecasetest() {

    //bool equalsIgnoreCase(String str);
    while(1) {
        //case1
        String testString = String::New("ABCDE");
        char value[6] = {'A','B','C','D','E',0x0};
        char value2[6];
        value2[0] = value[0] - 32;
        value2[1] = value[1] - 32;
        value2[2] = value[2] - 32;
        value2[3] = value[3] - 32;
        value2[4] = value[4] - 32;
        value2[5] = 0x0;

        String test1 = String::New(value2);

        if(testString->equalsIgnoreCase(test1)) {
            TEST_FAIL("String equalsIgnoreCase Special test1");
            break;
        }

        //case2
        char value3[6] = {'a','b','c','d','e',0x0};
        String test3 = String::New(value3);

        if(!testString->equalsIgnoreCase(test3)) {
            TEST_FAIL("String equalsIgnoreCase Special test2");
            break;
        }

        //case3
        char value4[6] = {'a','b','c',0x0};
        String test4 = String::New(value4);

        if(testString->equalsIgnoreCase(test4)) {
            TEST_FAIL("String equalsIgnoreCase Special test4");
            break;
        }

        //case4
/*
        try {
            String tmp;
            testString->equalsIgnoreCase(tmp);
            TEST_FAIL("String equalsIgnoreCase Special test5");
            break;
        } catch(NullPointerException e) {}
*/
        //case5
        String testString1 = String::New("AB");
        if(testString->equalsIgnoreCase(testString1)) {
            TEST_FAIL("String equalsIgnoreCase Special test6");
            break;
        }

        //case6
        String testString6 = String::New("ABCDEFG");
        if(testString->equalsIgnoreCase(testString1)) {
            TEST_FAIL("String equalsIgnoreCase Special test7");
            break;
        }

        //case7
        String testString7 = String::New("测试ａｐｋ");
        if(testString->equalsIgnoreCase(testString7)) {
            TEST_FAIL("String equalsIgnoreCase Special test8");
            break;
        }

        //case8
        String testString8 = String::New("abcde");
        if(!testString->equalsIgnoreCase(testString8)) {
            TEST_FAIL("String equalsIgnoreCase Special test9");
            break;
        }


        //case9
        String testString9 = String::New("aBcDe");
        if(!testString->equalsIgnoreCase(testString9)) {
            TEST_FAIL("String equalsIgnoreCase Special test10");
            break;
        }

        //case10
        String testString11 = String::New("a");
        if(testString->equalsIgnoreCase(testString11)) {
            TEST_FAIL("String equalsIgnoreCase Special test11");
            break;
        }

        TEST_OK("String equalsIgnoreCase Special test12");
        break;
    }

    //int indexOfIgnoreCase(String str);
    while(1) {
        String testString = String::New("ABCDE");
        //case1
        String testString1 = String::New("AB");
        if(testString->indexOfIgnoreCase(testString1) != 0) {
            TEST_FAIL("String indexOfIgnoreCase Special test1");
            break;
        }

        //case2
        String testString2 = String::New("ABCDEF");
        if(testString->indexOfIgnoreCase(testString2) != -1) {
            TEST_FAIL("String indexOfIgnoreCase Special test2");
            break;
        }

        //case3
        String testString3 = String::New("ABCDE");
        if(testString->indexOfIgnoreCase(testString3) == -1) {
            TEST_FAIL("String indexOfIgnoreCase Special test3");
            break;
        }

         //case4
        String testString4 = String::New("ab");
        if(testString->indexOfIgnoreCase(testString4) != 0) {
            TEST_FAIL("String indexOfIgnoreCase Special test4");
            break;
        }

        //case5
        String testString5 = String::New("abcdef");
        if(testString->indexOfIgnoreCase(testString5) != -1) {
            TEST_FAIL("String indexOfIgnoreCase Special test5");
            break;
        }

        //case6
        String testString6 = String::New("abcde");
        if(testString->indexOfIgnoreCase(testString6) == -1) {
            TEST_FAIL("String indexOfIgnoreCase Special test6");
            break;
        }

        //case7
/*
        String testString7;
        try {
            testString->indexOfIgnoreCase(testString7);
            TEST_FAIL("String indexOfIgnoreCase Special test7");
            break;
        } catch(NullPointerException e) {}
*/
        //case8
        String testString8 = String::New("bcde");
        if(testString->indexOfIgnoreCase(testString8) != 1) {
            TEST_FAIL("String indexOfIgnoreCase Special test8");
            break;
        }

        //case9
        String testString9 = String::New("b");
        if(testString->indexOfIgnoreCase(testString9) != 1) {
            TEST_FAIL("String indexOfIgnoreCase Special test9");
            break;
        }

        TEST_OK("String indexOfIgnoreCase Special test10");
        break;
    }

    //containsIgnoreCase
    while(1) {
        String testString = String::New("ABCDE");

        //case1
        String testString1 = String::New("AB");
        if(!testString->containsIgnoreCase(testString1)) {
            TEST_FAIL("String containsIgnoreCase Special test1");
            break;
        }

        //case2
        String testString2 = String::New("ABCDEF");
        if(testString->containsIgnoreCase(testString2)) {
            TEST_FAIL("String containsIgnoreCase Special test2");
            break;
        }

        //case3
        String testString3 = String::New("ABCDE");
        if(!testString->containsIgnoreCase(testString3)) {
            TEST_FAIL("String containsIgnoreCase Special test3");
            break;
        }

         //case4
        String testString4 = String::New("ab");
        if(!testString->containsIgnoreCase(testString4)) {
            TEST_FAIL("String containsIgnoreCase Special test4");
            break;
        }

        //case5
        String testString5 = String::New("abcdef");
        if(testString->containsIgnoreCase(testString5)) {
            TEST_FAIL("String containsIgnoreCase Special test5");
            break;
        }

        //case6
        String testString6 = String::New("abcde");
        if(!testString->containsIgnoreCase(testString6)) {
            TEST_FAIL("String containsIgnoreCase Special test6");
            break;
        }

        //case7
/*
        String testString7;
        try {
            testString->containsIgnoreCase(testString7);
            TEST_FAIL("String containsIgnoreCase Special test7");
            break;
        } catch(NullPointerException e) {}
*/

        //case8
        String testString8 = String::New("bcde");
        if(!testString->containsIgnoreCase(testString8)) {
            TEST_FAIL("String containsIgnoreCase Special test8");
            break;
        }

        //case9
        String testString9 = String::New("b");
        if(!testString->containsIgnoreCase(testString9)) {
            TEST_FAIL("String containsIgnoreCase Special test9");
            break;
        }

        TEST_OK("String containsIgnoreCase Special test10");
        break;
    }

    //endsWithIgnoreCase
    while(1) {
        String testString = String::New("ABCDE");
        if(!testString->endsWithIgnoreCase("DEa123",2)) {
            TEST_FAIL("String endsWithIgnoreCase Special test0");
        }
        
        if(testString->endsWithIgnoreCase("DEa123",3)) {
            TEST_FAIL("String endsWithIgnoreCase Special test1");
        }
        
        break;
    }
    
    while(1) {

        String testString = String::New("ABCDE");

        //case1
        String testString1 = String::New("AB");
        if(testString->endsWithIgnoreCase(testString1)) {
            TEST_FAIL("String endsWithIgnoreCase Special test1");
            break;
        }

        //case2
        String testString2 = String::New("ABCDEF");
        if(testString->endsWithIgnoreCase(testString2)) {
            TEST_FAIL("String endsWithIgnoreCase Special test2");
            break;
        }

        //case3
        String testString3 = String::New("ABCDE");
        if(!testString->endsWithIgnoreCase(testString3)) {
            TEST_FAIL("String endsWithIgnoreCase Special test3");
            break;
        }

         //case4
        String testString4 = String::New("ab");
        if(testString->endsWithIgnoreCase(testString4)) {
            TEST_FAIL("String endsWithIgnoreCase Special test4");
            break;
        }

        //case5
        String testString5 = String::New("abcdef");
        if(testString->endsWithIgnoreCase(testString5)) {
            TEST_FAIL("String endsWithIgnoreCase Special test5");
            break;
        }

        //case6
        String testString6 = String::New("abcde");
        if(!testString->endsWithIgnoreCase(testString6)) {
            TEST_FAIL("String endsWithIgnoreCase Special test6");
            break;
        }

        //case7
/*
        String testString7;
        try {
            testString->endsWithIgnoreCase(testString7);
            TEST_FAIL("String endsWithIgnoreCase Special test7");
            break;
        } catch(NullPointerException e) {}
*/
        //case8
        String testString8 = String::New("bcde");
        if(!testString->endsWithIgnoreCase(testString8)) {
            TEST_FAIL("String endsWithIgnoreCase Special test8");
            break;
        }
        
        std::string testString8_ = "bcde";
        if(!testString->endsWithIgnoreCase(testString8_)) {
            TEST_FAIL("String endsWithIgnoreCase Special test8_1");
            break;
        }

        //case9
        String testString9 = String::New("a");
        if(testString->endsWithIgnoreCase(testString9)) {
            TEST_FAIL("String endsWithIgnoreCase Special test9");
            break;
        }
        
        std::string testString9_ = "a";
        if(testString->endsWithIgnoreCase(testString9_)) {
            TEST_FAIL("String endsWithIgnoreCase Special test9_1");
            break;
        }

        //case10
        String testString10 = String::New("e");
        if(!testString->endsWithIgnoreCase(testString10)) {
            TEST_FAIL("String endsWithIgnoreCase Special test10");
            break;
        }
        
        std::string testString10_ = "e";
        if(!testString->endsWithIgnoreCase(testString10_)) {
            TEST_FAIL("String endsWithIgnoreCase Special test10_1");
            break;
        }
        
        //case1
        if(testString->endsWithIgnoreCase("AB")) {
            TEST_FAIL("String endsWithIgnoreCase Special test10_1");
            break;
        }

        //case2
        if(testString->endsWithIgnoreCase("ABCDEF")) {
            TEST_FAIL("String endsWithIgnoreCase Special test10_2");
            break;
        }

        //case3
        if(!testString->endsWithIgnoreCase("ABCDE")) {
            TEST_FAIL("String endsWithIgnoreCase Special test10_3");
            break;
        }

         //case4
        if(testString->endsWithIgnoreCase("ab")) {
            TEST_FAIL("String endsWithIgnoreCase Special test10_4");
            break;
        }

        //case5
        if(testString->endsWithIgnoreCase("abcdef")) {
            TEST_FAIL("String endsWithIgnoreCase Special test10_5");
            break;
        }

        //case6
        if(!testString->endsWithIgnoreCase("abcde")) {
            TEST_FAIL("String endsWithIgnoreCase Special test10_6");
            break;
        }

        //case8
        if(!testString->endsWithIgnoreCase("bcde")) {
            TEST_FAIL("String endsWithIgnoreCase Special test10_8");
            break;
        }

        //case9
        if(testString->endsWithIgnoreCase("a")) {
            TEST_FAIL("String endsWithIgnoreCase Special test10_9");
            break;
        }

        //case10
        if(!testString->endsWithIgnoreCase("e")) {
            TEST_FAIL("String endsWithIgnoreCase Special test10_10");
            break;
        }

        TEST_OK("String endsWithIgnoreCase Special test11");
        break;
    }

    //lastIndexOfIgnoreCase
    while(1) {
        String testString = String::New("ABCDABE");

        //case1
        String testString1 = String::New("AB");
        if(testString->lastIndexOfIgnoreCase(testString1) != 4) {
            TEST_FAIL("String lastIndexOfIgnoreCase Special test1");
            break;
        }

        //case2
        String testString2 = String::New("ABCDEF");
        if(testString->lastIndexOfIgnoreCase(testString2) != -1) {
            TEST_FAIL("String lastIndexOfIgnoreCase Special test2");
            break;
        }


        //case3
        String testString3 = String::New("ABCD");
        //TEST_FAIL("test3 is %d \n",testString->lastIndexOfIgnoreCase(testString3));
        if(testString->lastIndexOfIgnoreCase(testString3) != 0) {
            TEST_FAIL("String lastIndexOfIgnoreCase Special test3");
            break;
        }


         //case4
        String testString4 = String::New("ab");
        if(testString->lastIndexOfIgnoreCase(testString4) != 4) {
            TEST_FAIL("String lastIndexOfIgnoreCase Special test4");
            break;
        }

        //case5
        String testString5 = String::New("abcdef");
        if(testString->lastIndexOfIgnoreCase(testString5) != -1) {
            TEST_FAIL("String lastIndexOfIgnoreCase Special test5");
            break;
        }

        //case6
        String testString6 = String::New("abcdabe");
        if(testString->lastIndexOfIgnoreCase(testString6) != 0) {
            TEST_FAIL("String lastIndexOfIgnoreCase Special test6");
            break;
        }

        //case7
/*
        String testString7;
        try {
            testString->lastIndexOfIgnoreCase(testString7);
            TEST_FAIL("String lastIndexOfIgnoreCase Special test7");
            break;
        } catch(NullPointerException e) {}
*/
        //case8
        String testString8 = String::New("dabe");
        if(testString->lastIndexOfIgnoreCase(testString8) != 3) {
            TEST_FAIL("String lastIndexOfIgnoreCase Special test8");
            break;
        }

        //case9
        String testString9 = String::New("a");
        if(testString->lastIndexOfIgnoreCase(testString9) != 4) {
            TEST_FAIL("String lastIndexOfIgnoreCase Special test9");
            break;
        }

        TEST_OK("String lastIndexOfIgnoreCase Special test10");
        break;

    }
    
    while(1) {
        String testString = String::New("ABCDABE");

        //case1
        if(testString->lastIndexOfIgnoreCase("AB") != 4) {
            TEST_FAIL("String lastIndexOfIgnoreCase Special test11");
            break;
        }

        //case2
        if(testString->lastIndexOfIgnoreCase("ABCDEF") != -1) {
            TEST_FAIL("String lastIndexOfIgnoreCase Special test12");
            break;
        }


        //case3
        if(testString->lastIndexOfIgnoreCase("ABCD") != 0) {
            TEST_FAIL("String lastIndexOfIgnoreCase Special test13");
            break;
        }


         //case4
        if(testString->lastIndexOfIgnoreCase("ab") != 4) {
            TEST_FAIL("String lastIndexOfIgnoreCase Special test14");
            break;
        }

        //case5
        if(testString->lastIndexOfIgnoreCase("abcdef") != -1) {
            TEST_FAIL("String lastIndexOfIgnoreCase Special test15");
            break;
        }

        //case6
        if(testString->lastIndexOfIgnoreCase("abcdabe") != 0) {
            TEST_FAIL("String lastIndexOfIgnoreCase Special test16");
            break;
        }

        //case8
        if(testString->lastIndexOfIgnoreCase("dabe") != 3) {
            TEST_FAIL("String lastIndexOfIgnoreCase Special test18");
            break;
        }

        //case9
        if(testString->lastIndexOfIgnoreCase("a") != 4) {
            TEST_FAIL("String lastIndexOfIgnoreCase Special test19");
            break;
        }

        TEST_OK("String lastIndexOfIgnoreCase Special test20");
        break;

    }

}
