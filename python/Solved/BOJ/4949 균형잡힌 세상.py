# 4949 균형잡힌 세상
input = __import__('sys').stdin.readline

while 1:
    l = input().strip('\n')
    if l == '.': break
    else:
        stk = []
        F = True
        for c in l:
            if c == '(' or c == '[':
                stk.append(c)
            elif c == ')':
                if stk and stk[-1] == '(': stk.pop()
                else:
                    F = False
                    break
            elif c == ']':
                if stk and stk[-1] == '[': stk.pop()
                else:
                    F = False
                    break
            else:
                continue

    if F and not stk: print('yes')
    else: print('no')
