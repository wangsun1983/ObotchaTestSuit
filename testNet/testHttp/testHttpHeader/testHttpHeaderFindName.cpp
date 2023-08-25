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
#include "HttpHeader.hpp"

using namespace obotcha;

#define TEST_NAME(NAME,ID) \
    if(!st(HttpHeader)::NAME->equals(st(HttpHeader)::findName(st(HttpHeader)::Id::ID))) { \
        TEST_FAIL("HttpHeader find name[%s],exepect is %d,actual is %d",st(HttpHeader)::NAME->toChars(),static_cast<int>(st(HttpHeader)::Id::ID),st(HttpHeader)::findId(st(HttpHeader)::NAME));\
    }\

void testHttpHeaderFindName() {  
    TEST_NAME(Method,Method);
    TEST_NAME(Path,Path);
    TEST_NAME(Scheme,Scheme);
    TEST_NAME(Status,Status);
    TEST_NAME(Protocol,Protocol);

    //regular http header
    TEST_NAME(Accept,Accept);
    TEST_NAME(AcceptCh,AcceptCh);
    TEST_NAME(AcceptCharset,AcceptCharset);
    TEST_NAME(AcceptPatch,AcceptPatch);
    TEST_NAME(AcceptDatetime,AcceptDatetime);
    TEST_NAME(AcceptEncoding,AcceptEncoding);
    TEST_NAME(AcceptLanguage,AcceptLanguage);
    TEST_NAME(AcceptRanges,AcceptRanges);
    TEST_NAME(AccessControlAllowCredentials,AccessControlAllowCredentials);
    TEST_NAME(AccessControlAllowHeaders,AccessControlAllowHeaders);
    TEST_NAME(AccessControlAllowMethods,AccessControlAllowMethods);
    TEST_NAME(AccessControlAllowOrigin,AccessControlAllowOrigin);
    TEST_NAME(AccessControlExposeHeaders,AccessControlExposeHeaders);
    TEST_NAME(AccessControlMaxAge,AccessControlMaxAge);
    TEST_NAME(AccessControlRequestHeaders,AccessControlRequestHeaders);
    TEST_NAME(AccessControlRequestMethod,AccessControlRequestMethod);
    TEST_NAME(Age,Age);
    TEST_NAME(Allow,Allow);
    TEST_NAME(AltSvc,AltSvc);
    TEST_NAME(Authorization,Authorization);
    TEST_NAME(CacheControl,CacheControl);
    TEST_NAME(Connection,Connection);
    TEST_NAME(ContentDisposition,ContentDisposition);
    TEST_NAME(ContentEncoding,ContentEncoding);
    TEST_NAME(ContentLanguage,ContentLanguage);
    TEST_NAME(ContentLength,ContentLength);
    TEST_NAME(ContentLocation,ContentLocation);
    TEST_NAME(ContentMD5,ContentMD5);
    TEST_NAME(ContentRange,ContentRange);
    TEST_NAME(ContentSecurityPolicyReportOnly,ContentSecurityPolicyReportOnly);
    TEST_NAME(ContentSecurityPolicy,ContentSecurityPolicy);
    TEST_NAME(ContentType,ContentType);
    TEST_NAME(Cookie,Cookie);
    TEST_NAME(CrossOriginEmbedderPolicy,CrossOriginEmbedderPolicy);
    TEST_NAME(CrossOriginOpenerPolicy,CrossOriginOpenerPolicy);
    TEST_NAME(CrossOriginResourcePolicy,CrossOriginResourcePolicy);
    TEST_NAME(DNT,DNT);
    TEST_NAME(Date,Date);
    TEST_NAME(ETag,ETag);
    TEST_NAME(Expect,Expect);
    TEST_NAME(ExpectCT,ExpectCT);
    TEST_NAME(Expires,Expires);
    TEST_NAME(From,From);
    TEST_NAME(FrontEndHttps,FrontEndHttps);
    TEST_NAME(Host,Host);
    TEST_NAME(IfMatch,IfMatch);
    TEST_NAME(IfModifiedSince,IfModifiedSince);
    TEST_NAME(IfNoneMatch,IfNoneMatch);
    TEST_NAME(IfRange,IfRange);
    TEST_NAME(IfUnmodifiedSince,IfUnmodifiedSince);
    TEST_NAME(KeepAlive,KeepAlive);
    TEST_NAME(LastModified,LastModified);
    TEST_NAME(Link,Link);
    TEST_NAME(Location,Location);
    TEST_NAME(MaxForwards,MaxForwards);
    TEST_NAME(Origin,Origin);
    TEST_NAME(P3P,P3P);
    TEST_NAME(Pragma,Pragma);
    TEST_NAME(ProxyAuthenticate,ProxyAuthenticate);
    TEST_NAME(ProxyAuthorization,ProxyAuthorization);
    TEST_NAME(ProxyConnection,ProxyConnection);
    TEST_NAME(Range,Range);
    TEST_NAME(Referer,Referer);
    TEST_NAME(RefererPolicy,RefererPolicy);
    TEST_NAME(Refresh,Refresh);
    TEST_NAME(RetryAfter,RetryAfter);
    TEST_NAME(SaveData,SaveData);
    TEST_NAME(SecWebSocketKey,SecWebSocketKey);
    TEST_NAME(SecWebSocketAccept,SecWebSocketAccept);
    TEST_NAME(Server,Server);
    TEST_NAME(SetCookie,SetCookie);
    TEST_NAME(SecTokenBinding,SecTokenBinding);
    TEST_NAME(SecFetchDest,SecFetchDest);
    TEST_NAME(SecFetchMode,SecFetchMode);
    TEST_NAME(SecFetchSite,SecFetchSite);
    TEST_NAME(SecFetchUser,SecFetchUser);
    TEST_NAME(StrictTransportSecurity,StrictTransportSecurity);
    TEST_NAME(TE,TE);
    TEST_NAME(Timestamp,Timestamp);
    TEST_NAME(Trailer,Trailer);
    TEST_NAME(TransferEncoding,TransferEncoding);
    TEST_NAME(Upgrade,Upgrade);
    TEST_NAME(UserAgent,UserAgent);
    TEST_NAME(VIP,VIP);
    TEST_NAME(Vary,Vary);
    TEST_NAME(Via,Via);
    TEST_NAME(WWWAuthenticate,WWWAuthenticate);
    TEST_NAME(Warning,Warning);
    TEST_NAME(XAccelRedirect,XAccelRedirect);
    TEST_NAME(XContentSecurityPolicyReportOnly,XContentSecurityPolicyReportOnly);
    TEST_NAME(XContentTypeOptions,XContentTypeOptions);
    TEST_NAME(XForwardedFor,XForwardedFor);
    TEST_NAME(XForwardedProto,XForwardedProto);
    TEST_NAME(Forwarded,Forwarded);
    TEST_NAME(XFrameOptions,XFrameOptions);
    TEST_NAME(XPoweredBy,XPoweredBy);
    TEST_NAME(XRealIP,XRealIP);
    TEST_NAME(XRequestedWith,XRequestedWith);
    TEST_NAME(XThriftProtocol,XThriftProtocol);
    TEST_NAME(XUACompatible,XUACompatible);
    TEST_NAME(XWapProfile,XWapProfile);
    TEST_NAME(XXSSProtection,XXSSProtection);
    TEST_NAME(SecWebSocketVersion,SecWebSocketVersion);
    TEST_NAME(SecWebSocketExtensions,SecWebSocketExtensions);
    TEST_NAME(SecWebSocketOrigin,SecWebSocketOrigin);
    TEST_NAME(SecWebSocketKey1,SecWebSocketKey1);
    TEST_NAME(SecWebSocketKey2,SecWebSocketKey2);
    TEST_NAME(SecWebSocketKey3,SecWebSocketKey3);
    TEST_NAME(SecWebSocketProtocol,SecWebSocketProtocol);
    TEST_NAME(ServerTiming,ServerTiming);
    TEST_NAME(SourceMap,SourceMap);
    TEST_NAME(Digest,Digest);
    //Transfer-Encoding type
    //TEST_NAME(TransferChunked,TransferChunked);

    //http connection
    //TEST_NAME(ConnectionClose,ConnectionClose);

    //http2 authority
    TEST_NAME(Authority,Authority);

    TEST_NAME(ClearSiteData,ClearSiteData);
    TEST_NAME(Version,Version);
    
 
    TEST_OK("[HttpHeader test FindId case100]");

}
