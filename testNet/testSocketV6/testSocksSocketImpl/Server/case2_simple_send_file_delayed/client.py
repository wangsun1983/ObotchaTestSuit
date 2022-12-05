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

port = getEnvPort()

s = socket.socket(socket.AF_INET6, socket.SOCK_STREAM)
s.connect(("::1",port))

buf=4096*32

with open('./tmp/testdata', 'r') as fp:
    while True:
        data = fp.read(1024*4)
        s.send(data.encode("utf-8"));
        time.sleep(0.1)
        if not data:
            break;


print("Upload Donwloaded")