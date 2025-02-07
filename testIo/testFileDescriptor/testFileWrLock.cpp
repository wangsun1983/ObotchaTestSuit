#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <fcntl.h>
#include <sys/wait.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Barrier.hpp"
#include "FileDescriptor.hpp"
#include "TestLog.hpp"
#include "File.hpp"
#include "TimeWatcher.hpp"

using namespace obotcha;

void testFileWrLock() {
    File f1 = File::New("./tmp/rdlock");
    if(!f1->exists()) {
        f1->createNewFile();
    }
    
    auto pid = fork();
    if(pid == 0) {
        usleep(100*1000);
        auto fd = f1->open();
        TimeWatcher watcher = TimeWatcher::New();
        watcher->start();
        fd->lock(st(IO)::FileLockFlags::ReadLock);
        auto cost = watcher->stop();
        if(cost > 405 || cost < 395) {
            TEST_FAIL("[FileDescriptor WriteLock Test case1],cost is %d",cost);
        }
        fd->unlock();
    } else {
        auto fd = f1->open();
        fd->lock(st(IO)::FileLockFlags::WriteLock);
        usleep(1000*500);
        fd->unlock();
        wait(nullptr);
    }
    TEST_OK("[FileDescriptor WriteLock Test case100]");
}
