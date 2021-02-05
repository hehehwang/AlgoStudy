# 1992 쿼드트리
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**9)

bN = int(input())
board = [list(input().strip()) for _ in range(bN)]
res = []
def f(r1, r2, c1, c2):
    v = board[r1][c1]
    u = True
    for i in range(r2-r1):
        if not u: break
        for j in range(c2-c1):
            if not u: break
            if v != board[r1+i][c1+j]: u = False

    if u: res.append(v)
    else:
        rm, cm = (r1+r2)//2, (c1+c2)//2
        res.append('(')
        f(r1, rm, c1, cm)
        f(r1, rm, cm, c2)
        f(rm, r2, c1, cm)
        f(rm, r2, cm, c2)
        res.append(')')

f(0, bN,  0, bN)
print(''.join(res))