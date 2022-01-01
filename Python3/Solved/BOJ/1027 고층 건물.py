# 1027 고층 건물
# https://www.acmicpc.net/problem/1027
input = __import__('sys').stdin.readline

N = int(input())
buildings = list(map(int, input().split()))
ans = 0
for p in range(N):
    grad = [(buildings[p] - buildings[i]) / (p - i) if (p - i) else None for i in range(N)]
    view = 0
    prevGrad = 1_000_000_002
    for i in range(p, -1, -1):
        if (grad[i] is not None) and (grad[i] < prevGrad):
            view += 1
            prevGrad = grad[i]
    prevGrad = -1_000_000_002
    for i in range(p, N):
        if (grad[i] is not None) and (prevGrad < grad[i]):
            view += 1
            prevGrad = grad[i]
    ans = max(view, ans)
print(ans)
