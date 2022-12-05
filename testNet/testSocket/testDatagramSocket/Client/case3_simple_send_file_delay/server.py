from socket import *
import sys
import select

import sys
sys.path.append(r'../../../../../common')
from NetPort import getEnvPort
from NetPort import setEnvPort

host="127.0.0.1"

port = getEnvPort()

s = socket(AF_INET,SOCK_DGRAM)
s.bind((host,port))
addr = (host,port)

buf=4096
#print "start"
data,addr = s.recvfrom(buf)
f = open("./tmp/file",'wb')

try:

    while(data):
        f.write(data)
        s.settimeout(1)
        data,addr = s.recvfrom(buf)

except timeout:
    f.close()
    s.close()

port = port + 1
setEnvPort(port)

#print "File Donwloaded"