#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Barrier.hpp"
#include "ByteArrayReader.hpp"

using namespace obotcha;

extern void testHttpHeaderToString();
extern void testHttpHeaderSet();
extern void testHttpHeaderParse();
extern void testResponseReason();
extern void testHttpHeaderAppend();
extern void testHttpHeaderSelfDefine();
extern void testHttpHeaderSize();
extern void testHttpHeaderFindId();
extern void testHttpHeaderFindName();

int main() {
    testHttpHeaderSize();
    testHttpHeaderSelfDefine();
    testHttpHeaderAppend();
    testHttpHeaderSet();
    testHttpHeaderToString();
    testResponseReason();
    testHttpHeaderFindId();
    testHttpHeaderFindName();
    //testHttpHeaderParse(); TODO
    return 0;
}
