# 7569 토마토
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

# def getTomatoStatus(z, y, x):
#     if z < 0 or y < 0 or x < 0 or \
#         h <= z or n <= y or m <= x:
#         return -1
#     else: return tomatoBox[z][y][x]

def getNeighborTomato(z, y, x):
    # dz = [0, 0, 0, 0, 1, -1]
    # dy = [0, 0, 1, -1, 0, 0]
    # dx = [1, -1, 0, 0, 0, 0]
    # rtn = []
    # for i in range(6):
    #     coord = (z+dz[i], y+dy[i], x+dx[i])
    #     if getTomatoStatus(*coord) == 0:
    #         rtn.append(coord)
    # return rtn
    rtn = []
    if 0 <= x-1 and tomatoBox[x-1][y][z] == 0:
        rtn.append((z, y, x-1))
    if 0 <= y-1 and tomatoBox[x][y-1][z] == 0:
        rtn.append((z, y-1, x))
    if 0 <= z-1 and tomatoBox[x][y][z-1] == 0:
        rtn.append((z-1, y, x))
    if x+1 < m and tomatoBox[x+1][y][z] == 0:
        rtn.append((z, y, x+1))
    if y+1 < n and tomatoBox[x][y+1][z] == 0:
        rtn.append((z, y+1, x))
    if z+1 < h and tomatoBox[x][y][z+1] == 0:
        rtn.append((z+1, y, x))
    return rtn


def ripe(depth=0):
    global tomatoQue
    # if not tomatoQue : return -1
    if not tomatoQue: return depth
    nextQue = set([])
    for tomato in tomatoQue:
        tomatoBox[tomato[0]][tomato[1]][tomato[2]] = 1
        for coord in getNeighborTomato(*tomato):
            nextQue.add(coord)
    # if isAllRiped() : return depth
    tomatoQue = list(nextQue)
    return ripe(depth+1)

r = ripe()
if isAllRiped() : print(r)
else: print(-1)