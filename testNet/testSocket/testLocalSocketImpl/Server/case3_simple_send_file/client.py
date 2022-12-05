from socket import *
import sys
import select
import os
import socket

host="127.0.0.1"

# Create a UDS socket
s = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
 
# Connect the socket to the port where the server is listening
server_address = 'case3_socket'

s.connect(server_address)

#print "cccc"
with open('./tmp/testdata', 'r') as fp:
    while True:
        data = fp.read(1024*4)
        s.send(data.encode("utf-8"))
        
        if not data:
            break;

        data1 = s.recv(1024)


#print "Upload Donwloaded"