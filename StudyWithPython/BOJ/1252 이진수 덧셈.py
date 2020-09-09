#1252 이진수 덧셈
a, b = map(int, input().split())
c = str(a+b)
buff = 0
o = []
for i in range(len(str(c))):
    huff = int(c[-i-1]) + buff
    if huff > 1:
        buff = 1
        o.append(huff-2)
    else:
        buff = 0
        o.append(huff)
if buff != 0:
    o.append(1)
for _ in range(len(o)):
    print(o.pop(), end='')