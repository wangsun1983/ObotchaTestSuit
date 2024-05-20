import websockets
import asyncio
import sys

import sys
sys.path.append(r'../../../../../common')
from NetPort import getEnvPort
from NetPort import setEnvPort

class WSserver():
    async def handle(self,websocket,path):
        while True:
              try:
                  recv_msg = await websocket.recv()
                  print("i accept a message:",recv_msg)
              except:
                  print("exit")
                  await websocket.close()
                  #break
                  sys.exit(0)
            
        #await websocket.close()

    def run(self):
      self.port = getEnvPort()
      self.ser = websockets.serve(self.handle,"127.0.0.1",str(self.port))
      self.loop = asyncio.get_event_loop();
      self.loop.run_until_complete(self.ser)
      self.loop.run_forever()


ws = WSserver()
ws.run()
