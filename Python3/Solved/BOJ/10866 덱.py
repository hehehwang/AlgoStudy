# 10866 덱
from collections import deque
input = __import__('sys').stdin.readline

a = deque([])
for _ in range(int(input())):
    comm = input()
    if comm[:6] == 'push_b':
        a.appendleft(int(comm[10:]))
    elif comm[:6] == 'push_f':
        a.append(int(comm[10:]))
    elif comm[:5] == 'pop_f':
        if a: print(a.pop())
        else: print(-1)
    elif comm[:5] == 'pop_b':
        if a: print(a.popleft())
        else: print('-1')
    elif comm[0] == 's':
        print(len(a))
    elif comm[0] == 'e':
        if a: print(0)
        else: print(1)
    elif comm[0] == 'f':
        if a: print(a[-1])
        else: print(-1)
    elif comm[0] == 'b':
        if a: print(a[0])
        else: print(-1)
    else:
        raise NotImplementedError