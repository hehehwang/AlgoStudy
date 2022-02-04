# 18821 홀수와 짝수의 대결
# https://www.acmicpc.net/problem/18821

import multiprocessing as mp
from time import perf_counter

from polard_rho import pollard_rho

# # use c implementation
# from ctypes import cdll
# dll = cdll.LoadLibrary("./pollard_rho.dll")
# def oddeven(n: int):
#     return dll.isoddc(n)


# use python implementation
# from sympy.ntheory import factorint
def oddeven(n: int):
    l = len(pollard_rho(n))
    return l % 2


# # use sympy implementation
# def oddeven(n: int):
#     r = factorint(n)
#     return sum(r.values()) % 2


def rangeoe(st: int, en: int):
    c = [0, 0]
    for i in range(st, en):
        r = oddeven(i)
        c[r] += 1
        # m = min(c)
        # c[0] -= m
        # c[1] -= m
    return c


def rangeoe_mp(st: int, en: int):
    pfc = perf_counter()
    pool = mp.Pool()
    c = [0, 0]
    n = 1
    for r in pool.imap(oddeven, range(st, en), chunksize=int(1e3)):
        c[r] += 1
        if c[0] > c[1]:
            print("found:", n)
        m = min(c)
        c[0], c[1] = c[0] - m, c[1] - m
        if n % int(1e6) == 0:
            print(n, c, round(perf_counter() - pfc, 2))
            pfc = perf_counter()
        n += 1

    return c


BATCH_SIZE = 1000


def oddeven_batch(st: int):
    r = []
    for n in range(st, st + BATCH_SIZE):
        r.append(oddeven(n))
    return r


def rangeoe_batch(target: int):
    pfc = perf_counter()
    pool = mp.Pool()
    c = [0, 0]
    n = 1
    for batch in pool.imap(
        oddeven_batch, range(1, target + 1, BATCH_SIZE), chunksize=int(1e3)
    ):
        for r in batch:
            if n == target:
                break
            c[r] += 1
            if c[0] > c[1]:
                print(n)
            m = min(c)
            c[0], c[1] = c[0] - m, c[1] - m
            if n % int(1e6) == 0:
                print(n, c, round(perf_counter() - pfc, 2))
                pfc = perf_counter()
            n += 1
    print("done")


def main():
    tasks = (1, int(1e7))
    pfc = perf_counter()
    print(rangeoe_mp(*tasks))
    print(perf_counter() - pfc)


if __name__ == "__main__":
    main()
    # for i in range(1, 10001):
    #     print(i, oddeven(i))
