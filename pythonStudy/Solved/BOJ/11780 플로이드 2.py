# 11780 플로이드 2
input = __import__('sys').stdin.readline

n, m = int(input()), int(input())
n += 1
mxN = 10**8+1
floyd = [[mxN]*(n) for _ in range(n)]
route = [[0]*(n) for _ in range(n)]

for _ in range(m):
    a, b, c = map(int, input().split())
    floyd[a][b] = min(floyd[a][b], c)
    route[a][b] = b

for k in range(1, n):
    for i in range(1, n):
        if i == k: continue
        for j in range(1, n):
            if j == k: continue
            if i == j: floyd[i][j] = 0
            bypass = floyd[i][k] + floyd[k][j]
            if bypass < floyd[i][j]:
                floyd[i][j] = bypass
                route[i][j] = route[i][k]

for i in range(n):
    for j in range(n):
        if floyd[i][j] == mxN: floyd[i][j] = 0

[print(' '.join(map(str, f[1:]))) for f in floyd[1:]]
for i in range(1, n):
    for j in range(1, n):
        if i==j:
            print(0)
            continue
        nxt = [i]
        while 1:
            if nxt[-1] == j:
                print(len(nxt), ' '.join(map(str, nxt)))
                break
            elif nxt[-1] == 0:
                print(0)
                break
            nxt.append(route[nxt[-1]][j])