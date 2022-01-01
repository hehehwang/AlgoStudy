# 7662 이중 우선순위 큐 - two heapq
input = __import__('sys').stdin.readline
from heapq import *

def findMx():
    while mxH:
        v = mxH[0]
        if mxHd and v == mxHd[0]:
            heappop(mxH)
            heappop(mxHd)
            continue
        return -v
    return None

def findMn():
    while mnH:
        v = mnH[0]
        if mnHd and v == mnHd[0]:
            heappop(mnH)
            heappop(mnHd)
            continue
        return  v
    return None

for _ in range(int(input())):
    mxH, mxHd = [], []
    mnH, mnHd = [], []
    for i in range(int(input())):
        sss = input().split()
        if sss[0] == 'I':
            n = int(sss[1])
            heappush(mxH, -n)
            heappush(mnH, n)
        else:
            if sss[1] == '1': n = findMx()
            else: n = findMn()
            if n:
                heappush(mxHd, -n)
                heappush(mnHd, n)

    mx, mn = findMx(), findMn()
    if mx:
        print(mx, mn)
    else:
        print('EMPTY')