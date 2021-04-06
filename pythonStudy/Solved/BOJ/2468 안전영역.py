# 2468 안전 영역
from collections import deque
input = __import__('sys').stdin.readline

bN = int(input())
board = [list(map(int, input().split())) for _ in range(bN)]
dr = [0, 0, 1, -1]
dc = [1, -1, 0, 0]

res = []
for wh in range(0, 101):
    cnt = 0
    vis = [[0] * bN for _ in range(bN)]
    for ri in range(bN):
        for ci in range(bN):
            if board[ri][ci] <= wh: continue
            if vis[ri][ci]: continue
            cnt += 1
            Q = deque([(ri, ci)])
            while Q:
                v = Q.popleft()
                for i in range(4):
                    nr, nc = v[0] + dr[i], v[1] + dc[i]
                    if nr<0 or bN<=nr or nc<0 or bN<=nc: continue
                    if vis[nr][nc]: continue
                    if board[nr][nc] <= wh: continue
                    vis[nr][nc] = 1
                    Q.append((nr, nc))
    res.append(cnt)
print(max(res))