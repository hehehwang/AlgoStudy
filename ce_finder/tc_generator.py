# TODO:
# - add information about generators
# - sort generators by its number
import random
from itertools import combinations, permutations, product
from random import randint, sample


class TcGen:
    def p1012():
        r, c = 3, 4
        for _ in range(1000):
            k = randint(0, r * c)
            rtn = f"1\n{r} {c} {k}\n"
            samples = sample(range(r * c), k)
            for s in samples:
                rc, cc = s % r, s // r
                rtn += f"{rc} {cc}\n"
            yield rtn

    def p1799(size=5):
        for i in range(1000):
            rtn = ""
            rtn += f"{size}\n"
            for _ in range(size):
                for _ in range(size):
                    rtn += f"{randint(0, 1)} "
                rtn += "\n"
            yield rtn

    def p1107():
        def con(N, M, btn):
            inp = str(N) + "\n"
            inp += str(M) + "\n"
            inp += " ".join(btn)
            return inp

        for N in (
            list(range(0, 10)) + list(range(90, 110)) + list(range(499_990, 500_001))
        ):
            for M in range(0, 10):
                for btn in combinations([str(i) for i in range(10)], M):
                    yield con(N, M, btn)

    def scpc2021_2():
        for N in range(2, 15):
            for t in range(1, N):
                Bset = set()
                for a in range(2**N):
                    A = bin(a)[2 : 2 + N]
                    A = "0" * (N - len(A)) + A
                    B = ["0"] * N
                    for i in range(N):
                        if t <= i and A[i - t] == "1":
                            B[i] = "1"
                        if i < N - t and A[i + t] == "1":
                            B[i] = "1"
                    Bset.add("".join(B))
                inp = f"{len(Bset)}\n"
                for b in Bset:
                    inp += f"{N} {t}\n{b}\n"
                yield inp

    def p1300():
        for N in range(1, 10):
            for K in range(1, min(10**9, N * N) + 1):
                inp = str(N) + "\n" + str(K)
                yield inp
        for N in range(10**3, 10**5 + 1):
            for K in range(1, min(10**9, N * N) + 1, min(10**9, N * N) // 1000 + 1):
                inp = str(N) + "\n" + str(K)
                yield inp

    def p1427():
        for i in range(1, 1_000_000_001):
            yield str(i)

    def p20149():
        # yield 20149 inputs
        # example:
        # 1 1 5 5
        # 1 5 5 1
        bw = (-3, 4)
        points = list(product(range(*bw), repeat=2))
        for l1 in permutations(points, 2):
            for l2 in permutations(points, 2):
                inp = f"""{l1[0][0]} {l1[0][1]} {l1[1][0]} {l1[1][1]}
{l2[0][0]} {l2[0][1]} {l2[1][0]} {l2[1][1]}"""
                yield inp

    def p2636():
        """
        yield random inputs of boj problen No.2646
        """
        R, C = 12, 12
        for _ in range(100_000_000):
            inp = f"{R} {C}\n"
            for r in range(R):
                for c in range(C):
                    if r == R - 1 or c == C - 1 or r == 0 or c == 0:
                        inp += "0 "
                    else:
                        inp += f"{randint(0, 1)} "
                inp += "\n"
            yield inp


if __name__ == "__main__":
    pg = getattr(TcGen, "p" + str(int(input())))()
    for _ in range(10):
        print(next(pg))
        print()
