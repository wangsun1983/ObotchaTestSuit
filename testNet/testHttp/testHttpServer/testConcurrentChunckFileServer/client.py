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


class DownloadThread(threading.Thread):
    def __init__(self,id):
        threading.Thread.__init__(self)
        self.threadid = id;

    def run(self):
        count = 0
        while count < 16:
            url = "http://127.0.0.1:" + str(getEnvPort()) + "/index"
            r = requests.get(url)
            filename = "./tmp/"+"_id_" + str(self.threadid) + "_" + str(count)
            with open(os.path.join(os.path.dirname(os.path.abspath("__file__")),filename),"wb") as f:
                f.write(r.content)
            count = count + 1
            r.close()
            #print("send complete")

threads= []
index = 0
while index < 128:    
    #print "trace1"
    t = DownloadThread(index);
    t.start()
    threads.append(t)
    index = index + 1

for t in threads:
    t.join()

print("finish!!!")
