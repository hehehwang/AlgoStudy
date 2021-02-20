# 2568 전깃줄 - 2
from bisect import bisect_left
input = __import__('sys').stdin.readline

n = int(input())
nums = [tuple(map(int, input().split())) for _ in range(n)]
nums.sort()
lis = [0]
addr = [0]*len(nums)
for i in range(n):
    if lis[-1] < nums[i][1]:
        lis.append(nums[i][1])
        addr[i] = len(lis)-1
    else:
        idx = bisect_left(lis, nums[i][1])
        lis[idx] = nums[i][1]
        addr[i] = idx
print(n-len(lis)+1)
seq, idx = [], len(lis)-1
for i in range(n-1, -1, -1):
    a = addr[i]
    if a == idx: idx -= 1
    else: seq.append(nums[i][0])
[print(s) for s in seq[::-1]]
