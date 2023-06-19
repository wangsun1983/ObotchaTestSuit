#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Barrier.hpp"
#include "ByteRingArray.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testPopTo() {
    //
    while(1) {

        //case1
        ByteRingArray array = createByteRingArray(5);
        array->push(1);
        array->push(2);
        array->push(3);
        array->push(4);
        array->push(5);

        ByteRingArray data1 = createByteRingArray(array);
        data1->setEndIndex(0);
        data1->setSize(5);

        ByteRingArray arr1 = createByteRingArray(data1);

        //
        ByteArray result = arr1->popTo(0);
        if(result->size() != 1) {
            TEST_FAIL("[ByteRingArray Test popTo case1]");
            break;
        }

        if(result[0] != 1) {
            TEST_FAIL("[ByteRingArray Test popTo case2]");
            break;
        }

        arr1 = createByteRingArray(data1);
        result = arr1->popTo(1);
        if(result->size() != 2) {
            TEST_FAIL("[ByteRingArray Test popTo case3]");
            break;
        }

        if(result[0] != 1 || result[1] != 2) {
            TEST_FAIL("[ByteRingArray Test popTo case4]");
            break;
        }

        arr1 = createByteRingArray(data1);
        result = arr1->popTo(2);
        if(result->size() != 3) {
            TEST_FAIL("[ByteRingArray Test popTo case5]");
            break;
        }

        if(result[0] != 1 || result[1] != 2 || result[2] != 3) {
            TEST_FAIL("[ByteRingArray Test popTo case6]");
            break;
        }

        arr1 = createByteRingArray(data1);
        result = arr1->popTo(3);
        if(result->size() != 4) {
            TEST_FAIL("[ByteRingArray Test popTo case7]");
            break;
        }

        if(result[0] != 1 || result[1] != 2 || result[2] != 3 || result[3] != 4) {
            TEST_FAIL("[ByteRingArray Test popTo case8]");
            break;
        }

        arr1 = createByteRingArray(data1);
        result = arr1->popTo(4);
        if(result->size() != 5) {
            TEST_FAIL("[ByteRingArray Test popTo case9]");
            break;
        }

        if(result[0] != 1 || result[1] != 2 || result[2] != 3 || result[3] != 4 || result[4] != 5) {
            TEST_FAIL("[ByteRingArray Test popTo case10]");
            break;
        }

        //
        data1->setEndIndex(1);
        data1->setSize(5);
        arr1 = createByteRingArray(data1);

        result = arr1->popTo(1);
        if(result->size() != 1) {
            TEST_FAIL("[ByteRingArray Test popTo case11]");
            break;
        }

        if(result[0] != 2) {
            TEST_FAIL("[ByteRingArray Test popTo case12]");
            break;
        }

        arr1 = createByteRingArray(data1);
        result = arr1->popTo(2);
        if(result->size() != 2) {
            TEST_FAIL("[ByteRingArray Test popTo case13]");
            break;
        }

        if(result[0] != 2 || result[1] != 3) {
            TEST_FAIL("[ByteRingArray Test popTo case14]");
            break;
        }

        arr1 = createByteRingArray(data1);
        result = arr1->popTo(3);
        if(result->size() != 3) {
            TEST_FAIL("[ByteRingArray Test popTo case15]");
            break;
        }

        if(result[0] != 2 || result[1] != 3 || result[2] != 4) {
            TEST_FAIL("[ByteRingArray Test popTo case16]");
            break;
        }

        arr1 = createByteRingArray(data1);
        result = arr1->popTo(4);
        if(result->size() != 4) {
            TEST_FAIL("[ByteRingArray Test popTo case17]");
            break;
        }

        if(result[0] != 2 || result[1] != 3 || result[2] != 4 || result[3] != 5) {
            TEST_FAIL("[ByteRingArray Test popTo case18]");
            break;
        }

        arr1 = createByteRingArray(data1);
        result = arr1->popTo(0);
        if(result->size() != 5) {
            TEST_FAIL("[ByteRingArray Test popTo case19]");
            break;
        }

        if(result[0] != 2 || result[1] != 3 || result[2] != 4 || result[3] != 5 || result[4] != 1) {
            TEST_FAIL("[ByteRingArray Test popTo case20]");
            break;
        }

        //
        data1->setEndIndex(2);
        data1->setSize(5);
        arr1 = createByteRingArray(data1);

        result = arr1->popTo(2);
        if(result->size() != 1) {
            TEST_FAIL("[ByteRingArray Test popTo case21]");
            break;
        }

        if(result[0] != 3) {
            TEST_FAIL("[ByteRingArray Test popTo case22]");
            break;
        }

        arr1 = createByteRingArray(data1);
        result = arr1->popTo(3);
        if(result->size() != 2) {
            TEST_FAIL("[ByteRingArray Test popTo case23]");
            break;
        }

        if(result[0] != 3 || result[1] != 4) {
            TEST_FAIL("[ByteRingArray Test popTo case24]");
            break;
        }

        arr1 = createByteRingArray(data1);
        result = arr1->popTo(4);
        if(result->size() != 3) {
            TEST_FAIL("[ByteRingArray Test popTo case25]");
            break;
        }

        if(result[0] != 3 || result[1] != 4 || result[2] != 5) {
            TEST_FAIL("[ByteRingArray Test popTo case26]");
            break;
        }

        arr1 = createByteRingArray(data1);
        result = arr1->popTo(0);
        if(result->size() != 4) {
            TEST_FAIL("[ByteRingArray Test popTo case27]");
            break;
        }

        if(result[0] != 3 || result[1] != 4 || result[2] != 5 || result[3] != 1) {
            TEST_FAIL("[ByteRingArray Test popTo case28]");
            break;
        }

        arr1 = createByteRingArray(data1);
        result = arr1->popTo(1);
        if(result->size() != 5) {
            TEST_FAIL("[ByteRingArray Test popTo case29]");
            break;
        }

        if(result[0] != 3 || result[1] != 4 || result[2] != 5 || result[3] != 1 || result[4] != 2) {
            TEST_FAIL("[ByteRingArray Test popTo case30]");
            break;
        }

        //
        data1->setEndIndex(3);
        data1->setSize(5);
        arr1 = createByteRingArray(data1);

        result = arr1->popTo(3);
        if(result->size() != 1) {
            TEST_FAIL("[ByteRingArray Test popTo case31]");
            break;
        }

        if(result[0] != 4) {
            TEST_FAIL("[ByteRingArray Test popTo case32]");
            break;
        }

        arr1 = createByteRingArray(data1);
        result = arr1->popTo(4);
        if(result->size() != 2) {
            TEST_FAIL("[ByteRingArray Test popTo case33]");
            break;
        }

        if(result[0] != 4 || result[1] != 5) {
            TEST_FAIL("[ByteRingArray Test popTo case34]");
            break;
        }

        arr1 = createByteRingArray(data1);
        result = arr1->popTo(0);
        if(result->size() != 3) {
            TEST_FAIL("[ByteRingArray Test popTo case35]");
            break;
        }

        if(result[0] != 4 || result[1] != 5 || result[2] != 1) {
            TEST_FAIL("[ByteRingArray Test popTo case36]");
            break;
        }

        arr1 = createByteRingArray(data1);
        result = arr1->popTo(1);
        if(result->size() != 4) {
            TEST_FAIL("[ByteRingArray Test popTo case37]");
            break;
        }

        if(result[0] != 4 || result[1] != 5 || result[2] != 1 || result[3] != 2) {
            TEST_FAIL("[ByteRingArray Test popTo case38]");
            break;
        }

        arr1 = createByteRingArray(data1);
        result = arr1->popTo(2);
        if(result->size() != 5) {
            TEST_FAIL("[ByteRingArray Test popTo case39]");
            break;
        }

        if(result[0] != 4 || result[1] != 5 || result[2] != 1 || result[3] != 2 || result[4] != 3) {
            TEST_FAIL("[ByteRingArray Test popTo case40]");
            break;
        }

        //
        data1->setEndIndex(4);
        data1->setSize(5);
        arr1 = createByteRingArray(data1);

        result = arr1->popTo(4);
        if(result->size() != 1) {
            TEST_FAIL("[ByteRingArray Test popTo case51]");
            break;
        }

        if(result[0] != 5) {
            TEST_FAIL("[ByteRingArray Test popTo case52]");
            break;
        }

        arr1 = createByteRingArray(data1);
        result = arr1->popTo(0);
        if(result->size() != 2) {
            TEST_FAIL("[ByteRingArray Test popTo case53]");
            break;
        }

        if(result[0] != 5 || result[1] != 1) {
            TEST_FAIL("[ByteRingArray Test popTo case54]");
            break;
        }

        arr1 = createByteRingArray(data1);
        result = arr1->popTo(1);
        if(result->size() != 3) {
            TEST_FAIL("[ByteRingArray Test popTo case55]");
            break;
        }

        if(result[0] != 5 || result[1] != 1 || result[2] != 2) {
            TEST_FAIL("[ByteRingArray Test popTo case56]");
            break;
        }

        arr1 = createByteRingArray(data1);
        result = arr1->popTo(2);
        if(result->size() != 4) {
            TEST_FAIL("[ByteRingArray Test popTo case57]");
            break;
        }

        if(result[0] != 5 || result[1] != 1 || result[2] != 2 || result[3] != 3) {
            TEST_FAIL("[ByteRingArray Test popTo case58]");
            break;
        }

        arr1 = createByteRingArray(data1);
        result = arr1->popTo(3);
        if(result->size() != 5) {
            TEST_FAIL("[ByteRingArray Test popTo case59]");
            break;
        }

        if(result[0] != 5 || result[1] != 1 || result[2] != 2 || result[3] != 3 || result[4] != 4) {
            TEST_FAIL("[ByteRingArray Test popTo case60]");
            break;
        }


        TEST_OK("[ByteRingArray Test popTo case100]");
        break;
    }
    return;
}
