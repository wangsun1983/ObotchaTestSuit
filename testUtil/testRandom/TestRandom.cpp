#include <stdio.h>
#include <unistd.h>
#include "Math.hpp"
#include "Random.hpp"
#include "TestLog.hpp"

using namespace obotcha;

int main() {

    //int nextInt()
    while(1) {
        int array[1000];
        bool isOk = true;
        Random rand = createRandom();
        for(int index = 0;index < 1000;index++) {
            int v1 = rand->nextInt();
            for(int ckindex = 0;ckindex < index;ckindex++) {
                if(v1 == array[ckindex]) {
                    isOk = false;
                    break;
                }
            }

            array[index] = v1;

            if(!isOk) {
                TEST_FAIL("[TestRandom Test {nextInt(int)} case1]");
                break;
            }
        }

        if(isOk) {
            TEST_OK("[TestRandom Test {nextInt(int)} case2]");
            break;
        }

        break;
    }

    //static int nextInt(int min,int max);
    while(1) {
        int max = 100;
        int min = 10;
        Random rand = createRandom();
        for(int index = 0;index < 100000;index++) {
            int v = rand->nextInt(min,max);
            if(v > max || v < min) {
                TEST_FAIL("[TestRandom Test {nextInt(int,int)} case1] [FAIL] ");
                break;
            }
        }

        TEST_OK("[TestRandom Test {nextInt(int,int)} case2]");
        break;
    }

    //static int nextInt(int min);
    while(1) {
        int min = 10;
        Random rand = createRandom();
        for(int index = 0;index < 100000;index++) {
            int v = rand->nextInt(min);
            if(v < min) {
                TEST_FAIL("[TestRandom Test {nextInt(int)} case1] [FAIL] ");
                break;
            }
        }

        TEST_OK("[TestRandom Test {nextInt(int)} case2]");
        break;
    }

    //static double nextDouble();
    while(1) {
        double array[1000];
        bool isOk = true;
        Random rand = createRandom();
        for(int index = 0;index < 1000;index++) {
            double v1 = rand->nextDouble();
            //std::cout<<"v1 is "<<v1;
            for(int ckindex = 0;ckindex < index;ckindex++) {
                //if(v1 == array[ckindex]) {
                if(st(Math)::compareDouble(v1,array[ckindex]) == st(Math)::AlmostEqual) {
                    std::cout<<"v1 is "<<v1<<";array["<<ckindex<<"] = "<<array[ckindex]<<std::endl;
                    isOk = false;
                    break;
                }
            }

            array[index] = v1;

            if(!isOk) {
                TEST_FAIL("[TestRandom Test {nextDouble()} case1]");
                break;
            }
        }

        if(isOk) {
            TEST_OK("[TestRandom Test {nextDouble()} case2]");
            break;
        }

        break;
    }



    //static double nextDouble(double min,double max);
    while(1) {
        Random rand = createRandom();
        for(int index = 0;index < 1000;index++) {
            double min = 10.0001;
            double max = 15.00001;
            double t = rand->nextDouble(min,max);
            if(st(Math)::compareDouble(t,min) == st(Math)::Param2Greater || st(Math)::compareDouble(t,max) == st(Math)::Param1Greater) {
                TEST_FAIL("[TestRandom Test {nextDouble(double,double)} case1]");
                break;
            }
        }

        TEST_OK("[TestRandom Test {nextDouble(double,double)} case2]");
        break;
    }

    //static double nextDouble(double min);
    while(1) {
        Random rand = createRandom();
        for(int index = 0;index < 1000;index++) {
            double min = 10.0001;
            double t = rand->nextDouble(min);
            if(st(Math)::compareDouble(t,min) == st(Math)::Param2Greater) {
                TEST_FAIL("[TestRandom Test {nextDouble(double)} case1]");
                break;
            }
        }

        TEST_OK("[TestRandom Test {nextDouble(double)} case2]");
        break;
    }

    //static void nextBytes(ByteArray);
}
