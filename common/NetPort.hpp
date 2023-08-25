#ifndef __OBOTCHA_TEST_NET_PORT_HPP__
#define __OBOTCHA_TEST_NET_PORT_HPP__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "File.hpp"
#include "FileOutputStream.hpp"
#include "BufferedReader.hpp"

#define DEFAULT_PORT 4000
#define DEFAULT_PATH "/tmp/obotcha_test_suit_port.txt"

using namespace obotcha;


int getEnvPort() {
    File file = createFile(DEFAULT_PATH);
    if(file->exists()) {
        BufferedReader r = createBufferedReader(file);
        String value = r->readLine();
        return (value != nullptr)?value->toBasicInt():DEFAULT_PORT;
    }

    return DEFAULT_PORT;
}

void setEnvPort(int p) {
    if(p > 6000) {
        p = DEFAULT_PORT;
    }
    File file = createFile(DEFAULT_PATH);
    if(!file->exists()) {
        file->createNewFile();
    }
    FileOutputStream stream = createFileOutputStream(file);
    stream->open();
	auto data = createString(p)->toByteArray();
    stream->write(data);
    stream->flush();
    stream->close();
    
}

void resetEnvPort() {
    setEnvPort(DEFAULT_PORT);
}
#endif