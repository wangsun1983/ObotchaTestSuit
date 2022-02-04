import websockets
import asyncio
import sys

import sys
sys.path.append(r'../../../../../common')
from NetPort import getEnvPort
from NetPort import setEnvPort

class WSserver():
    async def handle(self,websocket,path):
      recv_msg = await websocket.recv()
      if recv_msg == "hello server":
        await websocket.send('i am server')
      self.port = self.port + 1
      setEnvPort(self.port)
      sys.exit(0)

    def run(self):
      self.port = getEnvPort()
      self.ser = websockets.serve(self.handle,"127.0.0.1",str(self.port))
      self.loop = asyncio.get_event_loop();
      self.loop.run_until_complete(self.ser)
      self.loop.run_forever()


ws = WSserver()
ws.run()
