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
#include "HttpPacket.hpp"
#include "TestLog.hpp"
#include "Http.hpp"

using namespace obotcha;

void testHttpHeaderToString() {
  while(1) {
    const char *raw= "GET /demo HTTP/1.1\r\n"
                 "Accept-Charset: utf-8, iso-8859-1;q=0.5\r\n"
                 "Accept-Encoding: deflate, gzip;q=1.0, *;q=0.5\r\n"
                 "Accept-Language: fr-CH, fr;q=0.9, en;q=0.8, de;q=0.7, *;q=0.5\r\n"
                 "Accept-Patch: application/example, text/example\r\n"
                 "Accept: text/html, application/xhtml+xml, application/xml;q=0.9, */*;q=0.8\r\n"
                 "Allow: GET, POST, HEAD\r\n"
                 "Authorization: Basic YWxhZGRpbjpvcGVuc2VzYW1l\r\n"
                 "Content-Disposition: form-data; name=\"fieldName\"; filename=\"filename.jpg\"\r\n"
                 "Content-Encoding: identity\r\n"
                 "Cache-Control: max-age=1000\r\n"
                 "Content-Length: 2000\r\n"
                 "Link: <https://example.com>; rel=\"preload\"\r\n"
                 "X-Frame-Options: allow-from https://example.com/\r\n"
                 "\r\n"
                 "Hot diggity dogg";

    ByteRingArray ringArray = createByteRingArray(1024*4);
    ringArray->push((byte *)raw,0,strlen(raw));
    ByteRingArrayReader reader = createByteRingArrayReader(ringArray);
    HttpHeaderParser parser = createHttpHeaderParser(reader);
    HttpHeader header1 = parser->doParse();

    String result = header1->toString(st(Http)::PacketType::Request);

    result = result->append("\r\n\r\n");
    //reparse again
    ByteRingArray ringArray2 = createByteRingArray(1024*4);
    ringArray2->push(result->toByteArray());
    ByteRingArrayReader reader2 = createByteRingArrayReader(ringArray2);
    HttpHeaderParser parser2 = createHttpHeaderParser(reader2);
    HttpHeader header2 = parser2->doParse();

    //check header1 && header2
    if(header1->getMethod() != header2->getMethod()) {
      TEST_FAIL("[HttpHeaderToString test Parse case1] [FAILED] method is %d\n",header1->getMethod());
      break;
    }

    if(!header1->getUrl()->toString()->equals(header2->getUrl()->toString())) {
      TEST_FAIL("[HttpHeaderToString test Parse case2] [FAILED] url is %s\n",header2->getUrl()->toString()->toChars());
      break;
    }

    if(header1->getVersion()->getMajorVer() != header2->getVersion()->getMajorVer()) {
      TEST_FAIL("[HttpHeaderToString test Parse case3] [FAILED] ver is %s\n",header1->getVersion()->toString()->toChars());
      break;
    }

    if(header1->getVersion()->getMinorVer() != header2->getVersion()->getMinorVer()) {
      TEST_FAIL("[HttpHeaderToString test Parse case3_1] [FAILED] ver is %s\n",header1->getVersion()->toString()->toChars());
      break;
    }

    //Charset
    auto charset1 = header1->getAcceptCharSet();
    auto charset2 = header2->getAcceptCharSet();
    if(charset1 == nullptr || charset2 == nullptr) {
      TEST_FAIL("[HttpHeaderToString test Parse case4]");
      break;
    }

    ArrayList<HttpHeaderAcceptCharSetItem> charsets1 = charset1->get();
    ArrayList<HttpHeaderAcceptCharSetItem> charsets2 = charset1->get();
    if(charsets1->size() != 2 || charsets2->size() != 2) {
      TEST_FAIL("[HttpHeaderToString test Parse case5]");
      break;
    }

    HttpHeaderAcceptCharSetItem charSetItem1_0 = charsets1->get(0);
    HttpHeaderAcceptCharSetItem charSetItem2_0 = charsets2->get(0);
    if(!charSetItem1_0->type->equalsIgnoreCase(charSetItem2_0->type)) {
      TEST_FAIL("[HttpHeaderToString test Parse case6]");
      break;
    }

    HttpHeaderAcceptCharSetItem charSetItem1_1 = charsets1->get(1);
    HttpHeaderAcceptCharSetItem charSetItem2_1 = charsets2->get(1);
    if(!charSetItem1_1->type->equalsIgnoreCase(charSetItem2_1->type)) {
      TEST_FAIL("[HttpHeaderToString test Parse case7]");
      break;
    }

    HttpHeaderAcceptCharSetItem charSetItem1_2 = charsets1->get(1);
    HttpHeaderAcceptCharSetItem charSetItem2_2 = charsets2->get(1);
    if(st(Float)::Compare(charSetItem1_2->weight,charSetItem2_2->weight) != 0) {
      TEST_FAIL("[HttpHeaderToString test Parse case8]");
      break;
    }

    //Encoding
    //Accept-Encoding: deflate, gzip;q=1.0, *;q=0.5\r\n
    HttpHeaderAcceptEncoding encoding1 = header1->getAcceptEncoding();
    HttpHeaderAcceptEncoding encoding2 = header2->getAcceptEncoding();

    ArrayList<HttpHeaderAcceptEncodingItem> encodings1 = encoding1->get();
    ArrayList<HttpHeaderAcceptEncodingItem> encodings2 = encoding2->get();
    if(encodings1->size() != 3 || encodings2->size() != 3) {
      TEST_FAIL("[HttpHeaderToString test Parse case9]");
      break;
    }

    HttpHeaderAcceptEncodingItem encodingItem1_0 = encodings1->get(0);
    HttpHeaderAcceptEncodingItem encodingItem2_0 = encodings2->get(0);
    if(!encodingItem1_0->type->equals(encodingItem1_0->type)) {
      TEST_FAIL("[HttpHeaderToString test Parse case9]");
      break;
    }

    HttpHeaderAcceptEncodingItem encodingItem1_1 = encodings1->get(1);
    HttpHeaderAcceptEncodingItem encodingItem2_1 = encodings2->get(1);
    if(!encodingItem1_1->type->equals(encodingItem2_1->type)) {
      TEST_FAIL("[HttpHeaderToString test Parse case10]");
      break;
    }

    if(st(Float)::Compare(encodingItem1_1->weight,encodingItem2_1->weight) != 0) {
      TEST_FAIL("[HttpHeaderToString test Parse case11] [FAILED] weight is %lf \n",encodingItem2_1->weight);
      break;
    }

    HttpHeaderAcceptEncodingItem encodingItem1_2 = encodings1->get(2);
    HttpHeaderAcceptEncodingItem encodingItem2_2 = encodings2->get(2);
    if(!encodingItem1_2->type->equals(encodingItem2_2->type)) {
      TEST_FAIL("[HttpHeaderToString test Parse case12]");
      break;
    }

    if(st(Float)::Compare(encodingItem1_2->weight,encodingItem2_2->weight) != 0) {
      TEST_FAIL("[HttpHeaderToString test Parse case13]");
      break;
    }

    //Accept-Language: fr-CH, fr;q=0.9, en;q=0.8, de;q=0.7, *;q=0.5
    HttpHeaderAcceptLanguage mAcceptLang1 = header1->getAcceptLanguage();
    HttpHeaderAcceptLanguage mAcceptLang2 = header2->getAcceptLanguage();

    ArrayList<HttpHeaderAcceptLanguageItem> langs1 = mAcceptLang1->get();
    ArrayList<HttpHeaderAcceptLanguageItem> langs2 = mAcceptLang2->get();

    if(langs1->size() != 5 || langs2->size() != 5) {
      TEST_FAIL("[HttpHeaderToString test Parse case14]");
      break;
    }

    HttpHeaderAcceptLanguageItem langItem1_0 = langs1->get(0);
    HttpHeaderAcceptLanguageItem langItem2_0 = langs2->get(0);
    if(!langItem1_0->lang->equals(langItem2_0->lang)) {
      TEST_FAIL("[HttpHeaderToString test Parse case15],langItem1 is %s,liangItem2 is %s",
                langItem1_0->lang->toChars(),langItem2_0->lang->toChars());
      break;
    }

    HttpHeaderAcceptLanguageItem langItem1_1 = langs1->get(1);
    HttpHeaderAcceptLanguageItem langItem2_1 = langs2->get(1);

    if(!langItem1_1->lang->equals(langItem2_1->lang)) {
      TEST_FAIL("[HttpHeaderToString test Parse case16]");
      break;
    }

    if(st(Float)::Compare(langItem1_1->weight,langItem2_1->weight) != 0) {
      TEST_FAIL("[HttpHeaderToString test Parse case17]");
      break;
    }

    HttpHeaderAcceptLanguageItem langItem1_2 = langs1->get(2);
    HttpHeaderAcceptLanguageItem langItem2_2 = langs2->get(2);
    if(!langItem1_2->lang->equals(langItem2_2->lang)) {
      TEST_FAIL("[HttpHeaderToString test Parse case18]");
      break;
    }

    if(st(Float)::Compare(langItem1_2->weight,langItem2_2->weight) != 0) {
      TEST_FAIL("[HttpHeaderToString test Parse case19]");
      break;
    }

    HttpHeaderAcceptLanguageItem langItem1_3 = langs1->get(3);
    HttpHeaderAcceptLanguageItem langItem2_3 = langs2->get(3);
    if(!langItem1_3->lang->equals(langItem2_3->lang)) {
      TEST_FAIL("[HttpHeaderToString test Parse case20]");
      break;
    }

    if(st(Float)::Compare(langItem1_3->weight,langItem2_3->weight) != 0) {
      TEST_FAIL("[HttpHeaderToString test Parse case21]");
      break;
    }

    HttpHeaderAcceptLanguageItem langItem1_4 = langs1->get(4);
    HttpHeaderAcceptLanguageItem langItem2_4 = langs2->get(4);
    if(!langItem1_4->lang->equals(langItem2_4->lang)) {
      TEST_FAIL("[HttpHeaderToString test Parse case22]");
      break;
    }

    if(st(Float)::Compare(langItem1_4->weight,langItem2_4->weight) != 0) {
      TEST_FAIL("[HttpHeaderToString test Parse case23]");
      break;
    }

    //Accept-Patch: application/example, text/example
    HttpHeaderAcceptPatch patch1 = header1->getAcceptPatch();
    HttpHeaderAcceptPatch patch2 = header2->getAcceptPatch();

    ArrayList<HttpHeaderAcceptPatchItem> patches1 = patch1->get();
    ArrayList<HttpHeaderAcceptPatchItem> patches2 = patch2->get();

    HttpHeaderAcceptPatchItem patchItem1_0 = patches1->get(0);
    HttpHeaderAcceptPatchItem patchItem2_0 = patches2->get(0);
    if(!patchItem1_0->type->equals(patchItem2_0->type)) {
      TEST_FAIL("[HttpHeaderToString test Parse case24]");
      break;
    }

    HttpHeaderAcceptPatchItem patchItem1_1 = patches1->get(1);
    HttpHeaderAcceptPatchItem patchItem2_1 = patches2->get(1);
    if(!patchItem1_1->type->equals(patchItem2_1->type)) {
      TEST_FAIL("[HttpHeaderToString test Parse case25]");
      break;
    }

    //Accept: text/html, application/xhtml+xml, application/xml;q=0.9, */*;q=0.8
    HttpHeaderAccept accept1 = header1->getAccept();
    HttpHeaderAccept accept2 = header2->getAccept();
    ArrayList<HttpHeaderAcceptItem> accepts1 = accept1->get();
    ArrayList<HttpHeaderAcceptItem> accepts2 = accept2->get();
    if(accepts1->size() != accepts2->size()) {
      TEST_FAIL("[HttpHeaderToString test Parse case26_0]");
      break;
    }

    HttpHeaderAcceptItem acceptItem1_0 = accepts1->get(0);
    HttpHeaderAcceptItem acceptItem2_0 = accepts2->get(0);
    if(!acceptItem1_0->type->equals(acceptItem2_0->type)) {
      TEST_FAIL("[HttpHeaderToString test Parse case26] [FAILED]\n");
      break;
    }

    HttpHeaderAcceptItem acceptItem1_1 = accepts1->get(1);
    HttpHeaderAcceptItem acceptItem2_1 = accepts2->get(1);
    if(!acceptItem1_1->type->equals(acceptItem2_1->type)) {
      TEST_FAIL("[HttpHeaderToString test Parse case27]");
      break;
    }

    HttpHeaderAcceptItem acceptItem1_2 = accepts1->get(2);
    HttpHeaderAcceptItem acceptItem2_2 = accepts2->get(2);
    if(!acceptItem1_2->type->equals(acceptItem2_2->type)) {
      TEST_FAIL("[HttpHeaderToString test Parse case28]");
      break;
    }

    if(st(Float)::Compare(acceptItem1_2->weight,acceptItem2_2->weight) != 0) {
      TEST_FAIL("[HttpHeaderToString test Parse case29]");
      break;
    }

    HttpHeaderAcceptItem acceptItem1_3 = accepts1->get(3);
    HttpHeaderAcceptItem acceptItem2_3 = accepts2->get(3);
    if(!acceptItem1_3->type->equals(acceptItem2_3->type)) {
      TEST_FAIL("[HttpHeaderToString test Parse case30]");
      break;
    }

    if(st(Float)::Compare(acceptItem1_3->weight,acceptItem2_3->weight) != 0) {
      TEST_FAIL("[HttpHeaderToString test Parse case31]");
      break;
    }

    //"Allow: GET, POST, HEAD\r\n"
    String allow1 = header1->get("Allow");
    String allow2 = header2->get("Allow");
    if(!allow1->equals(allow2)) {
      TEST_FAIL("[HttpHeaderToString test Parse case32] [FAILED] ,allow is %s\n",allow1->toChars());
      break;
    }

    //Authorization: Basic YWxhZGRpbjpvcGVuc2VzYW1l
    HttpHeaderAuthorization authorization1 = header1->getAuthorization();
    HttpHeaderAuthorization authorization2 = header2->getAuthorization();
    if(!authorization1->type->equals(authorization2->type)) {
      TEST_FAIL("[HttpHeaderToString test Parse case33]");
      break;
    }

    if(!authorization1->credentials->equals(authorization2->credentials)) {
      TEST_FAIL("[HttpHeaderToString test Parse case34]");
      break;
    }

    //Content-Disposition: form-data; name=\"fieldName\"; filename=\"filename.jpg\"
    HttpHeaderContentDisposition contentDisp1 = header1->getContentDisposition();
    HttpHeaderContentDisposition contentDisp2 = header2->getContentDisposition();
    if(contentDisp1->getType() != contentDisp2->getType()) {
      TEST_FAIL("[HttpHeaderToString test Parse case35]");
      break;
    }

    if(!contentDisp1->getName()->equals(contentDisp2->getName())) {
      TEST_FAIL("[HttpHeaderToString test Parse case36]");
      break;
    }

    if(!contentDisp1->getFileName()->equals(contentDisp2->getFileName())) {
      TEST_FAIL("[HttpHeaderToString test Parse case37]");
      break;
    }

    //Content-Encoding: identity
    String contentEncoding1 = header1->get("Content-Encoding");
    String contentEncoding2 = header2->get("Content-Encoding");
    if(!contentEncoding1->equals(contentEncoding2)) {
      TEST_FAIL("[HttpHeaderToString test Parse case38]");
      break;
    }

    //Cache-Control: max-age=1000
    HttpHeaderCacheControl cachecontrol1 = header1->getCacheControl();
    HttpHeaderCacheControl cachecontrol2 = header2->getCacheControl();
    if(cachecontrol1->maxAgeSeconds() != cachecontrol2->maxAgeSeconds()) {
      TEST_FAIL("[HttpHeaderToString test Parse case39]");
      break;
    }

    //Content-Length: 2000
    int contentLen1 = header1->getContentLength()->get();
    int contentLen2 = header2->getContentLength()->get();
    if(contentLen1 != contentLen2) {
      TEST_FAIL("[HttpHeaderToString test Parse case40]");
      break;
    }

    //Link: <https://example.com>; rel="preload"
    ArrayList<HttpHeaderLink> links1 = header1->getLinks();
    ArrayList<HttpHeaderLink> links2 = header2->getLinks();
    if(links1->size() != 1 || links2->size() != 1) {
      TEST_FAIL("[HttpHeaderToString test Parse case41]");
      break;
    }

    HttpHeaderLink link1_0 = links1->get(0);
    HttpHeaderLink link2_0 = links2->get(0);
    if(!link1_0->url->equals(link2_0->url)) {
      TEST_FAIL("[HttpHeaderToString test Parse case42]");
      break;
    }

    if(!link1_0->rel->equals(link2_0->rel)) {
      TEST_FAIL("[HttpHeaderToString test Parse case43]");
      break;
    }

    //X-Frame-Options: allow-from https://example.com/
    HttpHeaderXFrameOptions xframeoption1 = header1->getXFrameOptions();
    HttpHeaderXFrameOptions xframeoption2 = header2->getXFrameOptions();
    if(!xframeoption1->option->equals(xframeoption2->option)) {
      TEST_FAIL("[HttpHeaderToString test Parse case44]");
      break;
    }

    if(!xframeoption1->uri->equals(xframeoption2->uri)) {
      TEST_FAIL("[HttpHeaderToString test Parse case45]");
      break;
    }

    break;
  }

  TEST_OK("[HttpHeader test toString case100]");

}
