#include <stdio.h>
#include <unistd.h>

#include "Handler.hpp"
#include "Message.hpp"
#include "System.hpp"
#include "ByteRingArray.hpp"
#include "HttpServer.hpp"
#include "HttpCookie.hpp"
#include "HttpResponse.hpp"
#include "HttpStatus.hpp"
#include "HttpServerBuilder.hpp"
#include "Inet4Address.hpp"
#include "CountDownLatch.hpp"
#include "Handler.hpp"
#include "HttpPacketWriter.hpp"
#include "Enviroment.hpp"
#include "HPackHuffmanEncoder.hpp"
#include "HPackHuffmanDecoder.hpp"

using namespace obotcha;


int main() {
  String abc = String::New("Abcd123");
  HPackHuffmanEncoder encoder = HPackHuffmanEncoder::New();
  HPackHuffmanDecoder decoder = HPackHuffmanDecoder::New();

  ByteArray d1 = encoder->encode(abc);
  printf("d1 size is %d \n",d1->size());
  printf("d1[0] is %x \n",d1->at(0));

  ByteArray d2 = decoder->decode(d1);
  printf("d2 size is %d \n",d2->size());

  printf("d2 is %s \n",d2->toString()->toChars());

  return 0;
}
