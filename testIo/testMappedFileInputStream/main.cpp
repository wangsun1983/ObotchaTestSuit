#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Uint16.hpp"
#include "StrongPointer.hpp"
#include "String.hpp"
#include "BufferedReader.hpp"
#include "FileOutputStream.hpp"

using namespace obotcha;
extern void testMappedFileInputStream();

int main() {
  //prepare data
  File file = createFile("./tmp/base_data");
  file->removeAll();
  if(!file->exists()) {
    file->createNewFile();
    FileOutputStream stream = createFileOutputStream(file);
    stream->open(st(OutputStream)::Trunc);
    stream->write(createString("hello world,this is a test data.")->toByteArray());
    stream->close();
  }

  testMappedFileInputStream();
  return 0;
}
