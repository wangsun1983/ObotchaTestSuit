from socket import *
import sys
import select
import os
import socket
import time
import socket
import sys

sys.path.append(r'../../../../../common')
from NetPort import getEnvPort
from NetPort import setEnvPort

s = socket.socket(socket.AF_INET,socket.SOCK_STREAM) 
port = getEnvPort()

s.bind(("127.0.0.1", port))

path = "file"

f = open("./tmp/file",'wb')
s.listen(5)
conn,address = s.accept()
conn.settimeout(15)

while True:
    data = conn.recv(1024)
    print("receive data!!!")
    f.write(data)
    f.flush();
    time.sleep(0.01)
    if not data:
        print("receive no data!!!")
        break

f.close()
s.close()
conn.close()

port = port + 1
setEnvPort(port)
