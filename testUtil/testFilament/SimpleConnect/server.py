import socket
import sys
import time

sys.path.append(r'../../../common')
from NetPort import getEnvPort
from NetPort import setEnvPort

s = socket.socket()
host = socket.gethostname()
port = getEnvPort()

s.bind(("127.0.0.1", port))

s.listen(5)
#c,client = s.accept()

#receive_data = c.recv(1024)
count = 0
time.sleep(1)

while count < 3:
    #print(receive_data.decode("utf-8"))
    c,client = s.accept()
    c.sendto(b"hello world",client)
    count = count + 1

c.close()
s.close()

port = port+1
setEnvPort(port)

exit()
