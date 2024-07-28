
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "deque.h"

#define N 3

typedef struct State {
    int puzzle[N][N];
    int empty_row;
    int empty_col;
    struct State* parent;
} State;

// crea un nuevo estado
State* createState(int puzzle[N][N], int row, int col, State* parent){
    State* node = malloc(sizeof(State));

    memcpy(node->puzzle, puzzle, N * N * sizeof(int));

    node->empty_row = row;
    node->empty_col = col;
    node->parent = parent;
    return node;
}

// destruye un estado
void destroyState(State* node){
    free(node);
}

// comprueba si el nodo es el estado meta
// cambiar a memcmp
bool isGoal(State* node, int goal_state[N][N]) {
    /*for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (node->puzzle[i][j] != goal_state[i][j]) {
                return false;
            }
        }
    }
    return true;*/
    return memcmp(node->puzzle, goal_state, sizeof(int) * N * N) == 0;
}

// movimiento valido
bool validMove(int row, int col){
    return (row >= 0 && row < N) && (col >= 0 && col < N);
}

// movimiento de la casilla vacio
State* moveEmpty(State* state, int new_row, int new_col){
    State* new_state = createState(state->puzzle, new_row, new_col, state);
    memcpy(new_state->puzzle, state->puzzle, sizeof(state->puzzle));
    new_state->puzzle[state->empty_row][state->empty_col] = state->puzzle[new_row][new_col];
    new_state->puzzle[new_row][new_col] = 0;
    return new_state;
}

// estados que se tiene que explorar y los que ya se han explorado
Deque* queue;
Deque* explored;

State* bfs(State *initial_state, int goal_state[N][N]) {
    queue = createDeque();
    pushBack(queue, initial_state);
    explored = createDeque();
    pushBack(explored, initial_state->puzzle);

    while (!isEmpty(queue)) {
        State *node = popFront(queue);

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

                if (!find(explored, new_state->puzzle, sizeof(int) * N * N)) {
                    pushBack(queue, new_state);
                    pushBack(explored, new_state);
                } else {
                    destroyState(new_state);
                }
            }
        }
    }
    // si sale del bucle => no hay solucion
    return NULL;
}

void printSolution(State *node) {
    if (node == NULL) {
        return;
    }
    printSolution(node->parent);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", node->puzzle[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int initial_state[N][N] = {
        {1,0,2},
        {4,7,3},
        {5,6,8}
    };
    int goal_state[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}
    };

    State *initial_node = createState(initial_state, 0, 1, NULL);

    State *solution = bfs(initial_node, goal_state);
    if (solution == NULL) {
        printf("No existe solucion.\n");
    } else {
        printSolution(solution);
    }

    destroyDeque(queue);
    destroyDeque(explored);
    
    destroyState(initial_node);
    destroyState(solution);
    return 0;
}