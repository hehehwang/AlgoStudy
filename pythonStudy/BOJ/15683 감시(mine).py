# 15683 감시
from copy import deepcopy
from itertools import product

input = __import__('sys').stdin.readline

row, col = map(int, input().split())
office = [input().split() for _ in range(row)]

cctvN = 0
cctvCoord = []
# search cctv
for i in range(row):
    for j in range(col):
        if office[i][j] != '0' and office[i][j] != '6':
            cctvNo = int(office[i][j])
            cctvCoord.append((i, j, cctvNo))
            cctvN += 1
cctvPool = product(([1, 2, 3, 4]), repeat=cctvN)

def cntSight(board):
    cnt = 0
    for l in board:
        for r in l:
            if r == '0': cnt += 1
    return cnt

def sight(board, r, c, d):
    if d == 'r':
        for i in range(c+1, col):
            if board[r][i] == '6': break
            board[r][i] = '#'
    elif d == 'l':
        for i in range(c-1, -1, -1):
            if board[r][i] == '6': break
            board[r][i] = '#'
    elif d == 'u':
        for i in range(r-1, -1, -1):
            if board[i][c] == '6': break
            board[i][c] = '#'
    elif d == 'd':
        for i in range(r+1, row):
            if board[i][c] == '6': break
            board[i][c] = '#'
    else: raise NotImplementedError
    return board

# cctvPool에서 cctv 조합의 수를 하나씩 꺼내서
# 각 조합에 맞게 사무실의 시야를 색칠하고
# 0의 개수를 카운트한다.

def cctvOperation(board, ppp):
    for cctv, p in zip(cctvCoord, ppp):
        if cctv[-1] == 1:
            if p == 1:
                sight(board, cctv[0], cctv[1], 'r')
            if p == 2:
                sight(board, cctv[0], cctv[1], 'l')
            if p == 3:
                sight(board, cctv[0], cctv[1], 'u')
            if p == 4:
                sight(board, cctv[0], cctv[1], 'd')
        elif cctv[-1] == 2:
            if p%2:
                sight(board, cctv[0], cctv[1], 'r')
                sight(board, cctv[0], cctv[1], 'l')
            else:
                sight(board, cctv[0], cctv[1], 'u')
                sight(board, cctv[0], cctv[1], 'd')
        elif cctv[-1] == 3:
            if p == 1:
                sight(board, cctv[0], cctv[1], 'u')
                sight(board, cctv[0], cctv[1], 'r')
            if p == 2:
                sight(board, cctv[0], cctv[1], 'r')
                sight(board, cctv[0], cctv[1], 'd')
            if p == 3:
                sight(board, cctv[0], cctv[1], 'd')
                sight(board, cctv[0], cctv[1], 'l')
            if p == 4:
                sight(board, cctv[0], cctv[1], 'l')
                sight(board, cctv[0], cctv[1], 'u')
        elif cctv[-1] == 4:
            if p == 1:
                sight(board, cctv[0], cctv[1], 'l')
                sight(board, cctv[0], cctv[1], 'u')
                sight(board, cctv[0], cctv[1], 'r')
            elif p == 2:
                sight(board, cctv[0], cctv[1], 'u')
                sight(board, cctv[0], cctv[1], 'r')
                sight(board, cctv[0], cctv[1], 'd')
            elif p == 3:
                sight(board, cctv[0], cctv[1], 'r')
                sight(board, cctv[0], cctv[1], 'd')
                sight(board, cctv[0], cctv[1], 'l')
            elif p == 4:
                sight(board, cctv[0], cctv[1], 'd')
                sight(board, cctv[0], cctv[1], 'l')
                sight(board, cctv[0], cctv[1], 'u')
        elif cctv[-1] == 5:
            sight(board, cctv[0], cctv[1], 'l')
            sight(board, cctv[0], cctv[1], 'u')
            sight(board, cctv[0], cctv[1], 'r')
            sight(board, cctv[0], cctv[1], 'd')
        else: raise NotImplementedError
    return board

# blindSpot = []
# for pp in cctvPool:
#     n = cntSight(cctvOperation(deepcopy(office), pp))
#     blindSpot.append(n)
# print(blindSpot)
# print(min(blindSpot))

bs = 65
for pp in cctvPool:
    n = cntSight(cctvOperation(deepcopy(office), pp))
    bs = min(bs, n)
print(bs)