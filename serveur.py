import socket

socket_Serveur = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
address_Serveur = ('0.0.0.0', 65432)
socket_Serveur.bind(address_Serveur)

socket_Serveur.listen(1)
print("Server waiting...")

socket_Client, address_Client = socket_Serveur.accept()
print("connected from ", address_Client)
    
msg = b"Bonjour Client, je suis le serveur 65432, la connexion est etablie\n"
socket_Client.send(msg)

data = socket_Client.recv(1024).decode()
messages = data.split("\n")  

print("client message 1: ", messages[0])
if len(messages) > 1:
    print("client message 2: ", messages[1])

socket_Client.close()
socket_Serveur.close()

print("serveur fermée")
