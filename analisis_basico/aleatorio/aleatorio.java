import java.util.Random;

public class aleatorio {

    private static final int MIN = 0;
    private static final int MAX = 1000000;
    private static final int ITER = 100000000;

    public static void generateRandom() {
        // inicializa el generador de numeros aleatorios
        Random random = new Random();
        
        int random_num;
        for (int i = 0; i < ITER; i++) {
            // genera un numero aleatorio entre MIN y MAX - 1
            random_num = random.nextInt(MAX - MIN + 1) + MIN;
        }
    }

    public static void main(String[] args) {
        generateRandom();
    }
}