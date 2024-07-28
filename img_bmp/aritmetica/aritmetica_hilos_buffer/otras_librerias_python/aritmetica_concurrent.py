from concurrent.futures import ThreadPoolExecutor

N_THREADS = 4

def generateColor(width, height, start_height, end_height):
    
    # colores del imagen
    index = start_height * (width * 3 + n_padding_byte)
    for y in range(start_height, end_height):
        for x in range(width):
            r = int((x / width) * 255)
            g = int(((height - y) / height) * 255)
            b = int((y / height) * 255)

            data[index] = b
            data[index + 1] = g
            data[index + 2] = r
            index += 3
        index += n_padding_byte
            
def createBMP(width, height):
    
    global n_padding_byte
    n_padding_byte = 4 - ((width * 3) % 4)
    if n_padding_byte == 4:
        n_padding_byte = 0

    size = 54 + ((width * 3) + n_padding_byte) * height
    reserved1 = 0
    reserved2 = 0
    offset = 54
    header_size = 40
    planes = 1
    bitsperpixel = 24
    compression = 0
    image_size = ((width * 3) + n_padding_byte) * height
    x_resolution = 0
    y_resolution = 0
    used_colors = 0
    important_colors = 0

    # alineamiento, otras alternativas usando bytearray(), o la libreria struct
    header = b'\x42\x4D' + \
             size.to_bytes(4, 'little') + \
             reserved1.to_bytes(2, 'little') + \
             reserved2.to_bytes(2, 'little') + \
             offset.to_bytes(4, 'little') + \
             header_size.to_bytes(4, 'little') + \
             width.to_bytes(4, 'little') + \
             height.to_bytes(4, 'little') + \
             planes.to_bytes(2, 'little') + \
             bitsperpixel.to_bytes(2, 'little') + \
             compression.to_bytes(4, 'little') + \
             image_size.to_bytes(4, 'little') + \
             x_resolution.to_bytes(4, 'little') + \
             y_resolution.to_bytes(4, 'little') + \
             used_colors.to_bytes(4, 'little') + \
             important_colors.to_bytes(4, 'little') 

    try:
        with open("img_py_con.bmp", "wb") as file:
            # escritura cabecera en el archivo
            file.write(header)

            # buffer para la imagen
            global data 
            data = bytearray((width * 3 + n_padding_byte) * height)

            # parte hilo
            chunk_size = height // N_THREADS

            with ThreadPoolExecutor(max_workers=N_THREADS) as executor:
                
                for i in range(N_THREADS):
                    start_y = i * chunk_size
                    end_y = start_y + chunk_size if i < N_THREADS - 1 else height
                    
                    executor.submit(generateColor, width, height, start_y, end_y)


            file.write(data)

    except:
        print("Error al crear el archivo")

if __name__ == "__main__":
    width = 8000
    height = 8000
    createBMP(width, height)