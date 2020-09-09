from random import randint

print(50)
for _ in range(50):
    num = [str(randint(0,10)) for _ in range(10000)]
    print(''.join(num))
