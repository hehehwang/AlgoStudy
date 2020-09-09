# 2178 미로 탐색
from collections import deque
input = __import__('sys').stdin.readline

class node():
    def __init__(self, point, depth):
        self.point = point
        self.depth = depth

    def __repr__(self):
        return str(self.point) + str(self.depth)

def addvec(vec1, vec2):
    return (vec1[0]+vec2[0], vec1[1]+vec2[1])


#   0  1
# 0 00 01
# 1 10 NM

N, M = map(int, input().split())
mz = [[int(s) for s in input().strip()] for _ in range(N)]
visited = [[False for i in range(M)] for j in range(N)]
N, M = N-1, M-1
visited[0][0] = True

def isclear(point):
    return mz[point[0]][point[1]]

tree = deque([node((0, 0), 1)])

# BFS 트리 확장
def expand_tree():
    now_node = tree.popleft()
    mov_vec = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    for vec in mov_vec:
        mov_point = addvec(now_node.point, vec)
        if mov_point[0] < 0 or N < mov_point[0]: continue
        if mov_point[1] < 0 or M < mov_point[1] : continue
        if visited[mov_point[0]][mov_point[1]] : continue
        if isclear(mov_point):
            visited[mov_point[0]][mov_point[1]] = True
            tree.append( node(mov_point, now_node.depth+1) )

while True:
    if tree[0].point == (N, M):
        print(tree[0].depth)
        break
    else:
        expand_tree()
