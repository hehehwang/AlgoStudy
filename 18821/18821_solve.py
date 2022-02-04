from time import perf_counter


def main(target: int):
    sieve = [0] * (target + 1)
    c = [0, 0]
    pfc = perf_counter()
    for i in range(2, target + 1):
        if sieve[i]:
            continue
        j = i
        while j <= target:
            k = j
            while k <= target:
                sieve[k] += 1
                k += j
            j *= i
    for n in range(1, target + 1):
        c[sieve[n] % 2] += 1
        if c[0] > c[1]:
            print("found:", n)
        m = min(c)
        c[0], c[1] = c[0] - m, c[1] - m
        if n % int(1e6) == 0:
            print(n, c, round(perf_counter() - pfc, 2))
            pfc = perf_counter()


if __name__ == "__main__":
    pfc = perf_counter()
    main(int(1e9))
    print(perf_counter() - pfc)

