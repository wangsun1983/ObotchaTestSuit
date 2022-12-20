import socket
import threading
import time
import http.client
import requests
import os

import sys
sys.path.append(r'../../../../common')
from NetPort import getEnvPort
from NetPort import setEnvPort

#while 1:
port = getEnvPort()
print("port is ",port)

url = "http://127.0.0.1:" + str(port) + "/index"
url2 = "http://127.0.0.1:" + str(port) + "/apq"

#while 1:
r = requests.get(url)
payload={}
for c in r.cookies: 
    #print(c.name, c.value)
    payload[c.name] = c.value

print(payload)
r = requests.get(url2,data=payload)

#get cookie
print("trace4")