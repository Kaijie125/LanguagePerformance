import numpy as np

SIZE = 10000000

def array():
    array_1 = np.zeros(SIZE, dtype = int)
    array_2 = np.zeros(SIZE, dtype = int)
    result = np.zeros(SIZE, dtype = int)
    acc = 0

    array_1 = np.arange(SIZE)
    array_2 = SIZE - np.arange(SIZE)
    result = array_1 + array_2
    acc = np.sum(result)

    return int(acc / SIZE)

if __name__ == "__main__":
    size = array()
    print(f"Tamanio({SIZE}): {size}")