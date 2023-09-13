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

void testToId() {
    
    if(st(HttpMethod)::toId(st(HttpMethod)::DeleteString)!= st(HttpMethod)::Id::Delete) {
        TEST_FAIL("testHttpMethod toId case1");
    }
    
    if(st(HttpMethod)::toId(st(HttpMethod)::GetString) != st(HttpMethod)::Id::Get) {
        TEST_FAIL("testHttpMethod toId case2");
    }
    
    if(st(HttpMethod)::toId(st(HttpMethod)::HeadString)!=st(HttpMethod)::Id::Head) {
        TEST_FAIL("testHttpMethod toId case3");
    }
    
    if(st(HttpMethod)::toId(st(HttpMethod)::PostString)!=st(HttpMethod)::Id::Post) {
        TEST_FAIL("testHttpMethod toId case4");
    }
    
    if(st(HttpMethod)::toId(st(HttpMethod)::PutString)!=st(HttpMethod)::Id::Put) {
        TEST_FAIL("testHttpMethod toId case5");
    }
    
    if(st(HttpMethod)::toId(st(HttpMethod)::ConnectString)!=st(HttpMethod)::Id::Connect) {
        TEST_FAIL("testHttpMethod toId case6");
    }
    
    if(st(HttpMethod)::toId(st(HttpMethod)::OptionsString)!=st(HttpMethod)::Id::Options) {
        TEST_FAIL("testHttpMethod toId case7");
    }
    
    if(st(HttpMethod)::toId(st(HttpMethod)::TraceString)!=st(HttpMethod)::Id::Trace) {
        TEST_FAIL("testHttpMethod toId case8");
    }
    
    if(st(HttpMethod)::toId(st(HttpMethod)::CopyString)!=st(HttpMethod)::Id::Copy) {
        TEST_FAIL("testHttpMethod toId case9");
    }
    
    if(st(HttpMethod)::toId(st(HttpMethod)::LockString)!=st(HttpMethod)::Id::Lock) {
        TEST_FAIL("testHttpMethod toId case10");
    }
    
    if(st(HttpMethod)::toId(st(HttpMethod)::MkcolString)!=st(HttpMethod)::Id::Mkcol) {
        TEST_FAIL("testHttpMethod toId case11");
    }
    
    if(st(HttpMethod)::toId(st(HttpMethod)::MoveString)!=st(HttpMethod)::Id::Move) {
        TEST_FAIL("testHttpMethod toId case12");
    }
    
    if(st(HttpMethod)::toId(st(HttpMethod)::PropFindString)!=st(HttpMethod)::Id::PropFind) {
        TEST_FAIL("testHttpMethod toId case13");
    }
    
    if(st(HttpMethod)::toId(st(HttpMethod)::PropPatchString)!=st(HttpMethod)::Id::PropPatch) {
        TEST_FAIL("testHttpMethod toId case14");
    }
    
    if(st(HttpMethod)::toId(st(HttpMethod)::MoveString)!=st(HttpMethod)::Id::Move) {
        TEST_FAIL("testHttpMethod toId case15");
    }
    
    if(st(HttpMethod)::toId(st(HttpMethod)::UnlockString)!=st(HttpMethod)::Id::Unlock) {
        TEST_FAIL("testHttpMethod toId case16");
    }
    
    if(st(HttpMethod)::toId(st(HttpMethod)::ReportString)!=st(HttpMethod)::Id::Report) {
        TEST_FAIL("testHttpMethod toId case17");
    }
    
    if(st(HttpMethod)::toId(st(HttpMethod)::MkActivityString)!=st(HttpMethod)::Id::MkActivity) {
        TEST_FAIL("testHttpMethod toId case18");
    }
    
    if(st(HttpMethod)::toId(st(HttpMethod)::CheckoutString)!=st(HttpMethod)::Id::Checkout) {
        TEST_FAIL("testHttpMethod toId case19");
    }
    
    if(st(HttpMethod)::toId(st(HttpMethod)::MergeString)!=st(HttpMethod)::Id::Merge) {
        TEST_FAIL("testHttpMethod toId case20");
    }
    
    if(st(HttpMethod)::toId(st(HttpMethod)::MergeString)!=st(HttpMethod)::Id::Merge) {
        TEST_FAIL("testHttpMethod toId case21");
    }
    
    if(st(HttpMethod)::toId(st(HttpMethod)::MsearchString)!=st(HttpMethod)::Id::Msearch) {
        TEST_FAIL("testHttpMethod toId case22");
    }
    
    if(st(HttpMethod)::toId(st(HttpMethod)::NotifyString)!=st(HttpMethod)::Id::Notify) {
        TEST_FAIL("testHttpMethod toId case23");
    }
    
    if(st(HttpMethod)::toId(st(HttpMethod)::SubscribeString)!=st(HttpMethod)::Id::Subscribe) {
        TEST_FAIL("testHttpMethod toId case24");
    }
    
    if(st(HttpMethod)::toId(st(HttpMethod)::UnSubscribeString)!=st(HttpMethod)::Id::UnSubscribe) {
        TEST_FAIL("testHttpMethod toId case25");
    }
    
    if(st(HttpMethod)::toId(st(HttpMethod)::PatchString)!=st(HttpMethod)::Id::Patch) {
        TEST_FAIL("testHttpMethod toId case26");
    }
    
    if(st(HttpMethod)::toId(st(HttpMethod)::PurgeString)!=st(HttpMethod)::Id::Purge) {
        TEST_FAIL("testHttpMethod toId case27");
    }
    
    if(st(HttpMethod)::toId(st(HttpMethod)::LinkString)!=st(HttpMethod)::Id::Link) {
        TEST_FAIL("testHttpMethod toId case28");
    }
    
    if(st(HttpMethod)::toId(st(HttpMethod)::SearchString)!=st(HttpMethod)::Id::Search) {
        TEST_FAIL("testHttpMethod toId case29");
    }
    
    if(st(HttpMethod)::toId(st(HttpMethod)::UnlinkString)!=st(HttpMethod)::Id::Unlink) {
        TEST_FAIL("testHttpMethod toId case30");
    }
    
    if(st(HttpMethod)::toId(st(HttpMethod)::SourceString)!=st(HttpMethod)::Id::Source) {
        TEST_FAIL("testHttpMethod toId case31");
    }
    
    if(st(HttpMethod)::toId(st(HttpMethod)::PriString)!=st(HttpMethod)::Id::Pri) {
        TEST_FAIL("testHttpMethod toId case32");
    }
    
    TEST_OK("testHttpMethod toId case100");
}
