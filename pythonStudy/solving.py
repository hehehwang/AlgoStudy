# 10871 x보다 작은 수
n, x = map(int, input().split())
[print(i, end=' ') for i in map(int, input().split()) if i < x]