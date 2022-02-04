from websocket import create_connection

import sys
sys.path.append(r'../../../../../common')
from NetPort import getEnvPort

count = 0

url = "ws://127.0.0.1:" + str(getEnvPort()) + "/mytest"

while count < 1024*32:
    ws = create_connection(url)
    msg = "Hello, World"
    ws.send(msg)
    ws.close()
    count = count+1

print("test finished")