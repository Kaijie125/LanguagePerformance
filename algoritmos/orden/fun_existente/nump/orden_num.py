import struct
import numpy as np

if __name__ == "__main__":

    # archivo original
    try:
        with open("../random_list.bin", "rb") as file:
            array_bytes = file.read()
    except:
        print("Error al abrir")
        exit(0)

    num = len(array_bytes) // 4
    array_int = np.array(struct.unpack(f"{num}i", array_bytes))

    # txt para comprobar
    try:
        with open("random_list_py.txt", "w") as txt_file:
            for num_entero in array_int:
                txt_file.write(str(num_entero) + "\n")
    except:
        print("Error al crear el archivo de texto")
        exit(0)

    array_int.sort()

    # txt para comprobar
    try:
        with open("sorted_list_py.txt", "w") as txt_file_sorted:
            for num_entero in array_int:
                txt_file_sorted.write(str(num_entero) + "\n")
    except:
        print("Error al crear el archivo de texto")
        exit(0)