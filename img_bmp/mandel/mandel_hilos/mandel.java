import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;

public class mandel {

    static int N_THREADS = 4;
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

    // argumentos para los hilos
    private static class ThreadArgs {
        int i;
        int j;
        int end_height;
        int end_width;
    }

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

    // color de cada pixel
    static void setPixelColor(int iteration, double re2, double im2, int offset) {
        // Escala de grises
        byte gray = (byte) (255 * iteration / iter);
        img_data[offset + 2] = gray; // R
        img_data[offset + 1] = gray; // G
        img_data[offset] = gray; // B
    }

    // calculo de la iteraccion
    static void pixelIter(int i, int j, int offset) {
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

        setPixelColor(iteration, re2, im2, offset);
    }

    // funcion principal de mandelbrot
    static void mandelbrot(int i, int j, int end_height, int end_width) {
        int offset;
        for (int y = i; y < end_height; y++) {
            for (int x = j; x < end_width; x++) {
                offset = row_size * y + 3 * x;
                pixelIter(y, x, offset);
            }
        }
    }

    // clase de los hilos
    static class MyThread extends Thread {
        private int i;
        int j;
        int end_height;
        int end_width;

        MyThread(ThreadArgs args) {
            this.i = args.i;
            this.j = args.j;
            this.end_height = args.end_height;
            this.end_width = args.end_width;
        }

        // funcion que ejecuta el hilo
        @Override
        public void run() {
            mandelbrot(i, j, end_height, end_width);
        }
    }

    // funcion de los hilos
    static void paralelInit() {

        MyThread[] threads = new MyThread[N_THREADS];
        ThreadArgs[] t_args = new ThreadArgs[N_THREADS];

        for (int i = 0; i < N_THREADS; i++) {
            t_args[i] = new ThreadArgs();
            t_args[i].i = i * (height / N_THREADS);
            t_args[i].j = 0;
            t_args[i].end_height = (i + 1) * (height / N_THREADS);
            t_args[i].end_width = width;

            threads[i] = new MyThread(t_args[i]);
            threads[i].start();
        }

        for (int i = 0; i < N_THREADS; i++) {
            try {
                threads[i].join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args) {
        initVar();

        paralelInit();

        saveBMP();
    }
}
