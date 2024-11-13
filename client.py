import socket

socket_Client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
socket_Client.connect(('localhost', 65432))

data = socket_Client.recv(1024)
print(data.decode())

message1 = b"Bonjour Serveur 65432, nous sommes donc dans la phase de transfert\n"
socket_Client.send(message1)

message2 = b"Serveur 65432, je vous dis au revoir\n"
socket_Client.send(message2)

socket_Client.close()
print("client fermée")
