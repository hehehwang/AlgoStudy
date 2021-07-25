# PI 원주율 외우기 N회차 - deque로 풀기 + 쪼개서 읽기
from collections import deque
input = __import__('sys').stdin.readline

# 8 이상의 수부터 적용 가능
def f2(n):
    global pi, cache
    rtn = min(analyse3(pi[n-3:n])+cache[2],
              analyse4(pi[n-4:n])+cache[1],
              analyse5(pi[n-5:n])+cache[0])
    cache.append(rtn)
    cache.popleft()
    return rtn

def analyse3(s):
    if len(s) != 3: raise NotImplementedError
    if s[0]==s[1]==s[2]: return 1
    d = s[0]-s[1]
    if s[0]==s[1]+d==s[2]+2*d:
        if d == 1 or d == -1: return 2
        return 5
    if s[0]==s[2]: return 4
    return 10

def analyse4(s):
    if len(s) != 4: raise NotImplementedError
    if s[0]==s[1]==s[2]==s[3]: return 1
    d = s[0]-s[1]
    if s[0]==s[1]+d==s[2]+2*d==s[3]+3*d:
        if d == 1 or d == -1: return 2
        return 5
    if s[0]==s[2] and s[1]==s[3]: return 4
    return 10

def analyse5(s):
    if len(s) != 5: raise NotImplementedError
    if s[0]==s[1]==s[2]==s[3]==s[4]: return 1
    d = s[0]-s[1]
    if s[0]==s[1]+d==s[2]+2*d==s[3]+3*d==s[4]+4*d:
        if d == 1 or d == -1: return 2
        return 5
    if s[0]==s[2]==s[4] and s[1]==s[3]: return 4
    return 10

def _analyse5(s):
    if len(s) != 5: raise NotImplementedError
    if s[0]==s[1]==s[2]==s[3]==s[4]: return 1
    if s[0]-s[1] == s[1]-s[0] == s[2]-s[3] == s[3]-s[4] == 1 : return 2
    if s[0]-s[1] == s[1]-s[2] == s[2]-s[3] == s[3]-s[4] == -1 : return 2
    if s[0]==s[1]==s[3] and s[2]==s[4]: return 4
    if s[0]-s[1] == s[1]-s[2] == s[2]-s[3] == s[3]-s[4] : return 5
    return 10

for _ in range(int(input())):
    pi = list(map(int, input().strip()))
    piL = len(pi)

    cache = deque([analyse3(pi[:3]),
                   analyse4(pi[:4]),
                   analyse5(pi[:5]),
                   analyse3(pi[:3])+analyse3(pi[3:6]),
                   min(analyse4(pi[:4])+analyse3(pi[4:7]),
                       analyse3(pi[:3])+analyse4(pi[3:7])),
                   ])
    for i in range(8, len(pi)+1):
        v = f2(i)
    print(v)

# for i in range(10):
#     ss = input().strip()
#     print(i+1, analyse5(ss))