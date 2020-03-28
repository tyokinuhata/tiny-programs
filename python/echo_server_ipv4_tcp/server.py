import socket

PORT = 50000
BUF_SIZE = 4096

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(('', PORT))
server.listen()

while True:
    client, addr = server.accept()
    client.sendall('Hello from server!'.encode('UTF-8'))
    data = client.recv(BUF_SIZE)
    print(client)
    print(data.decode('utf-8'))
    client.close()