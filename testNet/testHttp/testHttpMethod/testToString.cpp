#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Barrier.hpp"
#include "ByteArrayReader.hpp"
#include "HttpMethod.hpp"
#include "TestLog.hpp"

using namespace obotcha;

void testToString() {
    
    if(!st(HttpMethod)::toString(st(HttpMethod)::Delete)->equals(st(HttpMethod)::DeleteString)) {
        TEST_FAIL("testHttpMethod toString case1");
    }
    
    if(!st(HttpMethod)::toString(st(HttpMethod)::Get)->equals(st(HttpMethod)::GetString)) {
        TEST_FAIL("testHttpMethod toString case2");
    }
    
    if(!st(HttpMethod)::toString(st(HttpMethod)::Head)->equals(st(HttpMethod)::HeadString)) {
        TEST_FAIL("testHttpMethod toString case3");
    }
    
    if(!st(HttpMethod)::toString(st(HttpMethod)::Post)->equals(st(HttpMethod)::PostString)) {
        TEST_FAIL("testHttpMethod toString case4");
    }
    
    if(!st(HttpMethod)::toString(st(HttpMethod)::Put)->equals(st(HttpMethod)::PutString)) {
        TEST_FAIL("testHttpMethod toString case5");
    }
    
    if(!st(HttpMethod)::toString(st(HttpMethod)::Connect)->equals(st(HttpMethod)::ConnectString)) {
        TEST_FAIL("testHttpMethod toString case6");
    }
    
    if(!st(HttpMethod)::toString(st(HttpMethod)::Options)->equals(st(HttpMethod)::OptionsString)) {
        TEST_FAIL("testHttpMethod toString case7");
    }
    
    if(!st(HttpMethod)::toString(st(HttpMethod)::Trace)->equals(st(HttpMethod)::TraceString)) {
        TEST_FAIL("testHttpMethod toString case8");
    }
    
    if(!st(HttpMethod)::toString(st(HttpMethod)::Copy)->equals(st(HttpMethod)::CopyString)) {
        TEST_FAIL("testHttpMethod toString case9");
    }
    
    if(!st(HttpMethod)::toString(st(HttpMethod)::Lock)->equals(st(HttpMethod)::LockString)) {
        TEST_FAIL("testHttpMethod toString case10");
    }
    
    if(!st(HttpMethod)::toString(st(HttpMethod)::Mkcol)->equals(st(HttpMethod)::MkcolString)) {
        TEST_FAIL("testHttpMethod toString case11");
    }
    
    if(!st(HttpMethod)::toString(st(HttpMethod)::Move)->equals(st(HttpMethod)::MoveString)) {
        TEST_FAIL("testHttpMethod toString case12");
    }
    
    if(!st(HttpMethod)::toString(st(HttpMethod)::PropFind)->equals(st(HttpMethod)::PropFindString)) {
        TEST_FAIL("testHttpMethod toString case13");
    }
    
    if(!st(HttpMethod)::toString(st(HttpMethod)::PropPatch)->equals(st(HttpMethod)::PropPatchString)) {
        TEST_FAIL("testHttpMethod toString case14");
    }
    
    if(!st(HttpMethod)::toString(st(HttpMethod)::Move)->equals(st(HttpMethod)::MoveString)) {
        TEST_FAIL("testHttpMethod toString case15");
    }
    
    if(!st(HttpMethod)::toString(st(HttpMethod)::Unlock)->equals(st(HttpMethod)::UnlockString)) {
        TEST_FAIL("testHttpMethod toString case16");
    }
    
    if(!st(HttpMethod)::toString(st(HttpMethod)::Report)->equals(st(HttpMethod)::ReportString)) {
        TEST_FAIL("testHttpMethod toString case17");
    }
    
    if(!st(HttpMethod)::toString(st(HttpMethod)::MkActivity)->equals(st(HttpMethod)::MkActivityString)) {
        TEST_FAIL("testHttpMethod toString case18");
    }
    
    if(!st(HttpMethod)::toString(st(HttpMethod)::Checkout)->equals(st(HttpMethod)::CheckoutString)) {
        TEST_FAIL("testHttpMethod toString case19");
    }
    
    if(!st(HttpMethod)::toString(st(HttpMethod)::Merge)->equals(st(HttpMethod)::MergeString)) {
        TEST_FAIL("testHttpMethod toString case20");
    }
    
    if(!st(HttpMethod)::toString(st(HttpMethod)::Merge)->equals(st(HttpMethod)::MergeString)) {
        TEST_FAIL("testHttpMethod toString case21");
    }
    
    if(!st(HttpMethod)::toString(st(HttpMethod)::Msearch)->equals(st(HttpMethod)::MsearchString)) {
        TEST_FAIL("testHttpMethod toString case22");
    }
    
    if(!st(HttpMethod)::toString(st(HttpMethod)::Notify)->equals(st(HttpMethod)::NotifyString)) {
        TEST_FAIL("testHttpMethod toString case23");
    }
    
    if(!st(HttpMethod)::toString(st(HttpMethod)::Subscribe)->equals(st(HttpMethod)::SubscribeString)) {
        TEST_FAIL("testHttpMethod toString case24");
    }
    
    if(!st(HttpMethod)::toString(st(HttpMethod)::UnSubscribe)->equals(st(HttpMethod)::UnSubscribeString)) {
        TEST_FAIL("testHttpMethod toString case25");
    }
    
    if(!st(HttpMethod)::toString(st(HttpMethod)::Patch)->equals(st(HttpMethod)::PatchString)) {
        TEST_FAIL("testHttpMethod toString case26");
    }
    
    if(!st(HttpMethod)::toString(st(HttpMethod)::Purge)->equals(st(HttpMethod)::PurgeString)) {
        TEST_FAIL("testHttpMethod toString case27");
    }
    
    if(!st(HttpMethod)::toString(st(HttpMethod)::Link)->equals(st(HttpMethod)::LinkString)) {
        TEST_FAIL("testHttpMethod toString case28");
    }
    
    if(!st(HttpMethod)::toString(st(HttpMethod)::Search)->equals(st(HttpMethod)::SearchString)) {
        TEST_FAIL("testHttpMethod toString case29");
    }
    
    if(!st(HttpMethod)::toString(st(HttpMethod)::Unlink)->equals(st(HttpMethod)::UnlinkString)) {
        TEST_FAIL("testHttpMethod toString case30");
    }
    
    if(!st(HttpMethod)::toString(st(HttpMethod)::Source)->equals(st(HttpMethod)::SourceString)) {
        TEST_FAIL("testHttpMethod toString case31");
    }
    
    if(!st(HttpMethod)::toString(st(HttpMethod)::Pri)->equals(st(HttpMethod)::PriString)) {
        TEST_FAIL("testHttpMethod toString case32");
    }
    
    TEST_OK("testHttpMethod toString case100");
}
