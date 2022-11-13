import socket
import time
import sys
sys.path.append(r'../../../../../common')
from NetPort import getEnvPort

port = getEnvPort()

s = socket.socket(socket.AF_INET6, socket.SOCK_STREAM)
s.connect(("::1",port))
count = 0

while (count < 1024):
    time.sleep(0.10)
    s.send(str("hello server").encode("utf-8"))
    count = count + 1

print("send complete")