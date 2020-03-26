import socket, datetime

PORT = 50000

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(('', PORT))
server.listen()

while True:
    client, addr = server.accept()
    msg = str(datetime.datetime.now())
    client.sendall(msg.encode('UTF-8'))
    # client.sendall(b'Hi, nice to meet you!\n')
    print(client)
    client.close()