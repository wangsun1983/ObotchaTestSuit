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
        if filename == "makefile":
            isMakefileExist = True
        if filename.find(".go") > 0:
            testType = TestType.TestByGo
        if filename.find(".python") > 0:
            testType = TestType.TestByPython

    if isMakefileExist:
        makeret = os.popen("cd " + path + " && make 2>&1").read()
        #debug
        #makeret = os.popen("cd " + path + " && make").read()
        buildpath = path.split("/")
        buildfile = BUILD_REPORT_DIR + "/"
        executefile = EXECUTE_REPORT_DIR + "/"
        for ll in buildpath:
            if ll != "." and len(ll) > 0 :
                buildfile += ll
                buildfile += "_"
                executefile += ll
                executefile += "_"

        if makeret.find("Error") > 0:
            buildfile += "FAIL.log"
        else:
            buildfile += "Success.log"

        #write BuildReport
        file = open(buildfile,"w")
        file.write(makeret)
        file.close()

        #test
        if makeret.find("Error") < 0:
            time = datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S.%f')[:-3]
            print("[" + time + "]" + " Start " + path)
            prepare(path)
            executeret = os.popen("cd " + path + " && ./mytest").read()
            print("[" + time + "]" + " Finish " + path)

            if executefile.find("[FAIL]") > 0:
                executefile += "FAIL.log"
            else:
                executefile += "Success.log"
            
            file = open(executefile,"w")
            file.write(executeret)
            file.close()
        else:
            executefile = executefile + "Nottest.log"
            file = open(executefile,"w")
            file.write("not test");
            file.close()

def main():
    #remove report
    os.system("rm -rf " + REPORT_DIR)
    currentPath = os.path.abspath('.') + "/"
    os.makedirs(currentPath + BUILD_REPORT_DIR)
    os.makedirs(currentPath + EXECUTE_REPORT_DIR)

    for path in testPath:
        for filename in os.listdir(path):
            testFolder = path + "/" + filename + "/";
            scanTest(testFolder)


if __name__ == '__main__':
    main()