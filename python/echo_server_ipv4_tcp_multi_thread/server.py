import socket, threading

PORT = 50000
BUF_SIZE = 4096

def client_handler(client, msg):
    data = client.recv(BUF_SIZE)
    print(data.decode('utf-8'))
    client.sendall(msg.encode('utf-8'))
    client.close()

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(('', PORT))
server.listen()

while True:
    client, addr = server.accept()
    print(client)
    p = threading.Thread(target=client_handler, args=(client, 'Hello from server!'))
    p.start()