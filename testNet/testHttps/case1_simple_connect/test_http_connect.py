import socket
import threading
import time
import http.client

count = 0

client = http.client.HTTPConnection("127.0.0.1:9260")
client.request("GET","/index")
r1 = client.getresponse()
#print(r1.read().decode("utf-8"))
#r1.close()
rep = r1.read().decode("utf-8")
client.request("GET","/index",body=rep)
client.close();

print("finish!!!")