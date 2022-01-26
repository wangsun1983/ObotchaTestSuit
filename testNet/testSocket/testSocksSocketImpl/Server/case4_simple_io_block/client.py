import socket
import time

import sys
sys.path.append(r'../../../../../common')
from NetPort import getEnvPort

s = socket.socket()
s.connect(("127.0.0.1",getEnvPort()))

count = 0

while (count < 512):
    time.sleep(0.10)
    s.send(str("hello server").encode("utf-8"))
    count = count + 1

#print("send complete")