import websocket
import threading


import sys
sys.path.append(r'../../../../../common')
from NetPort import getEnvPort

url = "ws://127.0.0.1:" + str(getEnvPort()) + "/mytest"

print("port is ",str(getEnvPort()))

ws = websocket.WebSocket()
ws.connect(url)
msg = "Hello, World"

with open('./tmp/testdata', 'r') as fp:
    while True:
        data = fp.read(1024*4)
        ws.send(data,websocket.ABNF.OPCODE_BINARY)
        if not data:
            break;

ws.close()



print("test finished")