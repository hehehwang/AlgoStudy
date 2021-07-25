# 2206 벽 부수고 이동하기
from collections import deque
input = __import__('sys').stdin.readline

bR, bC = map(int, input().split())
board = [list(map(int, input().strip())) for _ in range(bR)]
vis = [[[0]*bC for _ in range(bR)] for _ in range(2)]
dr = [0, 0, 1, -1]
dc = [1, -1, 0, 0]

def oob(r, c):
    return r<0 or bR<=r or c<0 or bC<=c

Q = deque([(0, 0, 0)])
vis[0][0][0] = 1
while Q:
    v = Q.popleft()
    for i in range(4):
        nr, nc, brk = v[0]+dr[i], v[1]+dc[i], v[2]
        if oob(nr, nc): continue
        if brk:
            if board[nr][nc]: continue
            if vis[1][nr][nc]: continue
            vis[1][nr][nc] = vis[1][v[0]][v[1]] + 1
            Q.append((nr, nc, 1))
        else:
            if board[nr][nc]: brk=1
            if vis[brk][nr][nc]: continue
            vis[brk][nr][nc] = vis[0][v[0]][v[1]] + 1
            Q.append((nr, nc, brk))

# [print(l) for l in vis[0]]
# print()
# [print(l) for l in vis[1]]
# print()

if vis[0][bR-1][bC-1] and vis[1][bR-1][bC-1]:
    print(min(vis[0][bR-1][bC-1], vis[1][bR-1][bC-1]))
elif vis[1][bR-1][bC-1]:
    print(vis[1][bR-1][bC-1])
elif vis[0][bR-1][bC-1]:
    print(vis[0][bR-1][bC-1])
else: print(-1)