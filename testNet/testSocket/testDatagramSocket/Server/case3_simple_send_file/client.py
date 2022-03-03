from socket import *
import sys
import select
import os
import time

import sys
sys.path.append(r'../../../../../common')
from NetPort import getEnvPort

host="127.0.0.1"

port = getEnvPort()

s = socket(AF_INET,SOCK_DGRAM)
addr = (host,port)

buf=4096*32
f = open("file",'wb')

print "cccc"
with open('data', 'r') as fp:
    while True:
        data = fp.read(1024*4)
        s.sendto(data,addr)

        if not data:
            break;

        data1,addr2 = s.recvfrom(buf)

print "Upload Donwloaded"