#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "UUID.hpp"
#include "Log.hpp"
#include "ArrayList.hpp"
#include "String.hpp"
#include "TestLog.hpp"

using namespace obotcha;

int main() {
    //String toValue();
    UUID uuid = createUUID();
    /*
    while(1) {
        ArrayList<String> list = craeteArrayList<String>();
        UUID uuid = createUUID();
        bool isOk = true;
        for(int i = 0;i<list->size();i++) {
            if(uuid->toString()->equals(list->get(i))) {
                isOk = false;
                printf("---[UUID Test {toString()} case1] [FAIL]--- \n");
                break;
            }

            list->add(uuid->toString());

            if(!isOk) {
                break;
            }
        }

    }*/
}
