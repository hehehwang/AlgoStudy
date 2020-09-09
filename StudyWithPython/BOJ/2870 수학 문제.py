#2870 수학숙제
input = __import__('sys').stdin.readline

lst = []
for _ in range(int(input())):
    ss = input()
    tmp = []
    for s in ss:
        if s in '0123456789':
            tmp.append(s)
        else:
            if tmp:
                lst.append(int(''.join(tmp)))
                tmp = []
if tmp: lst.append(int(''.join(tmp)))
[print(i) for i in sorted(lst)]