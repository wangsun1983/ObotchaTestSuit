import os
import datetime
from enum import Enum


class TestType(Enum):
    TestNormal  = 1
    TestByGo   = 2
    TestByPython = 3 

testPath = ["./testLang",
            "./testIo",
            "./testSecurity",
            "./testUtil",
            "./testUtil/testFilament",
            "./testUtil/testText",
            "./testUtil/testConcurrent",
            "./testProcess",]

#create report again
REPORT_DIR = './Report'
BUILD_REPORT_DIR ='./Report/BuildReport'
EXECUTE_REPORT_DIR ='./Report/ExecuteReport'

def prepare(path):
    print("prepare path is " + path)
    os.popen("rm -rf " + path + "tmp")
    os.popen("mkdir " + path + "tmp")

#define defaultTest
def scanTest(path):
    isMakefileExist = False
    #judge whether path is a folder
    if os.path.isfile(path) or not os.path.exists(path):
        return

    testType = TestType.TestNormal
    for filename in os.listdir(path):
        if filename == "mytest":
            os.popen("cd " + path + " && rm mytest")
        if filename == "tmp":
            os.popen("cd " + path + " && rm -rf tmp")
        if filename == "server":
            os.popen("cd " + path + " && rm -rf server")
        if filename == "client":
            os.popen("cd " + path + " && rm -rf client")

def main():
    #remove report
    for path in testPath:
        for filename in os.listdir(path):
            testFolder = path + "/" + filename + "/";
            scanTest(testFolder)


if __name__ == '__main__':
    main()