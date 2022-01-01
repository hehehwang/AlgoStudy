# 11779 최소 비용 구하기 2
from heapq import *
input = __import__('sys').stdin.readline

V, E = int(input()), int(input())
INF = 10**10+2
adj = [[] for _ in range(V+1)]
for _ in range(E):
    a, b, c = map(int, input().split())
    adj[a].append((c, b))
F, T = map(int, input().split())
pQ = [(0, F)]
minCost = [INF]*(V+1)
minCost[F] = 0
route = [0]*(V+1)
while pQ:
    v = heappop(pQ)
    vc, vv = v
    if vc != minCost[vv]: continue
    for nv in adj[vv]:
        nvc, nvv = nv
        newCost = nvc + vc
        if minCost[nvv] <= newCost: continue
        minCost[nvv] = newCost
        heappush(pQ, (newCost, nvv))
        route[nvv] = vv
print(minCost[T])
path = [T]
while path[-1] != F:
    path.append(route[path[-1]])
print(len(path))
print(' '.join(map(str, path[::-1])))

