# 1005 ACM Craft
input = __import__('sys').stdin.readline

for _ in range(int(input())):
    n, m = map(int, input().split())
    tC = [0] + list(map(int, input().split()))
    dp = [0]*(n+1)
    preQ = [[] for _ in range(n+1)]
    proQ = [[] for _ in range(n+1)]
    inDeg = [0]*(n+1)
    noDeg = []
    for i in range(m):
        a, b = map(int, input().split())
        proQ[a].append(b)
        preQ[b].append(a)
        inDeg[b] += 1
    target = int(input())
    for i in range(1, n+1):
        if not inDeg[i]: noDeg.append(i)
    while noDeg:
        v = noDeg.pop()
        if preQ[v]: dp[v] = max([dp[i] for i in preQ[v]]) + tC[v]
        else: dp[v] = tC[v]
        if v == target: break
        for nv in proQ[v]:
            inDeg[nv] -= 1
            if not inDeg[nv]: noDeg.append(nv)
    print(dp[target])