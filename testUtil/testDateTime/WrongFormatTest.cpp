#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "ByteArray.hpp"
#include "StrongPointer.hpp"
#include "ArrayIndexOutOfBoundsException.hpp"
#include "DateTime.hpp"
#include "Calendar.hpp"
#include "InitializeException.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void wrongformat() {
  try {
        DateTime t = DateTime::New(st(DateTime)::Format::ISO8601Frac,"2005-01-08T12.30:00Z");
        TEST_FAIL("DateTime wrongformat test1");
    } catch(InitializeException e) {}

    try {
        DateTime t = DateTime::New(st(DateTime)::Format::ISO8601Frac,"2005-01-8T12:30:00+01:00");
        TEST_FAIL("DateTime wrongformat test2");
    } catch(InitializeException e) {}

    try {
        DateTime t = DateTime::New(st(DateTime)::Format::ISO8601Frac,"2005-01-0812:30:00-01:00");
        TEST_FAIL("DateTime wrongformat test3");
    } catch(InitializeException e) {}

    try {
        DateTime t = DateTime::New(st(DateTime)::Format::ISO8601Frac,"2005-01-08T12:30:0");
        TEST_FAIL("DateTime wrongformat test4");
    } catch(InitializeException e) {}

    try {
        DateTime t = DateTime::New(st(DateTime)::Format::ISO8601Frac,"2005-01-8");
        TEST_FAIL("DateTime wrongformat test5");
    } catch(InitializeException e) {}

    try {
        DateTime t = DateTime::New(st(DateTime)::Format::ISO8601Frac,"2005-1-08T12:30:00Z");
        TEST_FAIL("DateTime wrongformat test6");
    } catch(InitializeException e) {}

    try {
        DateTime t = DateTime::New(st(DateTime)::Format::ISO8601Frac,"2005-01-08Z12:30:00+01:00");
        TEST_FAIL("DateTime wrongformat test7");
    } catch(InitializeException e) {}

    try {
        DateTime t = DateTime::New(st(DateTime)::Format::ISO8601Frac,"2005-01-08T12:30:00-01.00");
        TEST_FAIL("DateTime wrongformat test8");
    } catch(InitializeException e) {}

    try {
        DateTime t = DateTime::New(st(DateTime)::Format::ISO8601Frac,"2005-01-08T12;30:00");
        TEST_FAIL("DateTime wrongformat test9");
    } catch(InitializeException e) {}

    try {
        DateTime t = DateTime::New(st(DateTime)::Format::ISO8601Frac,"2005-01+08");
        TEST_FAIL("DateTime wrongformat test10");
    } catch(InitializeException e) {}

    try {
        DateTime t = DateTime::New(st(DateTime)::Format::ISO8601Frac,"2005-01-08T12:30:00.123*01:00");
        TEST_FAIL("DateTime wrongformat test11");
    } catch(InitializeException e) {}

    try {
        DateTime t = DateTime::New(st(DateTime)::Format::ISO8601Frac,"201009-23T16:17:01.2817002+02:00");
        TEST_FAIL("DateTime wrongformat test12");
    } catch(InitializeException e) {}

    try {
        DateTime t = DateTime::New(st(DateTime)::Format::ISO8601Frac,"005-01-08T12:30:00.123456");
        TEST_FAIL("DateTime wrongformat test13");
    } catch(InitializeException e) {}

    try {
        DateTime t = DateTime::New(st(DateTime)::Format::ISO8601Frac,"2005-01-0");
        TEST_FAIL("DateTime wrongformat test14");
    } catch(InitializeException e) {}

    try {
        DateTime t = DateTime::New(st(DateTime)::Format::ISO8601Frac,"jnghjgnbcfjb");
        TEST_FAIL("DateTime wrongformat test15");
    } catch(InitializeException e) {}

    try {
        DateTime t = DateTime::New(st(DateTime)::Format::RFC822,"at, 8 Jan 05 12:30:00 GMT");
        TEST_FAIL("DateTime wrongformat test16");
    } catch(InitializeException e) {}

    try {
        DateTime t = DateTime::New(st(DateTime)::Format::RFC822,"Sat, x Jan 05 12:30:00 +0100");
        TEST_FAIL("DateTime wrongformat test17");
    } catch(InitializeException e) {}

    try {
        DateTime t = DateTime::New(st(DateTime)::Format::RFC822,"Sat, 8 Jan 05 12:30:00 *0100");
        TEST_FAIL("DateTime wrongformat test18");
    } catch(InitializeException e) {}

    try {
        DateTime t = DateTime::New(st(DateTime)::Format::RFC822,"Tue, 18 Jan 05 12:30:00 abc");
        TEST_FAIL("DateTime wrongformat test19");
    } catch(InitializeException e) {}

    try {
        DateTime t = DateTime::New(st(DateTime)::Format::RFC822,"Wed, 12 Sep 73 02:01:2 CST");
        TEST_FAIL("DateTime wrongformat test20");
    } catch(InitializeException e) {}

    try {
        DateTime t = DateTime::New(st(DateTime)::Format::RFC822,"12 Sep 73 02.01:12 EST");
        TEST_FAIL("DateTime wrongformat test21");
    } catch(InitializeException e) {}

    try {
        DateTime t = DateTime::New(st(DateTime)::Format::RFC1123,"Sat, 8 Jan 2005 12:30:00 GPX");
        TEST_FAIL("DateTime wrongformat test22");
    } catch(InitializeException e) {}

    try {
        DateTime t = DateTime::New(st(DateTime)::Format::RFC1123,"Sat, 8 Jan 2005 xy:30:00 +0100");
        TEST_FAIL("DateTime wrongformat test23");
    } catch(InitializeException e) {}

    try {
        DateTime t = DateTime::New(st(DateTime)::Format::RFC1123,"Sat, 8 Jan 205 12:30:00 -0100");
        TEST_FAIL("DateTime wrongformat test24");
    } catch(InitializeException e) {}

    try {
        DateTime t = DateTime::New(st(DateTime)::Format::RFC1123,"Sat, 8 Jan 205 12:30:00 -0100");
        TEST_FAIL("DateTime wrongformat test25");
    } catch(InitializeException e) {}

    try {
        DateTime t = DateTime::New(st(DateTime)::Format::HTTP,"Sat, 08 Jn 2005 12:30:00 GMT");
        TEST_FAIL("DateTime wrongformat test26");
    } catch(InitializeException e) {}

    try {
        DateTime t = DateTime::New(st(DateTime)::Format::HTTP,"Sat 08 Jan 2005 12:30:00 -0100");
        TEST_FAIL("DateTime wrongformat test27");
    } catch(InitializeException e) {}

    try {
        DateTime t = DateTime::New(st(DateTime)::Format::RFC850,"Saturday, 8-Jan 05 12:30:00 GMT");
        TEST_FAIL("DateTime wrongformat test28");
    } catch(InitializeException e) {}

    try {
        DateTime t = DateTime::New(st(DateTime)::Format::RFC850,"Saturday, 8+Jan-05 12:30:00 +0100");
        TEST_FAIL("DateTime wrongformat test29");
    } catch(InitializeException e) {}

    try {
        DateTime t = DateTime::New(st(DateTime)::Format::RFC850,"Saturday 8-Jan-05 12:30:00 -0100");
        TEST_FAIL("DateTime wrongformat test30");
    } catch(InitializeException e) {}

    try {
        DateTime t = DateTime::New(st(DateTime)::Format::RFC850,"Wed, 12-pep-73 02:01:12 CST");
        TEST_FAIL("DateTime wrongformat test31");
    } catch(InitializeException e) {}

    try {
        DateTime t = DateTime::New(st(DateTime)::Format::RFC1036,"Saturday, 8 Jan 0512:30:00 GMT");
        TEST_FAIL("DateTime wrongformat test32");
    } catch(InitializeException e) {}

    try {
        DateTime t = DateTime::New(st(DateTime)::Format::RFC1036,"Saturday, 8 Jan 051 12:30:00 +0100");
        TEST_FAIL("DateTime wrongformat test33");
    } catch(InitializeException e) {}

    try {
        DateTime t = DateTime::New(st(DateTime)::Format::RFC1036,"Saturday, 8 Jan 05 12:30:00 -0100x");
        TEST_FAIL("DateTime wrongformat test34");
    } catch(InitializeException e) {}

    try {
        DateTime t = DateTime::New(st(DateTime)::Format::ASCTIME,"Bat Jan  8 12:30:00 2005");
        TEST_FAIL("DateTime wrongformat test35");
    } catch(InitializeException e) {}

    try {
        DateTime t = DateTime::New(st(DateTime)::Format::SORTABLE,"2005-01-08 12:30;00");
        TEST_FAIL("DateTime wrongformat test36");
    } catch(InitializeException e) {}

    try {
        DateTime t = DateTime::New(st(DateTime)::Format::SORTABLE,"2005+01-08");
        TEST_FAIL("DateTime wrongformat test36");
    } catch(InitializeException e) {}

    try {
        DateTime t = DateTime::New(String::New(""),String::New("12:30 PM"));
        TEST_FAIL("DateTime wrongformat test37");
    } catch(InitializeException e) {}

    TEST_OK("DateTime wrongformat test10");
}
