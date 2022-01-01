# 11724 연결요소의 개수
input = __import__('sys').stdin.readline
n, m = map(int, input().split())
adj = [[] for _ in range(n+1)]
visited = [False]*(n+1)
for _ in range(m):
    a, b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)

cnt = 0
for i in range(1, n+1):
    if not visited[i]:
        cnt += 1
        stk = adj[i][:]
        while stk:
            v = stk.pop()
            if not visited[v]:
                visited[v] = True
                stk.extend(adj[v])
print(cnt)