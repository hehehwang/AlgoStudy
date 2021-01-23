input = __import__('sys').stdin.readline
res = []
nums = [i for i in range(int(input()), 0, -1)]
stk = []
F = True
for _ in range(nums[0]):
    if not F: break
    v = int(input())
    while 1:
        if stk and stk[-1] == v:
            res.append('-')
            stk.pop()
            break
        else:
            if nums:
                res.append('+')
                stk.append(nums.pop())
            else:
                F = False
                print('NO')
                break
if F:
    [print(r) for r in res]