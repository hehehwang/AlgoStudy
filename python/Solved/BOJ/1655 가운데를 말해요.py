# 1655 가운데를 말해요
from heapq import heappush, heappop
input = __import__('sys').stdin.readline

maxHeap = []
minHeap = []
for _ in range(int(input())):
    num = int(input())
    if len(maxHeap) == len(minHeap):
        heappush(maxHeap, -num)
    else: heappush(minHeap, num)
    if minHeap and minHeap[0] < -maxHeap[0]:
        heappush(minHeap, -heappop(maxHeap))
        heappush(maxHeap, -heappop(minHeap))
    print(-maxHeap[0])