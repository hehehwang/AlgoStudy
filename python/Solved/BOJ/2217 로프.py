# 2217 로프
input = __import__('sys').stdin.readline

N = int(input())
weight = 0
rope = [int(input()) for _ in range(N)]
rope.sort(reverse=True)
for i in range(N):
    if not weight:
        weight = rope[i]
        continue
    weight = max(rope[i]*(i+1), weight)
print(weight)