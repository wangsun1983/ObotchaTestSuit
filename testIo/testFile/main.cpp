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
extern void testFileOpen();
extern void testFileCreateDirs();
extern void testFileIsDirectory();

int main() {
    testFileRename();
    testFileOpen();
    testFileGetTime();
    testFileGetNameWithNoSuffix();
    testFileGetName();
    testFileGetSuffix();
    testFileGetAbsPath();
    testCanRwx();
    testFileSetRwx();
    testFileCreateDirs();
    testFileIsDirectory();
}
