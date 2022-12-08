#include "Rsa.hpp"

using namespace obotcha;

extern void testRsa3Pcks1();
extern void testRsaf4Pcks1();
extern void testRsa3Pcks1OEAP();
extern void testRsa3Pcks1PSS();

int main() {
  testRsa3Pcks1();
  testRsaf4Pcks1();
  testRsa3Pcks1OEAP();
  //testRsa3Pcks1PSS();
  return 0;
}
