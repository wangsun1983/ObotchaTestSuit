#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Uint16.hpp"
#include "StrongPointer.hpp"
#include "String.hpp"
#include "TextLineReader.hpp"
#include "FileOutputStream.hpp"

using namespace obotcha;
extern void testTextLineReader();

int main() {
  //prepare data
  File file = File::New("./tmp/base_data");
  file->removeAll();
  if(!file->exists()) {
    file->createNewFile();
    FileOutputStream stream = FileOutputStream::New(file);
    //stream->open(st(IO)::FileControlFlags::Trunc);
	stream->open(st(IO)::FileControlFlags::Trunc);
    stream->write(String::New("hello\nworld\nni\nhao")->toByteArray());
    stream->close();
  }

  testTextLineReader();
  return 0;
}
