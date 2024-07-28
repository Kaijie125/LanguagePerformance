
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;

public class if_case_10{

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

    public static void main(String[] args) {
        int[] arr = readRandomBin();
        int n = arr.length;

        for (int i = 0; i < n; i++) {
        int value = arr[i] % 10;
            if (value == 0) {
         } else if (value == 1) {
         } else if (value == 2) {
         } else if (value == 3) {
         } else if (value == 4) {
         } else if (value == 5) {
         } else if (value == 6) {
         } else if (value == 7) {
         } else if (value == 8) {
         } else if (value == 9) {
         }
        }
    }
}
