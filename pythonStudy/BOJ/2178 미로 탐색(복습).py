# 2178 미로 탐색(복습)
from collections import deque
input = __import__('sys').stdin.readline

h, w = map(int, input().split())
board = [list(map(int, input().strip())) for _ in range(h)]
dy = [1, -1, 0 ,0]
dx = [0, 0, 1, -1]
vis = [[-1]*w for _ in range(h)]
vis[0][0] = 1
Q = deque([(0, 0)])

cntMin = 0

while Q:
    v = Q.popleft()
    for i in range(4):
        ny, nx = v[0] + dy[i], v[1] + dx[i]
        if ny<0 or h<=ny or nx<0 or w<=nx: continue
        if not (board[ny][nx]) or vis[ny][nx] != -1: continue
        vis[ny][nx] = vis[v[0]][v[1]] + 1
        Q.append((ny, nx))

# [print(' '.join(map(str, l))) for l in vis]
print(vis[-1][-1])