# 2583 영역 구하기
from collections import deque
input = __import__('sys').stdin.readline

c, r, rn = map(int, input().split())
board = [[1]*c for _ in range(r)]
vis = [[0]*c for _ in range(r)]
Q = deque([])
dr = [0, 0, 1, -1]
dc = [1, -1, 0, 0]
cnt = 0
area = []

for i in range(rn):
    r1, c1, r2, c2 = map(int, input().split())
    for ri in range(r1, r2):
        for ci in range(c1, c2):
            board[ri][ci] = 0

for i in range(r):
    for j in range(c):
        if not board[i][j]: continue
        if vis[i][j]: continue
        Q.append((i, j))
        vis[i][j] = 1
        cnt += 1
        tmp = 1
        while Q:
            v = Q.popleft()
            for k in range(4):
                nr = v[0] + dr[k]
                nc = v[1] + dc[k]
                if nr<0 or r<=nr or nc<0 or c<=nc: continue
                if not board[nr][nc]: continue
                if vis[nr][nc]: continue
                Q.append((nr, nc))
                vis[nr][nc] = 1
                tmp += 1
        area.append(tmp)
# [print(l) for l in board]
print(cnt)
print(' '.join(map(str, sorted(area))))