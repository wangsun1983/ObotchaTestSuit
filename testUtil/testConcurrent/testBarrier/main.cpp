extern int normaltest();
extern int looptest();
extern int testBarrierFunc();
extern void testBarrierRelease();
extern void testBarrierAlreadyRelease();
extern void testBarrierWaitTimeout();

int main() {
	testBarrierWaitTimeout();
	testBarrierAlreadyRelease();
    testBarrierRelease();
    normaltest();
    looptest();
    testBarrierFunc();
    return 0;
}
