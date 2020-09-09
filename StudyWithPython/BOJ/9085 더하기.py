# 9085 더하기
input = __import__('sys').stdin.readline
for c in range(int(input())):
    _ = input()
    print(sum(map(int, input().split())))