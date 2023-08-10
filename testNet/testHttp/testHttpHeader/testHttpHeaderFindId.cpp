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
    if(st(HttpHeader)::ID != st(HttpHeader)::findId(st(HttpHeader)::NAME)) { \
        TEST_FAIL("HttpHeader find id[%s],exepect is %d,actual is %d",st(HttpHeader)::NAME->toChars(),st(HttpHeader)::ID,st(HttpHeader)::findId(st(HttpHeader)::NAME));\
    }\

void testHttpHeaderFindId() {  
    TEST_ID(Method,TypeMethod);
    TEST_ID(Path,TypePath);
    TEST_ID(Scheme,TypeScheme);
    TEST_ID(Status,TypeStatus);
    TEST_ID(Protocol,TypeProtocol);

    //regular http header
    TEST_ID(Accept,TypeAccept);
    TEST_ID(AcceptCh,TypeAcceptCh);
    TEST_ID(AcceptCharset,TypeAcceptCharset);
    TEST_ID(AcceptPatch,TypeAcceptPatch);
    TEST_ID(AcceptDatetime,TypeAcceptDatetime);
    TEST_ID(AcceptEncoding,TypeAcceptEncoding);
    TEST_ID(AcceptLanguage,TypeAcceptLanguage);
    TEST_ID(AcceptRanges,TypeAcceptRanges);
    TEST_ID(AccessControlAllowCredentials,TypeAccessControlAllowCredentials);
    TEST_ID(AccessControlAllowHeaders,TypeAccessControlAllowHeaders);
    TEST_ID(AccessControlAllowMethods,TypeAccessControlAllowMethods);
    TEST_ID(AccessControlAllowOrigin,TypeAccessControlAllowOrigin);
    TEST_ID(AccessControlExposeHeaders,TypeAccessControlExposeHeaders);
    TEST_ID(AccessControlMaxAge,TypeAccessControlMaxAge);
    TEST_ID(AccessControlRequestHeaders,TypeAccessControlRequestHeaders);
    TEST_ID(AccessControlRequestMethod,TypeAccessControlRequestMethod);
    TEST_ID(Age,TypeAge);
    TEST_ID(Allow,TypeAllow);
    TEST_ID(AltSvc,TypeAltSvc);
    TEST_ID(Authorization,TypeAuthorization);
    TEST_ID(CacheControl,TypeCacheControl);
    TEST_ID(Connection,TypeConnection);
    TEST_ID(ContentDisposition,TypeContentDisposition);
    TEST_ID(ContentEncoding,TypeContentEncoding);
    TEST_ID(ContentLanguage,TypeContentLanguage);
    TEST_ID(ContentLength,TypeContentLength);
    TEST_ID(ContentLocation,TypeContentLocation);
    TEST_ID(ContentMD5,TypeContentMD5);
    TEST_ID(ContentRange,TypeContentRange);
    TEST_ID(ContentSecurityPolicyReportOnly,TypeContentSecurityPolicyReportOnly);
    TEST_ID(ContentSecurityPolicy,TypeContentSecurityPolicy);
    TEST_ID(ContentType,TypeContentType);
    TEST_ID(Cookie,TypeCookie);
    TEST_ID(CrossOriginEmbedderPolicy,TypeCrossOriginEmbedderPolicy);
    TEST_ID(CrossOriginOpenerPolicy,TypeCrossOriginOpenerPolicy);
    TEST_ID(CrossOriginResourcePolicy,TypeCrossOriginResourcePolicy);
    TEST_ID(DNT,TypeDNT);
    TEST_ID(Date,TypeDate);
    TEST_ID(ETag,TypeETag);
    TEST_ID(Expect,TypeExpect);
    TEST_ID(ExpectCT,TypeExpectCT);
    TEST_ID(Expires,TypeExpires);
    TEST_ID(From,TypeFrom);
    TEST_ID(FrontEndHttps,TypeFrontEndHttps);
    TEST_ID(Host,TypeHost);
    TEST_ID(IfMatch,TypeIfMatch);
    TEST_ID(IfModifiedSince,TypeIfModifiedSince);
    TEST_ID(IfNoneMatch,TypeIfNoneMatch);
    TEST_ID(IfRange,TypeIfRange);
    TEST_ID(IfUnmodifiedSince,TypeIfUnmodifiedSince);
    TEST_ID(KeepAlive,TypeKeepAlive);
    TEST_ID(LastModified,TypeLastModified);
    TEST_ID(Link,TypeLink);
    TEST_ID(Location,TypeLocation);
    TEST_ID(MaxForwards,TypeMaxForwards);
    TEST_ID(Origin,TypeOrigin);
    TEST_ID(P3P,TypeP3P);
    TEST_ID(Pragma,TypePragma);
    TEST_ID(ProxyAuthenticate,TypeProxyAuthenticate);
    TEST_ID(ProxyAuthorization,TypeProxyAuthorization);
    TEST_ID(ProxyConnection,TypeProxyConnection);
    TEST_ID(Range,TypeRange);
    TEST_ID(Referer,TypeReferer);
    TEST_ID(RefererPolicy,TypeRefererPolicy);
    TEST_ID(Refresh,TypeRefresh);
    TEST_ID(RetryAfter,TypeRetryAfter);
    TEST_ID(SaveData,TypeSaveData);
    TEST_ID(SecWebSocketKey,TypeSecWebSocketKey);
    TEST_ID(SecWebSocketAccept,TypeSecWebSocketAccept);
    TEST_ID(Server,TypeServer);
    TEST_ID(SetCookie,TypeSetCookie);
    TEST_ID(SecTokenBinding,TypeSecTokenBinding);
    TEST_ID(SecFetchDest,TypeSecFetchDest);
    TEST_ID(SecFetchMode,TypeSecFetchMode);
    TEST_ID(SecFetchSite,TypeSecFetchSite);
    TEST_ID(SecFetchUser,TypeSecFetchUser);
    TEST_ID(StrictTransportSecurity,TypeStrictTransportSecurity);
    TEST_ID(TE,TypeTE);
    TEST_ID(Timestamp,TypeTimestamp);
    TEST_ID(Trailer,TypeTrailer);
    TEST_ID(TransferEncoding,TypeTransferEncoding);
    TEST_ID(Upgrade,TypeUpgrade);
    TEST_ID(UserAgent,TypeUserAgent);
    TEST_ID(VIP,TypeVIP);
    TEST_ID(Vary,TypeVary);
    TEST_ID(Via,TypeVia);
    TEST_ID(WWWAuthenticate,TypeWWWAuthenticate);
    TEST_ID(Warning,TypeWarning);
    TEST_ID(XAccelRedirect,TypeXAccelRedirect);
    TEST_ID(XContentSecurityPolicyReportOnly,TypeXContentSecurityPolicyReportOnly);
    TEST_ID(XContentTypeOptions,TypeXContentTypeOptions);
    TEST_ID(XForwardedFor,TypeXForwardedFor);
    TEST_ID(XForwardedProto,TypeXForwardedProto);
    TEST_ID(Forwarded,TypeForwarded);
    TEST_ID(XFrameOptions,TypeXFrameOptions);
    TEST_ID(XPoweredBy,TypeXPoweredBy);
    TEST_ID(XRealIP,TypeXRealIP);
    TEST_ID(XRequestedWith,TypeXRequestedWith);
    TEST_ID(XThriftProtocol,TypeXThriftProtocol);
    TEST_ID(XUACompatible,TypeXUACompatible);
    TEST_ID(XWapProfile,TypeXWapProfile);
    TEST_ID(XXSSProtection,TypeXXSSProtection);
    TEST_ID(SecWebSocketVersion,TypeSecWebSocketVersion);
    TEST_ID(SecWebSocketExtensions,TypeSecWebSocketExtensions);
    TEST_ID(SecWebSocketOrigin,TypeSecWebSocketOrigin);
    TEST_ID(SecWebSocketKey1,TypeSecWebSocketKey1);
    TEST_ID(SecWebSocketKey2,TypeSecWebSocketKey2);
    TEST_ID(SecWebSocketKey3,TypeSecWebSocketKey3);
    TEST_ID(SecWebSocketProtocol,TypeSecWebSocketProtocol);
    TEST_ID(ServerTiming,TypeServerTiming);
    TEST_ID(SourceMap,TypeSourceMap);
    TEST_ID(Digest,TypeDigest);
    //Transfer-Encoding type
    //TEST_ID(TransferChunked,TypeTransferChunked);

    //http connection
    //TEST_ID(ConnectionClose,TypeConnectionClose);

    //http2 authority
    TEST_ID(Authority,TypeAuthority);

    TEST_ID(ClearSiteData,TypeClearSiteData);
    TEST_ID(Version,TypeVersion);
    
 
    TEST_OK("[HttpHeader test FindId case100]");

}
