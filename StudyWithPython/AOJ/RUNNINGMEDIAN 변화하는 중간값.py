# RUNNINGMEDIAN 변화하는 중간 값
from heapq import heappush, heappop
MOD = 20090711
def probGen(a:int, b:int)->int:
    seed = 1983
    while 1:
        yield seed
        seed = (seed*a+b)%MOD

for _ in range(int(input())):
    n, a, b = map(int, input().split())
    gen = probGen(a, b)
    maxHeap=[]
    minHeap=[]
    rtn = 0
    if n == 1: print(next(gen))
    else:
        for i in range(n):
            num = next(gen)
            if len(minHeap) == len(maxHeap): heappush(maxHeap, -num)
            else: heappush(minHeap, num)
            if minHeap and minHeap[0] < -maxHeap[0]:
                # a, b = heappop(maxHeap), heappop(minHeap)
                # heappush(minHeap, -a)
                # heappush(maxHeap, -b)
                heappush(minHeap, -heappop(maxHeap))
                heappush(maxHeap, -heappop(minHeap))
            # debug
            # if minHeap and minHeap[0] < -maxHeap[0]:
            #     print(i+1)
            rtn += -maxHeap[0]
            rtn %= MOD
        print(rtn%MOD)