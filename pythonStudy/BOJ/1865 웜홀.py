# 1865 웜홀
input = __import__('sys').stdin.readline
INF = 10e9+1
for _ in range(int(input())):
    n, r, w = map(int, input().split())
    adj = [[] for _ in range(n+1)]
    for i in range(r):
        a, b, c = map(int, input().split())
        adj[a].append((c, b))
        adj[b].append((c, a))
    for i in range(w):
        a, b, c = map(int, input().split())
        adj[a].append((-c, b))

    upper = [INF]*(n+1)
    upper[1] = 0
    updated = False
    for i in range(n):
        updated = False
        for v in range(1, n+1):
            for nv in adj[v]:
                if upper[v] + nv[0] < upper[nv[1]]:
                    updated = True
                    upper[nv[1]] = upper[v] + nv[0]
        if not updated:
            print('NO')
            break
    if updated:
        print('YES')