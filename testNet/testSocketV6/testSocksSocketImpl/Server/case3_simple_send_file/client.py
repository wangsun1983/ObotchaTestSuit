from socket import *
import sys
import select
import os
import socket

import sys
sys.path.append(r'../../../../../common')
from NetPort import getEnvPort

host="127.0.0.1"

port = getEnvPort();

s = socket.socket(socket.AF_INET6, socket.SOCK_STREAM)
s.connect(("::1",port))

print("cccc")
with open('./tmp/testdata', 'r') as fp:
    while True:
        data = fp.read(1024*4)
        s.send(data)
        
        if not data:
            break;

        data1 = s.recv(1024)


print("Upload Donwloaded")