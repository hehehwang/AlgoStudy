# 4225 쓰레기 슈트
from math import *
input = __import__('sys').stdin.readline

def dist(p1x, p1y, p2x, p2y, p3x, p3y):
    return ((p3y-p1y)*(p2x-p1x) - (p3x-p1x)*(p2y-p1y)) / hypot(p1x-p2x, p1y-p2y)

tc = 0
while(1):
    tc += 1
    ans = int(10**9)
    n = int(input())
    if not n: break
    pts = [list(map(int, input().split())) for _ in range(n)]

    for i in range(n):
        for j in range(i+1, n):
            tMin, tMax = 0, 0
            for k in range(n):
                v = dist(*pts[i], *pts[j], *pts[k])
                tMax = max(tMax, v)
                tMin = min(tMin, v)
                if ans < (tMax-tMin): break
            ans = min(ans, tMax-tMin)
    print('Case %d: %.2f' %(tc, ans+0.005-1e-16))