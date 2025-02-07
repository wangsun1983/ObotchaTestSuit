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

void testShareMemoryClear() {
	st(ShareMemory)::Create("aabbcc11",12);
    while(1) {
        ShareMemory memory = ShareMemory::New("aabbcc11",12,st(ShareMemory)::Type::WriteRead);
        ByteArray data = String::New("hello")->toByteArray();
        memory->write(data);
        
        ByteArray data2 = ByteArray::New(24);
        memory->read(data2);
        if(!data2->toString()->sameAs("hello")) {
            TEST_FAIL("[ShareMemory Test {clear()} case1]");
        }
        
        ByteArray data3 = ByteArray::New(24);
        memory->read(data3);
        if(!data3->toString()->sameAs("hello")) {
            TEST_FAIL("[ShareMemory Test {clear()} case2]");
        }
        
        memory->clear();
        auto data4 = ByteArray::New(24);
        int ret = memory->read(data4);
        for(int i = 0;i < data4->size();i++) {
            if(data4[i] != 0) {
                TEST_FAIL("[ShareMemory Test {clear()} case3],value[[%d] is 0x%x",i,data4[i]);
            }
        }
        memory->close();
        break;
    }
    TEST_OK("[ShareMemory Test {close()} case100]");
}
