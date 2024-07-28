import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;

public class aritmetica {
    
    public static void createBMP(int width, int height) {
        byte[] padding_byte = {0x00};
        // padding = (4 - (width * 3) % 4) % 4;
        int n_padding_byte = 4 - ((width * 3) % 4);
        if (n_padding_byte == 4) {
            n_padding_byte = 0;
        }

        int size = 54 + ((width * 3) + n_padding_byte) * height;
        int image_size = ((width * 3) + n_padding_byte) * height;

        // alineamirnto usando un buffer, por defecto es BIG_ENDIAN
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

        // apertura del archivo
        try (FileOutputStream file = new FileOutputStream("img_java.bmp")) {
            
            // escritura de cabecera
            file.write(buffer.array());
            
            // colores del imagen
            for (int y = 0; y < height; y++) {
                for (int x = 0; x < width; x++) {
                    int r = (int) ((x / (double) width) * 255);
                    int g = (int) (((height - y) / (double) height) * 255);
                    int b = (int) ((y / (double) height) * 255);

                    file.write(b);
                    file.write(g);
                    file.write(r);
                }

                for (int z = 0; z < n_padding_byte; z++) {
                    file.write(padding_byte);
                }
            }

        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    public static void main(String[] args){
        int width = 8000;
        int height = 8000;
        createBMP(width, height);
    }
}
