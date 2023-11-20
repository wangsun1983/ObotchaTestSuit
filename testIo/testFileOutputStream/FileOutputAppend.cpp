#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "FileOutputStream.hpp"
#include "FileInputStream.hpp"
#include "File.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void fileoutput_append_test() {

    //bool _FileOutputStream::write(char c)
    while(1) {
        File file = createFile("./tmp/output_append_test.txt");
        file->createNewFile();
        FileOutputStream stream = createFileOutputStream(file);
        stream->open(st(IO)::FileControlFlags::Trunc);
        stream->write('a');
        stream->flush();
        stream->close();

        FileOutputStream stream2 = createFileOutputStream(file);
        stream2->open(st(IO)::FileControlFlags::Append);
        stream2->write('b');
        stream2->flush();
        stream2->close();

        if(file->length() != 2) {
            TEST_FAIL("[TestFileOutputStream Test {open(Append)} case1]");
            break;
        }

        FileInputStream inputstream = createFileInputStream(file);
        inputstream->open();
        ByteArray content = inputstream->readAll();
        if(content == nullptr || content->size() != 2 ||content->at(0) != 'a' || content->at(1) != 'b') {
            TEST_FAIL("[TestFileOutputStream Test {open(Append)} case2]");
            break;
        }

        //file->removeAll();

        TEST_OK("[TestFileOutputStream Test {open(Append)} case3]");
        break;
    }
    
    
    while(1) {
        File file = createFile("./tmp/output_append_test3.txt");
        String content1 = createString("this i a");
        file->createNewFile();
        FileOutputStream stream = createFileOutputStream(file);
        stream->open(st(IO)::FileControlFlags::Trunc);
        stream->write(content1->toByteArray());
        stream->flush();
        stream->close();
    
        FileOutputStream stream2 = createFileOutputStream(file);
        String content2 = createString("this i b");
        stream2->open(st(IO)::FileControlFlags::Append);
        stream2->write(content2->toByteArray());
        stream2->flush();
        stream2->close();
    
        if(file->length() != 16) {
            TEST_FAIL("[TestFileOutputStream Test {open(Append)} case4]");
            break;
        }
    
        FileInputStream inputstream = createFileInputStream(file);
        inputstream->open();
        ByteArray content3 = inputstream->readAll();
        String mystr = content3->toString();
        if(content3 == nullptr || content3->size() != 16 ||
            mystr->sameAs("this i athis is b")) {
            TEST_FAIL("[TestFileOutputStream Test {open(Append)} case5]");
            break;
        }
        inputstream->close();
        
        FileOutputStream stream3 = createFileOutputStream(file);
        String str = createString("this i c");
        stream3->open(st(IO)::FileControlFlags::Trunc);
        stream3->write(str->toByteArray());
        stream3->flush();
        stream3->close();
        
        inputstream = createFileInputStream(file);
        inputstream->open();
        content3 = inputstream->readAll();
        data = content3->toString();
        if(content3 == nullptr || content3->size() != 8 ||
            !data->sameAs("this i c")) {
            TEST_FAIL("[TestFileOutputStream Test {open(Append)} case6]");
            break;
        }
        
        TEST_OK("[TestFileOutputStream Test {open(Append)} case7]");
        break;
    }
}
