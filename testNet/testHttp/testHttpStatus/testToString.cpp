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

void testToString() {
  while(1) {
    if(!st(HttpStatus)::toString(st(HttpStatus)::Continue)->equals(createString("Continue"))) {
        auto t = st(HttpStatus)::toString(st(HttpStatus)::Continue);
        TEST_FAIL("HttpStatus toString case1,t is %s",t->toChars());
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::SwitchProtocls)->equals(createString("Switching Protocols"))) {
        TEST_FAIL("HttpStatus toString case2");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::Ok)->equals(createString("OK"))) {
        TEST_FAIL("HttpStatus toString case3");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::Created)->equals(createString("Created"))) {
        TEST_FAIL("HttpStatus toString case4");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::Accepted)->equals(createString("Accepted"))) {
        TEST_FAIL("HttpStatus toString case5");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::NonAuthoritativeInformation)->equals(createString("Non-Authoritative Information"))) {
        TEST_FAIL("HttpStatus toString case6");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::NoContent)->equals(createString("No Content"))) {
        TEST_FAIL("HttpStatus toString case7");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::ResetContent)->equals(createString("Reset Content"))) {
        TEST_FAIL("HttpStatus toString case8");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::PartialContent)->equals(createString("Partial Content"))) {
        TEST_FAIL("HttpStatus toString case9");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::MultipleChoices)->equals(createString("Multiple Choices"))) {
        TEST_FAIL("HttpStatus toString case10");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::MovedPermanently)->equals(createString("Moved Permanently"))) {
        TEST_FAIL("HttpStatus toString case11");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::Found)->equals(createString("Found"))) {
        TEST_FAIL("HttpStatus toString case12");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::SeeOther)->equals(createString("See Other"))) {
        TEST_FAIL("HttpStatus toString case13");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::NotModified)->equals(createString("Not Modified"))) {
        TEST_FAIL("HttpStatus toString case14");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::UseProxy)->equals(createString("Use Proxy"))) {
        TEST_FAIL("HttpStatus toString case15");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::TemporaryRedirect)->equals(createString("Temporary Redirect"))) {
        TEST_FAIL("HttpStatus toString case16");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::BadRequest)->equals(createString("Bad Request"))) {
        TEST_FAIL("HttpStatus toString case17");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::Unauthorized)->equals(createString("Unauthorized"))) {
        TEST_FAIL("HttpStatus toString case18");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::PaymentRequired)->equals(createString("Payment Required"))) {
        TEST_FAIL("HttpStatus toString case19");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::Forbidden)->equals(createString("Forbidden"))) {
        TEST_FAIL("HttpStatus toString case20");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::NotFound)->equals(createString("Not Found"))) {
        TEST_FAIL("HttpStatus toString case21");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::MethodNotAllowed)->equals(createString("Method Not Allowed"))) {
        TEST_FAIL("HttpStatus toString case22");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::NotAcceptable)->equals(createString("Not Acceptable"))) {
        TEST_FAIL("HttpStatus toString case23");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::ProxyAuthenticationRequired)->equals(createString("Proxy Authentication Required"))) {
        TEST_FAIL("HttpStatus toString case24");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::RequestTimeout)->equals(createString("Request Time-out"))) {
        TEST_FAIL("HttpStatus toString case25");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::Conflict)->equals(createString("Conflict"))) {
        TEST_FAIL("HttpStatus toString case26");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::Gone)->equals(createString("Gone"))) {
        TEST_FAIL("HttpStatus toString case27");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::LengthRequired)->equals(createString("Length Required"))) {
        TEST_FAIL("HttpStatus toString case28");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::PreconditionFailed)->equals(createString("Precondition Failed"))) {
        TEST_FAIL("HttpStatus toString case29");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::RequestEntityToLarge)->equals(createString("Request Entity Too Large"))) {
        TEST_FAIL("HttpStatus toString case30");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::RequestUriTooLarge)->equals(createString("Request-URI Too Large"))) {
        TEST_FAIL("HttpStatus toString case31");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::UnsupportedMediaType)->equals(createString("Unsupported Media Type"))) {
        TEST_FAIL("HttpStatus toString case32");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::RequestedRangeNotSatisfiable)->equals(createString("Requested range not satisfiable"))) {
        TEST_FAIL("HttpStatus toString case33");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::ExpectationFailed)->equals(createString("Expectation Failed"))) {
        TEST_FAIL("HttpStatus toString case34");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::InternalServerError)->equals(createString("Internal Server Error"))) {
        TEST_FAIL("HttpStatus toString case35");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::NotImplemented)->equals(createString("Not Implemented"))) {
        TEST_FAIL("HttpStatus toString case36");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::BadGateway)->equals(createString("Bad Gateway"))) {
        TEST_FAIL("HttpStatus toString case37");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::ServiceUnavailable)->equals(createString("Service Unavailable"))) {
        TEST_FAIL("HttpStatus toString case38");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::GatewayTimeout)->equals(createString("Gateway Time-out"))) {
        TEST_FAIL("HttpStatus toString case39");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::VersionNotSupported)->equals(createString("HTTP Version not supported"))) {
        TEST_FAIL("HttpStatus toString case40");
    }
    if(!st(HttpStatus)::toString(-1)->equals(createString("Unknown"))) {
        TEST_FAIL("HttpStatus toString case41");
    }
    break;
  }
  
  TEST_OK("HttpStatus toString case100");
}
