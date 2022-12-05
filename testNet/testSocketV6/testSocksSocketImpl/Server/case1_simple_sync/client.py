import socket
import time
import sys
sys.path.append(r'../../../../../common')
from NetPort import getEnvPort

#https://www.jb51.net/article/136920.htm
s = socket.socket(socket.AF_INET6, socket.SOCK_STREAM)

port = getEnvPort()

s.connect(("::1",port))
#print "123"
s.send(str("hello server").encode("utf-8"))

sendData = s.recv(1024)
#print "222"
count = 0

while (count < 50):
    s.send(sendData)
    time.sleep(0.01)
    count = count + 1

#print("send complete")