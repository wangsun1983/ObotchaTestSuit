import socket
import time

import sys
sys.path.append(r'../../../../../common')
from NetPort import getEnvPort
from NetPort import setEnvPort

s = socket.socket() 
host = socket.gethostname()
port = getEnvPort()

s.bind(("127.0.0.1", port))

s.listen(5)
c,client = s.accept()

receive_data = c.recv(1024)
count = 0

while count < 1024:
    time.sleep(0.5)
    print(receive_data)
    c.sendto(receive_data,client)
    count = count + 1

c.close()
s.close()

port = port + 1
setEnvPort(port)

exit()