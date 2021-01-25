# 7576 토마토(복습)
from collections import deque
input = __import__('sys').stdin.readline

w, h = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(h)]
dur = [[0]*w for _ in range(h)]
dy = [0, 0, 1, -1]
dx = [1, -1, 0, 0]
Q = deque([])

for i in range(h):
    for j in range(w):
        if board[i][j] == 1:
            Q.append((i, j))
            dur[i][j] = 1

while Q:
    v = Q.popleft()
    for i in range(4):
        ny = v[0] + dy[i]
        nx = v[1] + dx[i]
        if ny < 0 or h <= ny or nx < 0 or w <= nx: continue
        if board[ny][nx] == -1 or dur[ny][nx]: continue
        dur[ny][nx] = dur[v[0]][v[1]] + 1
        Q.append((ny, nx))

# [print(' '.join(map(str, l))) for l in dur]

F, mxDur = True, 0
for i in range(h):
    for j in range(w):
        if board[i][j] != -1 and dur[i][j] == 0:
            F = False
            break
        mxDur = max(dur[i][j], mxDur)
print(mxDur-1 if F else -1)