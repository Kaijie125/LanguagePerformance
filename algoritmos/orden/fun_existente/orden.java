import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.util.Arrays;

public class orden {

    static int[] readRandomBin() {
        try (DataInputStream file = new DataInputStream(new FileInputStream("../random_list.bin"))) {

            long fileSize = file.available();
            int num = (int) (fileSize / Integer.BYTES);

            int[] array_int = new int[num];

            // lee el archivo binario en formato bytes
            byte[] array_byte = new byte[(int) fileSize];
            file.read(array_byte);

            // convierte al orden de bytes nativo
            ByteBuffer buffer = ByteBuffer.wrap(array_byte);
            buffer.order(ByteOrder.nativeOrder());

            for (int i = 0; i < num; ++i) {
                array_int[i] = buffer.getInt();
            }

            return array_int;
            
        } catch (IOException e) {
            System.err.println("Error al leer el archivo binario: " + e.getMessage());
            return null;
        }
    }

    static void createRandomFile(int[] array, int num) {
        try (BufferedWriter txtFile = new BufferedWriter(new FileWriter("random_list_java.txt"))) {
            for (int i = 0; i < num; ++i) {
                txtFile.write(Integer.toString(array[i]) + "\n");
            }
        } catch (IOException e) {
            System.err.println("Error al escribir en el archivo de texto: " + e.getMessage());
            return;
        }
    }

    static void createSortedFile(int[] array, int num) {
        try (BufferedWriter txtFile = new BufferedWriter(new FileWriter("sorted_list_java.txt"))) {
            for (int i = 0; i < num; ++i) {
                txtFile.write(Integer.toString(array[i]) + "\n");
            }
        } catch (IOException e) {
            System.err.println("Error al escribir en el archivo de texto: " + e.getMessage());
            return;
        }
    }

    public static void main(String[] args) {
        int[] arr = readRandomBin();
        int n = arr.length;

        /*
        createRandomFile(arr, n);
        */
        
        Arrays.sort(arr);

        createSortedFile(arr, n);
    }
}
