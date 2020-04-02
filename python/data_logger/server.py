import socket, datetime

PORT = 50000
BUF_SIZE = 4096

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(('', PORT))
server.listen()

while True:
    client, addr = server.accept()
    print('Connected')
    print(client)
    file_name = datetime.datetime.now().strftime('%m%d%H%M%S%f')
    log_file = open(file_name + '.txt', 'wt')
    try:
        while True:
            payload = client.recv(BUF_SIZE)
            if not payload:
                break
            print(payload.decode('utf-8'), file=log_file)
    except:
        print('Error')
        print(client)
    print('Completed')
    client.close()
    log_file.close()