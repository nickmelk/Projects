import random
import socket
import time
import gen.schema_pb2 as schema


TEMPERATURE_LOWER_BOUND = 50
TEMPERATURE_UPPER_BOUND = 150
RPM_LOWER_BOUND = 6000
RPM_UPPER_BOUND = 8000
BATTERY_VOLTAGE = 12
CAN_VOLTAGE = 5
SPEED_LOWER_BOUND = 0
SPEED_UPPER_BOUND = 150
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
    ENGINE_TEMPERATURE = 0
    GEARBOX_TEMPERATURE = 1
    COOLANT_TEMPERATURE = 2
    ENGINE_RPM_RAW = 3
    ENGINE_RPM_NORMALIZED = 4
    BATTERY_VOLTAGE = 5
    CAN_VOLTAGE = 6
    SPEED_READING = 7


def generate_random_reading():
    type = random.randint(0, len(INFO_MESSAGES)-1)
    message = schema.ReadingMessage()
    match type:
        case (ReadingType.ENGINE_TEMPERATURE | ReadingType.GEARBOX_TEMPERATURE |
              ReadingType.COOLANT_TEMPERATURE):
            message.temperature_reading.value = random.randint(
                TEMPERATURE_LOWER_BOUND, TEMPERATURE_UPPER_BOUND)
        case ReadingType.ENGINE_RPM_RAW:
            message.rpm_reading.value = random.randint(RPM_LOWER_BOUND,
                RPM_UPPER_BOUND)
        case ReadingType.ENGINE_RPM_NORMALIZED:
            message.rpm_reading.value = (random.randint(RPM_LOWER_BOUND,
                RPM_UPPER_BOUND) // 100 * 100)
        case ReadingType.BATTERY_VOLTAGE:
            message.voltage_reading.value = random.random() * BATTERY_VOLTAGE
        case ReadingType.CAN_VOLTAGE:
            message.voltage_reading.value = random.random() * CAN_VOLTAGE
        case ReadingType.SPEED_READING:
            message.speed_reading.value = random.randint(SPEED_LOWER_BOUND,
                SPEED_UPPER_BOUND)
    message.message = INFO_MESSAGES[type] if random.random() >= 0.5 else ""
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


def mainloop(udp_socket):
    while True:
        message = generate_random_reading()

        serialized_message = message.SerializeToString()
        udp_socket.sendto(serialized_message, (IP_ADDRESS, PORT))

        print(f"Sent a packet: {len(serialized_message):3}B", end="")
        print(f"{get_value(message):10.4g}", end="")
        print(f"{message.message if message.message else "":>25}")

        time.sleep(1)


def main():
    udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    try:
        mainloop(udp_socket)
    except KeyboardInterrupt:
        print("\nShutting down the server.")
    finally:
        udp_socket.close()


if __name__ == "__main__":
    main()
