from random import randint
from itertools import combinations

def p1799(size = 5):
    for i in range(1000):
        rtn = ''
        rtn += f'{size}\n'
        for _ in range(size):
            for _ in range(size):
                rtn += f'{randint(0, 1)} '
            rtn += '\n'
        yield rtn

def p1107():
    def con(N, M, btn):
        inp = str(N) + '\n'
        inp += str(M) + '\n'
        inp += ' '.join(btn)
        return inp

    for N in list(range(0, 10)) + list(range(90, 110)) + list(range(499_990, 500_001)):
        for M in range(0, 10):
            for btn in combinations([str(i) for i in range(10)], M):
                yield con(N, M, btn)
