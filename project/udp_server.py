import random
import socket
import time
import gen.schema_pb2 as schema

UDP_IP = "127.0.0.1"
UDP_PORT = 5005

INFO_MESSAGES = [
    "Engine temperature",
    "Gearbox temperature",
    "Coolant temperature",
    "Engine RPM (normalized)",
    "Engine RPM",
    "Battery voltage (12V)",
    "CAN voltage (5V)",
    "Engine speed"
]

class ReadingType:
    TEMPERATURE_READING = 0
    RPM_READING = 1
    VOLTAGE_READING = 2
    SPEED_READING = 3

udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

def generate_random_reading(type):
    match type:
        case ReadingType.TEMPERATURE_READING:
            reading = schema.TemperatureReading()
            reading.value = random.randint(-50, 150)
            reading.info = (INFO_MESSAGES[random.randint(0, 2)]
                            if random.random() > 0.5 else "")
        case ReadingType.RPM_READING:
            reading = schema.RPMReading()
            reading.value = random.randint(0, 9000) // 100 * 100
            reading.info = INFO_MESSAGES[4] if random.random() > 0.5 else ""
        case ReadingType.VOLTAGE_READING:
            reading = schema.VoltageReading()
            voltage_level = random.choice((5, 12))
            reading.value = random.random() * voltage_level
            voltage_info = (INFO_MESSAGES[5] if voltage_level == 5
                            else INFO_MESSAGES[6])
            reading.info = voltage_info if random.random() > 0.5 else ""
        case ReadingType.SPEED_READING:
            reading = schema.SpeedReading()
            reading.value = random.randint(0, 200)
            reading.info = INFO_MESSAGES[7] if random.random() > 0.5 else ""
    return reading

try:
    while True:
        message = generate_random_reading(random.randint(0, 3))
        serialized = message.SerializeToString()

        udp_socket.sendto(serialized, (UDP_IP, UDP_PORT))
        print(f"Sent UDP packet: {len(serialized):3}B", end="")
        print(f"{message.value:10.2f}", end="")
        print(f"{message.info if message.info else "":>25}")

        time.sleep(1)
except KeyboardInterrupt:
    print("\nShutting down the server.")

finally:
    udp_socket.close()
