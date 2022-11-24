#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderAcceptCh.hpp"
#include "HttpClient.hpp"
#include "HttpUrl.hpp"
#include "HttpPost.hpp"
#include "TestLog.hpp"
#include "System.hpp"
#include "NetPort.hpp"
#include "HttpMultiPart.hpp"

using namespace obotcha;

void testHttpChunkTest() {
  File file = createFile("data");

  if(!file->exists()) {
    file->createNewFile();
      for(int i = 0;i<1024;i++) {
      FileOutputStream stream = createFileOutputStream(file);
      stream->open(st(OutputStream)::Append);
      String data = createString("");
      for(int j = 0;j < 512;j++) {
        data = data->append(createString(st(System)::currentTimeMillis()));
      }
      stream->write(data->toByteArray());
      stream->close();
    }
  }

  int port = getEnvPort();
  String url = createString("http://127.0.0.1:")->append(createString(port),"/test");
  HttpGet get = createHttpGet(url);
  HttpClient client = createHttpClient();
  HttpResponse response = client->execute(get);

  ByteArray content = response->getEntity()->getChunk();
  

}
