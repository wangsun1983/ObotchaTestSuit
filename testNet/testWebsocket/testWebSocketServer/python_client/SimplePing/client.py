import websocket
import threading

import sys
sys.path.append(r'../../../../../common')
from NetPort import getEnvPort

url = "ws://127.0.0.1:" + str(getEnvPort()) + "/mytest"
ws = websocket.WebSocket()
ws.connect(url)
msg = "Hello, World"
ws.send("hello")
recvdata = ws.recv()
print("recvdata1 is",recvdata)

#for i in range(0,256):
#    ws.send("hello",websocket.ABNF.OPCODE_PING)
#    recvdata = ws.recv()
#    print("recvdata is",recvdata)

ws.close()



print("test finished")