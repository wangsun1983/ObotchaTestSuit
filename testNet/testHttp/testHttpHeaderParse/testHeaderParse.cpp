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
#include "TestLog.hpp"

using namespace obotcha;

void testHttpHeaderParse() {
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
    HttpHeader header = parser->doParse();

    if(header->getMethod() != st(HttpMethod)::Get) {
      TEST_FAIL("[HttpHeaderParse test Parse case1] method is %d",header->getMethod());
      break;
    }

    if(!header->getUrl()->toString()->equals("/demo")) {
      TEST_FAIL("[HttpHeaderParse test Parse case2] url is %s",header->getUrl()->toString()->toChars());
      break;
    }

    if(!header->getVersion()->toString()->equals("HTTP/1.1")) {
      TEST_FAIL("[HttpHeaderParse test Parse case3] ver is %s",header->getVersion()->toString()->toChars());
      break;
    }

    //Charset
    auto charset = header->getAcceptCharSet();
    if(charset == nullptr) {
      TEST_FAIL("[HttpHeaderParse test Parse case4]");
      break;
    }

    ArrayList<HttpHeaderAcceptCharSetItem> charsets = charset->get();
    if(charsets->size() != 2) {
      TEST_FAIL("[HttpHeaderParse test Parse case5]");
      break;
    }

    HttpHeaderAcceptCharSetItem charSetItem1 = charsets->get(0);
    if(!charSetItem1->type->equalsIgnoreCase("utf-8")) {
      TEST_FAIL("[HttpHeaderParse test Parse case6] char set is %s",charSetItem1->type->toChars());
      break;
    }

    HttpHeaderAcceptCharSetItem charSetItem2 = charsets->get(1);
    if(!charSetItem2->type->equalsIgnoreCase("iso-8859-1")) {
      TEST_FAIL("[HttpHeaderParse test Parse case7] char set is %s",charSetItem2->type->toChars());
      break;
    }

    if(st(Math)::compareFloat(charSetItem2->weight,0.5) != st(Math)::AlmostEqual) {
      TEST_FAIL("[HttpHeaderParse test Parse case8] charSetItem2->weight is %lf",charSetItem2->weight);
      break;
    }

    //Encoding
    //Accept-Encoding: deflate, gzip;q=1.0, *;q=0.5\r\n
    HttpHeaderAcceptEncoding encoding = header->getAcceptEncoding();
    ArrayList<HttpHeaderAcceptEncodingItem> encodings = encoding->get();
    if(encodings->size() != 3) {
      TEST_FAIL("[HttpHeaderParse test Parse case9]");
      break;
    }

    HttpHeaderAcceptEncodingItem encodingItem0 = encodings->get(0);
    if(!encodingItem0->type->equals("deflate")) {
      TEST_FAIL("[HttpHeaderParse test Parse case9]");
      break;
    }

    HttpHeaderAcceptEncodingItem encodingItem1 = encodings->get(1);
    if(!encodingItem1->type->equals("gzip")) {
      TEST_FAIL("[HttpHeaderParse test Parse case10]");
      break;
    }

    if(st(Math)::compareFloat(encodingItem1->weight,1.0) != st(Math)::AlmostEqual) {
      TEST_FAIL("[HttpHeaderParse test Parse case11] weight is %lf",encodingItem1->weight);
      break;
    }

    HttpHeaderAcceptEncodingItem encodingItem2 = encodings->get(2);
    if(!encodingItem2->type->equals("*")) {
      TEST_FAIL("[HttpHeaderParse test Parse case12]");
      break;
    }

    if(st(Math)::compareFloat(encodingItem2->weight,0.5) != st(Math)::AlmostEqual) {
      TEST_FAIL("[HttpHeaderParse test Parse case13]");
      break;
    }

    //Accept-Language: fr-CH, fr;q=0.9, en;q=0.8, de;q=0.7, *;q=0.5
    HttpHeaderAcceptLanguage mAcceptLang = header->getAcceptLanguage();
    ArrayList<HttpHeaderAcceptLanguageItem> langs = mAcceptLang->get();
    if(langs->size() != 5) {
      TEST_FAIL("[HttpHeaderParse test Parse case14]");
      break;
    }

    HttpHeaderAcceptLanguageItem langItem1 = langs->get(0);
    if(!langItem1->lang->equals("fr-CH")) {
      TEST_FAIL("[HttpHeaderParse test Parse case15]");
      break;
    }

    HttpHeaderAcceptLanguageItem langItem2 = langs->get(1);
    if(!langItem2->lang->equals("fr")) {
      TEST_FAIL("[HttpHeaderParse test Parse case16]");
      break;
    }

    if(st(Math)::compareFloat(langItem2->weight,0.9) != st(Math)::AlmostEqual) {
      TEST_FAIL("[HttpHeaderParse test Parse case17]");
      break;
    }

    HttpHeaderAcceptLanguageItem langItem3 = langs->get(2);
    if(!langItem3->lang->equals("en")) {
      TEST_FAIL("[HttpHeaderParse test Parse case18]");
      break;
    }

    if(st(Math)::compareFloat(langItem3->weight,0.8) != st(Math)::AlmostEqual) {
      TEST_FAIL("[HttpHeaderParse test Parse case19]");
      break;
    }

    HttpHeaderAcceptLanguageItem langItem4 = langs->get(3);
    if(!langItem4->lang->equals("de")) {
      TEST_FAIL("[HttpHeaderParse test Parse case20]");
      break;
    }

    if(st(Math)::compareFloat(langItem4->weight,0.7) != st(Math)::AlmostEqual) {
      TEST_FAIL("[HttpHeaderParse test Parse case21]");
      break;
    }

    HttpHeaderAcceptLanguageItem langItem5 = langs->get(4);
    if(!langItem5->lang->equals("*")) {
      TEST_FAIL("[HttpHeaderParse test Parse case22]");
      break;
    }

    if(st(Math)::compareFloat(langItem5->weight,0.5) != st(Math)::AlmostEqual) {
      TEST_FAIL("[HttpHeaderParse test Parse case23]");
      break;
    }

    //Accept-Patch: application/example, text/example
    HttpHeaderAcceptPatch patch = header->getAcceptPatch();
    ArrayList<HttpHeaderAcceptPatchItem> patches = patch->get();
    HttpHeaderAcceptPatchItem patchItem1 = patches->get(0);
    if(!patchItem1->type->equals("application/example")) {
      TEST_FAIL("[HttpHeaderParse test Parse case24]");
      break;
    }

    HttpHeaderAcceptPatchItem patchItem2 = patches->get(1);
    if(!patchItem2->type->equals("text/example")) {
      TEST_FAIL("[HttpHeaderParse test Parse case25]");
      break;
    }

    //Accept: text/html, application/xhtml+xml, application/xml;q=0.9, */*;q=0.8
    HttpHeaderAccept accept = header->getAccept();
    ArrayList<HttpHeaderAcceptItem> accepts = accept->get();
    if(accepts->size() != 4) {
      TEST_FAIL("[HttpHeaderParse test Parse case26_0]");
      break;
    }

    HttpHeaderAcceptItem acceptItem1 = accepts->get(0);
    if(!acceptItem1->type->equals("text/html")) {
      TEST_FAIL("[HttpHeaderParse test Parse case26] ,type is %s\n",acceptItem1->type->toChars());
      break;
    }

    HttpHeaderAcceptItem acceptItem2 = accepts->get(1);
    if(!acceptItem2->type->equals("application/xhtml+xml")) {
      TEST_FAIL("[HttpHeaderParse test Parse case27]");
      break;
    }

    HttpHeaderAcceptItem acceptItem3 = accepts->get(2);
    if(!acceptItem3->type->equals("application/xml")) {
      TEST_FAIL("[HttpHeaderParse test Parse case28]");
      break;
    }

    if(st(Math)::compareFloat(acceptItem3->weight,0.9) != st(Math)::AlmostEqual) {
      TEST_FAIL("[HttpHeaderParse test Parse case29]");
      break;
    }

    HttpHeaderAcceptItem acceptItem4 = accepts->get(3);
    if(!acceptItem4->type->equals("*/*")) {
      TEST_FAIL("[HttpHeaderParse test Parse case30]");
      break;
    }

    if(st(Math)::compareFloat(acceptItem4->weight,0.8) != st(Math)::AlmostEqual) {
      TEST_FAIL("[HttpHeaderParse test Parse case31]");
      break;
    }

    //"Allow: GET, POST, HEAD\r\n"
    ArrayList<Integer> allows = header->getAllow()->get();
    if(allows->size() != 3) {
      TEST_FAIL("[HttpHeaderParse test Parse case32]");
      break;
    }

    if(allows->get(0)->toValue() != st(HttpMethod)::Get) {
      TEST_FAIL("[HttpHeaderParse test Parse case32_1]");
      break;
    }

    if(allows->get(1)->toValue() != st(HttpMethod)::Post) {
      TEST_FAIL("[HttpHeaderParse test Parse case32_2]");
      break;
    }

    if(allows->get(2)->toValue() != st(HttpMethod)::Head) {
      TEST_FAIL("[HttpHeaderParse test Parse case32_3]");
      break;
    }

    //Authorization: Basic YWxhZGRpbjpvcGVuc2VzYW1l
    HttpHeaderAuthorization authorization = header->getAuthorization();
    if(!authorization->type->equals("Basic")) {
      TEST_FAIL("[HttpHeaderParse test Parse case33]");
      break;
    }

    if(!authorization->credentials->equals("YWxhZGRpbjpvcGVuc2VzYW1l")) {
      TEST_FAIL("[HttpHeaderParse test Parse case34]");
      break;
    }

    //Content-Disposition: form-data; name=\"fieldName\"; filename=\"filename.jpg\"
    HttpHeaderContentDisposition contentDisp = header->getContentDisposition();
    if(!contentDisp->type->equals("form-data")) {
      TEST_FAIL("[HttpHeaderParse test Parse case35]");
      break;
    }

    if(!contentDisp->name->equals("fieldName")) {
      TEST_FAIL("[HttpHeaderParse test Parse case36]");
      break;
    }

    if(!contentDisp->filename->equals("filename.jpg")) {
      TEST_FAIL("[HttpHeaderParse test Parse case37]");
      break;
    }

    //Content-Encoding: identity
    ArrayList<String> contentEncoding = header->getContentEncoding()->get();
    if(contentEncoding->size() != 1) {
      TEST_FAIL("[HttpHeaderParse test Parse case38]");
      break;
    }

    if(!contentEncoding->get(0)->equals("identity")) {
      TEST_FAIL("[HttpHeaderParse test Parse case38_1]");
      break;
    }

    //Cache-Control: max-age=1000
    HttpHeaderCacheControl cachecontrol = header->getCacheControl();
    if(cachecontrol->maxAgeSeconds() != 1000) {
      TEST_FAIL("[HttpHeaderParse test Parse case39]");
      break;
    }

    //Content-Length: 2000
    int contentLen = header->getContentLength()->get();
    if(contentLen != 2000) {
      TEST_FAIL("[HttpHeaderParse test Parse case40]");
      break;
    }

    //Link: <https://example.com>; rel="preload"
    ArrayList<HttpHeaderLink> links = header->getLinks();
    if(links->size() != 1) {
      TEST_FAIL("[HttpHeaderParse test Parse case41]");
      break;
    }

    HttpHeaderLink link = links->get(0);
    if(!link->url->equals("https://example.com")) {
      TEST_FAIL("[HttpHeaderParse test Parse case42]");
      break;
    }

    if(!link->rel->equals("preload")) {
      TEST_FAIL("[HttpHeaderParse test Parse case43]");
      break;
    }

    //X-Frame-Options: allow-from https://example.com/
    HttpHeaderXFrameOptions xframeoption = header->getXFrameOptions();
    if(!xframeoption->option->equals("allow-from")) {
      TEST_FAIL("[HttpHeaderParse test Parse case44]");
      break;
    }

    if(!xframeoption->uri->equals("https://example.com/")) {
      TEST_FAIL("[HttpHeaderParse test Parse case45]");
      break;
    }
    break;
  }

  TEST_OK("[HttpHeaderParse test Parse case100]");

}
