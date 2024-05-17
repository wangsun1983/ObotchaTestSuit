#include "DatagramSocketImpl.hpp"
#include "SocketBuilder.hpp"
#include "SocketMonitor.hpp"
#include "Handler.hpp"
#include "Inet6Address.hpp"
#include "FileOutputStream.hpp"
#include "FileInputStream.hpp"
#include "System.hpp"
#include "Md.hpp"

#include "TestLog.hpp"
#include "NetPort.hpp"
#include "NetEvent.hpp"

using namespace obotcha;

int main() {
    //prepare file
    File file = File::New("./tmp/testdata");

    if(!file->exists()) {
      file->createNewFile();
        for(int i = 0;i<1024;i++) {
        FileOutputStream stream = FileOutputStream::New(file);
        stream->open(st(IO)::FileControlFlags::Append);
        String data = String::New("");
        for(int i = 0;i < 1024;i++) {
          data = data->append(String::New(st(System)::CurrentTimeMillis()));
        }
        stream->write(data->toByteArray());
        stream->close();
      }
    }

    int port = getEnvPort();
    InetAddress addr = Inet6Address::New(port);
    Socket client = SocketBuilder::New()->setAddress(addr)->newDatagramSocket();

    int ret = client->connect();
    String resp = String::New("hello server");
    ByteArray fileBuff = ByteArray::New(1024*4);
    FileInputStream stream = FileInputStream::New(file);
    stream->open();
    long index = 0;
    long filesize = file->length();
    while(1) {
      long length = stream->read(fileBuff);
      int ret = client->getOutputStream()->write(fileBuff);
      filesize -= length;
      usleep(100*1000);
      if(filesize == 0) {
        break;
      }
    }
    stream->close();

    usleep(1000*1000);
    Md md5 = Md::New();
    String v1 = md5->encodeFile(File::New("./tmp/testdata"));
    String v2 = md5->encodeFile(File::New("./tmp/file"));

    if(v1 != v2) {
      TEST_FAIL("TestDataGramSocket case2_simple_send_file_delayed test1,v1 is %s,v2 is %s",v1->toChars(),v2->toChars());
    }

    client->close();
    
    TEST_OK("TestDataGramSocket case2_simple_send_file_delayed test100");
    return 0;
}