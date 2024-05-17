#include <stdio.h>

#include "File.hpp"
#include "FileInputStream.hpp"
#include "FileOutputStream.hpp"
#include "FileNotFoundException.hpp"
#include "System.hpp"

using namespace obotcha;

extern void testFileInputStreamReadAll();
extern void testFileInputStreamRead();
extern void testFileInputStreamReadTo();
extern void testFileInputStreamSeekTo();
extern void testFileInputStreamClose();
extern void testFileInputStreamReadNode();

int main() {
  //prepare data
  File file = File::New("./tmp/data.txt");
  if(!file->exists()) {
    file->createNewFile();
      for(int i = 0;i<1024;i++) {
      FileOutputStream stream = FileOutputStream::New(file);
      stream->open(st(IO)::FileControlFlags::Append);
      String data = String::New("");
      for(int i = 0;i < 1024;i++) {
        data = data->append(String::New(st(System)::CurrentTimeMillis()));
      }
      stream->write(data->toByteArray());
      stream->close();
    }
  }
  testFileInputStreamReadNode();
  testFileInputStreamClose();
  testFileInputStreamReadAll();
  testFileInputStreamRead();
  testFileInputStreamReadTo();
  testFileInputStreamSeekTo();
}
