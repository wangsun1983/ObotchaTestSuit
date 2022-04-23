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
//ZPHYKJKMDTPVUJZO
//JXKKIUKWPFNLLBSL
//GYJRCVQZIADUWINJ

int main() {
  SmtpConnection connection = createSmtpConnection();
  connection->setHostName(createString("abc"));
  connection->setSmtpServer(createString("smtp.163.com"));
  connection->setMailFrom(createString("wang_sun_1983@163.com"));
  connection->setUsername(createString("wang_sun_1983@163.com"));
  connection->setPassword(createString("GYJRCVQZIADUWINJ"));
  connection->setSubject(createString("hello title"));
  //connection->setSecurityType(st(SmtpConnection)::SSL);

  MailSenderBuilder senderBuilder = createMailSenderBuilder();
  MailSender sender = senderBuilder->addRecipient(createMailRecipient("wangsl","wang_sun_1983@163.com"))
                                   ->setConnection(connection)
                                   ->setMessage("hello,i am obotcha \r\n 123 \r\n tttt")
                                   ->setSubject("hello")
                                   ->build();
  sender->send();
}
