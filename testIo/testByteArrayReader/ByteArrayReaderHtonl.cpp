#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <arpa/inet.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Barrier.hpp"
#include "ByteArrayReader.hpp"
#include <string.h>
#include "TestLog.hpp"

using namespace obotcha;

void testByteArrayReaderHtonl() {
    while(1) {
        uint32_t value1 = 100;
        byte data1[sizeof(uint32_t)] = {0};
        memcpy(data1,&value1,sizeof(uint32_t));
        
        ByteArray array1 = ByteArray::New(data1,sizeof(uint32_t));
        ByteArrayReader littleReader1 = ByteArrayReader::New(array1);
        uint32_t checkLittleEndian = littleReader1->read<uint32_t>();
        if(value1 != checkLittleEndian) {
            TEST_FAIL("[TestByteArrayReader Htonl case1]");
        }
        
        ByteArrayReader bigReader2 = ByteArrayReader::New(array1,st(IO)::Endianness::Big);
        uint32_t checkBigEndian = bigReader2->read<int>();
        uint32_t checkBigEndian2 = htonl(value1);
        if(checkBigEndian != checkBigEndian2) {
            TEST_FAIL("[TestByteArrayReader Htonl case2]");
        }
        break;
    }
    
    while(1) {
        uint16_t value1 = 12;
        byte data1[sizeof(uint16_t)] = {0};
        memcpy(data1,&value1,sizeof(uint16_t));
        
        ByteArray array1 = ByteArray::New(data1,sizeof(uint16_t));
        ByteArrayReader littleReader1 = ByteArrayReader::New(array1);
        uint16_t checkLittleEndian = littleReader1->read<uint16_t>();
        if(value1 != checkLittleEndian) {
            TEST_FAIL("[TestByteArrayReader Htonl case3]");
        }
        
        ByteArrayReader bigReader2 = ByteArrayReader::New(array1,st(IO)::Endianness::Big);
        uint16_t checkBigEndian = bigReader2->read<uint16_t>();
        uint16_t checkBigEndian2 = htons(value1);
        if(checkBigEndian != checkBigEndian2) {
            TEST_FAIL("[TestByteArrayReader Htonl case4]");
        }
        break;
    }
    TEST_OK("[TestByteArrayReader Htonl case100]");
}
