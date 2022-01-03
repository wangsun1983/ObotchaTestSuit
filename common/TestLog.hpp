#ifndef __OBOTCHA_TEST_LOG_HPP__
#define __OBOTCHA_TEST_LOG_HPP__

#define TEST_OK(X) \
    printf("%-128s :\033[32m%s \033[37m\n",X,"[OK]")

#define TEST_FAIL(X) \
    printf("%-128s :\033[31m%s \033[37m\n",X,"[FAIL]")


#endif