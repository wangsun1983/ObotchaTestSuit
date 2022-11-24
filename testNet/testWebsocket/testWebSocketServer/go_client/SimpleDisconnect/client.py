import websocket
import threading

import sys
sys.path.append(r'../../../../../common')
from NetPort import getEnvPort

url = "ws://127.0.0.1:" + str(getEnvPort()) + "/mytest"

for i in range(0,256):
    ws = websocket.WebSocket()
    ws.connect(url)
    msg = "Hello, World"
    ws.send(msg)
    ws.close()