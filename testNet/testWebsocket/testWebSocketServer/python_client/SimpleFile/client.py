from websocket import create_connection
import threading

import sys
sys.path.append(r'../../../../../common')
from NetPort import getEnvPort

url = "ws://127.0.0.1:" + str(getEnvPort()) + "/mytest"
ws = create_connection(url)
msg = "Hello, World"

with open('./tmp/data', 'r') as fp:
    while True:
        data = fp.read(1024*4)
        ws.send(data)
        
        if not data:
            break;

ws.close()



print("test finished")