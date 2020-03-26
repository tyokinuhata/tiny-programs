import socket

PORT = 50000

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(('', PORT))
server.listen()

client, addr = server.accept()
client.sendall(b'Hi, nice to meet you!\n')
client.close()
server.close()