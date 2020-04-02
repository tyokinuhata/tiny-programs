import socket

PORT = 50000
BUF_SIZE = 4096

server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server.bind(('', PORT))

clients = []
while True:
    payload, client = server.recvfrom(BUF_SIZE)
    if not (client in clients):
        clients.append(client)
    if payload.decode('utf-8') == 'q':
        clients.remove(client)
    else:
        msg = str(client) + '>' + payload.decode('utf-8')
        print(msg)
        for client in clients:
            server.sendto(msg.encode('utf-8'), client)