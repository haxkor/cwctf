from socket import socket
from struct import pack

def p32(num):
    return pack("<I", num)

def p64(num):
    return pack("<Q", num)

def p8(num):
    return bytes([num])


host = "localhost"
port = 4444

sock = socket()
sock.connect((host, port))

sock.send( p64(1) + p8(2) + b"\n")
print(sock.recv(100))

