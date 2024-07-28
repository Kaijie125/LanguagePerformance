import struct
import sys

def cat(filename):
    with open(filename, 'rb') as file:
        # cabecera
        header_data = file.read(54) 
        content_data = file.read()

    # estructura de la cabecera del archivo BMP
    bmp_header = struct.unpack('<2sIHHIIIIHHIIIIII', header_data)

    # Imprime los valores de la cabecera
    """print(f'tipo: {bmp_header[0].decode()}')
    print(f'tamanio: {bmp_header[1]}')
    print(f'reservado 1: {bmp_header[2]}')
    print(f'reservado 2: {bmp_header[3]}')
    print(f'ofset: {bmp_header[4]}')
    print(f'tamanio del encabezado: {bmp_header[5]}')
    print(f'ancho: {bmp_header[6]}')
    print(f'altura: {bmp_header[7]}')
    print(f'planos: {bmp_header[8]}')
    print(f'ppb: {bmp_header[9]}')
    print(f'compresion: {bmp_header[10]}')
    print(f'tamanio del imagen: {bmp_header[11]}')
    print(f'resolucion horizontal: {bmp_header[12]}')
    print(f'resolucion vertical: {bmp_header[13]}')
    print(f'colores utilizados: {bmp_header[14]}')
    print(f'colores importantes: {bmp_header[15]}')
"""
    # calculo de bytes de relleno de cada fila
    img_size = bmp_header[11]
    img_height = bmp_header[7]
    img_width = bmp_header[6]
    n_bytes_per_row = int(img_size / img_height)
    additional_bytes = int(n_bytes_per_row - (img_width * 3))

    for i in range(0, img_height, 1):
        index = int(i * n_bytes_per_row)
        for j in range(0, img_width, 1):
            r = content_data[index]
            g = content_data[index + 1]
            b = content_data[index + 2] 
            print(r, g, b)
            index = index + 3

        print("bytes adicionales: ", end="")
        for j in range(0, additional_bytes, 1):
            print(str(content_data[index + j]) + " ", end="")
        print("")


    #for i in range(0, len(content_data), 1):
    #    r = content_data[i]
    #    g = content_data[i+1]
    #    b = content_data[i+2] 
    #    print(r, g, b)

if __name__ == '__main__':

    archivo_bmp = sys.argv[1]
    cat(archivo_bmp)