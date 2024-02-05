#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "File.hpp"
#include "TestLog.hpp"
#include "System.hpp"
#include "FileOutputStream.hpp"
#include "ForEveryOne.hpp"

using namespace obotcha;

void testFileList() {
    File f1 = createFile("./tmp/testListRoot");
    f1->createDirs();
    
    ArrayList<String> paths = createArrayList<String>();
    File f2 = createFile("./tmp/testListRoot/Dir1");
    f2->createDirs();
    paths->add(createString("tmp/testListRoot/Dir1"));
    
    File f3 = createFile("./tmp/testListRoot/Dir2");
    f3->createDirs();
    paths->add(createString("tmp/testListRoot/Dir2"));
    
    File f3_1 = createFile("./tmp/testListRoot/Dir2/1.txt");
    f3_1->createNewFile();
    //paths->add(createString("tmp/testListRoot/Dir2/1.txt"));
    
    File f3_2 = createFile("./tmp/testListRoot/Dir2/2.txt");
    f3_2->createNewFile();
    //paths->add(createString("tmp/testListRoot/Dir2/2.txt"));
    
    auto list1 = f1->list();
    if(list1->size() != 2) {
        TEST_FAIL("[File Test {list()} case1],size is %d \n",list1->size());
    }
    
    int hitCount = 0;
    ForEveryOne(path,list1) {
        ForEveryOne(path2,paths) {
            if(path->contains(path2)) {
                hitCount++;
                break;
            }
        }
    }
    
    if(hitCount != 2) {
        TEST_FAIL("[File Test {list()} case2],hitCount is %d",hitCount);
    }
    
    auto list2 = f1->listFiles();
    if(list2->size() != 2) {
        TEST_FAIL("[File Test {list()} case3],size is %d",list2->size());
    }
    
    hitCount = 0;
    ForEveryOne(file,list2) {
        ForEveryOne(path3,paths) {
            if(file->getAbsolutePath()->contains(path3)) {
                hitCount++;
                break;
            }
        }
    }
    if(hitCount != 2) {
        TEST_FAIL("[File Test {list()} case4],hitCount is %d \n",hitCount);
    }
    
    f1->removeAll();
    TEST_OK("[File Test {list()} case100]");
}
