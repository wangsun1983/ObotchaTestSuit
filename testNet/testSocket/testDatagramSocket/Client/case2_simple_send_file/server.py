from socket import *
import sys
import select
import os

import sys
sys.path.append(r'../../../../../common')
from NetPort import getEnvPort
from NetPort import setEnvPort

host="127.0.0.1"

port = getEnvPort()

s = socket(AF_INET,SOCK_DGRAM)
s.bind((host,port))
addr = (host,port)

buf=4096*32
print "start"
path = "file"

f = open("file",'wb')
data,addr = s.recvfrom(buf)

try:

    while(data):
        f.write(data)
        s.sendto(str("hello client").encode("utf-8"),addr)

        s.settimeout(1)
        data,addr = s.recvfrom(buf)


except timeout:
    f.close()
    s.close()

port = port + 1
setEnvPort(port)

print "File Donwloaded"