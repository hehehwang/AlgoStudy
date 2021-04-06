# 2665 미로 만들기 (BFS)
from collections import deque
input = __import__('sys').stdin.readline

N = int(input())
board = [[int(c) for c in input().strip()] for _ in range(N)]
vis = [[10**9+2]*N for _ in range(N)]
Q = deque([(0, 0)])
vis[0][0] = 0
dr = [0, 0, 1, -1]
dc = [1, -1, 0, 0]

while Q:
    vr, vc = Q.popleft()
    for k in range(4):
        nr, nc = vr+dr[k], vc+dc[k]
        if (nr<0 or nc<0 or N<=nr or N<=nc): continue
        newCost = vis[vr][vc] + 1 - board[nr][nc]
        if (vis[nr][nc] <= newCost): continue
        vis[nr][nc] = newCost
        Q.append((nr, nc))
print(vis[-1][-1])