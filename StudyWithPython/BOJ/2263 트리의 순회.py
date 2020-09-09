# 2263 트리의 순회
from sys import setrecursionlimit, stdin
setrecursionlimit(10**9)
input = stdin.readline

N = int(input())
inOrder = list(map(int, input().split()))
postOrder = list(map(int, input().split()))
inOrderLoc = dict()
for i in range(N):
    inOrderLoc[inOrder[i]] = i

def mkPreorder(inStart:int, inEnd:int, postStart:int, postEnd:int):
    if postStart == postEnd : return
    root = postOrder[postEnd-1]
    L = inOrderLoc[root] - inStart
    print(root, end= ' ')
    mkPreorder(inStart, inStart+L, postStart, postStart+L)
    mkPreorder(inStart+L+1, inEnd, postStart+L, postEnd-1)

mkPreorder(0, N, 0, N)

