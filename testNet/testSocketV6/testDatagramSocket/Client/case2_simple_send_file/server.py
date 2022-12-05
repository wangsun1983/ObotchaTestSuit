import socket

import sys
import select
import os

import sys
sys.path.append(r'../../../../../common')
from NetPort import getEnvPort

host="::1"

port = getEnvPort()

s = socket.socket(socket.AF_INET6, socket.SOCK_DGRAM)
s.bind((host,port))
addr = (host,port)

buf=4096*32
#print "start"
path = "file"


data,addr = s.recvfrom(buf)
f = open("./tmp/file",'wb')

try:

    while(data):
        f.write(data)
        s.sendto(str("hello client").encode("utf-8"),addr)
        f.flush()
        s.settimeout(1)
        data,addr = s.recvfrom(buf)


except timeout:
    f.close()
    s.close()

port = port + 1
setEnvPort(port)

#print "File Donwloaded"