# 1120 문자열
input = __import__('sys').stdin.readline
a, b = input().split()

minDiff = 50
for i in range(len(b)-len(a)+1):
    tmp = 0
    for j in range(len(a)):
        tmp += a[j] != b[i+j]
    minDiff = min(tmp, minDiff)
print(minDiff)