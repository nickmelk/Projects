import random
import socket
import time
import gen.schema_pb2 as schema


IP_ADDRESS = "127.0.0.1"
PORT = 5005

INFO_MESSAGES = [
    "Engine temperature",
    "Gearbox temperature",
    "Coolant temperature",
    "Engine RPM (raw)",
    "Engine RPM (normalized)",
    "Battery voltage (12V)",
    "CAN voltage (5V)",
    "Engine speed"
]


class ReadingType:
    UNKNOWN_READING = 0
    TEMPERATURE_READING = 1
    RPM_READING = 2
    VOLTAGE_READING = 3
    SPEED_READING = 4


def generate_random_reading():
    type = random.randint(ReadingType.TEMPERATURE_READING,
        ReadingType.SPEED_READING)
    message = schema.ReadingMessage()
    match type:
        case ReadingType.TEMPERATURE_READING:
            message.temperature_reading.value = random.randint(-50, 150)
            message.message = (INFO_MESSAGES[random.randint(0, 2)]
                            if random.random() > 0.5 else "")
        case ReadingType.RPM_READING:
            message.rpm_reading.value = random.randint(0, 9000)
            speed_info = INFO_MESSAGES[3]
            if random.random() > 0.5:
                speed_info = INFO_MESSAGES[4]
                message.rpm_reading.value = (message.rpm_reading.value // 100 *
                    100)
            message.message = speed_info if random.random() > 0.5  else ""
        case ReadingType.VOLTAGE_READING:
            voltage_level = random.choice((5, 12))
            message.voltage_reading.value = random.random() * voltage_level
            voltage_info = (INFO_MESSAGES[5] if voltage_level == 5
                            else INFO_MESSAGES[6])
            message.message = voltage_info if random.random() > 0.5 else ""
        case ReadingType.SPEED_READING:
            message.speed_reading.value = random.randint(0, 200)
            message.message = INFO_MESSAGES[7] if random.random() > 0.5 else ""
    return message


def get_value(message):
    name = message.WhichOneof("reading")
    match name:
        case "temperature_reading":
            return message.temperature_reading.value
        case "rpm_reading":
            return message.rpm_reading.value
        case "voltage_reading":
            return message.voltage_reading.value
        case "speed_reading":
            return message.speed_reading.value


def server_mainloop(udp_socket):
    while True:
        message = generate_random_reading()

        serialized_message = message.SerializeToString()
        udp_socket.sendto(serialized_message, (IP_ADDRESS, PORT))

        print(f"Sent UDP packet: {len(serialized_message):3}B", end="")
        print(f"{get_value(message):10.4g}", end="")
        print(f"{message.message if message.message else "":>25}")

        time.sleep(1)


def main():
    udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    try:
        server_mainloop(udp_socket)
    except KeyboardInterrupt:
        print("\nShutting down the server.")
    finally:
        udp_socket.close()



main()
