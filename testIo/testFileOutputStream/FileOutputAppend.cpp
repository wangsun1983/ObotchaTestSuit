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
        stream->open(st(OutputStream)::Trunc);
        stream->write('a');
        stream->flush();
        stream->close();

        FileOutputStream stream2 = createFileOutputStream(file);
        stream2->open(st(OutputStream)::Append);
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


}
