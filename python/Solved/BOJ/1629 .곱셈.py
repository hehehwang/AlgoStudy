# 1629 곱셈
import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

a, b, MOD = map(int, input().split())
def pwr(a, b):
    global MOD
    if b == 1: return a%MOD
    if b == 0: return 1
    if b%2: return (pwr(a, b-1)*a)% MOD
    else: return (pwr(a, b//2)**2)% MOD

print(pwr(a, b))