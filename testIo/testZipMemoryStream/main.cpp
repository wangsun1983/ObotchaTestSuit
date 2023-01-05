#include <stdio.h>

#include "File.hpp"
#include "FileInputStream.hpp"
#include "FileOutputStream.hpp"
#include "FileNotFoundException.hpp"
#include "System.hpp"

using namespace obotcha;

extern void testZipDecompress();

int main() {
  testZipDecompress();
  return 0;
}
