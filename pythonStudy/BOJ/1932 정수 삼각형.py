# 1932 정수 삼각형
input = __import__('sys').stdin.readline

n = int(input())
dp = [int(input())]
for i in range(n-1):
    # print(dp)
    arr = list(map(int, input().split()))
    ndp = []
    for j in range(len(arr)):
        if j == 0: ndp.append(arr[0]+dp[0])
        elif j == len(arr)-1: ndp.append(arr[j]+dp[j-1])
        else:
            ndp.append(max(dp[j], dp[j-1])+arr[j])
    dp = ndp[:]
print(max(dp))