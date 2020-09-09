# 7569 토마토 non-bfs 외틀렷을가?
from sys import setrecursionlimit, stdin
setrecursionlimit(10**9)
input = stdin.readline
m, n, h = map(int, input().split())
tomatoBox = [[[int(i) for i in input().split()] for i in range(n)] for j in range(h)]

tomatoQue = []
for z, tray in enumerate(tomatoBox):
    for y, line in enumerate(tray):
        for x, tomato in enumerate(line):
            if tomato == 1: tomatoQue.append((z, y, x))

def isAllRiped():
    for z in range(h):
        for y in range(n):
            if not all(tomatoBox[z][y]): return False
    return True

def getNeighborTomato(z, y, x):
    rtn = []
    if 0 <= z-1 and tomatoBox[z-1][y][x] == 0:
        rtn.append((z-1, y, x))
    if 0 <= y-1 and tomatoBox[z][y-1][x] == 0:
        rtn.append((z, y-1, x))
    if 0 <= x-1 and tomatoBox[z][y][x-1] == 0:
        rtn.append((z, y, x-1))
    if z+1 < h and tomatoBox[z+1][y][x] == 0:
        rtn.append((z+1, y, x))
    if y+1 < n and tomatoBox[z][y+1][x] == 0:
        rtn.append((z, y+1, x))
    if x+1 < m and tomatoBox[z][y][x+1] == 0:
        rtn.append((z, y, x+1))
    return rtn


day = 0
while tomatoQue:
    [print(t) for t in tomatoBox[0]]
    print(tomatoQue)
    print(day)
    print()
    nextQue = set([])
    for tomato in tomatoQue:
        tomatoBox[tomato[0]][tomato[1]][tomato[2]] = 1
        for coord in getNeighborTomato(*tomato):
            nextQue.add(coord)
    tomatoQue = list(nextQue)
    day += 1
if isAllRiped() : print(day-1)
else: print(-1)