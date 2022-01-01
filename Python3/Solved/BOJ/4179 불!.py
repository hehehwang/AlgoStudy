# 4179 불!
from collections import deque
input = __import__('sys').stdin.readline

maxN = int(10E9)

r, c = map(int, input().split())
board = [list(input().strip()) for _ in range(r)]
fVis = [[maxN]*c for _ in range(r)]
jVis = [[0]*c for _ in range(r)]
dy = [0, 0, 1, -1]
dx = [1, -1, 0, 0]
fQ, jQ = deque([]), deque([])
escape = False

for i in range(r):
    for j in range(c):
        if board[i][j] == 'F':
            fQ.append((i, j))
            fVis[i][j] = 1
        elif board[i][j] == 'J':
            jQ.append((i, j))
            jVis[i][j] = 1
## Fire!
while fQ:
    v = fQ.popleft()
    for i in range(4):
        ny = v[0] + dy[i]
        nx = v[1] + dx[i]
        if ny<0 or r<=ny or nx<0 or c<=nx: continue
        if board[ny][nx] == '#' or fVis[ny][nx] != maxN: continue
        fVis[ny][nx] = fVis[v[0]][v[1]] + 1
        fQ.append((ny, nx))

## J
while jQ and not escape:
    v = jQ.popleft()
    for i in range(4):
        ny = v[0] + dy[i]
        nx = v[1] + dx[i]
        if ny<0 or r<=ny or nx<0 or c<=nx:
            print(jVis[v[0]][v[1]])
            escape = True
            break
        if board[ny][nx] == '#': continue
        if fVis[ny][nx] <= jVis[v[0]][v[1]]+1: continue
        if jVis[ny][nx]: continue
        jVis[ny][nx] = jVis[v[0]][v[1]] + 1
        jQ.append((ny, nx))

if not escape: print('IMPOSSIBLE')

# print('BOARD: ')
# [print(' '.join(map(str, l))) for l in board]
# print()
# print('FVIS: ')
# [print(' '.join(map(str, l))) for l in fVis]
# print()
# print('JVIS: ')
# [print(' '.join(map(str, l))) for l in jVis]
# print()
