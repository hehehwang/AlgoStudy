import sys
sys.setrecursionlimit(10**6)
r = sys.stdin.readline
arr = []

def worm(i, j):
    arr[i][j] = 0
    if j != w - 1 and arr[i][j + 1]: worm(i, j + 1)
    if j != 0 and arr[i][j - 1]: worm(i, j - 1)
    if i != l - 1 and arr[i + 1][j]: worm(i + 1, j)
    if i != 0 and arr[i - 1][j]: worm(i - 1, j)

ans = 0
t = int(r())

for _1 in range(t):
    w, l, k = map(int, r().split())
    arr = [[0 for i in range(w)] for j in range(l)]

    for _2 in range(k):
        a, b = map(int, r().split())
        arr[b][a] = 1

    for i in range(l):
        for j in range(w):
            if arr[i][j]:
                ans += 1
                worm(i, j)
    print(ans)
    ans = 0