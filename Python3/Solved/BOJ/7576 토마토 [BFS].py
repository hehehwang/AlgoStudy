# 7576 토마토 BFS
from collections import deque
input = __import__('sys').stdin.readline
m, n = map(int, input().split())
tomatoTray = [[int(i) for i in input().split()] for j in range(n)]
tomatoQue = deque([])

for y, line in enumerate(tomatoTray):
    for x, tomato in enumerate(line):
        if tomato == 1:
            tomatoQue.append((y, x))

# 토마토 큐에서 하나를 뽑아서 확장한다.
while tomatoQue:
    y, x = tomatoQue.popleft()
    curr = tomatoTray[y][x]
    if 0 <= y-1 and tomatoTray[y-1][x] == 0:
        tomatoQue.append((y-1, x))
        tomatoTray[y-1][x] = curr+1
    if 0 <= x-1 and tomatoTray[y][x-1] == 0:
        tomatoQue.append((y, x-1))
        tomatoTray[y][x-1] = curr+1
    if y+1 < n and tomatoTray[y+1][x] == 0:
        tomatoQue.append((y+1, x))
        tomatoTray[y+1][x] = curr+1
    if x+1 < m and tomatoTray[y][x+1] == 0:
        tomatoQue.append((y, x+1))
        tomatoTray[y][x+1] = curr+1

# 만약 덜익은 토마토가 있으면 -1, 아니면 최대 거리 계산
maxT, notRiped = 0, False
for line in tomatoTray:
    for t in line:
        if t == 0:
            notRiped=True
            break
        else:
            maxT = max(maxT, t)

print(-1 if notRiped else (maxT-1))