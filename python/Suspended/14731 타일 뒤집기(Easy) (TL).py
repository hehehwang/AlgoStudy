# 14731 미분계산기 (LARGE)
from sys import setrecursionlimit
setrecursionlimit(10**9)
input = __import__('sys').stdin.readline
MOD = 10**9+7
# def pwrOld(n):
#     return (2**n)%MOD

# cache=[0]*(10**9+5)
# def pwrCache(n):
#     # if n == 1: return 2
#     # if n == 0: return 0
#     if cache[n]: return cache[n]
#     if n < 10*5:
#         cache[n] = (2**n)%MOD
#         return cache[n]
#     if n%2 == 1:
#         cache[n] = (expoCache(n//2)*expoCache(n//2+1))%MOD
#         return cache[n]
#     else:
#         cache[n] = (expoCache(n//2)**2)%MOD
#         return cache[n]

def pwr(n):
    if n < 10*5: return (2**n)%MOD
    if n%2 == 1: return (pwr(n//2)*pwr(n//2+1))%MOD
    else:
        return (pwr(n//2)**2)%MOD

def pwrFast(n):
    base = 2
    rtn = 1
    while n:
        if n&1:
            rtn *= base
            rtn %= MOD
        base **= 2
        base %= MOD
        # n >>= 1
        n //= 2
    return rtn%MOD

def pwrFastRecur(base, exp):
    if exp == 0:
        x = 1
    else:
        half = pwrFastRecur(base, exp // 2)
        x = half * half
        if exp % 2 == 1:
            x *= base
    return x % MOD

# for i in range(10**10, 10**10+100):
#     print(i, pwrFast(i), pwrFastRecur(2, i))

rtn = 0
for _ in range(int(input())):
    c, k = map(int, input().split())
    rtn += ((c * k)%MOD * pwrFast(k-1))%MOD
    rtn %= MOD
print(rtn)