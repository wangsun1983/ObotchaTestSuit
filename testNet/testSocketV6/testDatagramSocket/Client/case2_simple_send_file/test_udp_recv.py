import socket

import sys
import select
import os

host="::1"

port = 1234

s = socket.socket(socket.AF_INET6, socket.SOCK_DGRAM)
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

print "File Donwloaded"