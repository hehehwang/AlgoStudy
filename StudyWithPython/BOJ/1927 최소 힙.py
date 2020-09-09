# 1927 최소 힙
from heapq import heappush, heappop
input = __import__('sys').stdin.readline
h = []
for _ in range(int(input())):
    n = int(input())
    if n == 0:
        try:
            print(heappop(h))
        except:
            print(0)
    else:
        heappush(h, n)
