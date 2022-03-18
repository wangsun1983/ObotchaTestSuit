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
      recv_msg = await websocket.recv()
      fo.write(recv_msg)
      await websocket.send('i am server')
      self.port = self.port + 1
      setEnvPort(self.port)
      fo.close()
      sys.exit(0)

    def run(self):
      self.port = getEnvPort()
      self.ser = websockets.serve(self.handle,"127.0.0.1",str(self.port))
      self.loop = asyncio.get_event_loop();
      self.loop.run_until_complete(self.ser)
      self.loop.run_forever()


ws = WSserver()
ws.run()
