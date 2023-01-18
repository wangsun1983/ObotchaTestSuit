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

void testHttpHeaderAppend() {
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
    
    HttpHeader header2 = createHttpHeader();
    header2->append(header);
    //Charset
    auto charset = header2->getAcceptCharSet();
    if(charset == nullptr) {
      TEST_FAIL("[HttpHeader test Append case4]");
      break;
    }

    ArrayList<HttpHeaderAcceptCharSetItem> charsets = charset->get();
    if(charsets->size() != 2) {
      TEST_FAIL("[HttpHeader test Append case5]");
      break;
    }

    HttpHeaderAcceptCharSetItem charSetItem1 = charsets->get(0);
    if(!charSetItem1->type->equalsIgnoreCase("utf-8")) {
      TEST_FAIL("[HttpHeader test Append case6]  char set is %s ",charSetItem1->type->toChars());
      break;
    }

    HttpHeaderAcceptCharSetItem charSetItem2 = charsets->get(1);
    if(!charSetItem2->type->equalsIgnoreCase("iso-8859-1")) {
      TEST_FAIL("[HttpHeader test Append case7]  char set is %s ",charSetItem2->type->toChars());
      break;
    }

    if(st(Math)::compareFloat(charSetItem2->weight,0.5) != st(Math)::AlmostEqual) {
      TEST_FAIL("[HttpHeader test Append case8]  char set is %s ",charSetItem2->type->toChars());
      break;
    }

    //Encoding
    //Accept-Encoding: deflate, gzip;q=1.0, *;q=0.5\r
    HttpHeaderAcceptEncoding encoding = header2->getAcceptEncoding();
    ArrayList<HttpHeaderAcceptEncodingItem> encodings = encoding->get();
    if(encodings->size() != 3) {
      TEST_FAIL("[HttpHeader test Append case9]");
      break;
    }

    HttpHeaderAcceptEncodingItem encodingItem0 = encodings->get(0);
    if(!encodingItem0->type->equals("deflate")) {
      TEST_FAIL("[HttpHeader test Append case9]");
      break;
    }

    HttpHeaderAcceptEncodingItem encodingItem1 = encodings->get(1);
    if(!encodingItem1->type->equals("gzip")) {
      TEST_FAIL("[HttpHeader test Append case10]");
      break;
    }

    if(st(Math)::compareFloat(encodingItem1->weight,1.0) != st(Math)::AlmostEqual) {
      TEST_FAIL("[HttpHeader test Append case11]  weight is %lf ",encodingItem1->weight);
      break;
    }

    HttpHeaderAcceptEncodingItem encodingItem2 = encodings->get(2);
    if(!encodingItem2->type->equals("*")) {
      TEST_FAIL("[HttpHeader test Append case12]");
      break;
    }

    if(st(Math)::compareFloat(encodingItem2->weight,0.5) != st(Math)::AlmostEqual) {
      TEST_FAIL("[HttpHeader test Append case13]");
      break;
    }

    //Accept-Language: fr-CH, fr;q=0.9, en;q=0.8, de;q=0.7, *;q=0.5
    HttpHeaderAcceptLanguage mAcceptLang = header2->getAcceptLanguage();
    ArrayList<HttpHeaderAcceptLanguageItem> langs = mAcceptLang->get();
    if(langs->size() != 5) {
      TEST_FAIL("[HttpHeader test Append case14]");
      break;
    }

    HttpHeaderAcceptLanguageItem langItem1 = langs->get(0);
    if(!langItem1->lang->equals("fr-CH")) {
      TEST_FAIL("[HttpHeader test Append case15]");
      break;
    }

    HttpHeaderAcceptLanguageItem langItem2 = langs->get(1);
    if(!langItem2->lang->equals("fr")) {
      TEST_FAIL("[HttpHeader test Append case16]");
      break;
    }

    if(st(Math)::compareFloat(langItem2->weight,0.9) != st(Math)::AlmostEqual) {
      TEST_FAIL("[HttpHeader test Append case17]");
      break;
    }

    HttpHeaderAcceptLanguageItem langItem3 = langs->get(2);
    if(!langItem3->lang->equals("en")) {
      TEST_FAIL("[HttpHeader test Append case18]");
      break;
    }

    if(st(Math)::compareFloat(langItem3->weight,0.8) != st(Math)::AlmostEqual) {
      TEST_FAIL("[HttpHeader test Append case19]");
      break;
    }

    HttpHeaderAcceptLanguageItem langItem4 = langs->get(3);
    if(!langItem4->lang->equals("de")) {
      TEST_FAIL("[HttpHeader test Append case20]");
      break;
    }

    if(st(Math)::compareFloat(langItem4->weight,0.7) != st(Math)::AlmostEqual) {
      TEST_FAIL("[HttpHeader test Append case21]");
      break;
    }

    HttpHeaderAcceptLanguageItem langItem5 = langs->get(4);
    if(!langItem5->lang->equals("*")) {
      TEST_FAIL("[HttpHeader test Append case22]");
      break;
    }

    if(st(Math)::compareFloat(langItem5->weight,0.5) != st(Math)::AlmostEqual) {
      TEST_FAIL("[HttpHeader test Append case23]");
      break;
    }

    //Accept-Patch: application/example, text/example
    HttpHeaderAcceptPatch patch = header2->getAcceptPatch();
    ArrayList<HttpHeaderAcceptPatchItem> patches = patch->get();
    HttpHeaderAcceptPatchItem patchItem1 = patches->get(0);
    if(!patchItem1->type->equals("application/example")) {
      TEST_FAIL("[HttpHeader test Append case24]");
      break;
    }

    HttpHeaderAcceptPatchItem patchItem2 = patches->get(1);
    if(!patchItem2->type->equals("text/example")) {
      TEST_FAIL("[HttpHeader test Append case25]");
      break;
    }

    //Accept: text/html, application/xhtml+xml, application/xml;q=0.9, */*;q=0.8
    HttpHeaderAccept accept = header2->getAccept();
    ArrayList<HttpHeaderAcceptItem> accepts = accept->get();
    if(accepts->size() != 4) {
      TEST_FAIL("[HttpHeader test Append case26_0]");
      break;
    }

    HttpHeaderAcceptItem acceptItem1 = accepts->get(0);
    if(!acceptItem1->type->equals("text/html")) {
      TEST_FAIL("[HttpHeader test Append case26]  ,type is %s",acceptItem1->type->toChars());
      break;
    }

    HttpHeaderAcceptItem acceptItem2 = accepts->get(1);
    if(!acceptItem2->type->equals("application/xhtml+xml")) {
      TEST_FAIL("[HttpHeader test Append case27]");
      break;
    }

    HttpHeaderAcceptItem acceptItem3 = accepts->get(2);
    if(!acceptItem3->type->equals("application/xml")) {
      TEST_FAIL("[HttpHeader test Append case28]");
      break;
    }

    if(st(Math)::compareFloat(acceptItem3->weight,0.9) != st(Math)::AlmostEqual) {
      TEST_FAIL("[HttpHeader test Append case29]");
      break;
    }

    HttpHeaderAcceptItem acceptItem4 = accepts->get(3);
    if(!acceptItem4->type->equals("*/*")) {
      TEST_FAIL("[HttpHeader test Append case30]");
      break;
    }

    if(st(Math)::compareFloat(acceptItem4->weight,0.8) != st(Math)::AlmostEqual) {
      TEST_FAIL("[HttpHeader test Append case31]");
      break;
    }

    //"Allow: GET, POST, HEAD\r"
    String allow = header2->get("Allow");
    if(!allow->equals("GET, POST, HEAD")) {
      TEST_FAIL("[HttpHeader test Append case32]  ,allow is %s",allow->toChars());
      break;
    }

    //Authorization: Basic YWxhZGRpbjpvcGVuc2VzYW1l
    HttpHeaderAuthorization authorization = header2->getAuthorization();
    if(!authorization->type->equals("Basic")) {
      TEST_FAIL("[HttpHeader test Append case33]  ,allow is %s",allow->toChars());
      break;
    }

    if(!authorization->credentials->equals("YWxhZGRpbjpvcGVuc2VzYW1l")) {
      TEST_FAIL("[HttpHeader test Append case34]");
      break;
    }

    //Content-Disposition: form-data; name=\"fieldName\"; filename=\"filename.jpg\"
    HttpHeaderContentDisposition contentDisp = header2->getContentDisposition();
    if(contentDisp->getType() != st(HttpHeaderContentDisposition)::FormData) {
      TEST_FAIL("[HttpHeader test Append case35]");
      break;
    }

    if(!contentDisp->getName()->equals("fieldName")) {
      TEST_FAIL("[HttpHeader test Append case36]");
      break;
    }

    if(!contentDisp->getFileName()->equals("filename.jpg")) {
      TEST_FAIL("[HttpHeader test Append case37]");
      break;
    }

    //Content-Encoding: identity
    String contentEncoding = header2->get("Content-Encoding");
    if(!contentEncoding->equals("identity")) {
      TEST_FAIL("[HttpHeader test Append case38]");
      break;
    }

    //Cache-Control: max-age=1000
    HttpHeaderCacheControl cachecontrol = header2->getCacheControl();
    if(cachecontrol->maxAgeSeconds() != 1000) {
      TEST_FAIL("[HttpHeader test Append case39],maxAgeSeconds is %d",cachecontrol->maxAgeSeconds());
      break;
    }

    //Content-Length: 2000
    int contentLen = header2->getContentLength()->get();
    if(contentLen != 2000) {
      TEST_FAIL("[HttpHeader test Append case40]");
      break;
    }

    //Link: <https://example.com>; rel="preload"
    ArrayList<HttpHeaderLink> links = header2->getLinks();
    if(links->size() != 1) {
      TEST_FAIL("[HttpHeader test Append case41]");
      break;
    }

    HttpHeaderLink link = links->get(0);
    if(!link->url->equals("https://example.com")) {
      TEST_FAIL("[HttpHeader test Append case42]");
      break;
    }

    if(!link->rel->equals("preload")) {
      TEST_FAIL("[HttpHeader test Append case43]");
      break;
    }

    //X-Frame-Options: allow-from https://example.com/
    HttpHeaderXFrameOptions xframeoption = header2->getXFrameOptions();
    if(!xframeoption->option->equals("allow-from")) {
      TEST_FAIL("[HttpHeader test Append case44]");
      break;
    }

    if(!xframeoption->uri->equals("https://example.com/")) {
      TEST_FAIL("[HttpHeader test Append case45]");
      break;
    }
    
    if(header2->getProtocol() != st(NetProtocol)::Http) {
      TEST_FAIL("[HttpHeader test Append case46]");
      break;
    }
    
    break;
  }
 
  TEST_OK("[HttpHeader test Append case100]");

}
