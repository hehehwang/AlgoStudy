# 7576 토마토 non-bfs (TL)
input = __import__('sys').stdin.readline
m, n = map(int, input().split())
tomatoTray = [[int(i) for i in input().split()] for i in range(n)]
tomatoQue = []

for y, line in enumerate(tomatoTray):
    for x, tomato in enumerate(line):
        if tomato == 1: tomatoQue.append((y, x))

def isAllRiped():
    for y in range(n):
        if not all(tomatoTray[y]): return False
    return True

def getNeighborTomato(y, x):
    rtn = []
    if 0 <= y-1 and tomatoTray[y-1][x] == 0:
        tomatoTray[y-1][x] = 1
        rtn.append((y-1, x))
    if 0 <= x-1 and tomatoTray[y][x-1] == 0:
        tomatoTray[y][x-1] = 1
        rtn.append((y, x-1))
    if y+1 < n and tomatoTray[y+1][x] == 0:
        tomatoTray[y+1][x] = 1
        rtn.append((y+1, x))
    if x+1 < m and tomatoTray[y][x+1] == 0:
        tomatoTray[y][x+1] = 1
        rtn.append((y, x+1))
    return rtn

day = 0
if tomatoQue:
    tomatoQue = [getNeighborTomato(*coord) for coord in tomatoQue]
    tomatoQue = sum(tomatoQue, [])
    while tomatoQue:
        nextQue = set([])
        for tomato in tomatoQue:
            for coord in getNeighborTomato(*tomato):
                nextQue.add(coord)
        tomatoQue = list(nextQue)
        day += 1

    print(day if isAllRiped() else -1)
else:
    print(-1)

# 방문 표시를 뽑을 때 하게 되면 방문 여부를 가리며 가지를 확장시키는 것과 방문 했다고 표시하는 같은 단계에서 하게된다.
# 이 때문에 뽑는 순서에 따라 가지가 확장이 될수도 있고 안 될수도 있어 좋은 방법잉 아니다.
# 그러나 방문 표시를 넣을 때 하게 되면 이 효과가 다음 번 뽑을 때 나타나므로 이변의 여지가 없게 된다.