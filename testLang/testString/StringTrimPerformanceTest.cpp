#include <stdio.h>
#include <iostream>
#include <type_traits>

#include <string.h>
#include "String.hpp"
#include "ArrayList.hpp"
#include "NullPointerException.hpp"
#include "ArrayIndexOutOfBoundsException.hpp"
#include "IllegalArgumentException.hpp"
#include "TransformException.hpp"
#include "IllegalArgumentException.hpp"
//#include "TimeWatcher.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void trimPerformance() {
#if 0
   TimeWatcher watch = TimeWatcher::New();
   watch->start();
   String mytest = String::New(" a bc d s f g s");
   for(int i = 0;i<1024*1024;i++) {
     mytest->subString(2,4);
   }
   long interval = watch->stop();
   printf("substring cost %ld \n",interval);

   watch->start();
   for(int i = 0;i<1024*1024;i++) {
     mytest->subString2(2,4);
   }


  interval = watch->stop();
  printf("substring cost %ld \n",interval);
#endif


}
