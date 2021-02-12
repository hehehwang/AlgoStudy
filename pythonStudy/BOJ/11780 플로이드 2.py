# 11780 플로이드 2
input = __import__('sys').stdin.readline

n, m = int(input()), int(input())
n += 1
mxN = 10**8+1
floyd = [[mxN]*(n) for _ in range(n)]
enroute = [[0]*(n) for _ in range(n)]

for _ in range(m):
    a, b, c = map(int, input().split())
    floyd[a][b] = min(floyd[a][b], c)
    enroute[a][b] = b

for k in range(1, n):
    for i in range(1, n):
        if i == k: continue
        for j in range(1, n):
            if j == k: continue
            if i == j: floyd[i][j] = 0
            bypass = floyd[i][k] + floyd[k][j]
            if bypass < floyd[i][j]:
                floyd[i][j] = bypass
                enroute[i][j] = enroute[i][k]
            # floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j])
for i in range(n):
    for j in range(n):
        if floyd[i][j] == mxN: floyd[i][j] = 0
[print(' '.join(map(str, f[1:]))) for f in floyd[1:]]
# print()
# [print(' '.join(map(str, f[1:]))) for f in enroute[1:]]
# print()
for i in range(1, n):
    for j in range(1, n):
        if i==j:
            print(0)
            continue
        route = [i]
        while route[-1] != j:
            route.append(enroute[route[-1]][j])
        print(len(route), end=' ')
        print(' '.join(map(str, route)))