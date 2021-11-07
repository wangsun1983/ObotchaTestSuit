import socket
import time

s = socket.socket(socket.AF_INET6, socket.SOCK_STREAM)
s.connect(("::1",1222))
count = 0

while (count < 1024):
    time.sleep(0.10)
    s.send(str("hello server").encode("utf-8"))
    count = count + 1

print("send complete")