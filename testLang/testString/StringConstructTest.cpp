#include <stdio.h>
#include <iostream>
#include <type_traits>

#include <string.h>
#include "String.hpp"
#include "ArrayList.hpp"
#include "NullPointerException.hpp"
#include "ArrayIndexOutOfBoundsException.hpp"
#include "IllegalArgumentException.hpp"
#include "TransformException.hpp"
#include "IllegalArgumentException.hpp"

#include "TestLog.hpp"

using namespace obotcha;

void StringConstructTest() {
    //String append(String s);
    while(1) {
        std::string str = "abc";
        String str1 = String::New(&str);
        if(!str1->sameAs("abc")) {
            TEST_FAIL("String construct test1");
            break;
        }

        String str2 = String::New(str);
        if(!str2->sameAs("abc")) {
            TEST_FAIL("String construct test2");
            break;
        }

        String str3 = String::New(str2);
        if(!str3->sameAs("abc")) {
            TEST_FAIL("String construct test3");
            break;
        }

        String str4 = String::New("abc");
        if(!str4->sameAs("abc")) {
            TEST_FAIL("String construct test4");
            break;
        }

        String str5 = String::New("abcd",1,3);
        if(!str5->sameAs("bcd")) {
            TEST_FAIL("String construct test5");
            break;
        }

        bool isException = false;
        try {
            String str5 = String::New("abcd",1,6);
        } catch(...) {
            isException = true;
        }

        try {
            String str5 = String::New("abcd",-1,6);
        } catch(...) {
            isException = true;
        }

        try {
            String str5 = String::New("abcd",-1,-1);
        } catch(...) {
            isException = true;
        }

        if(!isException) {
            TEST_FAIL("String construct test6");
            break;
        }

        //
        Integer v1 = Integer::New(1200);
        String str6 = String::New(v1);
        if(!str6->sameAs("1200")) {
            TEST_FAIL("String construct test7");
            break;
        }

        //
        Boolean v2 = Boolean::New(false);
        String str7 = String::New(v2);
        if(!str7->sameAs("false")) {
            TEST_FAIL("String construct test8");
            break;
        }

        Boolean v3 = Boolean::New(true);
        String str8 = String::New(v3);
        if(!str8->sameAs("true")) {
            TEST_FAIL("String construct test9");
            break;
        }

/*
        Float v4 = Float::New(100.0001);
        String str9 = String::New(v4);
        if(!str9->sameAs("100.0001")) {
            TEST_FAIL("String construct test10-------[FAIL] str9 is %s\n",str9->toChars());
            break;
        }

        //
        Double v5 = Double::New(200.3322);
        String str10 = String::New(v5);
        if(!str10->sameAs("200.0002")) {
            TEST_FAIL("String construct test11-------[FAIL],str10 is %s \n",str10->toChars());
            break;
        }
*/
        //
        Long v6 = Long::New(200);
        String str11 = String::New(v6);
        if(!str11->sameAs("200")) {
            TEST_FAIL("String construct test12");
            break;
        }

        //
        Uint8 v7 = Uint8::New(200);
        String str12 = String::New(v7);
        if(!str12->sameAs("200")) {
            TEST_FAIL("String construct test13");
            break;
        }

        //
        Uint16 v8 = Uint16::New(12200);
        String str13 = String::New(v8);
        if(!str13->sameAs("12200")) {
            TEST_FAIL("String construct test14");
            break;
        }

        //
        Uint32 v9 = Uint32::New(12200);
        String str14 = String::New(v9);
        if(!str14->sameAs("12200")) {
            TEST_FAIL("String construct test15");
            break;
        }

        //
        Uint64 v10 = Uint64::New(12200);
        String str15 = String::New(v10);
        if(!str15->sameAs("12200")) {
            TEST_FAIL("String construct test16");
            break;
        }

        //
        Byte v11 = Byte::New(22);
        String str16 = String::New(v11);
        if(!str16->sameAs("22")) {
            TEST_FAIL("String construct test17");
            break;
        }

        //_String(int v);
        int v12 = 100;
        String str17 = String::New(v12);
        if(!str17->sameAs("100")) {
            TEST_FAIL("String construct test18");
            break;
        }


        //_String(bool v);
        bool v13 = false;
        String str18 = String::New(v13);
        if(!str18->sameAs("false")) {
            TEST_FAIL("String construct test19");
            break;
        }

        bool v14 = true;
        String str19 = String::New(v14);
        if(!str19->sameAs("true")) {
            TEST_FAIL("String construct test20");
            break;
        }

/*
        //_String(float v);
        float v15 = 11.112;
        String str20 = String::New(v15);
        if(!str20->sameAs("11.112")) {
            TEST_FAIL("String construct test21");
            break;
        }

        //_String(double v);
        double v16 = 11.112;
        String str21 = String::New(v16);
        if(!str21->sameAs("11.112")) {
            TEST_FAIL("String construct test22");
            break;
        }
*/
        //_String(long v);
        long v17 = 1200;
        String str22 = String::New(v17);
        if(!str22->sameAs("1200")) {
            TEST_FAIL("String construct test23");
            break;
        }

        //_String(char v);
        char v18 = 112;
        String str23 = String::New(v18);
        if(!str23->sameAs("p")) {
            TEST_FAIL("String construct test24,str23 is %s ",str23->toChars());
            break;
        }

        //_String(uint8_t);
        uint8_t v19 = 112;
        String str24 = String::New(v19);
        if(!str24->sameAs("112")) {
            TEST_FAIL("String construct test25");
            break;
        }

        //_String(uint16_t);
        uint16_t v20 = 1112;
        String str25 = String::New(v20);
        if(!str25->sameAs("1112")) {
            TEST_FAIL("String construct test26");
            break;
        }

        //_String(uint32_t);
        uint32_t v21 = 1113332;
        String str26 = String::New(v21);
        if(!str26->sameAs("1113332")) {
            TEST_FAIL("String construct test27");
            break;
        }

        //_String(uint64_t);
        uint32_t v22 = 111334432;
        String str27 = String::New(v22);
        if(!str27->sameAs("111334432")) {
            TEST_FAIL("String construct test28");
            break;
        }

        TEST_OK("String construct test100");
        break;
    }
}
