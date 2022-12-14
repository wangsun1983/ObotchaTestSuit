#include <stdio.h>
#include <unistd.h>

#include "Integer.hpp"
#include "StrongPointer.hpp"
#include "Long.hpp"
#include "WebSocketServer.hpp"
#include "WebSocketListener.hpp"
#include "Mutex.hpp"
#include "Condition.hpp"
#include "AutoLock.hpp"
#include "WebSocketProtocol.hpp"
#include "WebSocketComposer.hpp"
#include "File.hpp"
#include "FileOutputStream.hpp"
#include "WebSocketHybi13Parser.hpp"

#include "TestLog.hpp"

using namespace obotcha;

int testWebSocketInterface() {
  
  WebSocketParser parser = createWebSocketHybi13Parser();
  if(parser->getVersion() != 13) {
      TEST_FAIL("testWebSocketInterface case1");
  }
    
  TEST_OK("testWebSocketInterface case100");

  return 0;
}
