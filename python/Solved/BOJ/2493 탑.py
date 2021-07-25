# 2493 탑
input = __import__('sys').stdin.readline

n = int(input())
twr = [100000001] + list(map(int, input().split()))
stk = [(t, i) for i, t in enumerate(twr)]
res = [0]*n

while len(stk) != 1:
    tmp = [stk.pop()]
    while tmp:
        if tmp[-1][0] <= stk[-1][0]:
            res[tmp[-1][1]-1] = stk[-1][1]
            tmp.pop()
        else:
            tmp.append(stk.pop())

[print(r, end=' ') for r in res]