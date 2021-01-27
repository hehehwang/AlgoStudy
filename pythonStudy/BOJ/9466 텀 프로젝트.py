# 9466 텀 프로젝트
input = __import__('sys').stdin.readline

for _ in range(int(input())):
    n = int(input())
    choice = [0] + list(map(int, input().split()))
    vis = [0]*(n+1)
    teamNo = 1
    cnt = n
    for i in range(1, n+1):
        while vis[i] == 0:
            vis[i] = teamNo
            i = choice[i]
        while vis[i] == teamNo:
            cnt -= 1
            vis[i] = -1
            i = choice[i]
        teamNo += 1
    print(cnt)