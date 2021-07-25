# 16505 별
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**9)

N = int(input())
board = []
def f(n):
    if n == 0: return ['*']
    v = f(n-1)
    rtn = v[:]
    for i in range(1<<n-1):
        rtn[i] += v[i]
        rtn.append(v[i]+ ' '*(1<<n-1))
    return rtn

[print(l.strip()) for l in f(N)]