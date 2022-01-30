#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <dlfcn.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "StrongPointer.hpp"
#include "LibraryFile.hpp"
#include "TestLog.hpp"
#include "System.hpp"

using namespace obotcha;

using myfunc = int (*)(int , int );

int main() {
    //first build test Library
    String cmd = createString("cd ./library && make");
    st(System)::executeForResult(cmd);

    LibraryFile file = createLibraryFile(createString("./library/libtest.so"));
    myfunc t = (myfunc)file->getMethod(createString("start"));

    int v1 = 100;
    int v2 = 101;
    int ret = t(v1,v2);

    if(ret != 201) {
      TEST_FAIL("[LibraryFile Test case1],v1 is %d,v2 is %d \n",v1,v2);
    }

    TEST_OK("[LibraryFile Test case2]");
}
