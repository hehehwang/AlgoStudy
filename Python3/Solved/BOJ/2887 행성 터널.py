# 2887 행성 터널
# https://www.acmicpc.net/problem/2887
import heapq
input = __import__('sys').stdin.readline

N = int(input())
points = [(i, *map(int, input().split())) for i in range(N)]
grpNo = [i for i in range(N)]


def find(x):
    if grpNo[x] == x:
        return x
    grpNo[x] = find(grpNo[x])
    return grpNo[x]


def unite(a, b):
    if b < a:
        a, b = b, a
    grpNo[find(b)] = find(a)


def dist(a, b):
    return min(abs(i-j) for i, j in zip(a[1:], b[1:]))

lst, ans = [], 0
for k in range(1, 4):
    points.sort(key=lambda x: x[k])
    for i in range(N-1):
        ptA, ptB = points[i], points[i+1]
        heapq.heappush(lst, (dist(ptA, ptB), ptA[0], ptB[0]))

while lst:
    d, a, b = heapq.heappop(lst)
    if find(a) != find(b):
        ans += d
        unite(a, b)
print(ans)