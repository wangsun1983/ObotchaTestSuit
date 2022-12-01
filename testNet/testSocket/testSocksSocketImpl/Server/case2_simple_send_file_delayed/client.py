from socket import *
import sys
import select
import os
import time
import socket

import sys
sys.path.append(r'../../../../../common')
from NetPort import getEnvPort

host="127.0.0.1"

port = getEnvPort();

s = socket.socket()
s.connect(("127.0.0.1",port))

buf=4096*32
f = open("./tmp/testdata",'rb')

while True:
    data = f.read(1024*4)
    s.sendall(data)
    time.sleep(0.1)
    if data==b"":
        break;


#print "Upload Donwloaded"