
def swap(arr, a, b):
    arr[a], arr[b] = arr[b], arr[a]

def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1

    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            swap(arr, i, j)
    swap(arr, i + 1, high)
    return i + 1

def quickSort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)
        quickSort(arr, low, pi - 1)
        quickSort(arr, pi + 1, high)

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

def createRandomFile(array_int):
    try:
        with open("random_list_py.txt", "w") as txt_file:
            for num_entero in array_int:
                txt_file.write(str(num_entero) + "\n")
    except:
        print("Error al crear el archivo de texto")
        exit(1)

def createSortedFile(array_int):
    try:
        with open("sorted_list_py.txt", "w") as txt_file_sorted:
            for num_entero in array_int:
                txt_file_sorted.write(str(num_entero) + "\n")
    except:
        print("Error al crear el archivo de texto")
        exit(1)

if __name__ == "__main__":

    # archivo original
    num, array_int = readRandomBin()        

    """
    # txt para comprobar
    createRandomFile(array_int)
    """
    
    quickSort(array_int, 0, num - 1)

    # txt para comprobar
    createSortedFile(array_int)
    