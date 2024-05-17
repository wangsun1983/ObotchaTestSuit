#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "FileOutputStream.hpp"
#include "FileInputStream.hpp"
#include "File.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void file_write_loop() {
	File file = File::New("./tmp/loopwrite.txt");	
	if(!file->exists()) {
		file->createNewFile();
	}
	
    for(int i = 0;i < 1024*128;i++) {
	    FileOutputStream stream = FileOutputStream::New(file);
	    stream->open();
	    auto data = String::New(i)->toByteArray();
	    stream->write(data);
	    stream->flush();
	    stream->close();
		
		FileInputStream input = FileInputStream::New(file);
		input->open();
		ByteArray outdata = input->readAll();
		
		if(outdata->toString() != String::New(i)) {
			TEST_FAIL("[TestFileOutputStream Test {Loop write} case1],i is %d",i);
			break;
		}
		
		String want = String::New(i);
		auto p = want->toChars();
		auto q = outdata->toValue();
		for(int j = 0;j<outdata->size();j++) {
			if((int)p[j] != (int)q[j]) {
				TEST_FAIL("[TestFileOutputStream Test {Loop write} case2],j is %d",j);
				return;
			}
		}
	}
	TEST_OK("[TestFileOutputStream Test {Loop write} case100]");
}
