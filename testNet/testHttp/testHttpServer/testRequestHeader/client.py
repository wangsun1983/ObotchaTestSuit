import socket
import threading
import time
import http.client
import requests
import os

import sys
sys.path.append(r'../../../../common')
from NetPort import getEnvPort
from NetPort import setEnvPort

url = "http://127.0.0.1:" + str(getEnvPort()) + "/index"
#while 1:
headers = {"tag1":"value1","tag2":"value2"}
r = requests.get(url,headers = headers)
print("finished")