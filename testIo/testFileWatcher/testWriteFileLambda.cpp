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

int write_count_lambda = 0;

void testWriteFileLambda() {
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
        FileOutputStream stream = FileOutputStream::New(f);
        stream->open();
        int id = watcher->startWatch("./tmp/testdata4.txt",
                    st(FileWatcher)::Full,
                    [](String filepath,int op,int origid,int currentid){
                        if(filepath->contains("tmp/testdata4.txt") && op == IN_MODIFY) {
                            write_count_lambda = 123;
                        }
                    });
        usleep(1000*100);
        stream->write(String::New("abc")->toByteArray());
        stream->flush();
        usleep(1000*200);
        
        if(write_count_lambda != 123) {
            TEST_FAIL("testFileWatcher testWriteFileLambda case1");
        }
        watcher->close();
        break;
    }
    
    TEST_OK("testFileWatcher testWriteFileLambda case100");
}
