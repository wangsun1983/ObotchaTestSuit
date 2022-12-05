from socket import *
import sys
import select
import os
import time
import socket

# Create a UDS socket
s = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
 
# Connect the socket to the port where the server is listening
server_address = 'case2_socket'

s.connect(server_address)

buf=4096*32
#print "cccc"
with open('./tmp/testdata', 'r') as fp:
    while True:
        #print "aaaa"
        data = fp.read(1024*4)
        s.send(data.encode("utf-8"));
        time.sleep(0.1)
        if not data:
            break;

s.close()
#print "Upload Donwloaded"