MIN_MERGE = 32
 
def calcMinRun(n): 
    r = 0
    while n >= MIN_MERGE: 
        r |= n & 1
        n >>= 1
    return n + r 

#funcion de insercion
def insertion(arr, left, right): 
    for i in range(left + 1, right + 1): 
        j = i 
        #elementos mayores que temp a la derecha
        while j > left and arr[j] < arr[j - 1]: 
            arr[j], arr[j - 1] = arr[j - 1], arr[j] 
            j -= 1

#funcion de mezcla
def merge(arr, l, m, r): 
    len1 = m - l + 1
    len2 = r - m 
    left = []
    right = [] 

    #copia datos a los arrays temporales
    for i in range(0, len1): 
        left.append(arr[l + i]) 
    for i in range(0, len2): 
        right.append(arr[m + 1 + i]) 

    i = 0
    j = 0
    k = l

    #combina los array
    while i < len1 and j < len2: 
        if left[i] <= right[j]: 
            arr[k] = left[i] 
            i += 1
        else: 
            arr[k] = right[j] 
            j += 1
        k += 1
    
    #copia elementos restantes de left
    while i < len1: 
        arr[k] = left[i] 
        k += 1
        i += 1
    
    #copia elementos restantes de right
    while j < len2: 
        arr[k] = right[j] 
        k += 1
        j += 1

#funcion principal del timSort
def timSort(arr): 
    n = len(arr) 
    minRun = calcMinRun(n) 
    #ordena los bloques de tamanio RUN con insertion
    for start in range(0, n, minRun): 
        end = min(start + minRun - 1, n - 1) 
        insertion(arr, start, end) 
    
    #combina los bloques ordenados
    size = minRun 
    while size < n: 

        for left in range(0, n, 2 * size): 
            mid = min(n - 1, left + size - 1) 
            right = min((left + 2 * size - 1), (n - 1)) 

            #combina solo si hay array para combinar
            if mid < right: 
                merge(arr, left, mid, right) 

        size = 2 * size 


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

    timSort(array_int)

    # txt para comprobar
    createSortedFile(array_int)