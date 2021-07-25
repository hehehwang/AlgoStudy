# 18808 스티커 붙이기
input = __import__('sys').stdin.readline

nbRow, nbCol, stkN = map(int, input().split())
nb = [[0] * nbCol for _ in range(nbRow)]

def oob(r, c):
    return r < 0 or nbRow <= r or c < 0 or nbCol <= c

def fill(stk, nbR, nbC):
    r, c = len(stk), len(stk[0])
    for i in range(r):
        for j in range(c):
            if stk[i][j]: nb[nbR+i][nbC+j] = 1

def match(stk, nbr, nbc):
    r, c = len(stk), len(stk[0])
    for i in range(r):
        for j in range(c):
            if (nb[nbr+i][nbc+j] & stk[i][j]): return False
    return True

for _ in range(stkN):
    stkR, stkC = map(int, input().split())
    stk = [[] for _ in range(4)]
    stk[0] = [list(map(int, input().split())) for _ in range(stkR)]
    stk[1] = [[0]*stkR for _ in range(stkC)]
    stk[2] = [[0]*stkC for _ in range(stkR)]
    stk[3] = [[0]*stkR for _ in range(stkC)]
    for i in range(stkR):
        for j in range(stkC):
            stk[2][stkR-i-1][stkC-j-1] = stk[0][i][j]
    for j in range(stkC):
        for i in range(stkR):
            stk[1][j][stkR-i-1], stk[3][stkC-j-1][i] = stk[0][i][j], stk[0][i][j]

    done = False
    for nStk in stk:
        if done: break
        sR, sC = len(nStk), len(nStk[0])
        for nbr in range(nbRow-sR+1):
            if done: break
            for nbc in range(nbCol-sC+1):
                if match(nStk, nbr, nbc):
                    done = True
                    fill(nStk, nbr, nbc)
                    break

# [print(l) for l in nb]
# print()
print(sum([sum(l) for l in nb]))
