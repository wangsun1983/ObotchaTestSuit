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

void testHttpHeaderSet() {
  while(1) {
    const char *raw= "GET /demo HTTP/1.1\r"
                 "Accept-Charset: utf-8, iso-8859-1;q=0.5\r"
                 "Accept-Encoding: deflate, gzip;q=1.0, *;q=0.5\r"
                 "Accept-Language: fr-CH, fr;q=0.9, en;q=0.8, de;q=0.7, *;q=0.5\r"
                 "Accept-Patch: application/example, text/example\r"
                 "Accept: text/html, application/xhtml+xml, application/xml;q=0.9, */*;q=0.8\r"
                 "Allow: GET, POST, HEAD\r"
                 "Authorization: Basic YWxhZGRpbjpvcGVuc2VzYW1l\r"
                 "Content-Disposition: form-data; name=\"fieldName\"; filename=\"filename.jpg\"\r"
                 "Content-Encoding: identity\r"
                 "Cache-Control: max-age=1000\r"
                 "Content-Length: 2000\r"
                 "Link: <https://example.com>; rel=\"preload\"\r"
                 "X-Frame-Options: allow-from https://example.com/\r"
                 "\r"
                 "Hot diggity dogg";

    HttpHeader header = createHttpHeader();
    header->setMethod(st(HttpMethod)::Get);

    HttpUrl url = createHttpUrl();
    url->setPath("demo");
    header->setUrl(url);

    header->setVersion(createHttpHeaderVersion(1,1));
    header->set("Accept-Charset","utf-8, iso-8859-1;q=0.5");
    header->set("Accept-Encoding","deflate, gzip;q=1.0, *;q=0.5");
    header->set("Accept-Language","fr-CH, fr;q=0.9, en;q=0.8, de;q=0.7, *;q=0.5");
    header->set("Accept-Patch","application/example, text/example");
    header->set("Accept","text/html, application/xhtml+xml, application/xml;q=0.9, */*;q=0.8");
    header->set("Allow","GET, POST, HEAD");
    header->set("Authorization","Basic YWxhZGRpbjpvcGVuc2VzYW1l");
    header->set("Content-Disposition","form-data; name=\"fieldName\"; filename=\"filename.jpg\"");
    header->set("Content-Encoding","identity");
    header->set("Cache-Control","max-age=1000");
    header->set("Content-Length","2000");
    header->set("Link","<https://example.com>; rel=\"preload\"");
    header->set("X-Frame-Options","allow-from https://example.com/");

    //check
    if(header->getMethod() != st(HttpMethod)::Get) {
      TEST_FAIL("[HttpHeader test Set case1]  method is %d",header->getMethod());
      break;
    }

    if(!header->getUrl()->toString()->sameAs("/demo")) {
      TEST_FAIL("[HttpHeader test Set case2]  url is %s",header->getUrl()->toString()->toChars());
      break;
    }

    if(!header->getVersion()->toString()->sameAs("HTTP/1.1")) {
      TEST_FAIL("[HttpHeader test Set case3]  ver is %s",header->getVersion()->toString()->toChars());
      break;
    }

    //Charset
    auto charset = header->getAcceptCharSet();
    if(charset == nullptr) {
      TEST_FAIL("[HttpHeader test Set case4]");
      break;
    }

    ArrayList<HttpHeaderAcceptCharSetItem> charsets = charset->get();
    if(charsets->size() != 2) {
      TEST_FAIL("[HttpHeader test Set case5]");
      break;
    }

    HttpHeaderAcceptCharSetItem charSetItem1 = charsets->get(0);
    if(!charSetItem1->type->equalsIgnoreCase("utf-8")) {
      TEST_FAIL("[HttpHeader test Set case6]  char set is %s ",charSetItem1->type->toChars());
      break;
    }

    HttpHeaderAcceptCharSetItem charSetItem2 = charsets->get(1);
    if(!charSetItem2->type->equalsIgnoreCase("iso-8859-1")) {
      TEST_FAIL("[HttpHeader test Set case7]  char set is %s ",charSetItem2->type->toChars());
      break;
    }

    if(st(Float)::Compare(charSetItem2->weight,0.5) != 0) {
      TEST_FAIL("[HttpHeader test Set case8]  char set is %s ",charSetItem2->type->toChars());
      break;
    }

    //Encoding
    //Accept-Encoding: deflate, gzip;q=1.0, *;q=0.5\r
    HttpHeaderAcceptEncoding encoding = header->getAcceptEncoding();
    ArrayList<HttpHeaderAcceptEncodingItem> encodings = encoding->get();
    if(encodings->size() != 3) {
      TEST_FAIL("[HttpHeader test Set case9]");
      break;
    }

    HttpHeaderAcceptEncodingItem encodingItem0 = encodings->get(0);
    if(!encodingItem0->type->sameAs("deflate")) {
      TEST_FAIL("[HttpHeader test Set case9]");
      break;
    }

    HttpHeaderAcceptEncodingItem encodingItem1 = encodings->get(1);
    if(!encodingItem1->type->sameAs("gzip")) {
      TEST_FAIL("[HttpHeader test Set case10]");
      break;
    }

    if(st(Float)::Compare(encodingItem1->weight,1.0) != 0) {
      TEST_FAIL("[HttpHeader test Set case11]  weight is %lf ",encodingItem1->weight);
      break;
    }

    HttpHeaderAcceptEncodingItem encodingItem2 = encodings->get(2);
    if(!encodingItem2->type->sameAs("*")) {
      TEST_FAIL("[HttpHeader test Set case12]");
      break;
    }

    if(st(Float)::Compare(encodingItem2->weight,0.5) != 0) {
      TEST_FAIL("[HttpHeader test Set case13]");
      break;
    }

    //Accept-Language: fr-CH, fr;q=0.9, en;q=0.8, de;q=0.7, *;q=0.5
    HttpHeaderAcceptLanguage mAcceptLang = header->getAcceptLanguage();
    ArrayList<HttpHeaderAcceptLanguageItem> langs = mAcceptLang->get();
    if(langs->size() != 5) {
      TEST_FAIL("[HttpHeader test Set case14]");
      break;
    }

    HttpHeaderAcceptLanguageItem langItem1 = langs->get(0);
    if(!langItem1->lang->sameAs("fr-CH")) {
      TEST_FAIL("[HttpHeader test Set case15]");
      break;
    }

    HttpHeaderAcceptLanguageItem langItem2 = langs->get(1);
    if(!langItem2->lang->sameAs("fr")) {
      TEST_FAIL("[HttpHeader test Set case16]");
      break;
    }

    if(st(Float)::Compare(langItem2->weight,0.9) != 0) {
      TEST_FAIL("[HttpHeader test Set case17]");
      break;
    }

    HttpHeaderAcceptLanguageItem langItem3 = langs->get(2);
    if(!langItem3->lang->sameAs("en")) {
      TEST_FAIL("[HttpHeader test Set case18]");
      break;
    }

    if(st(Float)::Compare(langItem3->weight,0.8) != 0) {
      TEST_FAIL("[HttpHeader test Set case19]");
      break;
    }

    HttpHeaderAcceptLanguageItem langItem4 = langs->get(3);
    if(!langItem4->lang->sameAs("de")) {
      TEST_FAIL("[HttpHeader test Set case20]");
      break;
    }

    if(st(Float)::Compare(langItem4->weight,0.7) != 0) {
      TEST_FAIL("[HttpHeader test Set case21]");
      break;
    }

    HttpHeaderAcceptLanguageItem langItem5 = langs->get(4);
    if(!langItem5->lang->sameAs("*")) {
      TEST_FAIL("[HttpHeader test Set case22]");
      break;
    }

    if(st(Float)::Compare(langItem5->weight,0.5) != 0) {
      TEST_FAIL("[HttpHeader test Set case23]");
      break;
    }

    //Accept-Patch: application/example, text/example
    HttpHeaderAcceptPatch patch = header->getAcceptPatch();
    ArrayList<HttpHeaderAcceptPatchItem> patches = patch->get();
    HttpHeaderAcceptPatchItem patchItem1 = patches->get(0);
    if(!patchItem1->type->sameAs("application/example")) {
      TEST_FAIL("[HttpHeader test Set case24]");
      break;
    }

    HttpHeaderAcceptPatchItem patchItem2 = patches->get(1);
    if(!patchItem2->type->sameAs("text/example")) {
      TEST_FAIL("[HttpHeader test Set case25]");
      break;
    }

    //Accept: text/html, application/xhtml+xml, application/xml;q=0.9, */*;q=0.8
    HttpHeaderAccept accept = header->getAccept();
    ArrayList<HttpHeaderAcceptItem> accepts = accept->get();
    if(accepts->size() != 4) {
      TEST_FAIL("[HttpHeader test Set case26_0]");
      break;
    }

    HttpHeaderAcceptItem acceptItem1 = accepts->get(0);
    if(!acceptItem1->type->sameAs("text/html")) {
      TEST_FAIL("[HttpHeader test Set case26]  ,type is %s",acceptItem1->type->toChars());
      break;
    }

    HttpHeaderAcceptItem acceptItem2 = accepts->get(1);
    if(!acceptItem2->type->sameAs("application/xhtml+xml")) {
      TEST_FAIL("[HttpHeader test Set case27]");
      break;
    }

    HttpHeaderAcceptItem acceptItem3 = accepts->get(2);
    if(!acceptItem3->type->sameAs("application/xml")) {
      TEST_FAIL("[HttpHeader test Set case28]");
      break;
    }

    if(st(Float)::Compare(acceptItem3->weight,0.9) != 0) {
      TEST_FAIL("[HttpHeader test Set case29]");
      break;
    }

    HttpHeaderAcceptItem acceptItem4 = accepts->get(3);
    if(!acceptItem4->type->sameAs("*/*")) {
      TEST_FAIL("[HttpHeader test Set case30]");
      break;
    }

    if(st(Float)::Compare(acceptItem4->weight,0.8) != 0) {
      TEST_FAIL("[HttpHeader test Set case31]");
      break;
    }

    //"Allow: GET, POST, HEAD\r"
    String allow = header->get("Allow");
    if(!allow->sameAs("GET, POST, HEAD")) {
      TEST_FAIL("[HttpHeader test Set case32]  ,allow is %s",allow->toChars());
      break;
    }

    //Authorization: Basic YWxhZGRpbjpvcGVuc2VzYW1l
    HttpHeaderAuthorization authorization = header->getAuthorization();
    if(!authorization->type->sameAs("Basic")) {
      TEST_FAIL("[HttpHeader test Set case33]  ,allow is %s",allow->toChars());
      break;
    }

    if(!authorization->credentials->sameAs("YWxhZGRpbjpvcGVuc2VzYW1l")) {
      TEST_FAIL("[HttpHeader test Set case34]");
      break;
    }

    //Content-Disposition: form-data; name=\"fieldName\"; filename=\"filename.jpg\"
    HttpHeaderContentDisposition contentDisp = header->getContentDisposition();
    if(contentDisp->getType() != st(HttpHeaderContentDisposition)::FormData) {
      TEST_FAIL("[HttpHeader test Set case35]");
      break;
    }

    if(!contentDisp->getName()->sameAs("fieldName")) {
      TEST_FAIL("[HttpHeader test Set case36]");
      break;
    }

    if(!contentDisp->getFileName()->sameAs("filename.jpg")) {
      TEST_FAIL("[HttpHeader test Set case37]");
      break;
    }

    //Content-Encoding: identity
    String contentEncoding = header->get("Content-Encoding");
    if(!contentEncoding->sameAs("identity")) {
      TEST_FAIL("[HttpHeader test Set case38]");
      break;
    }

    //Cache-Control: max-age=1000
    HttpHeaderCacheControl cachecontrol = header->getCacheControl();
    if(cachecontrol->maxAgeSeconds() != 1000) {
      TEST_FAIL("[HttpHeader test Set case39],maxAgeSeconds is %d",cachecontrol->maxAgeSeconds());
      break;
    }

    //Content-Length: 2000
    int contentLen = header->getContentLength()->get();
    if(contentLen != 2000) {
      TEST_FAIL("[HttpHeader test Set case40]");
      break;
    }

    //Link: <https://example.com>; rel="preload"
    ArrayList<HttpHeaderLink> links = header->getLinks();
    if(links->size() != 1) {
      TEST_FAIL("[HttpHeader test Set case41]");
      break;
    }

    HttpHeaderLink link = links->get(0);
    if(!link->url->sameAs("https://example.com")) {
      TEST_FAIL("[HttpHeader test Set case42]");
      break;
    }

    if(!link->rel->sameAs("preload")) {
      TEST_FAIL("[HttpHeader test Set case43]");
      break;
    }

    //X-Frame-Options: allow-from https://example.com/
    HttpHeaderXFrameOptions xframeoption = header->getXFrameOptions();
    if(!xframeoption->option->sameAs("allow-from")) {
      TEST_FAIL("[HttpHeader test Set case44]");
      break;
    }

    if(!xframeoption->uri->sameAs("https://example.com/")) {
      TEST_FAIL("[HttpHeader test Set case45]");
      break;
    }
    
    if(header->getProtocol() != st(Net)::Protocol::Http) {
      TEST_FAIL("[HttpHeader test Set case46]");
      break;
    }
    
    break;
  }
 
  TEST_OK("[HttpHeader test Set case100]");

}
