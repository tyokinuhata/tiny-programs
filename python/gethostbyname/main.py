import socket

while True:
    try:
        hostname = input('ホスト名を入力（qで終了）')
        if hostname == 'q':
            break
        print(socket.gethostbyname(hostname))
    except:
        print('変換失敗')