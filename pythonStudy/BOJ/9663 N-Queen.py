# 9663 N-Queen
input = __import__('sys').stdin.readline

n = int(input())
board = [[0]*n for _ in range(n)]
cnt = 0
isUsedX = [0]*n
isUsedD1, isUsedD2 = [0]*(2*n-1), [0]*(2*n-1)

def nq(i):
    global cnt
    if i==n:
        # [print(b) for b in board]
        # print()
        # print(isUsedX)
        # print()
        cnt += 1
        return
    for j in range(n):
        if isUsedX[j]: continue
        if isUsedD1[i+j]: continue
        if isUsedD2[i-j+n-1]: continue
        board[i][j] = 1
        isUsedX[j] = 1
        isUsedD1[i+j], isUsedD2[i-j+n-1] = 1, 1
        nq(i+1)
        board[i][j] = 0
        isUsedX[j] = 0
        isUsedD1[i+j], isUsedD2[i-j+n-1] = 0, 0

nq(0)
print(cnt)