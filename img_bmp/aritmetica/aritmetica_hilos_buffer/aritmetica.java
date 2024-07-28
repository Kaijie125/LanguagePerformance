import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;

public class aritmetica {    

    private static final int N_THREADS = 4;
    private static int n_padding_byte;
    private static byte[] data;

    // estructura equivalente a la estructura threadArgs en C/C++
    private static class ThreadArgs {
        int width;
        int height;
        int start_height;
        int end_height;
    }

    // estructura que llama a la funcion run de la clase Thread
    private static class MyThread extends Thread {
        private ThreadArgs args;

        public MyThread(ThreadArgs args) {
            this.args = args;
        }

        public void run() {
            // tamanio teniendo en cuenta args.end_height - args.start_height
            int index = args.start_height * (args.width * 3 + n_padding_byte);

            // asigna los colores
            for (int y = args.start_height; y < args.end_height; y++) {
                for (int x = 0; x < args.width; x++) {
                    data[index + 2] = (byte) ((x / (float) args.width) * 255);
                    data[index + 1] = (byte) (((args.height - y) / (float) args.height) * 255);
                    data[index] = (byte) ((y / (float) args.height) * 255);

                    index += 3;
                }
                index += n_padding_byte;
            }

        }
    }

    private static void createBMP(int width, int height) {
        
        // n_padding_byte = (4 - (width * 3) % 4) % 4;
        n_padding_byte = 4 - ((width * 3) % 4);
        if (n_padding_byte == 4) {
            n_padding_byte = 0;
        }

        // cabecera del archivo BMP
        int size = 54 + ((width * 3) + n_padding_byte) * height;
        int image_size = ((width * 3) + n_padding_byte) * height;

        // alineaminto usando un buffer
        // java por defecto usa big endian
        ByteBuffer buffer = ByteBuffer.allocate(54).order(ByteOrder.LITTLE_ENDIAN);
        buffer.putShort((short) 0x4D42); // type
        buffer.putInt(size);             // size
        buffer.putShort((short) 0);      // reserved1
        buffer.putShort((short) 0);      // reserved2
        buffer.putInt(54);                // offset
        buffer.putInt(40);                // header_size
        buffer.putInt(width);             // width
        buffer.putInt(height);            // height
        buffer.putShort((short) 1);       // planes
        buffer.putShort((short) 24);      // bitsperpixel
        buffer.putInt(0);                 // compression
        buffer.putInt(image_size);        // image_size
        buffer.putInt(0);                 // x_resolution
        buffer.putInt(0);                 // y_resolution
        buffer.putInt(0);                 // used_colors
        buffer.putInt(0);                 // important_colors

        //apertura del archivo
        try (FileOutputStream file = new FileOutputStream("img_java.bmp")) {
            // escribe la cabecera
            file.write(buffer.array());
            
            // buffer para la imagen
            int data_size = (width * 3 + n_padding_byte) * height;
            data = new byte[data_size];

            // parte hilo
            MyThread[] threads = new MyThread[N_THREADS];
            int chunk_size = height / N_THREADS;
            ThreadArgs[] t_args = new ThreadArgs[N_THREADS];

            for (int i = 0; i < N_THREADS; i++) {
                t_args[i] = new ThreadArgs();
                t_args[i].width = width;
                t_args[i].height = height;
                t_args[i].start_height = i * chunk_size;
                t_args[i].end_height = (i < N_THREADS - 1) ? t_args[i].start_height + chunk_size : height;
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

            file.write(data);
            
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        int width = 8000;
        int height = 8000;

        createBMP(width, height);
    }
}
