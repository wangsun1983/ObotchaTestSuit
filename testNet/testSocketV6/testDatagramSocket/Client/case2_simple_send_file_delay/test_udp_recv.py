import socket
import sys
import select

host="::1"

port = 1234

s = socket.socket(socket.AF_INET6, socket.SOCK_DGRAM)
s.bind((host,port))
addr = (host,port)

buf=4096
print "start"
f = open("file",'wb')
data,addr = s.recvfrom(buf)
print "start1"
try:

    while(data):
        print "accept data"
        f.write(data)
        s.settimeout(1)
        data,addr = s.recvfrom(buf)

except timeout:
    f.close()
    s.close()

print "File Donwloaded"