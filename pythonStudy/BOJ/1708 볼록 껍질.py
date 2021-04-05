# 1708 볼록 껍질
from functools import cmp_to_key
input = __import__('sys').stdin.readline

MXN = 40_001
def ccw(x1, y1, x2, y2, x3, y3):
    return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1)
def subVec(a, b):
    return (a[0] - b[0], a[1] - b[1])
def sortKey(itm):
    global cp
    x, y = subVec(itm, cp)
    if x:
        return (y / x, x, y)  # floating point
    else:
        return (2 * MXN, x, y)
def cmp(itm1, itm2):
    cc = ccw(*cp, *itm1, *itm2)
    if (cc): return -cc
    # return sum(itm1) - sum(itm2)
    if (itm1[0] - itm2[0]): return itm1[0]-itm2[0]
    return itm1[1]-itm2[1]

pts = []
cp = (MXN, MXN)  # control point
ptn = 0
for _ in range(int(input())):
    a, b = map(int, input().split())
    if (a, b) < cp:
        if cp[0] != MXN: pts.append(cp)
        cp = (a, b)
    else:
        pts.append((a, b))

pts.sort(key=cmp_to_key(cmp)) # or key = sortKey
print(cp, pts)
stk = [cp, pts[0]]
for idx in range(1, len(pts)):
    pt = pts[idx]
    while (2 <= len(stk) and ccw(*stk[-2], *stk[-1], *pt) <= 0):
        stk.pop()
    stk.append(pt)
# print(stk)
print(len(stk))
