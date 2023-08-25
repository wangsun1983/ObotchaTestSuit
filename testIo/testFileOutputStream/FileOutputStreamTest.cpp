#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "FileOutputStream.hpp"
#include "FileInputStream.hpp"
#include "File.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void fileoutput_base_test() {
    //bool _FileOutputStream::write(char c)
    while(1) {
        File file = createFile("./tmp/base_test_1.txt");
        file->createNewFile();
        FileOutputStream stream = createFileOutputStream(file);
        stream->open(st(IO)::FileControlFlags::Trunc);
        stream->write('a');
        stream->flush();
        stream->close();

        if(file->length() != 1) {
            TEST_FAIL("[TestFileOutputStream Test {write(char)} case1]");
            break;
        }

        FileInputStream inputstream = createFileInputStream(file);
        inputstream->open();
        ByteArray content = inputstream->readAll();
        if(content == nullptr || content->size() != 1 ||content->at(0) != 'a') {
            TEST_FAIL("[TestFileOutputStream Test {write(char)} case2]");
            break;
        }

        //file->removeAll();

        TEST_OK("[TestFileOutputStream Test {write(char)} case3]");
        break;
    }

    //bool _FileOutputStream::write(ByteArray buff)
    while(1) {
        File file = createFile("./tmp/base_test_2.txt");
        file->createNewFile();
        FileOutputStream stream = createFileOutputStream(file);
        stream->open(st(IO)::FileControlFlags::Trunc);
        ByteArray b = createString("hello")->toByteArray();
        stream->write(b);
        stream->flush();
        stream->close();

        if(file->length() != 5) {
            TEST_FAIL("[TestFileOutputStream Test {write(ByteArray)} case1]");
            break;
        }

        FileInputStream inputstream = createFileInputStream(file);
        inputstream->open();
        ByteArray content = inputstream->readAll();
        if(content == nullptr || content->size() != 5) {
            TEST_FAIL("[TestFileOutputStream Test {write(ByteArray)} case2]");
            break;
        }

        String cc = content->toString();
        if(!cc->sameAs("hello")) {
            TEST_FAIL("[TestFileOutputStream Test {write(ByteArray)} case3]");
            break;
        }

        //file->removeAll();

        TEST_OK("[TestFileOutputStream Test {write(ByteArray)} case4]");
        break;
    }

    //bool _FileOutputStream::write(ByteArray buff,long size)
    while(1) {
        File file = createFile("./tmp/base_test_3.txt");
        file->createNewFile();
        FileOutputStream stream = createFileOutputStream(file);
        stream->open(st(IO)::FileControlFlags::Trunc);

        ByteArray b = createString("helloworld")->toByteArray();
        stream->write(b,5);
        stream->flush();
        stream->close();

        if(file->length() != 5) {
            TEST_FAIL("[TestFileOutputStream Test {write(ByteArray,long)} case1]");
            break;
        }

        FileInputStream inputstream = createFileInputStream(file);
        inputstream->open();
        ByteArray content = inputstream->readAll();
        if(content == nullptr || content->size() != 5) {
            TEST_FAIL("[TestFileOutputStream Test {write(ByteArray,long)} case2]");
            break;
        }

        String cc = content->toString();
        if(!cc->sameAs("world")) {
            TEST_FAIL("[TestFileOutputStream Test {write(ByteArray,long)} case3]");
            break;
        }

        //file->removeAll();

        TEST_OK("[TestFileOutputStream Test {write(ByteArray,long)} case4]");
        break;
    }

    //bool _FileOutputStream::writeString(String s)
    while(1) {
        File file = createFile("./tmp/base_test_4.txt");
        file->createNewFile();
        FileOutputStream stream = createFileOutputStream(file);
        stream->open(st(IO)::FileControlFlags::Trunc);
        stream->writeString(createString("nihao,abc"));
        stream->flush();
        stream->close();

        if(file->length() != 9) {
            TEST_FAIL("[TestFileOutputStream Test {write(String)} case1]");
            break;
        }

        FileInputStream inputstream = createFileInputStream(file);
        inputstream->open();
        ByteArray content = inputstream->readAll();
        if(content == nullptr || content->size() != 9) {
            TEST_FAIL("[TestFileOutputStream Test {write(String)} case2]");
            break;
        }

        String cc = content->toString();
        if(!cc->sameAs("nihao,abc")) {
            TEST_FAIL("[TestFileOutputStream Test {write(String)} case3]");
            break;
        }

        //file->removeAll();

        TEST_OK("[TestFileOutputStream Test {write(String)} case4]");
        break;
    }
}
