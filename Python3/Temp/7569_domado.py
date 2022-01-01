# 내 도마도는 왜 이 모양인가
from collections import deque
from itertools import product

################################
def isAllRiped():
    for y in range(n):
        if not all(tomatoTray[y]): return False
    return True


def getNeighborTomato(y, x):
    global tomatoTray
    rtn = []
    if 0 <= y - 1 and tomatoTray[y - 1][x] == 0:
        rtn.append((y - 1, x))
        tomatoTray[y-1][x] = 1
    if 0 <= x - 1 and tomatoTray[y][x - 1] == 0:
        rtn.append((y, x - 1))
        tomatoTray[y][x-1] = 1
    if y + 1 < n and tomatoTray[y + 1][x] == 0:
        rtn.append((y + 1, x))
        tomatoTray[y+1][x] = 1
    if x + 1 < m and tomatoTray[y][x + 1] == 0:
        rtn.append((y, x + 1))
        tomatoTray[y][x+1] = 1
    return rtn
##################################

n, m = 4, 4
tomatoProba = product([-1, 0, 1], repeat=n*m)
totalProba = 3**(4*4)
print(totalProba)
for i, proba in enumerate(tomatoProba):
    ##### answer code
    tomatoTray = [list(proba[i:i+m]) for i in range(n)]
    tomatoQue = deque([])

    for y, line in enumerate(tomatoTray):
        for x, tomato in enumerate(line):
            if tomato == 1:
                tomatoQue.append((y, x))

    while tomatoQue:
        y, x = tomatoQue.popleft()
        curr = tomatoTray[y][x]
        if 0 <= y - 1 and tomatoTray[y - 1][x] == 0:
            tomatoQue.append((y - 1, x))
            tomatoTray[y - 1][x] = curr + 1
        if 0 <= x - 1 and tomatoTray[y][x - 1] == 0:
            tomatoQue.append((y, x - 1))
            tomatoTray[y][x - 1] = curr + 1
        if y + 1 < n and tomatoTray[y + 1][x] == 0:
            tomatoQue.append((y + 1, x))
            tomatoTray[y + 1][x] = curr + 1
        if x + 1 < m and tomatoTray[y][x + 1] == 0:
            tomatoQue.append((y, x + 1))
            tomatoTray[y][x + 1] = curr + 1

    # 만약 덜익은 토마토가 있으면 -1, 아니면 최대 거리 계산
    maxT, notRiped = 0, False
    for line in tomatoTray:
        for t in line:
            if t == 0:
                notRiped = True
                break
            else:
                maxT = max(maxT, t)
    answer = -1 if notRiped else (maxT - 1)


    ##### error code
    # 7569 토마토(3D) non-bfs
    tomatoTray = [list(proba[i:i+m]) for i in range(n)]
    tomatoQue = []

    for y, line in enumerate(tomatoTray):
        for x, tomato in enumerate(line):
            if tomato == 1: tomatoQue.append((y, x))

    if tomatoQue:
        day = 0
        tomatoQue = [getNeighborTomato(*coord) for coord in tomatoQue]
        tomatoQue = sum(tomatoQue, [])
        while tomatoQue:
            nextQue = set([])
            for tomato in tomatoQue:
                for coord in getNeighborTomato(*tomato):
                    nextQue.add(coord)
            tomatoQue = list(nextQue)
            day += 1
        error = day if isAllRiped() else -1
    else: error = -1

    #############

    if answer != error:
        print('error occurred')
        print('answer :', answer)
        print('error :', error)
        print('problem below')
        print(n, m)
        tray = [list(proba[i:i+m]) for i in range(n)]
        [print(' '.join(map(str, tray[i]))) for i in range(n)]
        print()

    if i%1000000 == 0:
        print(round(i/totalProba, 2))
print('Done')