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
#include "MailSender.hpp"

using namespace obotcha;

extern int testMailSender();
extern int testSimpleMd5();

int main() {
    testMailSender();
    //testSimpleMd5();
    
    return 0;
}
