import socket
import time

import sys
sys.path.append(r'../../../../../common')
from NetPort import getEnvPort

s = socket.socket(socket.AF_INET6, socket.SOCK_DGRAM)
#s.connect(("::1",getEnvPort()))

print("port is ",getEnvPort())

addr = ("::1",getEnvPort())

s.sendto(str("hello server").encode("utf-8"),addr)

sendData,addr2 = s.recvfrom(1024)
print("addr2 is ",addr2)

count = 0

while (count < 50):
    #s.send(sendData)
    s.sendto(sendData,addr)
    time.sleep(0.01)
    count = count + 1

#print("send complete")