import socket

import sys
sys.path.append(r'../../../../../common')
from NetPort import getEnvPort


s = socket.socket(socket.AF_INET6, socket.SOCK_DGRAM)
print("trace1 \n");
port = getEnvPort()
print("trace1_1,port is ",port)

s.bind(("::1",port))
count = 0
print("trace2 \n");

receive_data,client = s.recvfrom(1024)
print("trace3 \n");

while count < 50:
    #print(receive_data.decode("utf-8"))
    s.sendto(receive_data.decode("utf-8"),client)
    count = count + 1

client.close()

exit()