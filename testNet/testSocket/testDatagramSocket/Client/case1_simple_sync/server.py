import socket

import sys
sys.path.append(r'../../../../../common')
from NetPort import getEnvPort
from NetPort import setEnvPort


s = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
port = getEnvPort()

s.bind(("127.0.0.1",port))
count = 0
receive_data,client = s.recvfrom(1024)

while count < 50:
    #print(receive_data.decode("utf-8"))
    s.sendto(receive_data,client)
    count = count + 1

client.close()
s.close()

port = port + 1
setEnvPort(port)

exit()