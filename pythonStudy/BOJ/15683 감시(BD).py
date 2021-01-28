# 15683 감시(BD)
from copy import deepcopy

input = __import__('sys').stdin.readline

row, col = map(int, input().split())
dr = [0, 1, 0, -1]
dc = [1, 0, -1, 0]
office = [list(map(int, input().split())) for _ in range(row)]
officeCpy = [[]]

cctvCoord = []
cctvN = 0

for i in range(row):
    for j in range(col):
        if office[i][j] != 6 and office[i][j]:
            cctvCoord.append((i, j))
            cctvN += 1

def oob(r, c):
    return (r<0) or (row<=r) or (c<0) or (col<=c)

def upd(r, c, i):
    i %= 4
    if oob(r, c) or officeCpy[r][c] == 6: return
    if officeCpy[r][c] == 0: officeCpy[r][c] = 7
    upd(r+dr[i], c+dc[i], i)

bs = 65
for combi in range(1<<(2*cctvN)):
    officeCpy = deepcopy(office)
    for cctvIdx in range(cctvN):
        dir = combi%4
        combi >>= 2
        cr, cc = cctvCoord[cctvIdx]
        if officeCpy[cr][cc] == 1:
            upd(cr, cc, dir)
        elif officeCpy[cr][cc] == 2:
            upd(cr, cc, dir)
            upd(cr, cc, dir+2)
        elif officeCpy[cr][cc] == 3:
            upd(cr, cc, dir)
            upd(cr, cc, dir+1)
        elif officeCpy[cr][cc] == 4:
            upd(cr, cc, dir)
            upd(cr, cc, dir+1)
            upd(cr, cc, dir+2)
        else:
            upd(cr, cc, dir)
            upd(cr, cc, dir+1)
            upd(cr, cc, dir+2)
            upd(cr, cc, dir+3)

    b = 0
    for i in range(row):
        for j in range(col):
            b += 0 if officeCpy[i][j] else 1
    bs = min(bs, b)

print(bs)
