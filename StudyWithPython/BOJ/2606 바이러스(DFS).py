# 2606 바이러스
input = __import__('sys').stdin.readline
c = int(input())
adj = [[] for _ in range(c)]
visited = [False] * c
for _ in range(int(input())):
    a, b = map(int, input().split())
    a, b = a - 1, b - 1
    adj[a].append(b)
    adj[b].append(a)

stk, cnt, visited[0] = adj[0][:], 0, True
while stk:
    n = stk.pop()
    if not visited[n]:
        visited[n]=True
        stk.extend(adj[n])
        cnt += 1
print(cnt)