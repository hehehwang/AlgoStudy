m, n, h = 100, 100, 100

for i in range(h):
    for j in range(n):
        for k in range(m):
            if i==50 and j ==50 and k == 50:
                print(1, end=' ')
            else:
                print(0, end=' ')
        print()