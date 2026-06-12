import socket

# Создаём сокет
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Подключаемся к серверу
sock.connect(('localhost', 5555))

# Отправляем сообщение
message = input("Введите сообщение: ")
sock.send((message + '\n').encode())

# Получаем ответ
reply = sock.recv(1024).decode()
print(f"Ответ: {reply}")

# Закрываем
sock.close()