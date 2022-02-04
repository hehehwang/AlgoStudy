from random import randint
from math import gcd


def isprime(x):
    if x < 2151139:
        return isprime_naive(x)
    return isprime_mr(x)


def isprime_mr(x: int):
    def modpow(base, pwr, mod):
        r = 1
        while pwr:
            if pwr % 2 == 1:
                r = (r * base) % mod
            pwr >>= 1
            base = (base * base) % mod
        return r

    bases = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41]
    if x in bases:
        return True
    if x % 2 == 0:
        return False
    s, d = 0, x - 1
    while d % 2 == 0:
        s += 1
        d >>= 1

    for a in bases:
        if modpow(a, d, x) == 1:
            continue
        for r in range(s):
            if modpow(a, d << r, x) == x - 1:
                break
        else:
            break
    else:
        return True
    return False


def isprime_naive(x: int):
    if x < 2:
        return False
    if x == 2:
        return True
    if x % 2 == 0:
        return False
    div = 3
    while div * div <= x:
        if x % div == 0:
            return False
        div += 2
    return True


def factorize(n: int, factors: list):
    while n % 2 == 0:
        factors.append(2)
        n //= 2
    if n == 1:
        return
    if isprime(n):
        factors.append(n)
        return

    def f_gen(c):
        return lambda x: (x * x + c) % n

    rab, tur = 3, 3
    f = f_gen(1)
    g = 1
    while g == 1:
        tur = f(tur)
        rab = f(f(rab))
        g = gcd(abs(tur - rab), n)
        if g == n:
            f = f_gen(randint(2, 10))
            tur = randint(2, n - 1)
            rab = tur
            g = 1

    factorize(n // g, factors)
    factorize(g, factors)


def pollard_rho(n: int):
    rtn = []
    factorize(n, rtn)
    return sorted(rtn)
