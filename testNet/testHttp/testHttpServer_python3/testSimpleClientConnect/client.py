import socket
import threading
import time
import http.client

import sys
sys.path.append(r'../../../../common')
from NetPort import getEnvPort
from NetPort import setEnvPort

count = 0

port = getEnvPort()
url = "127.0.0.1:" + str(port)

client = http.client.HTTPConnection(url)
client.request("GET","/index")
r1 = client.getresponse()
#print(r1.read().decode("utf-8"))
responseBody = r1.read().decode("utf-8");
print("responseBody is ",responseBody)

if responseBody == "this is server":
    bodydata = 'i am client'
    client.request(method="PUT",url="/index",body=bodydata);
#r1.close()
client.close();

print("finish!!!")