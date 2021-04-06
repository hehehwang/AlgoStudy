# 2156 포도주 시식
input = __import__('sys').stdin.readline

n = int(input())
dp = [[0]*2 for _ in range(n)]
if n == 1: print(int(input()))
else:
    dp[0][0] = int(input())
    dp[1][0] = int(input())
    dp[1][1] = dp[1][0] + dp[0][0]
    mV = max(dp[0][0], dp[1][1], dp[0][1])
    for i in range(2, n):
        wine = int(input())
        if n==2: dp[i][0] = max(dp[i-2][1], dp[i-2][0]) + wine
        else: dp[i][0] = max(dp[i-3][0], dp[i-3][1], dp[i-2][1], dp[i-2][0]) + wine
        dp[i][1] = dp[i-1][0] + wine
        mV = max(mV, dp[i][0], dp[i][1])
    print(mV)