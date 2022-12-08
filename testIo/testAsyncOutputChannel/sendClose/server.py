import socket
import time
import sys
sys.path.append(r'../../../common')
from NetPort import getEnvPort
from NetPort import setEnvPort

s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
port = getEnvPort()
server_address = ("127.0.0.1", port)
s.bind(server_address)
s.settimeout(10)
s.listen(5)

print('Waiting for connection...')
client,addr = s.accept()
with open("./tmp/file","wb") as f:
 while True:
  print("start rcv data")
  data = client.recv(1024)
  print("i receive data")
  time.sleep(0.1)
  if not data:
    client,addr = s.accept()
    print("i receive not data")
    break;
  f.write(data)
  f.flush()

f.close()
print("recv complete")

port = port + 1
setEnvPort(port)
