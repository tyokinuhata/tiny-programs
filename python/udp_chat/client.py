import socket, sys, threading

HOST = 'localhost'
PORT = 50000
BUF_SIZE = 4096

def server_handler(client):
    while True:
        try:
            payload = client.recv(BUF_SIZE)
            print(payload.decode('utf-8'))
        except:
            sys.exit()
    client.close()

client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

p = threading.Thread(target=server_handler, args=(client, ))
p.setDaemon(True)

while True:
    msg = input('')
    client.sendto(msg.encode('utf-8'), (HOST, PORT))
    if msg == 'q':
        break
    if not p.is_alive():
        p.start()
client.close()