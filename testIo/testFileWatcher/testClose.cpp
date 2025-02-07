#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "FileWatcher.hpp"
#include "TestLog.hpp"
#include "CountDownLatch.hpp"
#include "TimeWatcher.hpp"
#include "File.hpp"
#include "FileOutputStream.hpp"
#include "Process.hpp"
#include "System.hpp"
#include "TextLineReader.hpp"
#include "ForEveryOne.hpp"

using namespace obotcha;

void testClose() {
    //prepare data
    FileWatcher watcher = FileWatcher::New();
    usleep(1000*100);
    watcher->close();
    usleep(1000*100);
    
    auto mypid = st(Process)::MyPid();
    String cmd = String::New("ls -la /proc/");
    cmd = cmd->append(String::New(mypid));
    cmd = cmd->append("/task");
    
    auto ret = st(System)::ExecuteForResult(cmd);
    TextLineReader reader = TextLineReader::New(ret);
    ArrayList<String> lines = reader->lines();
    ForEveryOne(str,lines) {
        printf("ss is [%s] \n",str->toChars());
    }
    
    if(lines->size() != 5) {
        TEST_FAIL("FileWatcher close case1,size is %zu",lines->size());
    }
    
    if(!lines->get(3)->contains(String::New(mypid))) {
        TEST_FAIL("FileWatcher close case2");
    }
    
    TEST_OK("FileWatcher close case100");
}
