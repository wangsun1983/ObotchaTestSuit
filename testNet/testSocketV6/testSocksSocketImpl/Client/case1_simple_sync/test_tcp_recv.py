import socket

s = socket.socket(socket.AF_INET6, socket.SOCK_STREAM)

host = socket.gethostname()
port = getEnvPort()

s.bind(("::1", port))

s.listen(5)
c,client = s.accept()
print("trace1")
receive_data = c.recv(1024)
count = 0
print("trace2")
while count < 50:
    print(receive_data.decode("utf-8"))
    c.sendto(receive_data,client)
    count = count + 1

c.close()
s.close()

exit()