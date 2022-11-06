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

print "start"
path = "file"

f = open("file",'wb')
s.listen(5)
conn,address = s.accept()
conn.settimeout(5)

while True:
    #print "trace1"
    data = conn.recv(1024)
    f.write(data)
    f.flush();
    time.sleep(0.01)
    if not data:
        print "trace2"
        break

f.close()
s.close()
conn.close()

port = port + 1
setEnvPort(port)

print "File Donwloaded"