# PI 원주율 외우기 1회차 - 재귀로 풀기
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**5)

def f(n):
    if cache[n] != -1: return cache[n]
    if n<3: return 99
    rtn = min(analyse(pi[n-3:n])+f(n-3),
              analyse(pi[n-4:n])+f(n-4),
              analyse(pi[n-5:n])+f(n-5))
    cache[n] = rtn
    return rtn

def analyse(ss:str):
    if ss[0]==ss[1]:
        if all([i == ss[0] for i in ss]): return 1
        else: return 10
    elif ss[0]==ss[2]:
        for i in range(len(ss)-2):
            if ss[i] != ss[i+2]:
                return 10
        return 4
    else:
        ss = list(map(int, ss))
        d = ss[1]-ss[0]
        for i in range(len(ss)-1):
            if ss[i]+d != ss[i+1]:
                return 10
        if d == 1 or d ==-1:
            return 2
        else: return 5

for _ in range(int(input())):
    pi = input().strip()
    piL = len(pi)

    cache = [-1]*(piL+1)
    for i in (3, 4, 5):
        cache[i] = analyse(pi[:i])

    print(f(piL))