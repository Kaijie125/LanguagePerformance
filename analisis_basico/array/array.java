public class array {
    private static final int SIZE = 10000000;

    public static void main(String[] args) {
        int size = array_();
        System.out.println("Tamanio(" + SIZE + "): " + size);
    }

    private static int array_() {
        int[] array_1 = new int[SIZE];
        int[] array_2 = new int[SIZE];
        int[] result = new int[SIZE];
        int acc = 0;

        for (int i = 0; i < SIZE; i++) {
            array_1[i] = i;
        }

        for (int i = 0; i < SIZE; i++) {
            array_2[i] = SIZE - i;
        }

        for (int i = 0; i < SIZE; i++) {
            result[i] = array_1[i] + array_2[i];
        }

        for (int i = 0; i < SIZE; i++) {
            acc = acc + result[i];
        }
        System.out.println("Acc: " + acc);
        return (int) (acc / SIZE);
    }
}
