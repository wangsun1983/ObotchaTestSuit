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

using namespace obotcha;

void StringContentEqualsTest() {
    
    while(1) {
        String a = "a";
        String b = "a";
        if(!st(String)::contentEquals(a,b)) {
            printf("String ContentEquals test1-------[FAIL] \n");
            break;
        }

        String a1 = "a";
        String b1 = "b";
        if(st(String)::contentEquals(a1,b1)) {
            printf("String ContentEquals test2-------[FAIL] \n");
            break;
        }

        String a2 = "a";
        String b2 = nullptr;
        if(st(String)::contentEquals(a2,b2)) {
            printf("String ContentEquals test3-------[FAIL] \n");
            break;
        }

        String a3 = nullptr;
        String b3 = "a";
        if(st(String)::contentEquals(a3,b3)) {
            printf("String ContentEquals test4-------[FAIL] \n");
            break;
        }

        String a4 = nullptr;
        String b4 = nullptr;
        if(!st(String)::contentEquals(a4,b4)) {
            printf("String ContentEquals test5-------[FAIL] \n");
            break;
        }

        break;
    }


    while(1) {
        String a = "abc";
        String b = "ABC";
        if(!st(String)::contentEqualsIgnoreCase(a,b)) {
            printf("String ContentEquals test6-------[FAIL] \n");
            break;
        }

        String a1 = "ABC";
        String b1 = "ABC";
        if(!st(String)::contentEqualsIgnoreCase(a1,b1)) {
            printf("String ContentEquals test7-------[FAIL] \n");
            break;
        }

        String a2 = "ABC";
        String b2 = nullptr;
        if(st(String)::contentEqualsIgnoreCase(a2,b2)) {
            printf("String ContentEquals test8-------[FAIL] \n");
            break;
        }

        String a3 = nullptr;
        String b3 = "a";
        if(st(String)::contentEqualsIgnoreCase(a3,b3)) {
            printf("String ContentEquals test9-------[FAIL] \n");
            break;
        }

        String a4 = nullptr;
        String b4 = nullptr;
        if(!st(String)::contentEqualsIgnoreCase(a4,b4)) {
            printf("String ContentEquals test10-------[FAIL] \n");
            break;
        }

        break;
    }

    printf("String ContentEquals test100-------[OK] \n");
}
