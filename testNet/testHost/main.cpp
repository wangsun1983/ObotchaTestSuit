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

using namespace obotcha;

int main() {
  Host host = createHost();
  ArrayList<HostAddress> address = host->getAddresses();
  auto iter = address->getIterator();
  while(iter->hasValue()) {
    HostAddress addr = iter->getValue();
    printf("IpAddress:interface is %s,address is %s \n",addr->interface->toChars(),addr->ip->toChars());
    iter->next();
  }

  ArrayList<HostMac> macs = host->getMacAddresses();
  auto iter2 = macs->getIterator();
  while(iter2->hasValue()) {
    HostMac addr = iter2->getValue();
    printf("MacAddress:interface is %s,address is %s \n",addr->interface->toChars(),addr->mac->toChars());
    iter2->next();
  }

  String name = host->getName();
  printf("host name is %s \n",name->toChars());
}
