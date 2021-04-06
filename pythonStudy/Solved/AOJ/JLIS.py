# JLIS 합친 LIS
input = __import__('sys').stdin.readline
def f(s1, s2):
    global sss1, sss2
    if cache[s1][s2] != -1: return cache[s1][s2]
    nowVal = sss1[s1] if sss2[s2] < sss1[s1] else sss2[s2]
    ret = 1
    for i in range(len(sss1)-s1-1):
        n1 = s1+i+1
        if sss1[n1] > nowVal:
            ret = max(ret, f(n1, s2)+1)
    for j in range(len(sss2)-s2-1):
        n2 = s2+j+1
        if sss2[n2] > nowVal:
            ret = max(ret, f(s1, n2)+1)
    cache[s1][s2] = ret
    return ret

for _ in range(int(input())):
    input()
    MIN = -3000000000
    sss1 = [MIN]+list(map(int, input().split()))
    sss2 = [MIN]+list(map(int, input().split()))
    cache = [[-1]*len(sss2) for _ in range(len(sss1))]
    f(0, 0)

    maxNum = cache[0][0]-1
    [print(c) for c in cache]
    print(maxNum)