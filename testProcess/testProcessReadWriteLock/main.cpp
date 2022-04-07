#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Reflect.hpp"
#include "String.hpp"
#include "Reflect.hpp"

using namespace obotcha;
extern void testProcessReadWriteLock();

int main() {
  testProcessReadWriteLock();
  return 0;
}
