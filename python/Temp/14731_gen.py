from random import randint
n=100000
print(n)
for i in range(2*n):
    print(i%100, randint(0, 10**9))
    # print(100, 10**9)