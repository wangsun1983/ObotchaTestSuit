import socket
import time
import threading

import sys
sys.path.append(r'../../../../../common')
from NetPort import getEnvPort

connectNum = 0

class myThread (threading.Thread):
  def __init__(self,name):
        threading.Thread.__init__(self)
        self.name = name

  def run(self):
    global connectNum
    s = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
    # Connect the socket to the port where the server is listening
    server_address = 'case1_socket'
    s.connect(server_address)
    connectNum = connectNum+1
    file = open('./tmp/connectNum.txt','w')
    file.write(str(connectNum))
    file.close()
    s.send(str("hello server").encode("utf-8"))
    print("connect succeed!!!!!!")
    time.sleep(10);


thread1 = myThread("Thread-1")
thread1.start()
thread2 = myThread("Thread-2")
thread2.start()
thread3 = myThread("Thread-2")
thread3.start()
thread4 = myThread("Thread-2")
thread4.start()
thread5 = myThread("Thread-2")
thread5.start()
thread6 = myThread("Thread-2")
thread6.start()
thread7 = myThread("Thread-2")
thread7.start()
thread8 = myThread("Thread-2")
thread8.start()
thread9 = myThread("Thread-2")
thread9.start()
thread10 = myThread("Thread-2")
thread10.start()
thread11 = myThread("Thread-2")
thread11.start()
thread12 = myThread("Thread-2")
thread12.start()

thread1.join()
thread2.join()
thread3.join()
thread4.join()
thread5.join()
thread6.join()
thread7.join()
thread8.join()
thread9.join()
thread10.join()
thread11.join()
thread12.join()

print("test finished")

