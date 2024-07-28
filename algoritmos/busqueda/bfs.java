import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;

public class bfs {
    static final int N = 3;

    static class State {
        int[][] puzzle;
        int empty_row;
        int empty_col;
        State parent;

        // constructor de la clase estado
        State(int[][] puzzle, int x, int y, State parent) {
            //this.puzzle = puzzle;
            /*this.puzzle = new int[N][N];
            for (int i = 0; i < N; i++) {
                this.puzzle[i] = Arrays.copyOf(puzzle[i], N);
            }*/
            this.puzzle = Arrays.stream(puzzle).map(int[]::clone).toArray(int[][]::new);
            this.empty_row = x;
            this.empty_col = y;
            this.parent = parent;
        }
    }

    static State createState(int[][] puzzle, int x, int y, State parent) {
        return new State(puzzle, x, y, parent);
    }

    static Boolean isGoal(State node, int[][] goal) {
        // deepEquals compara arrays multidimensionales
        return Arrays.deepEquals(node.puzzle, goal);
    }

    static Boolean validMove(int row, int col) {
        return (row >= 0 && row < N) && (col >= 0 && col < N);
    }

    static State moveEmpty(State state, int new_row, int new_col) {
        State new_state = createState(state.puzzle, new_row, new_col, state);
        new_state.puzzle[state.empty_row][state.empty_col] = new_state.puzzle[new_row][new_col];
        new_state.puzzle[new_row][new_col] = 0;
        return new_state;
    }

    // estados que se tiene que explorar y los que ya se han explorado
    static Deque<State> queue = new ArrayDeque<>();
    static Deque<int[][]> explored = new ArrayDeque<>();

    static State bfs_(State initial_state, int[][] goal_state) {
        queue.add(initial_state);
        explored.add(initial_state.puzzle);

        while (!queue.isEmpty()) {
            State node = queue.poll();
            if (isGoal(node, goal_state)) {
                return node;
            }

            explored.add(node.puzzle);
            int[][] moves = { 
                {node.empty_row - 1, node.empty_col}, // arriba
                {node.empty_row, node.empty_col - 1}, // izquierda
                {node.empty_row, node.empty_col + 1}, // derecha
                {node.empty_row + 1, node.empty_col}  // abajo
            };

            for (int i = 0; i < 4; i++) {
                int move[] = {moves[i][0], moves[i][1]};

                if (validMove(move[0], move[1])) {
                    State new_state = moveEmpty(node, move[0], move[1]);
                    if (!explored.contains(new_state.puzzle)) {
                        queue.add(new_state);
                        explored.add(new_state.puzzle);
                    }
                }
            }
        }

        // si sale no hay solucion
        return null;
    }

    static void printSolution(State node) {
        if(node == null) {
            return;
        }
        printSolution(node.parent);
        for (int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                System.out.print(node.puzzle[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int[][] initialState = {
            {1,0,2},
            {4,7,3},
            {5,6,8}
        };
        int[][] goalState = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 0}
        };

        State initialNode = createState(initialState, 0, 1, null);

        State solution = bfs_(initialNode, goalState);
        if (solution == null) {
            System.out.println("No existe.");
        } else {
            printSolution(solution);
        }
    }

}
