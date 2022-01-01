# 1062 가르침
from itertools import combinations
input = __import__('sys').stdin.readline

# anta, tica 제외
ss = 'bdefghjklmopqrsuvwxyz'

def getBitmask(lst):
    lst = list(set(lst))
    rtn = 0
    for s in lst:
        rtn += 1<<(ord(s)-97)
    return rtn

n, k = map(int, input().split())
words = [getBitmask(input().strip()) for i in range(n)]
if 5<=k:
    default = ('a','c','i','t','n')
    if 5<k:
        combis = combinations(ss, k-5)
    else: combis = [()]
    rtn = 0
    for c in combis:
        mask = getBitmask(c+default)
        cnt = 0
        for w in words:
            if w&mask == w: cnt += 1
        if rtn < cnt:
            rtn = max(rtn, cnt)
    print(rtn)
else:
    print(0)