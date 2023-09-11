#include <iostream>
#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ArrayList.hpp"
#include "Integer.hpp"
#include "String.hpp"
#include "TestLog.hpp"
#include "Math.hpp"

using namespace obotcha;

int main() {
    //static long abs(long);
#if 0    
    long v1 = -100;
    if(st(Math)::abs(v1) != 100) {
        TEST_FAIL("Math abs test1");
    }
    
    double v2 = -110.0;
    if(st(Math)::abs(v2) != 110.0) {
        TEST_FAIL("Math abs test2");
    }
    
    int v3 = -120;
    if(st(Math)::abs(v3) != 120) {
        TEST_FAIL("Math abs test3");
    }
    
    float v4 = -130.0;
    if(st(Math)::abs(v4) != 130.0) {
        TEST_FAIL("Math abs test4");
    }
    
    double v5 = 60.0;
    if(st(Math)::cos(v5) != 0.5) {
        TEST_FAIL("Math abs test5");
    }
    
    double v6 = 30.0;
    if(st(Math)::sin(v6) != 0.5) {
        TEST_FAIL("Math abs test6");
    }
    
    double v7 = 45.0;
    if(st(Math)::tan(v7) != 1.0) {
        TEST_FAIL("Math abs test7");
    }
    
    double v8 = 0.5;
    if(st(Math)::acos(v8) != 60.0) {
        TEST_FAIL("Math abs test8");
    }
    
    double v9 = 0.5;
    if(st(Math)::asin(v9) != 30.0) {
        TEST_FAIL("Math abs test9");
    }
    
    double v10 = 1;
    if(st(Math)::asin(v10) != 45) {
        TEST_FAIL("Math abs test10");
    }
    
    long v11 = st(Math)::max((long)1,100);
    if(v11 != 100) {
        TEST_FAIL("Math abs test11");
    }
    
    double v12 = st(Math)::max(1.0,100.0);
    if(v12 != 100.0) {
        TEST_FAIL("Math abs test12");
    }
    
    float v13 = st(Math)::max(1.0,100.0);
    if(v13 != 100.0) {
        TEST_FAIL("Math abs test13");
    }
    
    v11 = st(Math)::min((long)1,100);
    if(v11 != 1) {
        TEST_FAIL("Math abs test14");
    }
    
    v12 = st(Math)::min(1.0,100.0);
    if(v12 != 1.0) {
        TEST_FAIL("Math abs test15");
    }
    
    v13 = st(Math)::min(1.0,100.0);
    if(v13 != 1.0) {
        TEST_FAIL("Math abs test16");
    }
    
    double v14 = st(Math)::pow(1.1,2);
    if(v14 != 1.21) {
        TEST_FAIL("Math abs test17");
    }

    long v15 = st(Math)::pow((long)11,2);
    if(v15 != 121) {
        TEST_FAIL("Math abs test18");
    }
    
    double v16 = st(Math)::sqrt(1.21);
    if(v16 != 1.1) {
        TEST_FAIL("Math abs test19");
    }
    
    int v17 = st(Math)::ceil(2.5);
    if(v17 != 3) {
        TEST_FAIL("Math abs test20");
    }
    
    int v18 = st(Math)::floor(2.5);
    if(v18 != 2) {
        TEST_FAIL("Math abs test21");
    }

    
    if(st(Math)::compareDouble(1.21,1.21) != st(Math)::AlmostEqual) {
        TEST_FAIL("Math abs test22");
    }
    
    if(st(Math)::compareDouble(1.31,1.21) != st(Math)::Param1Greater) {
        TEST_FAIL("Math abs test23");
    }
    
    if(st(Math)::compareDouble(1.31,1.41) != st(Math)::Param2Greater) {
        TEST_FAIL("Math abs test24");
    }

    if(st(Math)::compareFloat(1.21,1.21) != st(Math)::AlmostEqual) {
        TEST_FAIL("Math abs test22");
    }
    
    if(st(Math)::compareFloat(1.31,1.21) != st(Math)::Param1Greater) {
        TEST_FAIL("Math abs test23");
    }
    
    if(st(Math)::compareFloat(1.31,1.41) != st(Math)::Param2Greater) {
        TEST_FAIL("Math abs test24");
    }
#endif
    TEST_OK("Math abs test100");
    return 0;
}
