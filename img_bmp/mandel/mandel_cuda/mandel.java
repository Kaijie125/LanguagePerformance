/*
gcc -c -fpic mandel_jni.c -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/linux" -o mandel_jni.o
nvcc -c -Xcompiler -fPIC cuda_mandel.cu -o cuda_mandel.o
gcc -shared -o libmandel.so mandel_jni.o cuda_mandel.o -lcuda -lcudart
javac mandel.java 
*/

import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;

class mandel {
    static {
        System.loadLibrary("mandel");  // OJO: en Linux la biblioteca debe llamarse libMandel.so
    }
    public native void kernelWrapper(byte[] hst_img, int img_size, int iter, double x_min, double y_min, double h_x_step, double h_y_step, int W_x_H, int width, int row_size);


    // rango de los ejes x e y
    static double x_max = 1;
    static double x_min = -2;
    static double y_max = 1.5;
    static double y_min = -1.5;

    // nombre de la imagen
    static String file = "mandel_java.bmp";

    //tamanio de la imagen y numero de iteraciones
    static int width = 6000;
    static int height = 6000;
    static int iter = 500;

    // padding, tamanio de la fila y del imagen
    static int padding;
    static int row_size;
    static int img_size;

    // datos de la imagen: pixeles
    public static byte[] img_data;

    // conversion pixeles a coordenada x e y; incremento entre pixeles
    static double x_step;
    static double y_step;

    // inicializacion de las variables
    static void initVar() {
        // desplazamiento de los ejes
        x_step = (x_max - x_min) / width;
        y_step = (y_max - y_min) / height;

        // calculo del padding
        padding = 4 - (width * 3) % 4;
        if (padding == 4) {
            padding = 0;
        }

        // calculo del tamanio de la fila y del imagen
        row_size = width * 3 + padding;
        img_size = row_size * height;

        // datos de la cabezera
        img_data = new byte[img_size];
    }

    // guardar la imagen
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

    public static void main(String[] args) {
        initVar();

        new mandel().kernelWrapper(img_data, img_size, iter, x_min, y_min, x_step, y_step, height * width, width, row_size);
        
        saveBMP();
     }
 }