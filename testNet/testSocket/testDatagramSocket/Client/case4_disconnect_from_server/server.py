from socket import *
import sys
import select
import os

import sys
sys.path.append(r'../../../../../common')
from NetPort import getEnvPort
from NetPort import setEnvPort

host="127.0.0.1"

port = getEnvPort()

s = socket(AF_INET,SOCK_DGRAM)
s.bind((host,port))
addr = (host,port)

buf=4096*32
#print "start"
path = "file"

data,addr = s.recvfrom(buf)
s.close()

port = port + 1
setEnvPort(port)

#print "File Donwloaded"