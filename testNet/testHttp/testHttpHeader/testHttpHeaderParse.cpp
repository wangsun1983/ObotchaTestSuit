#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderParser.hpp"
#include "ByteRingArrayReader.hpp"
#include "HttpMethod.hpp"
#include "HttpHeaderAcceptCharSet.hpp"
#include "Math.hpp"
#include "HttpMethod.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testHttpHeaderParse() {
    const char *raw= "GET /demo HTTP/1.1\r\n"
                 "Accept-CH: DPR, Viewport-Width \r\n"
                 "Accept-Charset: utf-8, iso-8859-1;q=0.5\r\n"
                 "Accept-Encoding: deflate, gzip;q=1.0, *;q=0.5\r\n"
                 "Accept-Language: fr-CH, fr;q=0.9, en;q=0.8, de;q=0.7, *;q=0.5\r\n"
                 "Accept-Patch: application/example, text/example\r\n"
                 "Accept-Ranges: none \r\n"
                 "Access-Control-Allow-Credentials: true \r\n"
                 "Access-Control-Allow-Headers: X-Custom-Header, Upgrade-Insecure-Requests \r\n"
                 "Access-Control-Allow-Methods: POST, GET, OPTIONS \r\n"
                 "Access-Control-Allow-Origin: https://developer.mozilla.org \r\n"
                 "Access-Control-Expose-Headers: Content-Length, X-Kuma-Revision \r\n"
                 "Access-Control-Max-Age: 600  \r\n"
                 "Access-Control-Request-Headers: X-PINGOTHER, Content-Type \r\n"
                 "Access-Control-Request-Method: POST \r\n"
                 "Accept: text/html, application/xhtml+xml, application/xml;q=0.9, */*;q=0.8\r\n"
                 "Cache-control:max-age=31536000,max-stale=123,min-fresh=333,s-maxage=90\r\n"
                 "Clear-Site-Data: \"cache\", \"cookies\", \"storage\", \"executionContexts\"\r\n"
                 "Age: 24 \r\n"
                 "Allow: GET, POST, HEAD\r\n"
                 "Alt-Svc: h2=\"alt.example.com:8000\", h2=\":443\"; ma=2592000; persist=1"
                 "Authorization: Basic YWxhZGRpbjpvcGVuc2VzYW1l\r\n"
                 "Content-Disposition: form-data; name=\"fieldName\"; filename=\"filename.jpg\"\r\n"
                 "Content-Encoding: identity\r\n"
                 "Cache-Control: max-age=1000\r\n"
                 "Content-Length: 2000\r\n"
                 "Connection: keep-alive\r\n"
                 "Content-Disposition: attachment; filename=\"filename.jpg\""
                 "Link: <https://example.com>; rel=\"preload\"\r\n"
                 "X-Frame-Options: allow-from https://example.com/\r\n"
                 "\r\n"
                 "Hot diggity dogg";

     ByteRingArray ringArray = createByteRingArray(1024*4);
     ringArray->push((byte *)raw,0,strlen(raw));
     ByteRingArrayReader reader = createByteRingArrayReader(ringArray);
     HttpHeaderParser parser = createHttpHeaderParser(reader);
     HttpHeader header1 = parser->doParse();

     TEST_TODO("[HttpHeader test Set case100]");
}
