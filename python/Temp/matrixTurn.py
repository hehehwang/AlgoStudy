stk = [[1, 0, 0],
       [1, 1, 1]]

stkR, stkC = 2, 3

for i in range(stkR):
    for j in range(stkC):
        print(stk[i][j], end=' ')
    print()
print()
for j in range(stkC):
    for i in range(stkR):
        print(stk[stkR-i-1][j], end=' ')
    print()
print()
for i in range(stkR):
    for j in range(stkC):
        print(stk[stkR-i-1][stkC-j-1], end=' ')
    print()
print()
for j in range(stkC):
    for i in range(stkR):
        print(stk[i][stkC-j-1], end=' ')
    print()