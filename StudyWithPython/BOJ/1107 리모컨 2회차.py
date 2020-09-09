# 1107 리모콘 2회차
targetNum = int(input().strip())
broken = list(input().split()) if int(input()) else []

result = abs(targetNum-100)
# idx = 0
for num in range(1000001):
    enable = True
    for n in str(num):
        if n in broken:
            enable = False
            break
    if enable:
        result = min(result, abs(targetNum - num) + len(str(num)))
        # idx = i

print(result)