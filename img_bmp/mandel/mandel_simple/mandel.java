import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;

public class mandel {

    // rango de los ejes x e y
    static double x_max = 1;
    static double x_min = -2;
    static double y_max = 1.5;
    static double y_min = -1.5;

    // nombre de la imagen
    static String file = "mandel_java.bmp";

    static int width = 6000;
    static int height = 6000;
    static int iter = 500;

    // padding, tamanio de la fila y del imagen
    static int padding;
    static int row_size;
    static int img_size;

    // datos de la imagen: pixeles
    static byte[] img_data;

    // conversion pixeles a coordenada x e y; incremento entre pixeles
    static double x_step;
    static double y_step;

    // inicializacion de las variables
    static void initVar() {
        // Desplazamiento de los ejes
        x_step = (x_max - x_min) / width;
        y_step = (y_max - y_min) / height;

        // calculo del padding
        padding = 4 - (width * 3) % 4;
        if (padding == 4) {
            padding = 0;
        }

        // calculo del tamaño de la fila y de la imagen
        row_size = width * 3 + padding;
        img_size = row_size * height;

        // inicializo los pixeles
        img_data = new byte[img_size];
    }

    // guarda la imagen
    static void saveBMP() {
        ByteBuffer buffer = ByteBuffer.allocate(54).order(ByteOrder.LITTLE_ENDIAN);

        // datos de la cabecera
        buffer.putShort((short) 0x4D42); // type
        buffer.putInt(54 + img_size);    // size
        buffer.putShort((short) 0);      // reserved1
        buffer.putShort((short) 0);      // reserved2
        buffer.putInt(54);                // offset
        buffer.putInt(40);                // header_size
        buffer.putInt(width);             // width
        buffer.putInt(height);            // height
        buffer.putShort((short) 1);       // planes
        buffer.putShort((short) 24);      // bitsperpixel
        buffer.putInt(0);                 // compression
        buffer.putInt(img_size);          // image_size
        buffer.putInt(0);                 // x_resolution
        buffer.putInt(0);                 // y_resolution
        buffer.putInt(0);                 // used_colors
        buffer.putInt(0);                 // important_colors

        try (FileOutputStream fos = new FileOutputStream(file)) {
            fos.write(buffer.array());
            fos.write(img_data);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // asigna el color a un pixel
    static void setPixelColor(int iteration, double re2, double im2, byte[] pixel) {
        // Escala de grises
        int gray = (int) (255 * iteration / iter);
        pixel[2] = (byte) gray; // R
        pixel[1] = (byte) gray; // G
        pixel[0] = (byte) gray; // B
    }

    // calcula la iteracion de un pixel
    static void pixelIter(int i, int j, byte[] pixel) {
        int iteration = 0;
        double c_re = x_min + x_step / 2 + j * x_step;
        double c_im = y_min + y_step / 2 + i * y_step;
        double zn_re = 0;
        double zn_im = 0;
        double tmp_re;
        double re2 = 0;
        double im2 = 0;

        while ((re2 + im2 < 4) && (iteration < iter)) {
            tmp_re = re2 - im2 + c_re;
            zn_im = 2 * zn_re * zn_im + c_im;
            zn_re = tmp_re;
            re2 = zn_re * zn_re;
            im2 = zn_im * zn_im;
            iteration++;
        }

        setPixelColor(iteration, re2, im2, pixel);
    }

    // funcion principal de mandelbrot
    static void mandelbrot(byte[] img) {
        int offset;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                offset = row_size * i + 3 * j;
                byte[] pixel = {img[offset], img[offset + 1], img[offset + 2]};
                pixelIter(i, j, pixel);
                img[offset] = pixel[0];
                img[offset + 1] = pixel[1];
                img[offset + 2] = pixel[2];
            }
        }
    }

    public static void main(String[] args) {
        initVar();

        mandelbrot(img_data);

        saveBMP();
    }
}
