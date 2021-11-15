import socket
import time
import sys
import select
import os
import time


s = socket.socket(socket.AF_INET6, socket.SOCK_DGRAM)
addr = ("::1",1233)

buf=4096*32
f = open("file",'wb')

print("cccc")
with open('data', 'r') as fp:
    while True:
        print("aaaa")
        data = fp.read(1024*4)
        s.sendto(data,addr)
        time.sleep(0.1)
        if not data:
            break;


print("Upload Donwloaded")