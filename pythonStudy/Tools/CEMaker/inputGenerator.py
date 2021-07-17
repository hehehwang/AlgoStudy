import random
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

def scpc2021_2():
    for N in range(2, 15):
        for t in range(1, N):
            Bset = set()
            for a in range(2**N):
                A = bin(a)[2:2+N]
                A = '0'*(N-len(A))+A
                B = ['0']*N
                for i in range(N):
                    if (t<=i and A[i-t] == '1'): B[i] = '1'
                    if (i<N-t and A[i+t] == '1'): B[i] = '1'
                Bset.add(''.join(B))
            inp = f'{len(Bset)}\n'
            for b in Bset:
                inp += f"{N} {t}\n{b}\n"
            yield inp

if __name__ == '__main__':
    gen = scpc2021_2()
    print(next(gen))
    print(next(gen))