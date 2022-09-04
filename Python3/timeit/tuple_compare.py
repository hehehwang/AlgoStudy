from random import randint
from timeit import timeit


def concat_bitshift(a, b, c):
    return a << 40 | b << 20 | c


def deconcat_bitshift(c):
    mask = 0xFFFFF
    return c >> 40, (c >> 20) & mask, c & mask


nums = [[randint(1, int(1e5)) for _ in range(3)] for _ in range(int(3_000_000))]

tuples = [(i[0], i[1], i[2]) for i in nums]
bits = [concat_bitshift(i[0], i[1], i[2]) for i in nums]

# print(sorted(tuples))
# print([deconcat_bitshift(n) for n in sorted(bits)])

setup = "from __main__ import concat_bitshift, deconcat_bitshift, tuples, bits"
test_nums = 20
t1 = timeit("tuples.sort()", setup=setup, number=test_nums)
t2 = timeit(
    "[deconcat_bitshift(n) for n in sorted(bits)]", setup=setup, number=test_nums
)

print(f"naive_tuple: {t1:.3f}")
print(f"bitshift_tuple: {t2:.3f}")
