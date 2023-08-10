#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "HttpMime.hpp"
#include "HttpHeaderSourceMap.hpp"
#include "Math.hpp"
#include "TestLog.hpp"
#include "ForEveryOne.hpp"
#include "HttpStatus.hpp"

using namespace obotcha;

void testToId() {
  while(1) {
    if(st(HttpStatus)::toId("Continue") != st(HttpStatus)::Continue) {
        auto id = st(HttpStatus)::toId("Continue");
        TEST_FAIL("HttpStatus toId case1,id is %d",id);
    }
    if(st(HttpStatus)::toId("Switching Protocols") != st(HttpStatus)::SwitchProtocls) {
        auto id = st(HttpStatus)::toId("Switching Protocols");
        TEST_FAIL("HttpStatus toId case2,id is %d",id);
    }
    if(st(HttpStatus)::toId("OK") != st(HttpStatus)::Ok) {
        TEST_FAIL("HttpStatus toId case3");
    }
    if(st(HttpStatus)::toId("Created") != st(HttpStatus)::Created) {
        TEST_FAIL("HttpStatus toId case4");
    }
    if(st(HttpStatus)::toId("Accepted") != st(HttpStatus)::Accepted) {
        TEST_FAIL("HttpStatus toId case5");
    }
    if(st(HttpStatus)::toId("Non-Authoritative Information") 
        != st(HttpStatus)::NonAuthoritativeInformation) {
        TEST_FAIL("HttpStatus toId case6");
    }
    if(st(HttpStatus)::toId("No Content") != st(HttpStatus)::NoContent) {
        TEST_FAIL("HttpStatus toId case7");
    }
    if(st(HttpStatus)::toId("Reset Content") != st(HttpStatus)::ResetContent) {
        TEST_FAIL("HttpStatus toId case8");
    }
    if(st(HttpStatus)::toId("Partial Content") != st(HttpStatus)::PartialContent) {
        TEST_FAIL("HttpStatus toId case9");
    }
    if(st(HttpStatus)::toId("Multiple Choices") != st(HttpStatus)::MultipleChoices) {
        TEST_FAIL("HttpStatus toId case10");
    }
    if(st(HttpStatus)::toId("Moved Permanently") != st(HttpStatus)::MovedPermanently) {
        TEST_FAIL("HttpStatus toId case11");
    }
    if(st(HttpStatus)::toId("Found") != st(HttpStatus)::Found) {
        TEST_FAIL("HttpStatus toId case12");
    }
    if(st(HttpStatus)::toId("See Other") != st(HttpStatus)::SeeOther) {
        TEST_FAIL("HttpStatus toId case13");
    }
    if(st(HttpStatus)::toId("Not Modified") != st(HttpStatus)::NotModified) {
        TEST_FAIL("HttpStatus toId case14");
    }
    if(st(HttpStatus)::toId("Use Proxy") != st(HttpStatus)::UseProxy) {
        TEST_FAIL("HttpStatus toId case15");
    }
    if(st(HttpStatus)::toId("Temporary Redirect") != st(HttpStatus)::TemporaryRedirect) {
        TEST_FAIL("HttpStatus toId case16");
    }
    if(st(HttpStatus)::toId("Bad Request") != st(HttpStatus)::BadRequest) {
        TEST_FAIL("HttpStatus toId case17");
    }
    if(st(HttpStatus)::toId("Unauthorized") != st(HttpStatus)::Unauthorized) {
        TEST_FAIL("HttpStatus toId case18");
    }
    if(st(HttpStatus)::toId("Payment Required") != st(HttpStatus)::PaymentRequired) {
        TEST_FAIL("HttpStatus toId case19");
    }
    if(st(HttpStatus)::toId("Forbidden") != st(HttpStatus)::Forbidden) {
        TEST_FAIL("HttpStatus toId case20");
    }
    if(st(HttpStatus)::toId("Not Found") != st(HttpStatus)::NotFound) {
        TEST_FAIL("HttpStatus toId case21");
    }
    if(st(HttpStatus)::toId("Method Not Allowed") != st(HttpStatus)::MethodNotAllowed) {
        TEST_FAIL("HttpStatus toId case22");
    }
    if(st(HttpStatus)::toId("Not Acceptable") != st(HttpStatus)::NotAcceptable) {
        TEST_FAIL("HttpStatus toId case23");
    }
    if(st(HttpStatus)::toId("Proxy Authentication Required") != st(HttpStatus)::ProxyAuthenticationRequired) {
        TEST_FAIL("HttpStatus toId case24");
    }
    if(st(HttpStatus)::toId("Request Time-out") != st(HttpStatus)::RequestTimeout) {
        TEST_FAIL("HttpStatus toId case25");
    }
    if(st(HttpStatus)::toId("Conflict") != st(HttpStatus)::Conflict) {
        TEST_FAIL("HttpStatus toId case26");
    }
    if(st(HttpStatus)::toId("Gone") != st(HttpStatus)::Gone) {
        TEST_FAIL("HttpStatus toId case27");
    }
    if(st(HttpStatus)::toId("Length Required") != st(HttpStatus)::LengthRequired) {
        TEST_FAIL("HttpStatus toId case28");
    }
    if(st(HttpStatus)::toId("Precondition Failed") != st(HttpStatus)::PreconditionFailed) {
        TEST_FAIL("HttpStatus toId case29");
    }
    if(st(HttpStatus)::toId("Request Entity Too Large") != st(HttpStatus)::RequestEntityToLarge) {
        TEST_FAIL("HttpStatus toId case30");
    }
    if(st(HttpStatus)::toId("Request-URI Too Large") != st(HttpStatus)::RequestUriTooLarge) {
        TEST_FAIL("HttpStatus toId case31");
    }
    if(st(HttpStatus)::toId("Unsupported Media Type") != st(HttpStatus)::UnsupportedMediaType) {
        TEST_FAIL("HttpStatus toId case32");
    }
    if(st(HttpStatus)::toId("Requested range not satisfiable") != st(HttpStatus)::RequestedRangeNotSatisfiable) {
        TEST_FAIL("HttpStatus toId case33");
    }
    if(st(HttpStatus)::toId("Expectation Failed") != st(HttpStatus)::ExpectationFailed) {
        TEST_FAIL("HttpStatus toId case34");
    }
    if(st(HttpStatus)::toId("Internal Server Error") != st(HttpStatus)::InternalServerError) {
        TEST_FAIL("HttpStatus toId case35");
    }
    if(st(HttpStatus)::toId("Not Implemented") != st(HttpStatus)::NotImplemented) {
        TEST_FAIL("HttpStatus toId case36");
    }
    if(st(HttpStatus)::toId("Bad Gateway") != st(HttpStatus)::BadGateway) {
        TEST_FAIL("HttpStatus toId case37");
    }
    if(st(HttpStatus)::toId("Service Unavailable") != st(HttpStatus)::ServiceUnavailable) {
        TEST_FAIL("HttpStatus toId case38");
    }
    if(st(HttpStatus)::toId("Gateway Time-out") != st(HttpStatus)::GatewayTimeout) {
        TEST_FAIL("HttpStatus toId case39");
    }
    if(st(HttpStatus)::toId("HTTP Version not supported") != st(HttpStatus)::VersionNotSupported) {
        TEST_FAIL("HttpStatus toId case40");
    }
    if(st(HttpStatus)::toId("Unknown") != -1) {
        TEST_FAIL("HttpStatus toId case41");
    }
    break;
  }
  
  TEST_OK("HttpStatus toId case100");
}
