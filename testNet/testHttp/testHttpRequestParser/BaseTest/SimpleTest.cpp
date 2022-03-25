#include "HttpPacketParser.hpp"
#include "HttpPacketParserImpl.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void simpleTest() {
    String test = createString("keep-alive");
    if(test->equalsIgnoreCase("Keep-Alive")) {
        printf("it equals \n");
    } else {
        printf("it not equals \n");
    }
}
