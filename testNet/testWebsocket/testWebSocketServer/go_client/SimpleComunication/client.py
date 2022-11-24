import websocket
import threading

import sys
sys.path.append(r'../../../../../common')
from NetPort import getEnvPort

url = "ws://127.0.0.1:" + str(getEnvPort()) + "/mytest"
hit = 0

for i in range(0,256):
    ws = websocket.WebSocket()
    ws.connect(url)
    msg = "Hello,Server"
    ws.send(msg)
    recvdata = ws.recv()
    if recvdata == "Hello,Client":
        ws.close()
        hit = hit + 1

if hit == 256:
    ws = websocket.WebSocket()
    ws.connect(url)
    msg = "Finish"
    ws.send(msg)