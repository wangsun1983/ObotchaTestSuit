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
#include "FileInputStream.hpp"

using namespace obotcha;

int close_nowrite_count = 0;

DECLARE_CLASS(CloseNoWriteWatcher) IMPLEMENTS(FileUpdateListener){
public:
    void onFileUpdate(String filepath,int op,int origid,int currentid) {
        if(filepath->contains("tmp/testdata4.txt") && op == IN_CLOSE_NOWRITE) {
            close_nowrite_count = 123;
        }
    }
};

void testCloseNoWrite() {
    //prepare data
    while(1) {
        File file = File::New("./tmp/testdata4.txt");
        file->removeAll();
        if(!file->exists()) {
            file->createNewFile();
            FileOutputStream stream = FileOutputStream::New(file);
            stream->open(st(IO)::FileControlFlags::Trunc);
            stream->write(String::New("hello world,this is a test data.")->toByteArray());
            stream->close();
        }
          
        FileWatcher watcher = FileWatcher::New();
        File f = File::New("./tmp/testdata4.txt");
        FileInputStream stream = FileInputStream::New(f);
        stream->open();
        int id = watcher->startWatch("./tmp/testdata4.txt",st(FileWatcher)::Full,CloseNoWriteWatcher::New());
        usleep(1000*100);
        stream->close();
        usleep(1000*200);
        
        if(close_nowrite_count != 123) {
            TEST_FAIL("testFileWatcher testCloseNoWrite case1");
        }
        
        watcher->close();
        break;
    }
    
    TEST_OK("testFileWatcher testCloseNoWrite case100");
}
