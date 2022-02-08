import socket
import threading
import time
import http.client

import sys
sys.path.append(r'../../../../common')
from NetPort import getEnvPort
from NetPort import setEnvPort

count = 0

#sudo sysctl -w net.ipv4.tcp_timestamps=1

class ConnectThread(threading.Thread):
    def __init__(self):
        threading.Thread.__init__(self)

    def run(self):
        count = 0
        url = "127.0.0.1:" + str(getEnvPort());
        while count < 1024:
            try:
                client = http.client.HTTPConnection(url)
                client.request("GET","/index")
                r1 = client.getresponse()
                #print(r1.read().decode("utf-8"))
                #r1.close()
                client.close()
                r1.close()
                count = count + 1
            except OSError:
                print("no port can be used!!!!")
                time.sleep(10)

print("start!!!")

threads= []
index = 0
while index < 32:    
    #print "trace1"
    t = ConnectThread();
    t.start()
    threads.append(t)
    index = index + 1

for t in threads:
    t.join()

print("finish!!!")