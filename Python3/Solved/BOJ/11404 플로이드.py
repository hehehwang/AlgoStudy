# 11404 플로이드
input = __import__('sys').stdin.readline

n, m = int(input()), int(input())
mxN = 10**8+1
floyd = [[mxN]*n for _ in range(n)]
for _ in range(m):
    a, b, c = map(int, input().split())
    a -= 1
    b -= 1
    floyd[a][b] = min(floyd[a][b], c)
for k in range(n):
    for i in range(n):
        if i == k: continue
        for j in range(n):
            if j == k: continue
            if i == j: floyd[i][j] = 0
            floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j])
for i in range(n):
    for j in range(n):
        if floyd[i][j] == mxN: floyd[i][j] = 0
[print(' '.join(map(str, f))) for f in floyd]