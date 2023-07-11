import socket
import threading
import time
import http.client

import sys
sys.path.append(r'../../../../common')
from NetPort import getEnvPort
from NetPort import setEnvPort

count = 0

socket.setdefaulttimeout(10)
#sudo sysctl -w net.ipv4.tcp_timestamps=1

class ConnectThread(threading.Thread):
    def __init__(self,id):
        threading.Thread.__init__(self)
        self.myTid = id

    def run(self):
        count = 0
        url = "127.0.0.1:" + str(getEnvPort());
        while count < 1024:
            try:
                #print(str(self.myTid) + ":trace1")
                client = http.client.HTTPConnection(url)
                #print(str(self.myTid) + ":trace2")
                client.request("GET","/index")
                #print(str(self.myTid) + ":trace3")
                r1 = client.getresponse()
                #print(str(self.myTid) + ":" + r1.read().decode("utf-8"))
                r1.close()
                client.close()
                #print(str(self.myTid) + ":trace4")
                count = count + 1
            except OSError:
                print(str(self.myTid) + ":" + "no port can be used!!!!")
                time.sleep(5)
        print(str(self.myTid) + ":" +"finish!!!")



threads= []
index = 0
while index < 32:    
    #print "trace1"
    t = ConnectThread(index);
    t.start()
    threads.append(t)
    index = index + 1

for t in threads:
    t.join()

print("finish!!!")