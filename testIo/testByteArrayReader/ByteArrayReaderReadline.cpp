#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Barrier.hpp"
#include "ByteArrayReader.hpp"
#include "File.hpp"
#include "FileInputStream.hpp"
#include "FileOutputStream.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testReadline() {
#if 0
    //prepare data
    File file = createFile("./tmp/base_data");
    file->removeAll();
    if(!file->exists()) {
      file->createNewFile();
      FileOutputStream stream = createFileOutputStream(file);
      stream->open(st(IO)::FileControlFlags::Trunc);
      stream->write(createString("hello\nworld\nni\nhao")->toByteArray());
      stream->close();
    }


    FileInputStream stream = createFileInputStream(file);
    stream->open();
    ByteArray arr = stream->readAll();
    ByteArrayReader reader = createByteArrayReader(arr);
    ArrayList<String> contents = createArrayList<String>();
    contents->add(createString("hello"));
    contents->add(createString("world"));
    contents->add(createString("ni"));
    contents->add(createString("hao"));

    for(int i = 0;i<4;i++) {
        String t = reader->readLine();
        //TEST_FAIL("t is %s \n",t->toChars());
        if(!t->equals(contents->get(i))) {
          TEST_FAIL("[TestByteArrayReader ReadLine case1]");
        }
    }
    //TEST_FAIL("- \n");
    String t2 = reader->readLine();
    if(t2 != nullptr) {
      TEST_FAIL("[TestByteArrayReader ReadLine case2]");
    }

    TEST_OK("[TestByteArrayReader ReadLine case100]");
#endif
}
