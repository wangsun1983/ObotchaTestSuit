extern int normaltest();
extern int looptest();
extern int testBarrierFunc();
extern void testBarrierRelease();

int main() {
    testBarrierRelease();
    normaltest();
    looptest();
    testBarrierFunc();
    return 0;
}
