#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

#include "Thread.hpp"
#include "Object.hpp"
#include "System.hpp"
#include "Barrier.hpp"
#include "ByteArrayReader.hpp"
#include <string.h>
#include "TestLog.hpp"
#include "TextLineReader.hpp"

using namespace obotcha;

/*
*java code
public class test {
	public static void main(String args[]) {
		//byte[] data = {21,-51,91,7}; // index = 0 val = 1 || index = 1 val = 0 
		// 使用ByteBuffer.wrap方法
		//int  v = ByteBuffer.wrap(data).order(ByteOrder.LITTLE_ENDIAN).getInt();
		//System.out.println(v);
		
		for(int i = 0;i < 1024*32;i++) {
			ByteBuffer buffer = ByteBuffer.allocate(4);
			buffer.order(ByteOrder.LITTLE_ENDIAN);
			buffer.putInt(i);
			
			
			byte[] list = buffer.array();
			System.out.print(i);
			System.out.print(" ");
			dump(list[0]);
			dump(list[1]);
			dump(list[2]);
			dump(list[3]);
			
			int  v2 = ByteBuffer.wrap(list).order(ByteOrder.LITTLE_ENDIAN).getInt();
			System.out.print(v2);
			System.out.println("");
			
		}
	}
	
	public static void dump(byte v) {
		if(v >= 0) {
			System.out.print(v);
		} else {
			System.out.print(v + 256);
		}
		System.out.print(" ");
	}
}
*/

void testReaderArrayIntToArray() {
    while(1) {
        File f = File::New("./testdata/little_endian1.txt");
        TextLineReader reader = TextLineReader::New(f);
        String str = nullptr;
        while((str = reader->readLine()) != nullptr) {
            ArrayList<String> items = str->split(" ");
            int num = items->get(0)->toBasicInt();
            ByteArray data = ByteArray::New(4);
            data[0] = items->get(1)->toBasicInt();
            data[1] = items->get(2)->toBasicInt();
            data[2] = items->get(3)->toBasicInt();
            data[3] = items->get(4)->toBasicInt();
            ByteArrayReader myreader = ByteArrayReader::New(data,st(IO)::Endianness::Little);
            int v = myreader->read<int>();
             // printf("%d,%d,%d,%d [%d,%d]",
             //     data[0],data[1],data[2],data[3],v,num);
            
            if(v != num) {
                TEST_FAIL("[TestByteArrayReader IntToArray case1],v is %d,num is %d",v,num);
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
            data[0] = items->get(1)->toBasicInt();
            data[1] = items->get(2)->toBasicInt();
            data[2] = items->get(3)->toBasicInt();
            data[3] = items->get(4)->toBasicInt();
            ByteArrayReader myreader = ByteArrayReader::New(data,st(IO)::Endianness::Big);
            int v = myreader->read<int>();
            if(v != num) {
                TEST_FAIL("[TestByteArrayReader IntToArray case2],v is %d,num is %d",v,num);
            }
        }
        break;
    }
    TEST_OK("[TestByteArrayReader IntToArray case100]");
}
