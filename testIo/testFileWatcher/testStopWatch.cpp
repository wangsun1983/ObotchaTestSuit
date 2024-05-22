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

int open1_trace = 0;
int open2_trace = 0;

DECLARE_CLASS(StopWatcher) IMPLEMENTS(FileUpdateListener){
public:
    void onFileUpdate(String filepath,int op,int origid,int currentid) {
        if(open1_trace == 0 && op == st(FileWatcher)::Open) {
            open1_trace = 100;
        }else if(open1_trace == 100 && open2_trace == 0 && op == st(FileWatcher)::Open) {
            open2_trace = 100;
        }
    }
};

void testStopWatch() {
    //prepare data
    while(1) {
        printf("stop watch trace1 \n");
        File file = File::New("./tmp/testdata2.txt");
        file->removeAll();
        if(!file->exists()) {
            file->createNewFile();
            FileOutputStream stream = FileOutputStream::New(file);
            stream->open(st(IO)::FileControlFlags::Trunc);
            stream->write(String::New("hello world,this is a test data.")->toByteArray());
            stream->close();
        }
          
        FileWatcher watcher = FileWatcher::New();
        int id = watcher->startWatch("./tmp/testdata2.txt",st(FileWatcher)::Open,StopWatcher::New());
        Thread t = Thread::New([]{
            usleep(1000 *100);
            File f = File::New("./tmp/testdata2.txt");
            FileOutputStream stream = FileOutputStream::New(f);
            stream->open();
            stream->write(String::New("abc")->toByteArray());
        });
        t->start();
        
        usleep(1000*200);
        int ret = watcher->stopWatch(id);
        if(ret != 0) {
            TEST_FAIL("testFileWatcher stopWatch case1");
        }
        usleep(1000*50);
        Thread t2 = Thread::New([]{
            File f = File::New("./tmp/testdata2.txt");
            FileOutputStream stream = FileOutputStream::New(f);
            stream->open();
            stream->write(String::New("abc")->toByteArray());
        });
        t2->start();
        t2->join();
        printf("stop watch trace2 \n");
        if(open1_trace != 100) {
            TEST_FAIL("testFileWatcher stopWatch case2");
        }
        
        if(open2_trace != 0) {
            TEST_FAIL("testFileWatcher stopWatch case3");
        }
        watcher->close();
        printf("stop watch trace3 \n");
        break;
    }
    
    while(1) {
        printf("stop watch trace4 \n");
        FileWatcher watcher = FileWatcher::New();
        int ret = watcher->stopWatch(123);
        if(ret == 0) {
            TEST_FAIL("testFileWatcher stopWatch case4");
        }
        watcher->close();
        printf("stop watch trace5 \n");
        break;
    }
    
    TEST_OK("testFileWatcher stopWatch case100");
}
