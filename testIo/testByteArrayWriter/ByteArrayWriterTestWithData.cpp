#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Barrier.hpp"
#include "ByteArrayReader.hpp"
#include "ByteArrayWriter.hpp"
#include <string.h>
#include "TestLog.hpp"
#include "File.hpp"
#include "TextLineReader.hpp"

using namespace obotcha;


void testWithData() {
    while(1) {
        File f = File::New("./testdata/little_endian1.txt");
        TextLineReader reader = TextLineReader::New(f);
        String str = nullptr;
        while((str = reader->readLine()) != nullptr) {
            ArrayList<String> items = str->split(" ");
            int num = items->get(0)->toBasicInt();
            ByteArray data = ByteArray::New(4);
            ByteArrayWriter writer = ByteArrayWriter::New(data,st(IO)::Endianness::Little);
            writer->write(num);
            
            if(data[0] != items->get(1)->toBasicInt()
                ||data[1] != items->get(2)->toBasicInt()
                ||data[2] != items->get(3)->toBasicInt()
                ||data[3] != items->get(4)->toBasicInt()){
                
                TEST_FAIL("[TestByteArrayWriter testWithData case1]");    
            }
        }
        break;
    }
    
    while(1) {
        File f = File::New("./testdata/big_endian1.txt");
        TextLineReader reader = TextLineReader::New(f);
        String str = nullptr;
        while((str = reader->readLine()) != nullptr) {
            ArrayList<String> items = str->split(" ");
            int num = items->get(0)->toBasicInt();
            ByteArray data = ByteArray::New(4);
            ByteArrayWriter writer = ByteArrayWriter::New(data,st(IO)::Endianness::Big);
            writer->write(num);
            
            if(data[0] != items->get(1)->toBasicInt()
                ||data[1] != items->get(2)->toBasicInt()
                ||data[2] != items->get(3)->toBasicInt()
                ||data[3] != items->get(4)->toBasicInt()){
                TEST_FAIL("[TestByteArrayWriter testWithData case2]");    
            }
        }
        break;
    }
    
    TEST_OK("[TestByteArrayWriter testWithData case100]");
}
