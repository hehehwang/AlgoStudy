# 1922 네트워크 연결
input = __import__('sys').stdin.readline
__import__('sys').setrecursionlimit(10**9)

v = int(input())
e = int(input())
edge = []
for i in range(e):
    a, b, c = map(int, input().split())
    if a!=b: edge.append((a, b, c))
grpNo = [i for i in range(v+1)]

def find(v):
    if v == grpNo[v]: return v
    grpNo[v] = find(grpNo[v])
    return grpNo[v]
def unite(v1, v2):
    if v2<v1: v1, v2 = v2, v1
    grpNo[find(v2)] = find(v1)

edge.sort(key = lambda x:x[2])
tCost = 0
for ne in edge:
    a, b, c = ne
    if find(a) != find(b):
        unite(a, b)
        tCost+=c
print(tCost)