# 12100 2048 (Easy)
from copy import deepcopy
from collections import deque
input = __import__('sys').stdin.readline
boardN = int(input())
board = [list(map(int, input().split())) for _ in range(boardN)]
boardOrig = deepcopy(board)
# dir:  r  d  l  u

def oob(r, c):
    return r<0 or c<0 or boardN<=r or boardN<=c

def ptv(r, c):
    return board[r][c]

def move(dir):
    for i in range(boardN):
        que = deque([])
        for j in range(boardN):
            if dir ==  0: # r
                curr = (i, boardN-j-1)
            elif dir == 1: # d
                curr = (boardN-j-1, i)
            elif dir == 2: # l
                curr = (i, j)
            else: # u
                curr = (j, i)
            if ptv(*curr):
                if que:
                    moveTo = que.popleft()
                    board[moveTo[0]][moveTo[1]] = ptv(*curr)
                    board[curr[0]][curr[1]] = 0
                    que.append(curr)
            else:
                que.append(curr)

def merge(dir):
    for i in range(boardN):
        pV = 0
        pP = (0, 0)
        for j in range(boardN):
            if dir ==  0: # r
                curr = (i, boardN-j-1)
            elif dir == 1: # d
                curr = (boardN-j-1, i)
            elif dir == 2: # l
                curr = (i, j)
            else: # u
                curr = (j, i)
            if ptv(*curr):
                if ptv(*curr) == pV:
                    board[curr[0]][curr[1]] <<= 1
                    board[pP[0]][pP[1]] = 0
                    pV, pP = 0, (0, 0)
                else:
                    pV = ptv(*curr)
                    pP = curr
            else: break

def operate(dir):
    move(dir)
    merge(dir)
    move(dir)

def maxV():
    return max([max(l) for l in board])

mV = 0
for combi in range(1<<10):
    brute = combi
    board = deepcopy(boardOrig)
    for i in range(5):
        dir = brute%4
        brute //= 4
        operate(dir)
    mV = max(mV, maxV())

print(mV)