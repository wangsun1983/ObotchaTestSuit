#include <stdio.h>
#include <unistd.h>

//#include "Thread.hpp"
//#include "ArrayList.hpp"
#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "NtpClient.hpp"
#include "System.hpp"
#include "Host.hpp"
#include "TestLog.hpp"

using namespace obotcha;

int main() {
  Host host = Host::New();
  ArrayList<HostAddress> address = host->getAddresses();
  auto iter = address->getIterator();
  while(iter->hasValue()) {
    HostAddress addr = iter->getValue();
    if(addr->ip == nullptr || addr->ip->size() == 0) {
      TEST_FAIL("Host test `ase1");
    }
    iter->next();
  }

  ArrayList<HostMac> macs = host->getMacAddresses();
  auto iter2 = macs->getIterator();
  while(iter2->hasValue()) {
    HostMac addr = iter2->getValue();
    //printf("MacAddress:interface is %s,address is %s \n",addr->interface->toChars(),addr->mac->toChars());
    if(addr->interface == nullptr || addr->interface->size() == 0) {
      TEST_FAIL("Host test case2");
    }
    iter2->next();
  }

  String name = host->getName();
  if(name == nullptr || name->size() == 0) {
    TEST_FAIL("Host test case3");
  }

  TEST_OK("Host test case100");
  
}
