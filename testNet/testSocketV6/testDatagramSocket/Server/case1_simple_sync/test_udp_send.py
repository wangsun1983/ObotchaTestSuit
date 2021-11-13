import socket
import time

s = socket.socket(socket.AF_INET6, socket.SOCK_DGRAM)
s.connect(("::1",1222))

s.send(str("hello server").encode("utf-8"))

sendData = s.recv(1024)
print("i recv data")

count = 0

while (count < 50):
    s.send(sendData)
    time.sleep(0.01)
    count = count + 1

print("send complete")