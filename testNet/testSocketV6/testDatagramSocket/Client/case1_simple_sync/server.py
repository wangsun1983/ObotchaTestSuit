import socket

import sys
sys.path.append(r'../../../../../common')
from NetPort import getEnvPort


s = socket.socket(socket.AF_INET6, socket.SOCK_DGRAM)

s.bind(("::1",getEnvPort()))
count = 0
receive_data,client = s.recvfrom(1024)


while count < 50:
    #print(receive_data.decode("utf-8"))
    s.sendto(receive_data,client)
    count = count + 1

exit()