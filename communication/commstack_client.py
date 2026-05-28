import socket
import time
import random
import string

HOST = "127.0.0.1"
PORT = 5000

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

client.connect((HOST, PORT))

print("[CONNECTED TO COMMSTACK]")

characters = string.ascii_letters + string.digits
length = 16

while True:
    # event = "IR:OBSTACLE_DETECTED"
    # Faster alternative for generating a single string
    random_str = "".join(random.choices(characters, k=length))

    client.send(random_str.encode())

    print(f"[EVENT SENT] {random_str}")

    time.sleep(3)

    