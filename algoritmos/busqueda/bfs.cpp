#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

#define N 3

struct State {
    std::vector<std::vector<int>> puzzle;
    int empty_row;
    int empty_col;
    State* parent;
};

// crea un nuevo estado
State* createState(const std::vector<std::vector<int>>& puzzle, int row, int col, State* parent) {
    State* node = new State;
    node->puzzle = puzzle;
    node->empty_row = row;
    node->empty_col = col;
    node->parent = parent;
    return node;
}

// destruye un estado
void destroyState(State* node) {
    delete node;
}

// comprueba si el nodo es el estado meta
bool isGoal(State* node, const std::vector<std::vector<int>>& goal_state) {
    return node->puzzle == goal_state;
}

// movimiento valido
bool validMove(int row, int col) {
    return (row >= 0 && row < N) && (col >= 0 && col < N);
}

// movimiento de la casilla vacia
State* moveEmpty(State* state, int new_row, int new_col) {
    State* new_state = createState(state->puzzle, new_row, new_col, state);
    std::swap(new_state->puzzle[state->empty_row][state->empty_col], new_state->puzzle[new_row][new_col]);
    new_state->empty_row = new_row;
    new_state->empty_col = new_col;
    return new_state;
}

// estados que se tiene que explorar y los que ya se han explorado
std::deque<State*> queue;
std::deque<std::vector<std::vector<int>>> explored;

State* bfs(State* initial_state, const std::vector<std::vector<int>>& goal_state) {
    queue.push_back(initial_state);
    explored.push_back(initial_state->puzzle);

    while (!queue.empty()) {
        State* node = queue.front();
        queue.pop_front();

        if (isGoal(node, goal_state)) {
            return node;
        }

        int moves[4][2] = {
            {node->empty_row - 1, node->empty_col}, // arriba
            {node->empty_row, node->empty_col - 1}, // izquierda
            {node->empty_row, node->empty_col + 1}, // derecha
            {node->empty_row + 1, node->empty_col}  // abajo
        };

        for (int i = 0; i < 4; i++) {
            int move[2] = {moves[i][0], moves[i][1]};

            if (validMove(move[0], move[1])) {
                State* new_state = moveEmpty(node, move[0], move[1]);
                
                // si find() no encuentra devuelve el uktimo
                if (std::find(explored.begin(), explored.end(), new_state->puzzle) == explored.end()) {
                    queue.push_back(new_state);
                    explored.push_back(new_state->puzzle);
                } else {
                    destroyState(new_state);
                }
            }
        }
    }

    // si sale del bucle => no hay solucion
    return nullptr;
}

void printSolution(State* node) {
    if (node == nullptr) {
        return;
    }
    printSolution(node->parent);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << node->puzzle[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

int main() {
    std::vector<std::vector<int>> initial_state = {
        {1,0,2},
        {4,7,3},
        {5,6,8}
    };
    std::vector<std::vector<int>> goal_state = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}
    };

    State* initial_node = createState(initial_state, 0, 1, nullptr);

    State* solution = bfs(initial_node, goal_state);
    if (solution == nullptr) {
        std::cout << "No existe solucion.\n";
    } else {
        printSolution(solution);
    }

    destroyState(initial_node);
    destroyState(solution);

    return 0;
}
