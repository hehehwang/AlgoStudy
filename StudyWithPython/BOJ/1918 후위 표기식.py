# 1918 후위 표기식
ops = {'*':3,
        '/':3,
        '+':2,
        '-':2,
        '(':1,
        ')':1}
ss = input()
stk = []
for s in ss:
    if s not in ops.keys():
        print(s, end='')

    elif not stk or s == '(':
        stk.append(s)

    elif s == ')':
        while stk[-1] != '(':
            print(stk.pop(), end='')
        stk.pop()

    elif ops[s] <= ops[stk[-1]]:
        while 1:
            if not stk: break
            if ops[s] <= ops[stk[-1]]:
                print(stk.pop(), end='')
            else: break
        stk.append(s)
    else:
        stk.append(s)
for i in range(len(stk)):
    print(stk.pop(), end='')