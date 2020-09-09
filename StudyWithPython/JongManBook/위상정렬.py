# dfs 위상정렬 구현해보장
adj = [[], #0
       [2], #1
       [3], #2
       [4], #3
       [5], #4
       [], #5
       [7, 8, 9], #6
       [1], #7
       [2], #8
       [4], #9
       [10],] # 10

visited = []
rtn = []
def dfs(here):
    global visited
    # print(here)
    visited[here] = True
    for there in adj[here]:
        if not visited[there]: dfs(there)
    rtn.append(here)

def dfsAll():
    global visited
    visited = [False] * 11
    for i in range(11):
        if not visited[i]:
            dfs(i)
dfsAll()
print(' '.join(map(str, reversed(rtn))))
