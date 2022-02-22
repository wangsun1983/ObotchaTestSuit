#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "OrpcEntry.hpp"
#include "OrpcServerModule.hpp"

using namespace obotcha;

#define Entry1 0

DeclareOrpcEntry(Entry1,String,path);

DeclareOrpcServerFunc(Entry1,String,path);