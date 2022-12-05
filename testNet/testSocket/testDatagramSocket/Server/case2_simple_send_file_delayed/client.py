import sys
import select
import os
import time
import socket

import sys
sys.path.append(r'../../../../../common')
from NetPort import getEnvPort

host="127.0.0.1"

port = getEnvPort()

s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
s.connect(("127.0.0.1",getEnvPort()))
print("port is ",port)

with open('./tmp/testdata', 'r') as fp:
    while True:
        data = fp.read(1024*4)
        s.send(data.encode("utf-8"))
        time.sleep(0.1)
        if not data:
            break;


#print "Upload Donwloaded"