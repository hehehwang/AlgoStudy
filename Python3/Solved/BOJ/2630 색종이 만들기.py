# 2630 색종이 만들기
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**9)

bN = int(input())
board = [list(map(int, input().split())) for _ in range(bN)]
bp, wp = 0, 0

def f(r1, c1, r2, c2):
    global bp, wp
    v = board[r1][c1]
    b = False
    for ri in range(r1, r2):
        if b: break
        for ci in range(c1, c2):
            if board[ri][ci] != v:
                b = True
                break
    if not b:
        if v: bp += 1
        else: wp += 1
    else:
        rm = (r1+r2)//2
        cm = (c1+c2)//2
        f(r1, c1, rm, cm)
        f(r1, cm, rm, c2)
        f(rm, c1, r2, cm)
        f(rm, cm, r2, c2)

f(0, 0, bN, bN)
print(wp)
print(bp)