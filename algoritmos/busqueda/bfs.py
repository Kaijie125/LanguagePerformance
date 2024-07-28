from collections import deque
import copy
N = 3

# estados del puzzle
class State:
    def __init__(self, puzzle, empty_row, empty_col, parent):
        self.puzzle = puzzle
        self.empty_row = empty_row
        self.empty_col = empty_col
        self.parent = parent

def isGoal(node, goal_state):
    return node.puzzle == goal_state

def validMove(row, col):
    return (0 <= row < N) and (0 <= col < N)

def moveEmpty(state, new_row, new_col):

    new_state = State(copy.deepcopy(state.puzzle), new_row, new_col, state)
    new_state.puzzle[state.empty_row][state.empty_col] = state.puzzle[new_row][new_col]
    new_state.puzzle[new_row][new_col] = 0
    return new_state

def bfs(initial_state, goal_state):
    # estados que se tiene que explorar y los que ya se han explorado
    queue = deque()
    queue.append(initial_state)
    explored = deque()
    explored.append(initial_state.puzzle)

    while len(queue) > 0:
        # expande el primer elemento, al ser BFS es una FIFO
        node = queue.popleft()

        if isGoal(node, goal_state):
            return node

        moves = [
            (node.empty_row - 1, node.empty_col), # arriba
            (node.empty_row, node.empty_col - 1), # izquierda
            (node.empty_row, node.empty_col + 1), # derecha
            (node.empty_row + 1, node.empty_col)  # abajo
        ]

        for move in moves:
            if validMove(move[0], move[1]):
                new_state = moveEmpty(node, move[0], move[1])
                if new_state.puzzle not in explored:
                    queue.append(new_state)
                    explored.append(new_state.puzzle)
   
    # si sale del bucle => no hay solucion
    return None

def printSolution(node):
    if node is None:
        return
    printSolution(node.parent)
    for row in node.puzzle:
        print(row)
    print()

if __name__ == "__main__":
    initial_state = State(
        [[1,0,2], 
         [4,7,3], 
         [5,6,8]],
        0, 1, None
    )
    goal_state = [[1, 2, 3], 
                  [4, 5, 6], 
                  [7, 8, 0]]
    
    solution = bfs(initial_state, goal_state)
    
    if solution is None:
        print("no existe solucion.")
    else:
        printSolution(solution)