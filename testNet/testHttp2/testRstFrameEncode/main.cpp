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
#include "HttpPacketWriter.hpp"
#include "Http2RstFrame.hpp"

using namespace obotcha;


int main() {
  Http2RstFrame rst = Http2RstFrame::New();
  rst->setStreamId(1);
  rst->setErrorCode(5);
  Http2FrameByteArray l = rst->toFrameData();
  byte data[] = {0x0,0x0,0x4,0x3,0x0,0x0,0x0,0x0,0x3,0x0,0x0,0x0,0x5};
  for(int i = 0;i < l->size();i++) {
      printf(" %x",l->at(i));
  }

  return 0;
}
