# 13015 별 찍기 - 23
n = int(input())
def f1(n):
    print('*'*n + ' ' * (2*n-3) + '*'*n)
def f2(n):
    for i in range(n-2):
        print(' '*(i+1) +
              '*' + ' '*(n-2) + '*' +
              ' '*(2*n-5-2*i) +
              '*' + ' '*(n-2) + '*')
def f3(n):
    print(' '*(n-1)+'*'+' '*(n-2) + '*' + ' ' * (n-2) + '*')

def f4(n):
    for i in range(n-3, -1, -1):
        print(' '*(i+1) +
              '*' + ' '*(n-2) + '*' +
              ' '*(2*n-5-2*i) +
              '*' + ' '*(n-2) + '*')

seq = [f1, f2, f3, f4, f1]
for s in seq:
    s(n)