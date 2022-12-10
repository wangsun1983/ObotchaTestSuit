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
#include "Md.hpp"

using namespace obotcha;
//ZPHYKJKMDTPVUJZO
//JXKKIUKWPFNLLBSL
//GYJRCVQZIADUWINJ

int testSimpleMd5() {
#if 0    
    char *opad = "hello world";
    char *ustrResult = "ni hao";
    
    SmtpSimpleMd5 md5pass2;
    md5pass2.update((unsigned char*)opad, strlen(opad));
    md5pass2.update((unsigned char*)ustrResult, strlen(ustrResult));
    md5pass2.finalize();
    
    char *decoded_challenge = (char *)md5pass2.hex_digest();
    printf("decoded_chan is %s \n",decoded_challenge);
    
    Md md = createMd(st(Md)::Md5);
    String ss = createString(opad)->append(ustrResult);
    auto r = md->encrypt(ss);
    printf("decoded_chan2 is %s \n",r->toChars());
#endif    
    return 0;
}
