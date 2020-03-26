import socket

HOST = 'localhost'
# HOST = '127.0.0.1'
PORT = 50000
BUF_SIZE = 4096

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((HOST, PORT))
data = client.recv(BUF_SIZE)
print(data.decode('UTF-8'))
client.close()