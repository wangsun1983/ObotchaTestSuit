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
    if(!st(HttpStatus)::toString(st(HttpStatus)::Continue)->equals(String::New("Continue"))) {
        auto t = st(HttpStatus)::toString(st(HttpStatus)::Continue);
        TEST_FAIL("HttpStatus toString case1,t is %s",t->toChars());
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::SwitchProtocls)->equals(String::New("Switching Protocols"))) {
        TEST_FAIL("HttpStatus toString case2");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::Ok)->equals(String::New("OK"))) {
        TEST_FAIL("HttpStatus toString case3");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::Created)->equals(String::New("Created"))) {
        TEST_FAIL("HttpStatus toString case4");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::Accepted)->equals(String::New("Accepted"))) {
        TEST_FAIL("HttpStatus toString case5");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::NonAuthoritativeInformation)->equals(String::New("Non-Authoritative Information"))) {
        TEST_FAIL("HttpStatus toString case6");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::NoContent)->equals(String::New("No Content"))) {
        TEST_FAIL("HttpStatus toString case7");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::ResetContent)->equals(String::New("Reset Content"))) {
        TEST_FAIL("HttpStatus toString case8");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::PartialContent)->equals(String::New("Partial Content"))) {
        TEST_FAIL("HttpStatus toString case9");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::MultipleChoices)->equals(String::New("Multiple Choices"))) {
        TEST_FAIL("HttpStatus toString case10");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::MovedPermanently)->equals(String::New("Moved Permanently"))) {
        TEST_FAIL("HttpStatus toString case11");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::Found)->equals(String::New("Found"))) {
        TEST_FAIL("HttpStatus toString case12");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::SeeOther)->equals(String::New("See Other"))) {
        TEST_FAIL("HttpStatus toString case13");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::NotModified)->equals(String::New("Not Modified"))) {
        TEST_FAIL("HttpStatus toString case14");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::UseProxy)->equals(String::New("Use Proxy"))) {
        TEST_FAIL("HttpStatus toString case15");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::TemporaryRedirect)->equals(String::New("Temporary Redirect"))) {
        TEST_FAIL("HttpStatus toString case16");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::BadRequest)->equals(String::New("Bad Request"))) {
        TEST_FAIL("HttpStatus toString case17");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::Unauthorized)->equals(String::New("Unauthorized"))) {
        TEST_FAIL("HttpStatus toString case18");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::PaymentRequired)->equals(String::New("Payment Required"))) {
        TEST_FAIL("HttpStatus toString case19");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::Forbidden)->equals(String::New("Forbidden"))) {
        TEST_FAIL("HttpStatus toString case20");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::NotFound)->equals(String::New("Not Found"))) {
        TEST_FAIL("HttpStatus toString case21");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::MethodNotAllowed)->equals(String::New("Method Not Allowed"))) {
        TEST_FAIL("HttpStatus toString case22");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::NotAcceptable)->equals(String::New("Not Acceptable"))) {
        TEST_FAIL("HttpStatus toString case23");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::ProxyAuthenticationRequired)->equals(String::New("Proxy Authentication Required"))) {
        TEST_FAIL("HttpStatus toString case24");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::RequestTimeout)->equals(String::New("Request Time-out"))) {
        TEST_FAIL("HttpStatus toString case25");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::Conflict)->equals(String::New("Conflict"))) {
        TEST_FAIL("HttpStatus toString case26");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::Gone)->equals(String::New("Gone"))) {
        TEST_FAIL("HttpStatus toString case27");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::LengthRequired)->equals(String::New("Length Required"))) {
        TEST_FAIL("HttpStatus toString case28");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::PreconditionFailed)->equals(String::New("Precondition Failed"))) {
        TEST_FAIL("HttpStatus toString case29");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::RequestEntityToLarge)->equals(String::New("Request Entity Too Large"))) {
        TEST_FAIL("HttpStatus toString case30");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::RequestUriTooLarge)->equals(String::New("Request-URI Too Large"))) {
        TEST_FAIL("HttpStatus toString case31");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::UnsupportedMediaType)->equals(String::New("Unsupported Media Type"))) {
        TEST_FAIL("HttpStatus toString case32");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::RequestedRangeNotSatisfiable)->equals(String::New("Requested range not satisfiable"))) {
        TEST_FAIL("HttpStatus toString case33");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::ExpectationFailed)->equals(String::New("Expectation Failed"))) {
        TEST_FAIL("HttpStatus toString case34");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::InternalServerError)->equals(String::New("Internal Server Error"))) {
        TEST_FAIL("HttpStatus toString case35");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::NotImplemented)->equals(String::New("Not Implemented"))) {
        TEST_FAIL("HttpStatus toString case36");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::BadGateway)->equals(String::New("Bad Gateway"))) {
        TEST_FAIL("HttpStatus toString case37");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::ServiceUnavailable)->equals(String::New("Service Unavailable"))) {
        TEST_FAIL("HttpStatus toString case38");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::GatewayTimeout)->equals(String::New("Gateway Time-out"))) {
        TEST_FAIL("HttpStatus toString case39");
    }
    if(!st(HttpStatus)::toString(st(HttpStatus)::VersionNotSupported)->equals(String::New("HTTP Version not supported"))) {
        TEST_FAIL("HttpStatus toString case40");
    }
    if(!st(HttpStatus)::toString(-1)->equals(String::New("Unknown"))) {
        TEST_FAIL("HttpStatus toString case41");
    }
    break;
  }
  
  TEST_OK("HttpStatus toString case100");
}
