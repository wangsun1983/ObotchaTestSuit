import sys
import select
import os
import time
import socket

sys.path.append(r'../../../../../common')
from NetPort import getEnvPort

host="127.0.0.1"

port = getEnvPort()

s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
s.connect(("127.0.0.1",getEnvPort()))

#print "cccc"
with open('./tmp/testdata', 'r') as fp:
    while True:
        data = fp.read(1024*4)
        s.send(data.encode("utf-8"))

        if not data:
            break;

        data1,addr2 = s.recvfrom(1024)

#print "Upload Donwloaded"