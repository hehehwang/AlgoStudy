# 15649 N과 M(1) (복습)
input = __import__('sys').stdin.readline

n, m = map(int, input().split())
isUsed = [False]*(n+1)
piece = []

def seq(k):
    if k == m:
        print(' '.join(map(str, piece)))
        return
    for i in range(1, n+1):
        if isUsed[i]: continue
        isUsed[i] = True
        piece.append(i)
        seq(k+1)
        isUsed[i] = False
        piece.pop()

seq(0)