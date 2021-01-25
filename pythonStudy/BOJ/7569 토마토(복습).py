# 7569 토마토(복습)
from collections import deque
input = __import__('sys').stdin.readline

w, h, z= map(int, input().split())
board = [[list(map(int, input().split())) for i in range(h)] for j in range(z)]
dur = [[[0]*w for i in range(h)] for j in range(z)]
dz = [1, -1, 0, 0, 0, 0]
dy = [0, 0, 1, -1, 0, 0]
dx = [0, 0, 0, 0, 1, -1]
Q = deque([])

for k in range(z):
    for i in range(h):
        for j in range(w):
            if board[k][i][j] == 1:
                Q.append((k, i, j))
                dur[k][i][j] = 1
            elif board[k][i][j] == 0:
                dur[k][i][j] = -1

while Q:
    v = Q.popleft()
    for i in range(6):
        nz = v[0] + dz[i]
        ny = v[1] + dy[i]
        nx = v[2] + dx[i]
        if ny<0 or h<=ny or nx<0 or w<=nx or nz<0 or z<=nz: continue
        if dur[nz][ny][nx] >= 0: continue
        dur[nz][ny][nx]  = dur[v[0]][v[1]][v[2]] + 1
        Q.append((nz, ny, nx))

# [print(' '.join(map(str, l))) for l in dur]

F, mxDur = True, 0
for k in range(z):
    for i in range(h):
        for j in range(w):
            if dur[k][i][j] == -1:
                F = False
                break
            mxDur = max(dur[k][i][j], mxDur)
print(mxDur-1 if F else -1)