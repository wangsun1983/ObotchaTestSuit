import socket
import time
import sys

sys.path.append(r'../../../../../common')
from NetPort import getEnvPort

port = getEnvPort();

s = socket.socket(socket.AF_INET6, socket.SOCK_STREAM)
s.bind(("::1",port))

s.listen(5)
c,client = s.accept()

receive_data = c.recv(1024)
count = 0

while count < 1024:
    time.sleep(0.1)
    print(receive_data.decode("utf-8"))
    c.sendto(receive_data,client)
    count = count + 1
   

c.close()
s.close()

exit()