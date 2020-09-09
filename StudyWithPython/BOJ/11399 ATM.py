# 11399 ATM
input = __import__('sys').stdin.readline
_ = input()
pp = list(map(int, input().split()))
ret = 0
for i, p in enumerate(sorted(pp)):
    ret += p*(len(pp)-i)
print(ret)
