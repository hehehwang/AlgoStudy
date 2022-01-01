# 7569 토마토(3D) BFS
from sys import setrecursionlimit, stdin
from collections import deque
setrecursionlimit(10**9)
input = stdin.readline
m, n, h = map(int, input().split())
tomatoBox = [[[int(i) for i in input().split()] for j in range(n)] for k in range(h)]
# visit = [[[False]*m for i in range(n)] for j in range(h)]
#
# dz = [0, 0, 0, 0, 1, -1]
# dy = [0, 0, 1, -1, 0, 0]
# dx = [1, -1, 0, 0, 0, 0]

tomatoQue = deque([])
for z, tray in enumerate(tomatoBox):
    for y, line in enumerate(tray):
        for x, tomato in enumerate(line):
            if tomato == 1:
                tomatoQue.append((z, y, x))
            # if tomato != 0: visit[z][y][x] = True

# 토마토 큐에서 하나를 뽑아서 확장한다.
while tomatoQue:
    # cz, cy, cx = tomatoQue.popleft()
    # curr = tomatoBox[cz][cy][cx]
    # for i in range(6):
    #     nz, ny, nx = cz+dz[i], cy+dy[i], cx+dx[i]
    #     if nz<0 or ny<0 or nx<0 or h<=nz or n<=ny or m<=nx: continue
    #     if visit[nz][ny][nx]: continue
    #     if tomatoBox[nz][ny][nx] != 0: continue
    #     tomatoBox[nz][ny][nx] = curr + 1
    #     visit[nz][ny][nx] = True
    #     tomatoQue.append((nz, ny, nx))
    z, y, x = tomatoQue.popleft()
    curr = tomatoBox[z][y][x]
    if 0 <= z-1 and tomatoBox[z-1][y][x] == 0:
        tomatoQue.append((z-1, y, x))
        tomatoBox[z-1][y][x] = curr+1
    if 0 <= y-1 and tomatoBox[z][y-1][x] == 0:
        tomatoQue.append((z, y-1, x))
        tomatoBox[z][y-1][x] = curr+1
    if 0 <= x-1 and tomatoBox[z][y][x-1] == 0:
        tomatoQue.append((z, y, x-1))
        tomatoBox[z][y][x-1] = curr+1
    if z+1 < h and tomatoBox[z+1][y][x] == 0:
        tomatoQue.append((z+1, y, x))
        tomatoBox[z+1][y][x] = curr+1
    if y+1 < n and tomatoBox[z][y+1][x] == 0:
        tomatoQue.append((z, y+1, x))
        tomatoBox[z][y+1][x] = curr+1
    if x+1 < m and tomatoBox[z][y][x+1] == 0:
        tomatoQue.append((z, y, x+1))
        tomatoBox[z][y][x+1] = curr+1

# 만약 덜익은 토마토가 있으면 -1, 아니면 최대 거리 계산
maxT, notRiped = 0, False
for tray in tomatoBox:
    for line in tray:
        for t in line:
            if t == 0:
                notRiped=True
                break
            else:
                maxT = max(maxT, t)
    if notRiped: break

# print(tomatoBox)
print(-1 if notRiped else (maxT-1))
