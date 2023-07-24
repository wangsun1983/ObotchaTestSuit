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
        ArrayListIterator<String> iterator = str1list->getIterator();

        if(str1list->size() != 4) {
            TEST_FAIL("String split Special test1");
            break;
        }

        if(!str1list->get(0)->sameAs("a")
            ||!str1list->get(1)->sameAs("b")
            ||!str1list->get(2)->sameAs("c")
            ||!str1list->get(3)->sameAs("d")) {
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

        if(!str3list->get(0)->sameAs("a")
            ||!str3list->get(1)->sameAs("b")) {
            TEST_FAIL("String split Special test6");
            break;
        }

        TEST_OK("String split Special test8");
        break;
    }
    
    //split(char const*, int)
    while(1) {
        const char * str = "a1d1c1d";
        String ss = createString(str);
        auto list = ss->split("123",1);
        if(list->size() != 4) {
            TEST_FAIL("String split Special test9");
        }
        
        if(!list->get(0)->sameAs("a") ||
           !list->get(1)->sameAs("d") ||
           !list->get(2)->sameAs("c") ||
           !list->get(3)->sameAs("d")) {
            TEST_FAIL("String split Special test10");
        }
        break;
    }
            
    TEST_OK("String split Special test100");

}
