# JUMPGAME 외발 뛰기
input = __import__('sys').stdin.readline

# naive
def f(r, c):
    global board, n
    if r<0 or n<=r or c<0 or n<=c : return False
    if r == n-1 and c == n-1 : return True
    else:
        return bool(f(r+board[r][c], c) + f(r, c+board[r][c]))
# dp
def f2(r, c):
    global board, n, cache
    if r<0 or n<=r or c<0 or n<=c : return False
    if r == n-1 and c == n-1 : return True
    else:
        if cache[r][c] == -1:
            cache[r][c] = bool(f2(r+board[r][c], c) + f2(r, c+board[r][c]))
        return cache[r][c]


for _ in range(int(input())):
    n = int(input())
    board = [list(map(int, input().split())) for _ in range(n)]
    cache = [[-1]*n for _ in range(n)]
    print('YES' if f2(0, 0) else 'NO')