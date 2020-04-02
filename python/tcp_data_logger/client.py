import socket, sys

HOST = 'localhost'
PORT = 50000

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    client.connect((HOST, PORT))
except:
    print('Not connected')
    sys.exit()

while True:
    msg = input()
    if msg == 'q':
        break
    client.sendall(msg.encode('utf-8'))

client.close()