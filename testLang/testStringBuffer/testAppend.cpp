#include "StringBuffer.hpp"

using namespace obotcha;


void testAppend() {

    StringBuffer buffer = createStringBuffer();
    buffer->append("abc","abc2","abc3");
    printf("buff string is %s \n",buffer->toString()->toChars());
}
