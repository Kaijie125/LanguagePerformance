import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;

public class timsort {
    static int MIN_MERGE = 32; 
  
    public static int minRunLength(int n) { 
        assert n >= 0; 
  
        int r = 0; 
        while (n >= MIN_MERGE) { 
            r |= (n & 1); 
            n >>= 1; 
        } 
        return n + r; 
    } 
  
    public static void insertionSort(int[] arr, int left, int right) { 
        for (int i = left + 1; i <= right; i++) { 
            int temp = arr[i]; 
            int j = i - 1; 

            while (j >= left && arr[j] > temp) { 
                arr[j + 1] = arr[j]; 
                j--; 
            } 
            arr[j + 1] = temp; 
        } 
    } 
  
    public static void merge(int[] arr, int l, int m, int r) { 
        int len1 = m - l + 1;
        int len2 = r - m; 

        int[] left = new int[len1]; 
        int[] right = new int[len2]; 

        for (int x = 0; x < len1; x++) { 
            left[x] = arr[l + x]; 
        } 
        for (int x = 0; x < len2; x++) { 
            right[x] = arr[m + 1 + x]; 
        } 
  
        int i = 0; 
        int j = 0; 
        int k = l; 
  
        while (i < len1 && j < len2) { 
            if (left[i] <= right[j]) { 
                arr[k] = left[i]; 
                i++; 
            } 
            else { 
                arr[k] = right[j]; 
                j++; 
            } 
            k++; 
        } 
  
        while (i < len1) { 
            arr[k] = left[i]; 
            k++; 
            i++; 
        } 
        while (j < len2) { 
            arr[k] = right[j]; 
            k++; 
            j++; 
        } 
    } 
  
    public static void timSort(int[] arr, int n) 
    { 
        int minRun = minRunLength(n); 
  
        for (int i = 0; i < n; i += minRun) { 
            insertionSort(arr, i, Math.min((i + MIN_MERGE - 1), (n - 1))); 
        } 
        for (int size = minRun; size < n; size = 2 * size) { 
            for (int left = 0; left < n; left += 2 * size) { 
                int mid = left + size - 1; 
                int right = Math.min((left + 2 * size - 1), (n - 1)); 

                if (mid < right) 
                    merge(arr, left, mid, right); 
            } 
        } 
    } 

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
        
        timSort(arr, n);

        createSortedFile(arr, n);
    }
}
