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

url_index = "http://127.0.0.1:" + str(getEnvPort()) + "/index"
url_apq = "http://127.0.0.1:" + str(getEnvPort()) + "/apq"
#while 1:
#r = requests.get("http://127.0.0.1:1256/index")
r = requests.get(url_index)

payload={}
time.sleep(2)

for c in r.cookies: 
    #print(c.name, c.value)
    print("name = " + c.name)
    print("value = " + c.value)
    print("domain = " + c.domain)
    print("path = " + c.path)
    print("expires = " + str(c.expires))
    payload[c.name] = c.value
    #payload["domain"] = c.domain
    payload["path"] = c.path
    payload["expires"] = str(c.expires)
    time_local = time.localtime(c.expires)
    dt = time.strftime("%Y-%m-%d %H:%M:%S", time_local)
    print(dt)

print(payload)
#r = requests.get("http://127.0.0.1:1256/apq",data=payload)
r = requests.get(url_apq,data=payload)

#get cookie
print("trace4")