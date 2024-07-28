import numpy as np

SIZE = 10000000

def array():
    array_1 = np.zeros(SIZE, dtype = int)
    array_2 = np.zeros(SIZE, dtype = int)
    result = np.zeros(SIZE, dtype = int)
    acc = 0

    for i in range(SIZE):
        array_1[i] = i

    for i in range(SIZE):
        array_2[i] = SIZE - i

    for i in range(SIZE):
        result[i] = array_1[i] + array_2[i]

    for i in range(SIZE):
        acc = acc + result[i]

    return int(acc / SIZE)

if __name__ == "__main__":
    size = array()
    print(f"Tamanio({SIZE}): {size}")
