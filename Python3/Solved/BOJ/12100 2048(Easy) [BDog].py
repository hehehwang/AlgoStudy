# 12100 2048 (Easy)(BD)
from copy import deepcopy
input = __import__('sys').stdin.readline
boardN = int(input())
board = [list(map(int, input().split())) for _ in range(boardN)]
boardOrig = deepcopy(board)

def rotate():
    tmp = deepcopy(board)
    for i in range(boardN):
        for j in range(boardN):
            board[i][j] = tmp[boardN-j-1][i]

def tilt(dir):
    for _ in range(dir): rotate()
    for i, l in enumerate(board):
        newL = [0]*boardN
        idx = 0
        for n in l:
            if not n: continue
            if not newL[idx]: newL[idx] = n
            elif newL[idx] == n:
                newL[idx] <<= 1
                idx += 1
            else:
                idx += 1
                newL[idx] = n
        board[i] = newL[:]

mV = 0
for combi in range(1<<10):
    board = deepcopy(boardOrig)
    brute = combi
    for i in range(5):
        dir = combi%4
        combi //= 4
        tilt(dir)
    V = max([max(l) for l in board])
    mV = max(mV, V)
print(mV)