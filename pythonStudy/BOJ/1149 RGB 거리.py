# 1149 RGB거리
input = __import__('sys').stdin.readline

N = int(input())
rgbCost = [list(map(int, input().split())) for _ in range(N)]
dp = [[0]*3 for _ in range(N)]

dp[0] = rgbCost[0]
for i in range(1, N):
    dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + rgbCost[i][0]
    dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + rgbCost[i][1]
    dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + rgbCost[i][2]

print(min(dp[-1]))