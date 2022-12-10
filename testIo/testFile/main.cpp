#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "File.hpp"

extern void testFileGetName();
extern void testFileGetAbsPath();
extern void testCanRwx();
extern void testFileSetRwx();
extern void testFileGetSuffix();
extern void testFileGetNameWithNoSuffix();
extern void testFileGetTime();
extern void testFileRename();

int main() {
    testFileRename();
   
    testFileGetTime();
    testFileGetNameWithNoSuffix();
    testFileGetName();
    testFileGetSuffix();
    testFileGetAbsPath();
    testCanRwx();
    testFileSetRwx();
}
