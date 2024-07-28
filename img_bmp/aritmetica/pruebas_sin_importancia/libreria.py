# uso de libreria
# solucion de tamaño pequenio 3x3 con un relleno
# ordenacion distinta arriba a abajo en vez de abajo a arriba en los colores

from PIL import Image

def createBMP(width, height):
    # se crea una nueva imagen con fondo blanco
    image = Image.new('RGB', (width, height))
    pixels = image.load()

    # coloracion de los pixeles 
    for y in range(height):
        for x in range(width):
            r = int((x / width) * 255)
            g = int((y / height) * 255)
            b = int(((height - y) / height) * 255)
            pixels[x, y] = (r, g, b)

    # imagen en formato BMP
    image.save('img_py.bmp')

if __name__ == "__main__":
    width = 4000
    height = 4000
    createBMP()