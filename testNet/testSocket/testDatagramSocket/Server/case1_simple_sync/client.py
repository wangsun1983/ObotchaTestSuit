import socket
import time

import sys
sys.path.append(r'../../../../../common')
from NetPort import getEnvPort

s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
port = getEnvPort()
print("port is ",port)

s.connect(("127.0.0.1",getEnvPort()))
print("connect")

s.send(str("hello server").encode("utf-8"))
print("connect send")

sendData = s.recv(1024).decode()

count = 0

while (count < 50):
    s.send(sendData.encode("utf-8"))
    time.sleep(0.01)
    count = count + 1

print("send complete")