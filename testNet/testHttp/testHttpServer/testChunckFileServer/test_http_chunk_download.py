import socket
import threading
import time
import http.client
import requests
import os

count = 1
#while 1:
count = 0
while count < 32:
    r = requests.get("http://127.0.0.1:1123/index")
    filename = "./tmp/"+str(count)
    with open(os.path.join(os.path.dirname(os.path.abspath("__file__")),filename),"wb") as f:
        f.write(r.content)
    count = count + 1
    r.close()

print("finished")