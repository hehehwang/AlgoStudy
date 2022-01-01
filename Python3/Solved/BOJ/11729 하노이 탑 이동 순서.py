# 11729 하노이 탑 이동 순서
import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def hannoi(n, f, t):
    # n개의 원판을 f에서 t로 이동
    if n == 1:
        print(f'{f} {t}')
        return None
    k = 6 - f - t
    hannoi(n-1, f, k)
    hannoi(1, f, t)
    hannoi(n-1, k, t)

v = int(input())
print((1<<v) - 1)
hannoi(v, 1, 3)
