# 2250 트리의 높이와 너비
input = __import__('sys').stdin.readline
__import__('sys').setrecursionlimit(10**9)

lc = [0]*10001
rc = [0]*10001
depth = [[0, 0] for _ in range(10001)]
n = int(input())
for i in range(n):
    p, l, r = map(int, input().split())
    lc[p] = l
    rc[p] = r

# 중위 순회
# 왼쪽 -> 나 -> 오른쪽
res = []
r = 0
def inorder(curr, d):
    global r
    if curr == -1:
        return 0
    inorder(lc[curr], d+1)
    r += 1
    res.append((d, curr))
    if not depth[d][0] or r < depth[d][0]: depth[d][0] = r
    if not depth[d][1] or depth[d][1] < r: depth[d][1] = r
    inorder((rc[curr]), d+1)

def findRoot():
    global n
    lst = [False] + [True]*n
    for l in lc:
        if l != -1: lst[l] = False
    for r in rc:
        if r != -1: lst[r] = False
    for i, v in enumerate(lst):
        if v: return i
inorder(findRoot(), 0)
mxWidth = 0
mxDepth = 0
# print(lc)
# print(rc)
# [print(d, end=' ') for d in res]
# print()
# [print(d, end=' ') for d in depth]
# print()
for i, d in enumerate(depth):
    if not sum(d): break
    width = d[1]-d[0]+1
    if mxWidth < width:
        mxWidth = width
        mxDepth = i
print(mxDepth+1, mxWidth)