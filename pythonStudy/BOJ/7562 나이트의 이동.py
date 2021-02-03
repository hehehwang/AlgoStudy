# 7562 나이트의 이동
from collections import deque
input = __import__('sys').stdin.readline

dr = [2, 2, 1, 1, -1, -1, -2, -2]
dc = [1, -1, 2, -2, 2, -2, 1, -1]

for i in range(int(input())):
    bN = int(input())
    board = [[0]*bN for _ in range(bN)]
    vis = [[0]*bN for _ in range(bN)]
    now = tuple(map(int, input().split()))
    dest = tuple(map(int, input().split()))
    Q = deque([now])
    vis[now[0]][now[1]] = 1
    while not vis[dest[0]][dest[1]]:
        v = Q.popleft()
        for i in range(8):
            nr, nc = v[0]+dr[i], v[1]+dc[i]
            if nr<0 or bN<=nr or nc<0 or bN<=nc: continue
            if vis[nr][nc]: continue
            board[nr][nc] = board[v[0]][v[1]] + 1
            vis[nr][nc] = 1
            Q.append((nr, nc))
    print(board[dest[0]][dest[1]])