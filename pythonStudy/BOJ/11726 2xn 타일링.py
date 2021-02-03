# 11726 2xn 타일링
input = __import__('sys').stdin.readline

n = int(input())
MOD = 10007
dp = [0]*(n+1)
dp[0], dp[1] = 1, 2
for i in range(2, n):
    dp[i] = (dp[i-1] + dp[i-2])%MOD
print(dp[n-1])