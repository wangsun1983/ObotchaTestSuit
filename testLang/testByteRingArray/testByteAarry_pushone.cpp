#include <stdio.h>
#include <unistd.h>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"
#include "ByteRingArray.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testByteRingArrayPushOne() {
    ByteRingArray data1 = createByteRingArray(5);
    data1->setEndIndex(0);
    data1->setSize(5);
    printf("start is %d \n",data1->getStartIndex());
  
    while(1) {
        ByteRingArray array = createByteRingArray(3);
        array->push(1);
        printf("array start is %d,next is %d \n",array->getStartIndex(),array->getNextIndex());
        array->push(2);
        printf("array start is %d,next is %d \n",array->getStartIndex(),array->getNextIndex());
        array->push(3);
        printf("array start is %d,next is %d \n",array->getStartIndex(),array->getNextIndex());
        
        printf("start pop \n");
        array->pop();
        printf("array start is %d,next is %d \n",array->getStartIndex(),array->getNextIndex());
        array->pop();
        printf("array start is %d,next is %d \n",array->getStartIndex(),array->getNextIndex());
        array->pop();
        printf("array start is %d,next is %d \n",array->getStartIndex(),array->getNextIndex());
        
        printf("start push \n");
        array->push(1);
        printf("array start is %d,next is %d \n",array->getStartIndex(),array->getNextIndex());
        array->push(2);
        printf("array start is %d,next is %d \n",array->getStartIndex(),array->getNextIndex());
        array->push(3);
        printf("array start is %d,next is %d \n",array->getStartIndex(),array->getNextIndex());
        
        break;
    }

    TEST_OK("[ByteRingArray Test Capacity case100]");
}
