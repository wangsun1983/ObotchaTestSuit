#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "StrongPointer.hpp"
#include "ShareMemory.hpp"
#include "EPollObserver.hpp"
#include "TestLog.hpp"
#include "File.hpp"

using namespace obotcha;

//do not support ????
void testShareMemoryClose() {
	st(ShareMemory)::Create("aabbcc",12);
    while(1) {
        ShareMemory memory = createShareMemory("aabbcc",12,st(ShareMemory)::Type::WriteRead);
        File f = createFile("/dev/shm/aabbcc");
        if(!f->exists()) {
            TEST_FAIL("[ShareMemory Test {close()} case1]");
        }
        usleep(1000*50);
        //memory->close();
		st(ShareMemory)::Clear("aabbcc");
        File f2 = createFile("/dev/shm/aabbcc");
        if(f2->exists()) {
            TEST_FAIL("[ShareMemory Test {close()} case2]");
        }
        break;
    }
    TEST_OK("[ShareMemory Test {close()} case100]");
}
