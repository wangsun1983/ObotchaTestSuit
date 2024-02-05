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

#define TEST_ID(NAME,ID) \
    if(st(HttpHeader)::Id::ID != st(HttpHeader)::findId(st(HttpHeader)::NAME)) { \
        TEST_FAIL("HttpHeader find id[%s],exepect is %d,actual is %d", \
			st(HttpHeader)::NAME->toChars(),static_cast<int>(st(HttpHeader)::Id::ID),st(HttpHeader)::findId(st(HttpHeader)::NAME));\
    }\

void testHttpHeaderFindId() {  
    TEST_ID(Method,Method);
    TEST_ID(Path,Path);
    TEST_ID(Scheme,Scheme);
    TEST_ID(Status,Status);
    TEST_ID(Protocol,Protocol);

    //regular http header
    TEST_ID(Accept,Accept);
    TEST_ID(AcceptCh,AcceptCh);
    TEST_ID(AcceptCharset,AcceptCharset);
    TEST_ID(AcceptPatch,AcceptPatch);
    TEST_ID(AcceptDatetime,AcceptDatetime);
    TEST_ID(AcceptEncoding,AcceptEncoding);
    TEST_ID(AcceptLanguage,AcceptLanguage);
    TEST_ID(AcceptRanges,AcceptRanges);
    TEST_ID(AccessControlAllowCredentials,AccessControlAllowCredentials);
    TEST_ID(AccessControlAllowHeaders,AccessControlAllowHeaders);
    TEST_ID(AccessControlAllowMethods,AccessControlAllowMethods);
    TEST_ID(AccessControlAllowOrigin,AccessControlAllowOrigin);
    TEST_ID(AccessControlExposeHeaders,AccessControlExposeHeaders);
    TEST_ID(AccessControlMaxAge,AccessControlMaxAge);
    TEST_ID(AccessControlRequestHeaders,AccessControlRequestHeaders);
    TEST_ID(AccessControlRequestMethod,AccessControlRequestMethod);
    TEST_ID(Age,Age);
    TEST_ID(Allow,Allow);
    TEST_ID(AltSvc,AltSvc);
    TEST_ID(Authorization,Authorization);
    TEST_ID(CacheControl,CacheControl);
    TEST_ID(Connection,Connection);
    TEST_ID(ContentDisposition,ContentDisposition);
    TEST_ID(ContentEncoding,ContentEncoding);
    TEST_ID(ContentLanguage,ContentLanguage);
    TEST_ID(ContentLength,ContentLength);
    TEST_ID(ContentLocation,ContentLocation);
    TEST_ID(ContentMD5,ContentMD5);
    TEST_ID(ContentRange,ContentRange);
    TEST_ID(ContentSecurityPolicyReportOnly,ContentSecurityPolicyReportOnly);
    TEST_ID(ContentSecurityPolicy,ContentSecurityPolicy);
    TEST_ID(ContentType,ContentType);
    TEST_ID(Cookie,Cookie);
    TEST_ID(CrossOriginEmbedderPolicy,CrossOriginEmbedderPolicy);
    TEST_ID(CrossOriginOpenerPolicy,CrossOriginOpenerPolicy);
    TEST_ID(CrossOriginResourcePolicy,CrossOriginResourcePolicy);
    TEST_ID(DNT,DNT);
    TEST_ID(Date,Date);
    TEST_ID(ETag,ETag);
    TEST_ID(Expect,Expect);
    TEST_ID(ExpectCT,ExpectCT);
    TEST_ID(Expires,Expires);
    TEST_ID(From,From);
    TEST_ID(FrontEndHttps,FrontEndHttps);
    TEST_ID(Host,Host);
    TEST_ID(IfMatch,IfMatch);
    TEST_ID(IfModifiedSince,IfModifiedSince);
    TEST_ID(IfNoneMatch,IfNoneMatch);
    TEST_ID(IfRange,IfRange);
    TEST_ID(IfUnmodifiedSince,IfUnmodifiedSince);
    TEST_ID(KeepAlive,KeepAlive);
    TEST_ID(LastModified,LastModified);
    TEST_ID(Link,Link);
    TEST_ID(Location,Location);
    TEST_ID(MaxForwards,MaxForwards);
    TEST_ID(Origin,Origin);
    TEST_ID(P3P,P3P);
    TEST_ID(Pragma,Pragma);
    TEST_ID(ProxyAuthenticate,ProxyAuthenticate);
    TEST_ID(ProxyAuthorization,ProxyAuthorization);
    TEST_ID(ProxyConnection,ProxyConnection);
    TEST_ID(Range,Range);
    TEST_ID(Referer,Referer);
    TEST_ID(RefererPolicy,RefererPolicy);
    TEST_ID(Refresh,Refresh);
    TEST_ID(RetryAfter,RetryAfter);
    TEST_ID(SaveData,SaveData);
    TEST_ID(SecWebSocketKey,SecWebSocketKey);
    TEST_ID(SecWebSocketAccept,SecWebSocketAccept);
    TEST_ID(Server,Server);
    TEST_ID(SetCookie,SetCookie);
    TEST_ID(SecTokenBinding,SecTokenBinding);
    TEST_ID(SecFetchDest,SecFetchDest);
    TEST_ID(SecFetchMode,SecFetchMode);
    TEST_ID(SecFetchSite,SecFetchSite);
    TEST_ID(SecFetchUser,SecFetchUser);
    TEST_ID(StrictTransportSecurity,StrictTransportSecurity);
    TEST_ID(TE,TE);
    TEST_ID(Timestamp,Timestamp);
    TEST_ID(Trailer,Trailer);
    TEST_ID(TransferEncoding,TransferEncoding);
    TEST_ID(Upgrade,Upgrade);
    TEST_ID(UserAgent,UserAgent);
    TEST_ID(VIP,VIP);
    TEST_ID(Vary,Vary);
    TEST_ID(Via,Via);
    TEST_ID(WWWAuthenticate,WWWAuthenticate);
    TEST_ID(Warning,Warning);
    TEST_ID(XAccelRedirect,XAccelRedirect);
    TEST_ID(XContentSecurityPolicyReportOnly,XContentSecurityPolicyReportOnly);
    TEST_ID(XContentTypeOptions,XContentTypeOptions);
    TEST_ID(XForwardedFor,XForwardedFor);
    TEST_ID(XForwardedProto,XForwardedProto);
    TEST_ID(Forwarded,Forwarded);
    TEST_ID(XFrameOptions,XFrameOptions);
    TEST_ID(XPoweredBy,XPoweredBy);
    TEST_ID(XRealIP,XRealIP);
    TEST_ID(XRequestedWith,XRequestedWith);
    TEST_ID(XThriftProtocol,XThriftProtocol);
    TEST_ID(XUACompatible,XUACompatible);
    TEST_ID(XWapProfile,XWapProfile);
    TEST_ID(XXSSProtection,XXSSProtection);
    TEST_ID(SecWebSocketVersion,SecWebSocketVersion);
    TEST_ID(SecWebSocketExtensions,SecWebSocketExtensions);
    TEST_ID(SecWebSocketOrigin,SecWebSocketOrigin);
    TEST_ID(SecWebSocketKey1,SecWebSocketKey1);
    TEST_ID(SecWebSocketKey2,SecWebSocketKey2);
    TEST_ID(SecWebSocketKey3,SecWebSocketKey3);
    TEST_ID(SecWebSocketProtocol,SecWebSocketProtocol);
    TEST_ID(ServerTiming,ServerTiming);
    TEST_ID(SourceMap,SourceMap);
    TEST_ID(Digest,Digest);
    //Transfer-Encoding type
    //TEST_ID(TransferChunked,TransferChunked);

    //http connection
    //TEST_ID(ConnectionClose,ConnectionClose);

    //http2 authority
    TEST_ID(Authority,Authority);

    TEST_ID(ClearSiteData,ClearSiteData);
    TEST_ID(Version,Version);
    
 
    TEST_OK("[HttpHeader test FindId case100]");

}
