
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;

public class switch_case_10{

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
            switch (value) {
               case 0:
                   break;
              case 1:
                    break;
              case 2:
                    break;
              case 3:
                    break;
              case 4:
                    break;
              case 5:
                    break;
              case 6:
                    break;
              case 7:
                    break;
              case 8:
                    break;
              case 9:
                    break;
               default:
                    break;
            }

        }
    }
}
