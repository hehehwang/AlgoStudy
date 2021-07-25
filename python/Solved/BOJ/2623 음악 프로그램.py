# 2623 음악 프로그램
from collections import deque
input = __import__('sys').stdin.readline

preq = [[] for _ in range(1002)]
indeg = [0]*1002
nodeg = deque([])
res = []
n, m = map(int, input().split())
for _ in range(m):
    lst = list(map(int, input().split()))[1:]
    for i in range(len(lst)-1):
        a, b = lst[i], lst[i+1]
        preq[a].append(b)
        indeg[b] += 1
for i in range(1, n+1):
    if not indeg[i]: nodeg.append(i)
while nodeg:
    v = nodeg.popleft()
    res.append(v)
    for nv in preq[v]:
        indeg[nv] -= 1
        if not indeg[nv]: nodeg.append(nv)

if len(res) != n: print(0)
else: [print(r) for r in res]