import os
import datetime
import threading
import time
from enum import Enum


class TestType(Enum):
    TestNormal             = 1
    TestRunGoClient        = 2
    TestRunGoServer        = 3
    TestRunPythonClient    = 4
    TestRunPythonServer    = 5

#"./testLang",
#            "./testIo",
#            "./testSecurity",
#            "./testUtil",
#            "./testUtil/testFilament",
#            "./testUtil/testText",
#            "./testUtil/testConcurrent",
#            "./testProcess"

testPath = ["./testNet/testSocket/testSocksSocketImpl/Server"]

#create report again
REPORT_DIR = './Report'
BUILD_REPORT_DIR ='./Report/BuildReport'
EXECUTE_REPORT_DIR ='./Report/ExecuteReport'

def prepare(path):
    print("prepare path is " + path)
    os.popen("rm -rf " + path + "tmp")
    os.popen("mkdir " + path + "tmp")

execThreadLog = ""
def execByThread(cmd,elog):
    global execThreadLog
    execThreadLog = os.popen(cmd).read()

#define defaultTest
def scanTest(path):
    print("path is ",path)

    isMakefileExist = False
    #judge whether path is a folder
    if os.path.isfile(path) or not os.path.exists(path):
        print("path trace is ",path)
        return

    testType = TestType.TestNormal
    for filename in os.listdir(path):
        print("filename is ",filename)
        if filename == "makefile":
            isMakefileExist = True
        if filename == "client.go":
            testType = TestType.TestRunGoClient
        if filename == "server.go":
            testType = TestType.TestRunGoServer
        if filename == "client.py":
            testType = TestType.TestRunPythonClient
        if filename == "server.py":
            testType = TestType.TestRunPythonServer

    print("path trace2 type is ",testType)

    if isMakefileExist:
        makeret = os.popen("cd " + path + " && make 2>&1").read()
        if testType == TestType.TestRunGoServer :
            gobuild = os.popen("cd " + path + " && go build server.go 2>&1").read()
            makeret = makeret + "\r\n" + gobuild
        if testType == TestType.TestRunGoClient :
            gobuild = os.popen("cd " + path + " && go build client.go 2>&1").read()
            makeret = makeret + "\r\n" + gobuild

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
            printTime = datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S.%f')[:-3]
            print("[" + printTime + "]" + " Start " + path)
            prepare(path)
            #check whether it is a cs test
            executeret = ""

            if testType == TestType.TestNormal:
                executeret = os.popen("cd " + path + " && ./mytest").read()
            if testType == TestType.TestRunPythonClient:
                print("start python client test")
                cmd = "cd " + path + " && ./mytest"
                t1 = threading.Thread(target= execByThread, args=(cmd,executeret), name='Thread-A')
                t1.start()
                time.sleep(1)

                pythonCmd = "cd " + path + " && python3 client.py"
                t2 = threading.Thread(target= execByThread, args=(pythonCmd,executeret), name='Thread-A')
                t2.start()
                t1.join();
                t2.join();
                global execThreadLog
                executeret = execThreadLog
                execThreadLog = ""

            print(executeret)
            printTime = datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S.%f')[:-3]
            print("[" + printTime + "]" + " Finish " + path)

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