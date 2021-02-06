# 1941 소문난 칠공주
from itertools import combinations
input = __import__('sys').stdin.readline

board = [input().strip() for _ in range(5)]
dr = [0, 0, 1, -1]
dc = [1, -1, 0, 0]

pool = combinations(range(25), 7)
ans = 0
for combi in pool:
    som = 0
    history = []
    for princess in combi:
        r, c = princess%5, princess//5
        som += int(board[r][c] == 'S')
        history.append((r, c))
    if 4<=som:
        connected = [False]*7
        stk = [history[0]]
        while stk:
            r, c = stk.pop()
            for k in range(4):
                nr = r + dr[k]
                nc = c + dc[k]
                if nr<0 or nc<0 or 5<=nr or 5<=nc: continue
                for j in range(7):
                    if history[j] == (nr, nc) and not connected[j]:
                        connected[j] = True
                        stk.append((nr, nc))
                        break
        if sum(connected) == 7:
            ans += 1
            # print(history)

print(ans)