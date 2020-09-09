# 11048 동전0
input = __import__('sys').stdin.readline
N, K = map(int, input().split())
coinValue, coinUsed =[], [0]*N
for _ in range(N):
    coinValue.append(int(input()))
for i in range(N):
    j = N-i-1
    coinUsed[j] = K // coinValue[j]
    K %= coinValue[j]
print(sum(coinUsed))