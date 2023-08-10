#include <stdio.h>
#include <unistd.h>

#include "IniReader.hpp"
#include "Log.hpp"
#include "IniWriter.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testIniValue() {
    while(1) {
      IniReader reader = createIniReader(createFile("testData.ini"));
      IniValue v = reader->parse();
      auto writer = createIniWriter(createFile("./tmp/testData1.ini"));
      writer->write(v);
      
      IniReader reader2 = createIniReader(createFile("./tmp/testData1.ini"));
      HashMap<String,HashMap<String,String>> iniValues = reader2->parse()->getAll();
      if(iniValues == nullptr) {
        TEST_FAIL("IniValue test1");
        break;
      }

      //root(no Section)
      HashMap<String,String> v1 = iniValues->get(st(IniValue)::RootSection);
      if(v1 == nullptr || v1->size() != 1) {
        TEST_FAIL("IniValue test2");
        break;
      }

      String v2 = v1->get(S("abc1"));
      if(v2 == nullptr || !v2->sameAs("1")) {
        TEST_FAIL("IniValue test3");
        break;
      }

      //l1
      HashMap<String,String> l1maps = iniValues->get(S("l1"));
      if(l1maps == nullptr || l1maps->size() != 6) {
        TEST_FAIL("IniValue test4");
        break;
      }

      if(l1maps->get(S("a")) == nullptr || !l1maps->get(S("a"))->sameAs("1")) {
        TEST_FAIL("IniValue test5");
        break;
      }

      if(l1maps->get(S("b")) == nullptr || !l1maps->get(S("b"))->sameAs("2")) {
        TEST_FAIL("IniValue test6");
        break;
      }

      if(l1maps->get(S("c")) == nullptr || !l1maps->get(S("c"))->sameAs("3")) {
        TEST_FAIL("IniValue test7");
        break;
      }

      if(l1maps->get(S("e")) == nullptr || !l1maps->get(S("e"))->sameAs("4")) {
        TEST_FAIL("IniValue test8");
        break;
      }

      if(l1maps->get(S("f")) == nullptr || !l1maps->get(S("f"))->sameAs("5")) {
        TEST_FAIL("IniValue test9");
        break;
      }

      if(l1maps->get(S("g")) == nullptr || !l1maps->get(S("g"))->sameAs("6")) {
        TEST_FAIL("IniValue test10");
        break;
      }

      //l2
      HashMap<String,String> l2maps = iniValues->get(S("l2"));
      if(l2maps->get(S("a")) == nullptr || !l2maps->get(S("a"))->sameAs("7")) {
        TEST_FAIL("IniValue test10_1");
        break;
      }

      if(l2maps->get(S("b")) == nullptr || !l2maps->get(S("b"))->sameAs("8")) {
        TEST_FAIL("IniValue test11");
        break;
      }

      if(l2maps->get(S("c")) == nullptr || !l2maps->get(S("c"))->sameAs("9")) {
        TEST_FAIL("IniValue test12");
        break;
      }

      if(l2maps->get(S("d")) == nullptr || !l2maps->get(S("d"))->sameAs("10")) {
        TEST_FAIL("IniValue test13");
        break;
      }

      //l3
      HashMap<String,String> l3maps = iniValues->get(S("l3"));
      if(l3maps->get(S("a")) == nullptr || !l3maps->get(S("a"))->sameAs("1.1")) {
        TEST_FAIL("IniValue test14");
        break;
      }

      if(l3maps->get(S("b")) == nullptr || !l3maps->get(S("b"))->sameAs("2.1")) {
        TEST_FAIL("IniValue test15");
        break;
      }

      if(l3maps->get(S("c")) == nullptr || !l3maps->get(S("c"))->sameAs("3.1")) {
        TEST_FAIL("IniValue test16");
        break;
      }

      //l4
      HashMap<String,String> l4maps = iniValues->get(S("l4"));
      if(l4maps->get(S("a")) == nullptr || !l4maps->get(S("a"))->sameAs("true")) {
        TEST_FAIL("IniValue test17");
        break;
      }

      if(l4maps->get(S("b")) == nullptr || !l4maps->get(S("b"))->sameAs("false")) {
        TEST_FAIL("IniValue test18");
        break;
      }

      if(l4maps->get(S("c")) == nullptr || !l4maps->get(S("c"))->sameAs("true")) {
        TEST_FAIL("IniValue test19");
        break;
      }

      if(l4maps->get(S("d")) == nullptr || !l4maps->get(S("d"))->sameAs("false")) {
        TEST_FAIL("IniValue test20");
        break;
      }

      break;
    }

    while(1) {
      IniReader reader = createIniReader(createFile("twisted.ini"));
      HashMap<String,HashMap<String,String>> iniValues = reader->parse()->getAll();

      //root(no Section)
      HashMap<String,String> v1 = iniValues->get(st(IniValue)::RootSection);
      if(v1 == nullptr || v1->size() != 1) {
        TEST_FAIL("IniValue test21");
        break;
      }

      String v2 = v1->get(S("abc1f"));
      if(v2 == nullptr || !v2->sameAs("12f")) {
        TEST_FAIL("IniValue test22");
        break;
      }

      //blanks
      HashMap<String,String> blanksMaps = iniValues->get(S("blanks"));
      if(blanksMaps == nullptr || blanksMaps->size() != 20) {
        TEST_FAIL("IniValue test22_1");
        break;
      }

      if(blanksMaps->get(S("a")) == nullptr || !blanksMaps->get(S("a"))->sameAs("1")) {
        TEST_FAIL("IniValue test23");
        break;
      }

      if(blanksMaps->get(S("b")) == nullptr || !blanksMaps->get(S("b"))->sameAs("1")) {
        TEST_FAIL("IniValue test24");
        break;
      }

      if(blanksMaps->get(S("c")) == nullptr || !blanksMaps->get(S("c"))->sameAs("1")) {
        TEST_FAIL("IniValue test25");
        break;
      }

      if(blanksMaps->get(S("d")) == nullptr || !blanksMaps->get(S("d"))->sameAs("1")) {
        TEST_FAIL("IniValue test26");
        break;
      }

      if(blanksMaps->get(S("e")) == nullptr || !blanksMaps->get(S("e"))->sameAs("1")) {
        TEST_FAIL("IniValue test27");
        break;
      }

      if(blanksMaps->get(S("f")) == nullptr || !blanksMaps->get(S("f"))->sameAs("1")) {
        TEST_FAIL("IniValue test28");
        break;
      }

      if(blanksMaps->get(S("g")) == nullptr || !blanksMaps->get(S("g"))->sameAs("1")) {
        TEST_FAIL("IniValue test29");
        break;
      }

      if(blanksMaps->get(S("h")) == nullptr || !blanksMaps->get(S("h"))->sameAs("1")) {
        TEST_FAIL("IniValue test30");
        break;
      }

      if(blanksMaps->get(S("i")) == nullptr || !blanksMaps->get(S("i"))->sameAs("1")) {
        TEST_FAIL("IniValue test31");
        break;
      }

      if(blanksMaps->get(S("j")) == nullptr || !blanksMaps->get(S("j"))->sameAs("1")) {
        TEST_FAIL("IniValue test32");
        break;
      }

      if(blanksMaps->get(S("k")) == nullptr || !blanksMaps->get(S("k"))->sameAs("1")) {
        TEST_FAIL("IniValue test33");
        break;
      }

      if(blanksMaps->get(S("l")) == nullptr || !blanksMaps->get(S("l"))->sameAs("1")) {
        TEST_FAIL("IniValue test34");
        break;
      }

      if(blanksMaps->get(S("m")) == nullptr || !blanksMaps->get(S("m"))->sameAs("1")) {
        TEST_FAIL("IniValue test35");
        break;
      }

      if(blanksMaps->get(S("n")) == nullptr || !blanksMaps->get(S("n"))->sameAs("1")) {
        TEST_FAIL("IniValue test36");
        break;
      }

      if(blanksMaps->get(S("o")) == nullptr || !blanksMaps->get(S("o"))->sameAs("1")) {
        TEST_FAIL("IniValue test37");
        break;
      }

      if(blanksMaps->get(S("p")) == nullptr || !blanksMaps->get(S("p"))->sameAs("1")) {
        TEST_FAIL("IniValue test38");
        break;
      }

      if(blanksMaps->get(S("q")) == nullptr || !blanksMaps->get(S("q"))->sameAs("1")) {
        TEST_FAIL("IniValue test39");
        break;
      }

      if(blanksMaps->get(S("r")) == nullptr || !blanksMaps->get(S("r"))->sameAs("1")) {
        TEST_FAIL("IniValue test40");
        break;
      }

      if(blanksMaps->get(S("s")) == nullptr || !blanksMaps->get(S("s"))->sameAs("1")) {
        TEST_FAIL("IniValue test41");
        break;
      }

      if(blanksMaps->get(S("t")) == nullptr || !blanksMaps->get(S("t"))->sameAs("1")) {
        TEST_FAIL("IniValue test42");
        break;
      }

      //[empty]
      HashMap<String,String> emptyMaps = iniValues->get(S("empty"));

      if(emptyMaps == nullptr || emptyMaps->size() != 14) {
        TEST_FAIL("IniValue test43");
        break;
      }

      if(emptyMaps->get(S("a")) == nullptr || emptyMaps->get(S("a"))->size() != 0) {
        TEST_FAIL("IniValue test44");
        break;
      }

      if(emptyMaps->get(S("b")) == nullptr || emptyMaps->get(S("b"))->size() != 0) {
        TEST_FAIL("IniValue test45");
        break;
      }

      if(emptyMaps->get(S("c")) == nullptr || emptyMaps->get(S("c"))->size() != 0) {
        TEST_FAIL("IniValue test46");
        break;
      }

      if(emptyMaps->get(S("d")) == nullptr || emptyMaps->get(S("d"))->size() != 0) {
        TEST_FAIL("IniValue test45");
        break;
      }

      if(emptyMaps->get(S("e")) == nullptr || emptyMaps->get(S("e"))->size() != 0) {
        TEST_FAIL("IniValue test46");
        break;
      }

      if(emptyMaps->get(S("f")) == nullptr || emptyMaps->get(S("f"))->size() != 0) {
        TEST_FAIL("IniValue test47");
        break;
      }

      if(emptyMaps->get(S("g")) == nullptr || emptyMaps->get(S("g"))->size() != 0) {
        TEST_FAIL("IniValue test48");
        break;
      }

      if(emptyMaps->get(S("h")) == nullptr || emptyMaps->get(S("h"))->size() != 0) {
        TEST_FAIL("IniValue test49");
        break;
      }

      if(emptyMaps->get(S("i")) == nullptr || emptyMaps->get(S("i"))->size() != 0) {
        TEST_FAIL("IniValue test50");
        break;
      }

      if(emptyMaps->get(S("j")) == nullptr || emptyMaps->get(S("j"))->size() != 0) {
        TEST_FAIL("IniValue test51");
        break;
      }

      if(emptyMaps->get(S("k")) == nullptr || emptyMaps->get(S("k"))->size() != 0) {
        TEST_FAIL("IniValue test52");
        break;
      }

      if(emptyMaps->get(S("l")) == nullptr || emptyMaps->get(S("l"))->size() != 0) {
        TEST_FAIL("IniValue test53");
        break;
      }

      if(emptyMaps->get(S("m")) == nullptr || emptyMaps->get(S("m"))->size() != 0) {
        TEST_FAIL("IniValue test54");
        break;
      }

      if(emptyMaps->get(S("n")) == nullptr || emptyMaps->get(S("n"))->size() != 0) {
        TEST_FAIL("IniValue test55");
        break;
      }

      //[peculiar]
      HashMap<String,String> peculiarMaps = iniValues->get(S("peculiar"));

      if(peculiarMaps == nullptr || peculiarMaps->size() != 12) {
        TEST_FAIL("IniValue test56");
        break;
      }

      if(peculiarMaps->get(S("a")) == nullptr || !peculiarMaps->get(S("a"))->sameAs(";")) {
        TEST_FAIL("IniValue test57,v is %s \n",peculiarMaps->get(S("a"))->toChars());
        break;
      }

      if(peculiarMaps->get(S("b")) == nullptr || !peculiarMaps->get(S("b"))->sameAs("#")) {
        TEST_FAIL("IniValue test58");
        break;
      }

      if(peculiarMaps->get(S("c")) == nullptr || !peculiarMaps->get(S("c"))->sameAs(";")) {
        TEST_FAIL("IniValue test59");
        break;
      }

      if(peculiarMaps->get(S("d")) == nullptr || !peculiarMaps->get(S("d"))->sameAs("#")) {
        TEST_FAIL("IniValue test60");
        break;
      }

      if(peculiarMaps->get(S("e")) == nullptr || !peculiarMaps->get(S("e"))->sameAs("\\")) {
        TEST_FAIL("IniValue test61");
        break;
      }

      if(peculiarMaps->get(S("f")) == nullptr || !peculiarMaps->get(S("f"))->sameAs("\\")) {
        TEST_FAIL("IniValue test62");
        break;
      }

      if(peculiarMaps->get(S("g")) == nullptr || !peculiarMaps->get(S("g"))->sameAs("\\")) {
        TEST_FAIL("IniValue test63");
        break;
      }

      if(peculiarMaps->get(S("h")) == nullptr || !peculiarMaps->get(S("h"))->sameAs("\\")) {
        TEST_FAIL("IniValue test64");
        break;
      }

      if(peculiarMaps->get(S("i")) == nullptr || peculiarMaps->get(S("i"))->size() != 0) {
        TEST_FAIL("IniValue test65");
        break;
      }

      if(peculiarMaps->get(S("j")) == nullptr || peculiarMaps->get(S("j"))->size() != 0) {
        TEST_FAIL("IniValue test66");
        break;
      }

      if(peculiarMaps->get(S("k")) == nullptr || peculiarMaps->get(S("k"))->size() != 0) {
        TEST_FAIL("IniValue test67");
        break;
      }

      if(peculiarMaps->get(S("l")) == nullptr || peculiarMaps->get(S("l"))->size() != 0) {
        TEST_FAIL("IniValue test68");
        break;
      }

      //[quotes]
      HashMap<String,String> quotesMap = iniValues->get(S("quotes"));
      if(quotesMap->get(S("s1")) == nullptr || !quotesMap->get(S("s1"))->sameAs("'")) {
        TEST_FAIL("IniValue test69_1,value is %s \n",quotesMap->get(S("s1"))->toChars());
        break;
      }

      if(quotesMap->get(S("s2")) == nullptr || quotesMap->get(S("s2"))->size() != 0) {
        TEST_FAIL("IniValue quotes test70_1");
        break;
      }

      if(quotesMap->get(S("s3")) == nullptr || quotesMap->get(S("s3"))->sameAs("'")) {
        TEST_FAIL("IniValue quotes test71_1");
        break;
      }

      if(quotesMap->get(S("s4")) == nullptr || quotesMap->get(S("s4"))->sameAs("'")) {
        TEST_FAIL("IniValue quotes test72_1");
        break;
      }

      if(quotesMap->get(S("d1")) == nullptr || !quotesMap->get(S("d1"))->sameAs("\"")) {
        TEST_FAIL("IniValue quotes test69,value is %s \n",quotesMap->get(S("d1"))->toChars());
        break;
      }

      if(quotesMap->get(S("d2")) == nullptr || quotesMap->get(S("d2"))->size() != 0) {
        TEST_FAIL("IniValue quotes test70");
        break;
      }

      if(quotesMap->get(S("d3")) == nullptr || !quotesMap->get(S("d3"))->sameAs("\"\"\"")) {
        TEST_FAIL("IniValue quotes test71,value is %s \n",quotesMap->get(S("d3"))->toChars());
        break;
      }

      if(quotesMap->get(S("d4")) == nullptr || !quotesMap->get(S("d4"))->sameAs("\"\"\"\"")) {
        TEST_FAIL("IniValue quotes test72 ,value is %s \n",quotesMap->get(S("d4"))->toChars());
        break;
      }

      if(quotesMap->get(S("m1")) == nullptr || !quotesMap->get(S("m1"))->sameAs("\"")) {
        TEST_FAIL("IniValue quotes test73");
        break;
      }

      if(quotesMap->get(S("m2")) == nullptr || !quotesMap->get(S("m2"))->sameAs("\'")) {
        TEST_FAIL("IniValue quotes test74");
        break;
      }

      if(quotesMap->get(S("h1")) == nullptr || !quotesMap->get(S("h1"))->sameAs("hello\'world")) {
        TEST_FAIL("IniValue quotes test75 value is %s\n",quotesMap->get(S("h1"))->toChars());
        break;
      }

      if(quotesMap->get(S("h2")) == nullptr || !quotesMap->get(S("h2"))->sameAs("hello")) {
        TEST_FAIL("IniValue quotes test76");
        break;
      }

      if(quotesMap->get(S("h3")) == nullptr || !quotesMap->get(S("h3"))->sameAs("hello")) {
        TEST_FAIL("IniValue quotes test77");
        break;
      }

      if(quotesMap->get(S("h4")) == nullptr || !quotesMap->get(S("h4"))->sameAs("hello\"world")) {
        TEST_FAIL("IniValue quotes test77");
        break;
      }

      if(quotesMap->get(S("h5")) == nullptr || !quotesMap->get(S("h5"))->sameAs("hello")) {
        TEST_FAIL("IniValue quotes test78");
        break;
      }

      if(quotesMap->get(S("h6")) == nullptr || !quotesMap->get(S("h6"))->sameAs("hello")) {
        TEST_FAIL("IniValue quotes test78");
        break;
      }

      //section a
      if(iniValues->get(S("a")) == nullptr || iniValues->get(S("a"))->size() != 0) {
        TEST_FAIL("IniValue quotes test79");
        break;
      }

      if(iniValues->get(S("b")) == nullptr || iniValues->get(S("b"))->size() != 0) {
        TEST_FAIL("IniValue quotes test80");
        break;
      }

      if(iniValues->get(S("c")) == nullptr || iniValues->get(S("c"))->size() != 0) {
        TEST_FAIL("IniValue quotes test81");
        break;
      }

      if(iniValues->get(S("d")) == nullptr || iniValues->get(S("d"))->size() != 0) {
        TEST_FAIL("IniValue quotes test82");
        break;
      }

      if(iniValues->get(S("begin    end")) == nullptr || iniValues->get(S("begin    end"))->size() != 0) {
        TEST_FAIL("IniValue quotes test83");
        break;
      }

      if(iniValues->get(S("open[")) == nullptr || iniValues->get(S("open["))->size() != 0) {
        TEST_FAIL("IniValue quotes test84");
        break;
      }

      //multi inputs
      HashMap<String,String> multiInputMaps = iniValues->get(S("multi"));
      if(multiInputMaps == nullptr || multiInputMaps->size() != 12) {
        TEST_FAIL("IniValue quotes test85,multiInputMaps->size() is %d \n",multiInputMaps->size());
        break;
      }

      if(multiInputMaps->get(S("a")) == nullptr || !multiInputMaps->get(S("a"))->equals(S("beginend"))) {
        TEST_FAIL("IniValue quotes test86");
        break;
      }

      if(multiInputMaps->get(S("b")) == nullptr || !multiInputMaps->get(S("b"))->equals(S("begin end"))) {
        TEST_FAIL("IniValue quotes test87");
        break;
      }

      if(multiInputMaps->get(S("c")) == nullptr || !multiInputMaps->get(S("c"))->equals(S("begin  end"))) {
        TEST_FAIL("IniValue quotes test88");
        break;
      }

      if(multiInputMaps->get(S("d")) == nullptr || !multiInputMaps->get(S("d"))->equals(S("1234"))) {
        TEST_FAIL("IniValue quotes test89,v is %s \n",multiInputMaps->get(S("d"))->toChars());
        break;
      }

      if(multiInputMaps->get(S("e")) == nullptr || !multiInputMaps->get(S("e"))->equals(S("1     2     3     4"))) {
        TEST_FAIL("IniValue quotes test90,v is %s \n",multiInputMaps->get(S("e"))->toChars());
        break;
      }

      if(multiInputMaps->get(S("f")) == nullptr || !multiInputMaps->get(S("f"))->equals(S("1"))) {
        TEST_FAIL("IniValue quotes test91");
        break;
      }

      if(multiInputMaps->get(S("ww")) == nullptr || !multiInputMaps->get(S("ww"))->equals(S("1,2,3,4"))) {
        TEST_FAIL("IniValue quotes test92,v is %s \n",multiInputMaps->get(S("ww"))->toChars());
        break;
      }

      if(multiInputMaps->get(S("hidden")) == nullptr || !multiInputMaps->get(S("hidden"))->equals(S("because of the preceding backslash multi-lining the comment"))) {
        TEST_FAIL("IniValue quotes test93");
        break;
      }

      if(multiInputMaps->get(S("visible")) == nullptr || !multiInputMaps->get(S("visible"))->equals(S("1"))) {
        TEST_FAIL("IniValue quotes test94");
        break;
      }

      if(multiInputMaps->get(S("g")) == nullptr || !multiInputMaps->get(S("g"))->equals(S("1"))) {
        TEST_FAIL("IniValue quotes test95");
        break;
      }

      if(multiInputMaps->get(S("h")) == nullptr || !multiInputMaps->get(S("h"))->equals(S("1"))) {
        TEST_FAIL("IniValue quotes test96,value is %s \n",multiInputMaps->get(S("h"))->toChars());
        break;
      }

      if(multiInputMaps->get(S("multi line key")) == nullptr || !multiInputMaps->get(S("multi line key"))->equals(S("multi line value"))) {
        TEST_FAIL("IniValue quotes test96,value is %s \n",multiInputMaps->get(S("multi line key"))->toChars());
        break;
      }

      break;
    }

    TEST_OK("IniValue test100");
}
