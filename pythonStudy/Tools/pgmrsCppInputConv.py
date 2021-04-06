#
input = __import__('sys').stdin.readline

ss = input().strip()
for s in ss:
    if s == '[': print('{', end='')
    elif s == ']': print('}', end='')
    else: print(s, end='')