import socket
import time

import sys
sys.path.append(r'../../../../../common')
from NetPort import getEnvPort

s = socket.socket()

s.connect(("127.0.0.1",getEnvPort()))

s.send(str("hello server").encode("utf-8"))

sendData = s.recv(1024).decode()

count = 0

while (count < 50):
    s.send(sendData)
    time.sleep(0.01)
    count = count + 1

#print("send complete")