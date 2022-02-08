import socket
import threading
import time
import http.client

import sys
sys.path.append(r'../../../../common')
from NetPort import getEnvPort
from NetPort import setEnvPort

count = 0
url = "127.0.0.1:" + str(getEnvPort())

while count < 1:
    client = http.client.HTTPConnection(url)
    client.request("GET","/index")
    r1 = client.getresponse()
    print(r1.read().decode("utf-8"))
    r1.close()
    client.close();
    count = count + 1