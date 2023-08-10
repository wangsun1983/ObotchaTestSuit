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
    if(!st(HttpHeader)::NAME->equals(st(HttpHeader)::findName(st(HttpHeader)::ID))) { \
        TEST_FAIL("HttpHeader find name[%s],exepect is %d,actual is %d",st(HttpHeader)::NAME->toChars(),st(HttpHeader)::ID,st(HttpHeader)::findId(st(HttpHeader)::NAME));\
    }\

void testHttpHeaderFindName() {  
    TEST_NAME(Method,TypeMethod);
    TEST_NAME(Path,TypePath);
    TEST_NAME(Scheme,TypeScheme);
    TEST_NAME(Status,TypeStatus);
    TEST_NAME(Protocol,TypeProtocol);

    //regular http header
    TEST_NAME(Accept,TypeAccept);
    TEST_NAME(AcceptCh,TypeAcceptCh);
    TEST_NAME(AcceptCharset,TypeAcceptCharset);
    TEST_NAME(AcceptPatch,TypeAcceptPatch);
    TEST_NAME(AcceptDatetime,TypeAcceptDatetime);
    TEST_NAME(AcceptEncoding,TypeAcceptEncoding);
    TEST_NAME(AcceptLanguage,TypeAcceptLanguage);
    TEST_NAME(AcceptRanges,TypeAcceptRanges);
    TEST_NAME(AccessControlAllowCredentials,TypeAccessControlAllowCredentials);
    TEST_NAME(AccessControlAllowHeaders,TypeAccessControlAllowHeaders);
    TEST_NAME(AccessControlAllowMethods,TypeAccessControlAllowMethods);
    TEST_NAME(AccessControlAllowOrigin,TypeAccessControlAllowOrigin);
    TEST_NAME(AccessControlExposeHeaders,TypeAccessControlExposeHeaders);
    TEST_NAME(AccessControlMaxAge,TypeAccessControlMaxAge);
    TEST_NAME(AccessControlRequestHeaders,TypeAccessControlRequestHeaders);
    TEST_NAME(AccessControlRequestMethod,TypeAccessControlRequestMethod);
    TEST_NAME(Age,TypeAge);
    TEST_NAME(Allow,TypeAllow);
    TEST_NAME(AltSvc,TypeAltSvc);
    TEST_NAME(Authorization,TypeAuthorization);
    TEST_NAME(CacheControl,TypeCacheControl);
    TEST_NAME(Connection,TypeConnection);
    TEST_NAME(ContentDisposition,TypeContentDisposition);
    TEST_NAME(ContentEncoding,TypeContentEncoding);
    TEST_NAME(ContentLanguage,TypeContentLanguage);
    TEST_NAME(ContentLength,TypeContentLength);
    TEST_NAME(ContentLocation,TypeContentLocation);
    TEST_NAME(ContentMD5,TypeContentMD5);
    TEST_NAME(ContentRange,TypeContentRange);
    TEST_NAME(ContentSecurityPolicyReportOnly,TypeContentSecurityPolicyReportOnly);
    TEST_NAME(ContentSecurityPolicy,TypeContentSecurityPolicy);
    TEST_NAME(ContentType,TypeContentType);
    TEST_NAME(Cookie,TypeCookie);
    TEST_NAME(CrossOriginEmbedderPolicy,TypeCrossOriginEmbedderPolicy);
    TEST_NAME(CrossOriginOpenerPolicy,TypeCrossOriginOpenerPolicy);
    TEST_NAME(CrossOriginResourcePolicy,TypeCrossOriginResourcePolicy);
    TEST_NAME(DNT,TypeDNT);
    TEST_NAME(Date,TypeDate);
    TEST_NAME(ETag,TypeETag);
    TEST_NAME(Expect,TypeExpect);
    TEST_NAME(ExpectCT,TypeExpectCT);
    TEST_NAME(Expires,TypeExpires);
    TEST_NAME(From,TypeFrom);
    TEST_NAME(FrontEndHttps,TypeFrontEndHttps);
    TEST_NAME(Host,TypeHost);
    TEST_NAME(IfMatch,TypeIfMatch);
    TEST_NAME(IfModifiedSince,TypeIfModifiedSince);
    TEST_NAME(IfNoneMatch,TypeIfNoneMatch);
    TEST_NAME(IfRange,TypeIfRange);
    TEST_NAME(IfUnmodifiedSince,TypeIfUnmodifiedSince);
    TEST_NAME(KeepAlive,TypeKeepAlive);
    TEST_NAME(LastModified,TypeLastModified);
    TEST_NAME(Link,TypeLink);
    TEST_NAME(Location,TypeLocation);
    TEST_NAME(MaxForwards,TypeMaxForwards);
    TEST_NAME(Origin,TypeOrigin);
    TEST_NAME(P3P,TypeP3P);
    TEST_NAME(Pragma,TypePragma);
    TEST_NAME(ProxyAuthenticate,TypeProxyAuthenticate);
    TEST_NAME(ProxyAuthorization,TypeProxyAuthorization);
    TEST_NAME(ProxyConnection,TypeProxyConnection);
    TEST_NAME(Range,TypeRange);
    TEST_NAME(Referer,TypeReferer);
    TEST_NAME(RefererPolicy,TypeRefererPolicy);
    TEST_NAME(Refresh,TypeRefresh);
    TEST_NAME(RetryAfter,TypeRetryAfter);
    TEST_NAME(SaveData,TypeSaveData);
    TEST_NAME(SecWebSocketKey,TypeSecWebSocketKey);
    TEST_NAME(SecWebSocketAccept,TypeSecWebSocketAccept);
    TEST_NAME(Server,TypeServer);
    TEST_NAME(SetCookie,TypeSetCookie);
    TEST_NAME(SecTokenBinding,TypeSecTokenBinding);
    TEST_NAME(SecFetchDest,TypeSecFetchDest);
    TEST_NAME(SecFetchMode,TypeSecFetchMode);
    TEST_NAME(SecFetchSite,TypeSecFetchSite);
    TEST_NAME(SecFetchUser,TypeSecFetchUser);
    TEST_NAME(StrictTransportSecurity,TypeStrictTransportSecurity);
    TEST_NAME(TE,TypeTE);
    TEST_NAME(Timestamp,TypeTimestamp);
    TEST_NAME(Trailer,TypeTrailer);
    TEST_NAME(TransferEncoding,TypeTransferEncoding);
    TEST_NAME(Upgrade,TypeUpgrade);
    TEST_NAME(UserAgent,TypeUserAgent);
    TEST_NAME(VIP,TypeVIP);
    TEST_NAME(Vary,TypeVary);
    TEST_NAME(Via,TypeVia);
    TEST_NAME(WWWAuthenticate,TypeWWWAuthenticate);
    TEST_NAME(Warning,TypeWarning);
    TEST_NAME(XAccelRedirect,TypeXAccelRedirect);
    TEST_NAME(XContentSecurityPolicyReportOnly,TypeXContentSecurityPolicyReportOnly);
    TEST_NAME(XContentTypeOptions,TypeXContentTypeOptions);
    TEST_NAME(XForwardedFor,TypeXForwardedFor);
    TEST_NAME(XForwardedProto,TypeXForwardedProto);
    TEST_NAME(Forwarded,TypeForwarded);
    TEST_NAME(XFrameOptions,TypeXFrameOptions);
    TEST_NAME(XPoweredBy,TypeXPoweredBy);
    TEST_NAME(XRealIP,TypeXRealIP);
    TEST_NAME(XRequestedWith,TypeXRequestedWith);
    TEST_NAME(XThriftProtocol,TypeXThriftProtocol);
    TEST_NAME(XUACompatible,TypeXUACompatible);
    TEST_NAME(XWapProfile,TypeXWapProfile);
    TEST_NAME(XXSSProtection,TypeXXSSProtection);
    TEST_NAME(SecWebSocketVersion,TypeSecWebSocketVersion);
    TEST_NAME(SecWebSocketExtensions,TypeSecWebSocketExtensions);
    TEST_NAME(SecWebSocketOrigin,TypeSecWebSocketOrigin);
    TEST_NAME(SecWebSocketKey1,TypeSecWebSocketKey1);
    TEST_NAME(SecWebSocketKey2,TypeSecWebSocketKey2);
    TEST_NAME(SecWebSocketKey3,TypeSecWebSocketKey3);
    TEST_NAME(SecWebSocketProtocol,TypeSecWebSocketProtocol);
    TEST_NAME(ServerTiming,TypeServerTiming);
    TEST_NAME(SourceMap,TypeSourceMap);
    TEST_NAME(Digest,TypeDigest);
    //Transfer-Encoding type
    //TEST_NAME(TransferChunked,TypeTransferChunked);

    //http connection
    //TEST_NAME(ConnectionClose,TypeConnectionClose);

    //http2 authority
    TEST_NAME(Authority,TypeAuthority);

    TEST_NAME(ClearSiteData,TypeClearSiteData);
    TEST_NAME(Version,TypeVersion);
    
 
    TEST_OK("[HttpHeader test FindId case100]");

}
