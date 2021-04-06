# 2239 스도쿠
input = __import__('sys').stdin.readline

board=[list(map(int, input().strip())) for _ in range(9)]
zeros=[(i, j) for i in range(9) for j in range(9) if not board[i][j]]
def possibleNums(r, c):
    chk = [True]*10
    for i in range(9):
        chk[board[r][i]] = False
        chk[board[i][c]] = False
    for i in range((r//3)*3, (r//3)*3+3):
        for j in range((c//3)*3, (c//3)*3+3):
            chk[board[i][j]] = False
    rtn = [i for i in range(1, 10) if chk[i]]
    return rtn
def findSudoku(i):
    if i == len(zeros): return True
    z = zeros[i]
    lst = possibleNums(*z)
    if not lst:
        return False
    for l in lst:
        board[z[0]][z[1]] = l
        if findSudoku(i+1): return True
        board[z[0]][z[1]] = 0
findSudoku(0)
[print(''.join(map(str, b))) for b in board]