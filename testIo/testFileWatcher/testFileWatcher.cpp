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

using namespace obotcha;

int testCount = 0;
CountDownLatch latch = createCountDownLatch(1);

DECLARE_CLASS(MyFileObserver) IMPLEMENTS(FileUpdateListener){
public:
    void onFileUpdate(String filepath,int op,int origid,int currentid) {
        if(!filepath->contains("testdata.txt")) {
            TEST_FAIL("testFileWatcher case1");
        }
        
        if(op != st(FileWatcher)::Open && op != st(FileWatcher)::Modify) {
            TEST_FAIL("testFileWatcher case2");
        }
        
        latch->countDown();
    }
};

int main() {
    //prepare data
    File file = createFile("./tmp/testdata.txt");
    file->removeAll();
    if(!file->exists()) {
        file->createNewFile();
        FileOutputStream stream = createFileOutputStream(file);
        stream->open(st(IO)::FileControlFlags::Trunc);
        stream->write(createString("hello world,this is a test data.")->toByteArray());
        stream->close();
    }
      
    FileWatcher watcher = createFileWatcher();
    watcher->startWatch("./tmp/testdata.txt",st(FileWatcher)::Open,createMyFileObserver());
    Thread t = createThread([]{
        usleep(1000 *100);
        File f = createFile("./tmp/testdata.txt");
        FileOutputStream stream = createFileOutputStream(f);
        stream->open();
        stream->write(createString("abc")->toByteArray());
    });
    t->start();
    
    TimeWatcher twatcher = createTimeWatcher();
    twatcher->start();
    latch->await(400);
    long v = twatcher->stop();
    if(v > 200) {
        TEST_FAIL("testFileWatcher case3");
    }
    
    TEST_OK("testFileWatcher case100");
}
