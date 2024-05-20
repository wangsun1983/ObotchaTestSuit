import websockets
import asyncio
import sys

import sys
sys.path.append(r'../../../../../common')
from NetPort import getEnvPort
from NetPort import setEnvPort

fo = open("./tmp/file", "wb")

class WSserver():
    async def handle(self,websocket,path):
      while True:
          try:
              recv_msg = await websocket.recv()
              fo.write(recv_msg)                
          except:
              sys.exit(0)
              
      await websocket.close()
      sys.exit(0)

    def run(self):
      self.port = getEnvPort()
      self.ser = websockets.serve(self.handle,"127.0.0.1",str(self.port))
      self.loop = asyncio.get_event_loop();
      self.loop.run_until_complete(self.ser)
      self.loop.run_forever()


ws = WSserver()
ws.run()
