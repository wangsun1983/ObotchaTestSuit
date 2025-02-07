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
CountDownLatch latch = CountDownLatch::New(1);

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

int testStartWatch() {
    //prepare data
    File file = File::New("./tmp/testdata.txt");
    file->removeAll();
    if(!file->exists()) {
        file->createNewFile();
        FileOutputStream stream = FileOutputStream::New(file);
        stream->open(st(IO)::FileControlFlags::Trunc);
        stream->write(String::New("hello world,this is a test data.")->toByteArray());
        stream->close();
    }
      
    FileWatcher watcher = FileWatcher::New();
    watcher->startWatch("./tmp/testdata.txt",st(FileWatcher)::Open,MyFileObserver::New());
    Thread t = Thread::New([]{
        usleep(1000 *100);
        File f = File::New("./tmp/testdata.txt");
        FileOutputStream stream = FileOutputStream::New(f);
        stream->open();
        stream->write(String::New("abc")->toByteArray());
    });
    t->start();
    
    TimeWatcher twatcher = TimeWatcher::New();
    twatcher->start();
    latch->await(400);
    long v = twatcher->stop();
    if(v > 200) {
        TEST_FAIL("testFileWatcher case3");
    }
    
    TEST_OK("testFileWatcher case100");
    return 0;
}
