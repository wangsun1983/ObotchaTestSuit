import os
import fileinput

includePath = [
    "../util/concurrent/include/",
    "../util/coroutine/include/",
    "../util/text/include/",
    "../sql/include/",
    "../lang/include/",
    "../io/include/",
    "../util/include/",
    "../net/include/",
    "../net/http/include/",
    "../net/socket/include/",
    "../net/websocket/include/",
    "../net/smtp/include/",
    "../net/http/client/include/",
    "../security/include/",
    "../process/include/",
]

testPath = [ "./testIo",
    "./testIo/testAsyncOutputChannel",
    "./testLang",
    "./testNet",
    "./testNet/testHttp",
    "./testNet/testHttp/testHttpClient_go",
    #do not test"./testNet/testHttp/testHttpClient_python",
    "./testNet/testHttp/testHttpServer_go",
    "./testNet/testHttp/testHttpServer_python3",
    "./testNet/testHttp/testHttpRequestParser",
    #do not test "./testNet/testHttp2",
    "./testNet/testSocket/testDatagramSocket/Client",
    "./testNet/testSocket/testDatagramSocket/Server",
    "./testNet/testSocket/testLocalSocketImpl/Client",
    "./testNet/testSocket/testLocalSocketImpl/Server",
    "./testNet/testSocket/testSocketMonitor/",
    "./testNet/testSocket/testSocksSocketImpl/Client",
    "./testNet/testSocket/testSocksSocketImpl/Server",
    "./testNet/testSocket/testSocksSocketImpl/Server_go",
    "./testNet/testSocket/testSSLSocketImpl/Server",
    "./testNet/testSocketV6/testDatagramSocket/Client",
    "./testNet/testSocketV6/testDatagramSocket/Server",
    "./testNet/testSocketV6/testSocksSocketImpl/Client",
    "./testNet/testSocketV6/testSocksSocketImpl/Server",
    "./testNet/testWebsocket/testWebSocketClient/python_server",
    "./testNet/testWebsocket",
    "./testNet/testWebsocket/testWebSocketServer/go_client",
    "./testNet/testWebsocket/testWebSocketServer/python_client",
    "./testProcess",
    "./testSecurity",
    "./testUtil",
    "./testUtil/testText",
    "./testUtil/testFilament",
    "./testUtil/testConcurrent",
    "./testSql",
    "./testSql/testMySqlClient",
    "./testSql/testRedisClient",
    "./testSql/testSqlite3Client",]

#create report again
REPORT_DIR = './Report'
COVERAGE_REPORT_DIR ='./Report/CoverageReport'
COVERAGE_REPORT_FILE ='./Report/CoverageReport/report.txt'

functionMap = {'':0}
buildFailedList = []

def prepareReportFolder():
    currentPath = os.path.abspath('.') + "/"
    if not os.path.exists(currentPath + REPORT_DIR):
        os.makedirs(currentPath + REPORT_DIR)
    
    if not os.path.exists(currentPath + COVERAGE_REPORT_DIR):
        os.makedirs(currentPath + COVERAGE_REPORT_DIR)

    os.popen("rm " + COVERAGE_REPORT_FILE).read()


def dumpObotchaSo():
    os.popen("objdump -t ../out/lib/libobotcha.so > ./Report/CoverageReport/obotchadump.txt").read()

def analyseObjdump():
    for line in fileinput.input("./Report/CoverageReport/obotchadump.txt"):
        if line.find("g ") > 0 and line.find("obotcha") >0 and line.find(".text") > 0:
            #print(line)
            index = line.rfind(" ")
            function = line[index+1:len(line) - 1]
            functionMap[function] = 1

privateFunc={"classname::function":1}

def scanInclude():
    for path in includePath:
        for filename in os.listdir(path):
            print("full path is ",path + filename)
            isPrivateStart = True
            className = ""
            for line in fileinput.input(path + filename):
                if line.find("private:") >= 0:
                    isPrivateStart = True
                    continue
                elif line.find("public:") >= 0:
                    isPrivateStart = False
                    continue
                elif line.find("DECLARE_") >= 0:
                    classStart = line.find("(");
                    classEnd = line.find(")");
                    className = line[classStart + 1:classEnd]
                    continue

                if isPrivateStart:
                    endIndex = line.find("(")
                    if endIndex > 0 :
                        startIndex = endIndex
                        while startIndex >= 0 and line[startIndex] != " ":
                            startIndex = startIndex - 1
                        funcname = line[startIndex + 1:endIndex]
                        privateFunc[className + "::" + funcname] = 1


def scan(path):
    print("path is ",path)
    isMakeFileExist = False

    for filename in os.listdir(path):
        if filename == "makefile":
            print("i find makefile:",path)
            isMakeFileExist = True
            break
    
    print("isMakeFileExist is ",isMakeFileExist)

    if isMakeFileExist:
        print("start make")
        makeret = os.popen("cd " + path + " && make 2>&1").read()
        if makeret.find("Error") > 0:
            buildFailedList.append(path)
        else:
            #make first
            cmd = "objdump -t " + path + "mytest"
            print("objdump cmd is ",cmd)
            objanalysis = os.popen("objdump -t " + path + "mytest").read()
            for line in objanalysis.splitlines():
                if line.find("UND") > 0 and line.find("obotcha") >0:
                    index = line.rfind(" ")
                    function = line[index+1:len(line) - 1]
                    print("find function:",function)
                    functionMap[function] = 1

def main():
    scanInclude();
    prepareReportFolder()
    dumpObotchaSo()
    analyseObjdump()
    print("before scan size is " + str(len(functionMap)))

    for path in testPath:
        for filename in os.listdir(path):
            testFolder = path + "/" + filename + "/";
            scan(testFolder)

    #print("scan size is " + str(len(functionMap)))

    f = open(COVERAGE_REPORT_FILE, "a")
    for key,value in functionMap.items():
        if value == 1:
            filt = os.popen("c++filt " + key).read()
            
            endIndex = filt.find("(")
            startIndex =filt.find("_")
            funcStr = filt[startIndex + 1:endIndex]
            if not funcStr in privateFunc.keys():
                f.write(filt + '\r\n')
                print(filt)

if __name__ == '__main__':
    main()