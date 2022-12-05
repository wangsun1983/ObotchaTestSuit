import socket
import time
import sys
import select
import os
import time

import sys
sys.path.append(r'../../../../../common')
from NetPort import getEnvPort

s = socket.socket(socket.AF_INET6, socket.SOCK_DGRAM)
addr = ("::1",getEnvPort())

buf=4096*32

with open('./tmp/testdata', 'r') as fp:
    while True:
        data = fp.read(1024*4)
        s.sendto(data.encode("utf-8"),addr)
        time.sleep(0.1)
        if not data:
            break;


print("Upload Donwloaded")