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

void testShareMemoryReadWrite() {
	while(1) {
		st(ShareMemory)::Create("trdwr",12);
		auto sharemem = ShareMemory::New("trdwr",12,st(ShareMemory)::Type::WriteRead);
		ByteArray data = String::New("hello")->toByteArray();
		sharemem->write(data);
		
		auto sharemem1 = ShareMemory::New("trdwr",12,st(ShareMemory)::Type::Read);
		ByteArray d1 = ByteArray::New(12);
		sharemem1->read(d1);
		sharemem1->close();
		
		auto sharemem2 = ShareMemory::New("trdwr",12,st(ShareMemory)::Type::Read);
		ByteArray d2 = ByteArray::New(12);
		sharemem2->read(d2);
		
		if(!d1->toString()->sameAs("hello")) {
			TEST_FAIL("[ShareMemory Test {Read/Write()} case1]");
		}
		
		if(!d2->toString()->sameAs("hello")) {
			TEST_FAIL("[ShareMemory Test {Read/Write()} case2]");
		}
		break;
	}
	
    TEST_OK("[ShareMemory Test {Read/Write()} case100]");
}
