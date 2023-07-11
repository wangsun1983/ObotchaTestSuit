import socket
import time
import threading

import sys
sys.path.append(r'../../../../../common')
from NetPort import getEnvPort


class myThread (threading.Thread):
  def __init__(self,name):
        threading.Thread.__init__(self)
        self.name = name

  def run(self):      
    count = 1024
    while count > 0:
      self.s = socket.socket()
      self.s.connect(("127.0.0.1",getEnvPort()))
      self.s.send(str("hello world").encode("utf-8"))
      count = count - 1;


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

time.sleep(5)

print("test finished")