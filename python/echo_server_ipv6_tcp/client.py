import socket

HOST = '::1'
PORT = 50000
BUF_SIZE = 4096

client = socket.socket(socket.AF_INET6, socket.SOCK_STREAM)
client.connect((HOST, PORT))
data = client.recv(BUF_SIZE)
print(data.decode('UTF-8'))
client.close()