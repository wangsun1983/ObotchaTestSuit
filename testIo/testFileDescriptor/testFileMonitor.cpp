#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <fcntl.h>
#include <sys/wait.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Barrier.hpp"
#include "FileDescriptor.hpp"
#include "TestLog.hpp"
#include "File.hpp"
#include "TimeWatcher.hpp"
#include "SocketMonitor.hpp"
#include "InetLocalAddress.hpp"
#include "SocketBuilder.hpp"

using namespace obotcha;

int monitorfd = 0;
int unmonitorfd = 0;
int monitorfd_hit = 0;
int unmonitorfd_hit = 0;

DECLARE_CLASS(MySockListener) IMPLEMENTS(SocketListener) {
public:
    void onSocketMessage(st(Net)::Event e,Socket s,ByteArray) {
        if(e == st(Net)::Event::Disconnect && 
            s->getFileDescriptor()->getFd() == monitorfd) {
            monitorfd_hit++;
        }
        
        if(e == st(Net)::Event::Disconnect && 
            s->getFileDescriptor()->getFd() == unmonitorfd) {
            unmonitorfd_hit++;
        }
    }
};

void testFileMonitor() {
    Socket s1 = SocketBuilder::New()
                ->setAddress(InetLocalAddress::New("./tmp/sock1"))
                ->newSocket();
                
    Socket s2 = SocketBuilder::New()
                ->setAddress(InetLocalAddress::New("./tmp/sock2"))
                ->newSocket();
    monitorfd = s1->getFileDescriptor()->getFd();
    unmonitorfd = s2->getFileDescriptor()->getFd();
    
    auto listener = MySockListener::New();
    
    SocketMonitor monitor = SocketMonitor::New();
    monitor->bind(s1,listener);
    monitor->bind(s2,listener);
    s2->getFileDescriptor()->unMonitor();
    
    s1->close();
    s2->close();
    
    usleep(1000*500);
    monitor->close();
    
    if(monitorfd_hit != 1) {
        TEST_FAIL("[FileDescriptor Monitor Test case1]");
    }
    
    if(unmonitorfd_hit != 0) {
        TEST_FAIL("[FileDescriptor Monitor Test case2]");
    }
    
    TEST_OK("[FileDescriptor Monitor Test case100]");
}
