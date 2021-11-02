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

using namespace obotcha;

void ignorecasetest() {

    //bool equalsIgnoreCase(String str);
    while(1) {
        //case1
        String testString = createString("ABCDE");
        char value[6] = {'A','B','C','D','E',0x0};
        char value2[6];
        value2[0] = value[0] - 32;
        value2[1] = value[1] - 32;
        value2[2] = value[2] - 32;
        value2[3] = value[3] - 32;
        value2[4] = value[4] - 32;
        value2[5] = 0x0;

        String test1 = createString(value2);

        if(testString->equalsIgnoreCase(test1)) {
            printf("String equalsIgnoreCase Special test1-------[FAIL] is %s\n",test1->toChars());
            break;
        }

        //case2
        char value3[6] = {'a','b','c','d','e',0x0};
        String test3 = createString(value3);

        if(!testString->equalsIgnoreCase(test3)) {
            printf("String equalsIgnoreCase Special test2-------[FAIL] \n");
            break;
        }

        //case3
        char value4[6] = {'a','b','c',0x0};
        String test4 = createString(value4);

        if(testString->equalsIgnoreCase(test4)) {
            printf("String equalsIgnoreCase Special test4-------[FAIL] \n");
            break;
        }

        //case4
/*
        try {
            String tmp;
            testString->equalsIgnoreCase(tmp);
            printf("String equalsIgnoreCase Special test5-------[FAIL] \n");
            break;
        } catch(NullPointerException e) {}
*/
        //case5
        String testString1 = createString("AB");
        if(testString->equalsIgnoreCase(testString1)) {
            printf("String equalsIgnoreCase Special test6-------[FAIL] \n");
            break;
        }

        //case6
        String testString6 = createString("ABCDEFG");
        if(testString->equalsIgnoreCase(testString1)) {
            printf("String equalsIgnoreCase Special test7-------[FAIL] \n");
            break;
        }

        //case7
        String testString7 = createString("测试ａｐｋ");
        if(testString->equalsIgnoreCase(testString7)) {
            printf("String equalsIgnoreCase Special test8-------[FAIL] \n");
            break;
        }

        //case8
        String testString8 = createString("abcde");
        if(!testString->equalsIgnoreCase(testString8)) {
            printf("String equalsIgnoreCase Special test9-------[FAIL] \n");
            break;
        }


        //case9
        String testString9 = createString("aBcDe");
        if(!testString->equalsIgnoreCase(testString9)) {
            printf("String equalsIgnoreCase Special test10-------[FAIL] \n");
            break;
        }

        //case10
        String testString11 = createString("a");
        if(testString->equalsIgnoreCase(testString11)) {
            printf("String equalsIgnoreCase Special test11-------[FAIL] \n");
            break;
        }

        printf("String equalsIgnoreCase Special test12-------[Success] \n");
        break;
    }

    //int indexOfIgnoreCase(String str);
    while(1) {
        String testString = createString("ABCDE");
        //case1
        String testString1 = createString("AB");
        if(testString->indexOfIgnoreCase(testString1) != 0) {
            printf("String indexOfIgnoreCase Special test1-------[FAIL] \n");
            break;
        }

        //case2
        String testString2 = createString("ABCDEF");
        if(testString->indexOfIgnoreCase(testString2) != -1) {
            printf("String indexOfIgnoreCase Special test2-------[FAIL] \n");
            break;
        }

        //case3
        String testString3 = createString("ABCDE");
        if(testString->indexOfIgnoreCase(testString3) == -1) {
            printf("String indexOfIgnoreCase Special test3-------[FAIL] \n");
            break;
        }

         //case4
        String testString4 = createString("ab");
        if(testString->indexOfIgnoreCase(testString4) != 0) {
            printf("String indexOfIgnoreCase Special test4-------[FAIL] \n");
            break;
        }

        //case5
        String testString5 = createString("abcdef");
        if(testString->indexOfIgnoreCase(testString5) != -1) {
            printf("String indexOfIgnoreCase Special test5-------[FAIL] \n");
            break;
        }

        //case6
        String testString6 = createString("abcde");
        if(testString->indexOfIgnoreCase(testString6) == -1) {
            printf("String indexOfIgnoreCase Special test6-------[FAIL] \n");
            break;
        }

        //case7
/*
        String testString7;
        try {
            testString->indexOfIgnoreCase(testString7);
            printf("String indexOfIgnoreCase Special test7-------[FAIL] \n");
            break;
        } catch(NullPointerException e) {}
*/
        //case8
        String testString8 = createString("bcde");
        if(testString->indexOfIgnoreCase(testString8) != 1) {
            printf("String indexOfIgnoreCase Special test8-------[FAIL] \n");
            break;
        }

        //case9
        String testString9 = createString("b");
        if(testString->indexOfIgnoreCase(testString9) != 1) {
            printf("String indexOfIgnoreCase Special test9-------[FAIL] \n");
            break;
        }

        printf("String indexOfIgnoreCase Special test10-------[Success] \n");
        break;
    }

    //containsIgnoreCase
    while(1) {
        String testString = createString("ABCDE");

        //case1
        String testString1 = createString("AB");
        if(!testString->containsIgnoreCase(testString1)) {
            printf("String containsIgnoreCase Special test1-------[FAIL] \n");
            break;
        }

        //case2
        String testString2 = createString("ABCDEF");
        if(testString->containsIgnoreCase(testString2)) {
            printf("String containsIgnoreCase Special test2-------[FAIL] \n");
            break;
        }

        //case3
        String testString3 = createString("ABCDE");
        if(!testString->containsIgnoreCase(testString3)) {
            printf("String containsIgnoreCase Special test3-------[FAIL] \n");
            break;
        }

         //case4
        String testString4 = createString("ab");
        if(!testString->containsIgnoreCase(testString4)) {
            printf("String containsIgnoreCase Special test4-------[FAIL] \n");
            break;
        }

        //case5
        String testString5 = createString("abcdef");
        if(testString->containsIgnoreCase(testString5)) {
            printf("String containsIgnoreCase Special test5-------[FAIL] \n");
            break;
        }

        //case6
        String testString6 = createString("abcde");
        if(!testString->containsIgnoreCase(testString6)) {
            printf("String containsIgnoreCase Special test6-------[FAIL] \n");
            break;
        }

        //case7
/*
        String testString7;
        try {
            testString->containsIgnoreCase(testString7);
            printf("String containsIgnoreCase Special test7-------[FAIL] \n");
            break;
        } catch(NullPointerException e) {}
*/

        //case8
        String testString8 = createString("bcde");
        if(!testString->containsIgnoreCase(testString8)) {
            printf("String containsIgnoreCase Special test8-------[FAIL] \n");
            break;
        }

        //case9
        String testString9 = createString("b");
        if(!testString->containsIgnoreCase(testString9)) {
            printf("String containsIgnoreCase Special test9-------[FAIL] \n");
            break;
        }

        printf("String containsIgnoreCase Special test10-------[Success] \n");
        break;
    }

    //endsWithIgnoreCase
    while(1) {

        String testString = createString("ABCDE");

        //case1
        String testString1 = createString("AB");
        if(testString->endsWithIgnoreCase(testString1)) {
            printf("String endsWithIgnoreCase Special test1-------[FAIL] \n");
            break;
        }

        //case2
        String testString2 = createString("ABCDEF");
        if(testString->endsWithIgnoreCase(testString2)) {
            printf("String endsWithIgnoreCase Special test2-------[FAIL] \n");
            break;
        }

        //case3
        String testString3 = createString("ABCDE");
        if(!testString->endsWithIgnoreCase(testString3)) {
            printf("String endsWithIgnoreCase Special test3-------[FAIL] \n");
            break;
        }

         //case4
        String testString4 = createString("ab");
        if(testString->endsWithIgnoreCase(testString4)) {
            printf("String endsWithIgnoreCase Special test4-------[FAIL] \n");
            break;
        }

        //case5
        String testString5 = createString("abcdef");
        if(testString->endsWithIgnoreCase(testString5)) {
            printf("String endsWithIgnoreCase Special test5-------[FAIL] \n");
            break;
        }

        //case6
        String testString6 = createString("abcde");
        if(!testString->endsWithIgnoreCase(testString6)) {
            printf("String endsWithIgnoreCase Special test6-------[FAIL] \n");
            break;
        }

        //case7
/*
        String testString7;
        try {
            testString->endsWithIgnoreCase(testString7);
            printf("String endsWithIgnoreCase Special test7-------[FAIL] \n");
            break;
        } catch(NullPointerException e) {}
*/
        //case8
        String testString8 = createString("bcde");
        if(!testString->endsWithIgnoreCase(testString8)) {
            printf("String endsWithIgnoreCase Special test8-------[FAIL] \n");
            break;
        }

        //case9
        String testString9 = createString("a");
        if(testString->endsWithIgnoreCase(testString9)) {
            printf("String endsWithIgnoreCase Special test9-------[FAIL] \n");
            break;
        }

        //case10
        String testString10 = createString("e");
        if(!testString->endsWithIgnoreCase(testString10)) {
            printf("String endsWithIgnoreCase Special test10-------[FAIL] \n");
            break;
        }

        printf("String endsWithIgnoreCase Special test11-------[Success] \n");
        break;
    }

    //lastIndexOfIgnoreCase
    while(1) {
        String testString = createString("ABCDABE");

        //case1
        String testString1 = createString("AB");
        if(testString->lastIndexOfIgnoreCase(testString1) != 4) {
            printf("String lastIndexOfIgnoreCase Special test1-------[FAIL] \n");
            break;
        }

        //case2
        String testString2 = createString("ABCDEF");
        if(testString->lastIndexOfIgnoreCase(testString2) != -1) {
            printf("String lastIndexOfIgnoreCase Special test2-------[FAIL] \n");
            break;
        }


        //case3
        String testString3 = createString("ABCD");
        //printf("test3 is %d \n",testString->lastIndexOfIgnoreCase(testString3));
        if(testString->lastIndexOfIgnoreCase(testString3) != 0) {
            printf("String lastIndexOfIgnoreCase Special test3-------[FAIL] \n");
            break;
        }


         //case4
        String testString4 = createString("ab");
        if(testString->lastIndexOfIgnoreCase(testString4) != 4) {
            printf("String lastIndexOfIgnoreCase Special test4-------[FAIL] \n");
            break;
        }

        //case5
        String testString5 = createString("abcdef");
        if(testString->lastIndexOfIgnoreCase(testString5) != -1) {
            printf("String lastIndexOfIgnoreCase Special test5-------[FAIL] \n");
            break;
        }

        //case6
        String testString6 = createString("abcdabe");
        if(testString->lastIndexOfIgnoreCase(testString6) != 0) {
            printf("String lastIndexOfIgnoreCase Special test6-------[FAIL] \n");
            break;
        }

        //case7
/*
        String testString7;
        try {
            testString->lastIndexOfIgnoreCase(testString7);
            printf("String lastIndexOfIgnoreCase Special test7-------[FAIL] \n");
            break;
        } catch(NullPointerException e) {}
*/
        //case8
        String testString8 = createString("dabe");
        if(testString->lastIndexOfIgnoreCase(testString8) != 3) {
            printf("String lastIndexOfIgnoreCase Special test8-------[FAIL] \n");
            break;
        }

        //case9
        String testString9 = createString("a");
        if(testString->lastIndexOfIgnoreCase(testString9) != 4) {
            printf("String lastIndexOfIgnoreCase Special test9-------[FAIL] \n");
            break;
        }

        printf("String lastIndexOfIgnoreCase Special test10-------[Success] \n");
        break;

    }

}
