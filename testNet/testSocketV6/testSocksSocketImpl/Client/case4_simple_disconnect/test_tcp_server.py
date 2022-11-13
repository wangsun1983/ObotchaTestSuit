from socket import *
import sys
import threading
import socket
import time

sys.path.append(r'../../../../../common')
from NetPort import getEnvPort

class ShutDownThread(threading.Thread):
    def __init__(self,c,s):
        threading.Thread.__init__(self)
        self.mconn = c
        self.maddr = s

    def run(self):
        self.mconn.close()


s = socket.socket(socket.AF_INET6, socket.SOCK_STREAM)
port = getEnvPort()
print("port is ",port)

s.bind(("::1",port))

index = 0
print("start test")

threads= []
s.listen(256)

while index < 1024*32:    
    #print "trace1"
    myconn,myaddr = s.accept()
    t = ShutDownThread(myconn,myaddr);
    t.start()
    threads.append(t)
    index = index + 1

for t in threads:
    #print "start join"
    t.join()

print ("finish!!!")