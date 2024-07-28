import struct
import random

MIN = 0
MAX = 1000000
ITER = 10000000

def generateRandom():
    random_array = []
    for i in range (ITER):
        random_array.append(random.randint(MIN, MAX))
    
    # return [random.randint(MIN, MAX) for _ in range(ITER)]
    return random_array


if __name__ == "__main__":
    array = generateRandom()

    # transforma el array a bytes
    binary = struct.pack(f"{len(array)}i", *array)

    try:
        with open("random_list.bin", "wb") as file:
            file.write(binary)
    except:
        print("Error open()")
    
    """
    try:
        with open("random_list.txt", 'w') as file:
            for i in array:
                file.write(str(i) + '\n')
    except:
        print("Error open()")
    """