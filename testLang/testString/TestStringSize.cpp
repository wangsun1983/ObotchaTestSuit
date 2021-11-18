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

void TestStringSize() {

    while(1) {
        String str = createString(" abc f ");
        if(str->size() != 7) {
            printf("String size test1-------[FAIL] \n");
            break;
        }

        char buff[12] = {0};
        buff[0] = 'a';
        buff[1] = 'b';
        buff[3] = 'd';
        buff[4] = 'f';
        str = createString(buff);
        if(str->size() != 2) {
            printf("String size1 test2-------[FAIL],size is %d \n",str->size());
            break;
        }
        break;
    }

    printf("String size test100-------[OK] \n");
}
