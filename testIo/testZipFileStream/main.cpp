#include <stdio.h>

#include "File.hpp"
#include "FileInputStream.hpp"
#include "FileOutputStream.hpp"
#include "FileNotFoundException.hpp"
#include "System.hpp"

using namespace obotcha;

extern void testZipDecompress();
extern void testZipCompress();
extern void testZipFileStreamRead();

int main() {
  //prepare test data
  File file = File::New("./tmp/base_data");
  if(!file->exists()) {
    file->createNewFile();
      for(int i = 0;i<32*1024;i++) {
      FileOutputStream stream = FileOutputStream::New(file);
      stream->open(st(IO)::FileControlFlags::Append);
      String data = String::New("");
      for(int j = 0;j < 32;j++) {
        data = data->append(String::New(st(System)::CurrentTimeMillis()));
      }
      stream->write(data->toByteArray());
      stream->close();
    }
  }

  File zipfile = File::New("./tmp/base_zip");
  if(!zipfile->exists()) {
    system("zip -r ./tmp/base_zip ./tmp/base_data");
  }

  File zippasswordfile = File::New("./tmp/base_password_data");
  if(!zippasswordfile->exists()) {
    system("zip -P 123456 -r ./tmp/base_password_data ./tmp/base_data");
  }

  testZipDecompress();
  testZipCompress();
  testZipFileStreamRead();
}
