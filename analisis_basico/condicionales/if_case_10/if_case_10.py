
def readRandomBin():
    try:
        with open("../random_list.bin", "rb") as file:
            array_bytes = file.read()
    except:
        print("Error al abrir")
        exit(1)

    num = len(array_bytes) // 4
    array_int = [int.from_bytes(array_bytes[i:i+4], byteorder='little') for i in range(0, len(array_bytes), 4)]

    return num, array_int

if __name__ == "__main__":
    num, array_int = readRandomBin()

    for i in range(num):
        value = array_int[i] % 10
        if value == 0:
            pass
        elif value == 1:
            pass
        elif value == 2:
            pass
        elif value == 3:
            pass
        elif value == 4:
            pass
        elif value == 5:
            pass
        elif value == 6:
            pass
        elif value == 7:
            pass
        elif value == 8:
            pass
        elif value == 9:
            pass
