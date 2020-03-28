import socket, datetime

PORT = 50000
BUF_SIZE = 4096

server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server.bind(('', PORT))

while True:
    data, client = server.recvfrom(BUF_SIZE)
    msg = str(datetime.datetime.now())
    server.sendto(msg.encode('UTF-8'), client)
    print(msg)
    print(client)