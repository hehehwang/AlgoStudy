# 10026 적록색약
from collections import deque
input = __import__('sys').stdin.readline

bN = int(input())
board = [list(input()) for _ in range(bN)]
dr = [0, 0, 1, -1]
dc = [1, -1, 0, 0]
cntN, cntCb = 0, 0

vis = [[0]*bN for _ in range(bN)]
for ri in range(bN):
    for ci in range(bN):
        if vis[ri][ci]: continue
        Q = deque([(ri, ci)])
        cntN += 1
        while Q:
            v = Q.popleft()
            for i in range(4):
                nr, nc = v[0] + dr[i], v[1] + dc[i]
                if nr<0 or bN<=nr or nc<0 or bN<=nc: continue
                if vis[nr][nc]: continue
                if board[nr][nc] != board[v[0]][v[1]]: continue
                vis[nr][nc] = 1
                Q.append((nr, nc))

vis = [[0]*bN for _ in range(bN)]
for ri in range(bN):
    for ci in range(bN):
        if vis[ri][ci]: continue
        Q = deque([(ri, ci)])
        cntCb += 1
        while Q:
            v = Q.popleft()
            for i in range(4):
                nr, nc = v[0] + dr[i], v[1] + dc[i]
                if nr<0 or bN<=nr or nc<0 or bN<=nc: continue
                if vis[nr][nc]: continue
                if (board[nr][nc] == 'R' and board[v[0]][v[1]] == 'G') or \
                    (board[nr][nc] == 'G' and board[v[0]][v[1]] == 'R') or \
                    (board[nr][nc] == board[v[0]][v[1]]):
                    vis[nr][nc] = 1
                    Q.append((nr, nc))
                else: continue

print(cntN, cntCb)