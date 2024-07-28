import random

MIN = 0
MAX = 1000000
ITER = 100000000

def generateRandom():
    
    random_num = 0
    for _ in range (ITER):
        # genera un numero aleatorio entre MIN y MAX (ambos incluidos)
        random_num = random.randint(MIN, MAX)


if __name__ == "__main__":
    generateRandom()