# 1074 Z
import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def zf(n, r, c):
    if n == 1: return 2*r+c
    MID = (1<<(n-1))
    if r<MID and c<MID: return zf(n-1, r, c)
    elif r<MID and MID<=c: return zf(n-1, r, c-MID) + (MID*MID)
    elif MID<=r and c<MID: return zf(n-1, r-MID, c) + (MID*MID)*2
    else: return zf(n-1, r-MID, c-MID) + (MID*MID)*3

print(zf(*map(int, input().split())))