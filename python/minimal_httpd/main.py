import socket

PORT = 8080
BUF_SIZE = 4096

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(('', PORT))
server.listen()

body = open('index.html', 'rt')
res = 'HTTP/1.0 200 OK\n\n' + body.read()
body.close()

while True:
    client, addr = server.accept()
    payload = client.recv(BUF_SIZE)
    print(payload.decode('utf-8'))
    client.sendall(res.encode('utf-8'))
    client.close()