# 1016 제곱 ㄴㄴ수
input = __import__('sys').stdin.readline

LMT = 1000000
sieve = [True]*(LMT+1)
Mi, Ma = map(int, input().split())
rng = Ma - Mi + 1
iterMax = int(Ma**0.5)
for i in range(2, iterMax+1):
    if i != 2 and i%2==0: continue
    if i != 3 and i%3==0: continue
    if i != 5 and i%5==0: continue
    if i != 7 and i%7==0: continue
    jg = i*i
    for mult in range(Mi//jg, (Ma//jg)+1):
        if (mult*jg < Mi): continue
        if (Ma < mult * jg): continue
        sieve[mult*jg - Mi] = False
print(sum(sieve[0:rng]))