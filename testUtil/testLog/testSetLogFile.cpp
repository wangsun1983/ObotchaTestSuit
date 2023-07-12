#include <iostream>
#include <stdio.h>
#include <unistd.h>

#include "Thread.hpp"
#include "ArrayList.hpp"
#include "Integer.hpp"
#include "String.hpp"
#include "LruCache.hpp"
#include "TestLog.hpp"
#include "Log.hpp"
#include "ForEveryOne.hpp"
#include "FileInputStream.hpp"

using namespace obotcha;

void testSetLogFile() {
    while(1) {
        st(Log)::getInstance()->startSetting()
                              ->setInfoLogPath("./tmp","info_log_")
                              ->setWarningLogPath("./tmp","warning_log_")
                              ->setErrorLogPath("./tmp","error_log_")
                              ->setFatalLogPath("./tmp","fatal_log_")
                              ->completeSetting();
        LOG(ERROR)<<"error log";
        LOG(WARNING)<<"warning log";
        //LOG(FATAL)<<"error log";
        LOG(INFO)<<"info log";
        
        usleep(1000*1000);
        sync();
        st(Log)::getInstance()->startSetting()
                              ->setInfoLogPath("./tmp","info2_log_")
                              ->setWarningLogPath("./tmp","warning2_log_")
                              ->setErrorLogPath("./tmp","error2_log_")
                              ->setFatalLogPath("./tmp","fatal2_log_")
                              ->completeSetting();
        LOG(ERROR)<<"error2 log";
        LOG(WARNING)<<"warning2 log";
        //LOG(FATAL)<<"error log";
        LOG(INFO)<<"info2 log";
        usleep(1000*1000);
        sync();
        st(Log)::getInstance()->close();
        //check whether there contains info log
        {
            bool found = false;
            File f = createFile("./tmp");
            auto files = f->listFiles();
            ForEveryOne(file,files) {
                if(file->getName()->contains("info")) {
                    auto stream = createFileInputStream(file);
                    stream->open();
                    auto content = stream->readAll()->toString();
                    if(content->contains("info log")) {
                        found = true;
                    }
                    stream->close();
                }
            }
            
            if(!found) {
                TEST_FAIL("test Log case1");
            }
        }
        
        //check whether there contains error log
        {
            bool found = false;
            File f = createFile("./tmp");
            auto files = f->listFiles();
            ForEveryOne(file,files) {
                if(file->getName()->contains("error")) {
                    auto stream = createFileInputStream(file);
                    stream->open();
                    auto content = stream->readAll()->toString();
                    if(content->contains("error log")) {
                        found = true;
                    }
                }
            }
            
            if(!found) {
                TEST_FAIL("test Log case2");
            }
        }
        
        //check whether there contains warning log
        {
            bool found = false;
            File f = createFile("./tmp");
            auto files = f->listFiles();
            ForEveryOne(file,files) {
                if(file->getName()->contains("warning")) {
                    auto stream = createFileInputStream(file);
                    stream->open();
                    auto content = stream->readAll()->toString();
                    if(content->contains("warning log")) {
                        found = true;
                    }
                }
            }
            
            if(!found) {
                TEST_FAIL("test Log case3");
            }
        }
        
        //-------2-----
        //check whether there contains info log
        {
            bool found = false;
            File f = createFile("./tmp");
            auto files = f->listFiles();
            ForEveryOne(file,files) {
                if(file->getName()->contains("info2")) {
                    auto stream = createFileInputStream(file);
                    stream->open();
                    printf("start read \n");
                    auto content = stream->readAll()->toString();
                    printf("file name is %s \n",file->getName()->toChars());
                    printf("content is %s \n",content->toChars());
                    
                    if(content->contains("info2 log")) {
                        found = true;
                    }
                }
            }
            
            if(!found) {
                TEST_FAIL("test Log case4");
            }
        }
        
        //check whether there contains error log
        {
            bool found = false;
            File f = createFile("./tmp");
            auto files = f->listFiles();
            ForEveryOne(file,files) {
                if(file->getName()->contains("error2")) {
                    auto stream = createFileInputStream(file);
                    stream->open();
                    auto content = stream->readAll()->toString();
                    if(content->contains("error2 log")) {
                        found = true;
                    }
                }
            }
            
            if(!found) {
                TEST_FAIL("test Log case5");
            }
        }
        
        //check whether there contains warning log
        {
            bool found = false;
            File f = createFile("./tmp");
            auto files = f->listFiles();
            ForEveryOne(file,files) {
                if(file->getName()->contains("warning2")) {
                    auto stream = createFileInputStream(file);
                    stream->open();
                    auto content = stream->readAll()->toString();
                    if(content->contains("warning2 log")) {
                        found = true;
                    }
                }
            }
            
            if(!found) {
                TEST_FAIL("test Log case6");
            }
        }
        break;
    }
    
    TEST_OK("test Log case100");
}
