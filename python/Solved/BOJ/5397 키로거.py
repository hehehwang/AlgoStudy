# 5397 키로거
input = __import__('sys').stdin.readline

for _ in range(int(input())):
    left, right = [], []
    for s in input().strip():
        if s == '>':
            if right: left.append(right.pop())
        elif s == '<':
            if left: right.append(left.pop())
        elif s == '-':
            if left: left.pop()
        else:
            left.append(s)
    print(''.join(left+list(reversed(right))))