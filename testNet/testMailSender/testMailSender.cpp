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

int testMailSender() {
  SmtpConnection connection = SmtpConnection::New();
  connection->setHostName(String::New("abc"));
  connection->setSmtpServer(String::New("smtp.163.com"));
  connection->setMailFrom(String::New("wang_sun_1983@163.com"));
  connection->setUsername(String::New("wang_sun_1983@163.com"));
  connection->setPassword(String::New("GYJRCVQZIADUWINJ"));
  connection->setSubject(String::New("hello title"));
  //connection->setSecurityType(st(SmtpConnection)::SSL);

  MailSenderBuilder senderBuilder = MailSenderBuilder::New();
  MailSender sender = senderBuilder->addRecipient(MailRecipient::New("wangsl","wang_sun_1983@163.com"))
                                   ->setConnection(connection)
                                   ->setMessage("hello,i am obotcha \r\n 123 \r\n tttt")
                                   ->setSubject("hello")
                                   ->build();
  sender->send();
  return 0;
}
