import socket
import sys
import os
import time

server_address = 'case6_socket'
 
# Make sure the socket does not already exist
try:
    os.unlink(server_address)
except OSError:
    if os.path.exists(server_address):
        raise
# Create a UDS socket
sock = socket.socket(socket.AF_UNIX,socket.SOCK_STREAM)
# Bind the socket to the port

sock.bind(server_address)

# Listen for incoming connections
sock.listen(1)
print("start listen!!!")
time.sleep(10)
print("start listen2!!!")


# Wait for a connection

#connection, client_address = sock.accept()

#receive_data = connection.recv(1024)

