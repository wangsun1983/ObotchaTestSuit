#include <stdio.h>
#include <unistd.h>

#include "YamlReader.hpp"
#include "YamlValue.hpp"
#include "Log.hpp"
#include "TestLog.hpp"

using namespace obotcha;

struct TestData {
    std::string path;
    std::string name;
};

int main() {
    YamlReader reader = createYamlReader()->loadFile(createFile("test.yaml"));
    YamlValue root = reader->parse();

    //version: '{build}'
    String value1 = root->get<String>(createString("version"));
    if(!value1->sameAs("{build}")) {
      TEST_FAIL("[TestYamlReader Test parse()} case1]");
    }

    //os: Visual Studio 2015
    String value2 = root->get<String>(createString("os"));
    if(!value2->sameAs("Visual Studio 2015")) {
      TEST_FAIL("[TestYamlReader Test parse()} case2]");
    }

    //environment:
    //  matrix:
    //  - Toolset: v140
    //  - Toolset: v120
    //  - Toolset: v110
    //  - Toolset: v100
    YamlValue value3 = root->get<YamlValue>(createString("environment"));
    YamlValue value3_1 = value3->get<YamlValue>(createString("matrix"));
    YamlValue value3_1_1 = value3_1->getAt<YamlValue>(0);
    String chckV = value3_1_1->get<String>(createString("Toolset"));
    if(!chckV->sameAs("v140")) {
      TEST_FAIL("[TestYamlReader Test parse()} case3]");
    }

    YamlValue value3_1_2 = value3_1->getAt<YamlValue>(1);
    chckV = value3_1_2->get<String>(createString("Toolset"));
    if(!chckV->sameAs("v120")) {
      TEST_FAIL("[TestYamlReader Test parse()} case4]");
    }

    YamlValue value3_1_3 = value3_1->getAt<YamlValue>(2);
    chckV = value3_1_3->get<String>(createString("Toolset"));
    if(!chckV->sameAs("v110")) {
      TEST_FAIL("[TestYamlReader Test parse()} case5]");
    }

    YamlValue value3_1_4 = value3_1->getAt<YamlValue>(3);
    chckV = value3_1_4->get<String>(createString("Toolset"));
    if(!chckV->sameAs("v100")) {
      TEST_FAIL("[TestYamlReader Test parse()} case6]");
    }

    YamlValue value4 = root->get<YamlValue>("platform");
    String value4_1 = value4->getAt<String>(0);
    if(!value4_1->sameAs("Win32")) {
      TEST_FAIL("[TestYamlReader Test parse()} case7]");
    }

    String value4_2 = value4->getAt<String>(1);
    if(!value4_2->sameAs("x64")) {
      TEST_FAIL("[TestYamlReader Test parse()} case8]");
    }

    String value4_3 = value4->getAt<String>(2);
    if(!value4_3->sameAs("111")) {
      TEST_FAIL("[TestYamlReader Test parse()} case9]");
    }

    YamlValue value5 = root->get<YamlValue>("configuration");
    String value5_1 = value5->getAt<String>(0);
    if(!value5_1->sameAs("Debug")) {
      TEST_FAIL("[TestYamlReader Test parse()} case10]");
    }

    YamlValue value6 = root->get<YamlValue>("build");
    String value6_1 = value6->get<String>("verbosity");
    if(!value6_1->sameAs("minimal")) {
      TEST_FAIL("[TestYamlReader Test parse()} case11]");
    }

    YamlValue value7 = root->get<YamlValue>("artifacts");
    YamlValue value7_1 = value7->getAt<YamlValue>(0);
    String value7_2 = value7_1->get<String>("path");
    String value7_3 = value7_1->get<String>("name");
    if(!value7_2->sameAs("_build/Testing/Temporary/*") || !value7_3->sameAs("test_results")) {
      TEST_FAIL("[TestYamlReader Test parse()} case12]");
    }

    YamlValue value8 = root->get<YamlValue>("before_build");
    YamlValue value8_1 = value8->getAt<YamlValue>(0);
    String str8_1 = value8_1->get<String>(createString("ps"));
    String vv = createString("Write-Output \"Configuration: $env:CONFIGURATION\"\n"\
    "Write-Output \"Platform: $env:PLATFORM\"\n"\
    "$generator = switch ($env:TOOLSET)\n"\
    "{\n"\
    "    \"v140\" {\"Visual Studio 14 2015\"}\n"\
    "    \"v120\" {\"Visual Studio 12 2013\"}\n"\
    "    \"v110\" {\"Visual Studio 11 2012\"}\n"\
    "    \"v100\" {\"Visual Studio 10 2010\"}\n"\
    "}\n"\
    "if ($env:PLATFORM -eq \"x64\")\n"\
    "{\n"\
    "    $generator = \"$generator Win64\"\n"\
    "}\n");

    if(!str8_1->equals(vv)) {
      TEST_FAIL("[TestYamlReader Test parse()} case13],value is %s \n",vv->toChars());
    }

    TEST_OK("[TestYamlReader Test parse()} case14]");
}
