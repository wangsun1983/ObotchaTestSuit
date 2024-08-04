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
#include "Inet4Address.hpp"
#include "WebSocketServerBuilder.hpp"

using namespace obotcha;

DECLARE_CLASS(MyWsListener) IMPLEMENTS(WebSocketListener) {
public:
    _MyWsListener() {
        mMutex = Mutex::New();
        mConditaion = Condition::New();
    }

    
    int onData(WebSocketFrame message,WebSocketLinker client) {
        printf("message is %s \n",message->getData()->toString()->toChars());
        //mMessage = message->getData();
        String response = String::New("hello from server ");
        printf("message len is %d \n",response->size());
        ByteArray array = response->toByteArray();
        printf("array size is %d \n",array->size());
        //WebSocketFrameComposer mComposer = createWebSocketFrameComposer(false);
        
        //int ret = st(NetUtils)::sendTcpPacket(fd,mComposer->generateMessageFrame(st(WebSocketProtocol)::OPCODE_TEXT,ByteArray::New(response)));
        //WebSocketComposer composer = client->getComposer();

        //ArrayList<ByteArray> text = composer->genTextMessage(client,String::New("hello world from server"));
        //int ret = st(NetUtils)::sendTcpPacket(fd,text->get(0));
        sleep(1);
        int ret = client->sendTextMessage(String::New("hello world from server"));
        printf("onMessage send result is %d \n",ret);
        mConditaion->notify();
        return 0;
    }

    int onConnect(WebSocketLinker client) {
        printf("on connect fd  \n");
        return 0;
    }

    int onDisconnect(WebSocketLinker client) {
        printf("on disconnect fd\n");
        return 0;
    }

    int onPong(WebSocketLinker client) {
        return 0;
    }

    int onPing(WebSocketLinker client) {
        return 0;
    }

    //String waitMessage() {
     //   AutoLock ll(mMutex);
    //    mConditaion->wait(mMutex);
    //    return mMessage;
    //}

private:
    Mutex mMutex;
    Condition mConditaion;
    //String mMessage;   
};



int main() {
    MyWsListener l = MyWsListener::New();

    
    InetAddress address = Inet4Address::New(1234);
    WebSocketServer server = WebSocketServerBuilder::New()
                            ->setInetAddr(address)
                            ->addListener("mytest",l)
                            ->build();
    
    
    server->start();
    printf("websocket start trace1 \n");
    //l->waitMessage();
    printf("websocket start trace2 \n");

    while(1) {sleep(1);}
    server->close();
    printf("websocket start trace3 \n");

    
    printf("websocket start trace4 \n");
}
