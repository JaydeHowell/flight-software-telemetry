import socket
import struct

UDP_IP = "127.0.0.1"
UDP_PORT = 8080

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

sock.bind((UDP_IP, UDP_PORT))

print(f"Listening to {UDP_IP} {UDP_PORT}")

while True:

    data, addr = sock.recvfrom(1024)

    if len(data) == 8:

        pressure, voltage = struct.unpack('<ff', data)

        print(f"{addr} Pressure: {pressure:.2f} | Voltage: {voltage:.2f}")
    else:
        print(f"{addr} Received packet is malformed. Size: {len(data)} bytes.")