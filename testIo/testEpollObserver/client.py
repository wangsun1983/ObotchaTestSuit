import socket
import time

import sys
sys.path.append(r'../../common')
from NetPort import getEnvPort

count = 50
port = getEnvPort()

while (count > 0):
    s = socket.socket()
    s.connect(("127.0.0.1",port))
    count = count - 1;

#print("send complete")