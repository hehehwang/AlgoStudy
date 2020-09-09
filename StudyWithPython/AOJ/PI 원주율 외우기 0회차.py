# PI 원주율 외우기 0회차
from collections import deque
input = __import__('sys').stdin.readline

# lo~hi-1 까지 무차별적으로 쪼개서 시도해본다.
def f1(lo, hi):
    global pi, cache
    # 제발 기저사례 생각좀 하자 히영아 젭알..
    if hi==lo : return 0
    if hi-lo < 3: return 99
    v = []
    v.append(analyse(pi[lo:lo+3]) + f1(lo+3, hi))
    if hi-lo>=4 :
        v.append(analyse(pi[lo:lo+4]) + f1(lo+4, hi))
    if hi-lo>=5 :
        v.append(analyse(pi[lo:lo+5]) + f1(lo+5, hi))
    return min(v)

# 8 이상의 수부터 적용 가능
def f2(n):
    global pi, cache
    rtn = min(analyse(pi[n-3:n])+cache[2],
              analyse(pi[n-4:n])+cache[1],
              analyse(pi[n-5:n])+cache[0])
    cache.append(rtn)
    cache.popleft()
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

    # cache = deque([])
    # for i in range(3):
    #     cache.append(f1(0, i+6))
    # print(cache, min(cache))

    cache = deque([analyse(pi[:3]),
                   analyse(pi[:4]),
                   analyse(pi[:5]),
                   analyse(pi[:3])+analyse(pi[3:6]),
                   min(analyse(pi[:4])+analyse(pi[4:7]),
                       analyse(pi[:3])+analyse(pi[3:7])),
                   ])
    for i in range(8, len(pi)+1):
        v = f2(i)
    print(v)


# for i in range(10):
#     ss = input().strip()
#     print(analyse(ss))