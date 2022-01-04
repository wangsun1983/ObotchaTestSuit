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

void splittest() {

    //----------------------------


    //sp<_ArrayList<String>> split(const char* v);

    //sp<_ArrayList<String>> split(std::string v);
    //----------------------------

    ////sp<_ArrayList<String>> split(String v);
    while(1) {
        //case 1
        String str1 = createString(" a b c d ");
        ArrayList<String> str1list = str1->split(createString(" "));
        ListIterator<String> iterator = str1list->getIterator();

        if(str1list->size() != 4) {
            TEST_FAIL("String split Special test1");
            break;
        }

        if(!str1list->get(0)->equals("a")
            ||!str1list->get(1)->equals("b")
            ||!str1list->get(2)->equals("c")
            ||!str1list->get(3)->equals("d")) {
            TEST_FAIL("String split Special test2");
            break;
        }

        //case 2
        String str2 = createString(" ");
        ArrayList<String> str2list = str2->split(createString(" "));
        if(str2list->size() != 0) {
            TEST_FAIL("String split Special test3");
            break;
        }

        //case 3
        String str3 = createString("accbcc");
        ArrayList<String> str3list = str3->split(createString("cc"));
        if(str3list->size() != 2) {
            TEST_FAIL("String split Special test5");
            break;
        }

        if(!str3list->get(0)->equals("a")
            ||!str3list->get(1)->equals("b")) {
            TEST_FAIL("String split Special test6");
            break;
        }

        TEST_OK("String split Special test8");
        break;
    }

}
