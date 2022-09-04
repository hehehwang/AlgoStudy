def concat_tuple(a, b):
    return (a, b)


def deconcat_tuple(t):
    return t[0], t[1]


def concat_multi(a, b):
    return a * 1048576 + b


def deconcat_multi(c):
    return c // 1048576, c % 1048576


def concat_bitshift(a, b):
    return a << 20 | b


def deconcat_bitshift(c):
    return c >> 20, c & 0xFFFFF


def concat_str(a, b):
    return str(a) + "," + str(b)


def deconcat_str(c):
    c = c.split(",")
    return int(c[0]), int(c[1])


from timeit import timeit

setup = "from __main__ import concat_tuple, deconcat_tuple, concat_multi, deconcat_multi, concat_bitshift, deconcat_bitshift, concat_str, deconcat_str; a, b = 12321,32123"

t1 = timeit("c = concat_tuple(a, b); deconcat_tuple(c)", setup=setup)
t2 = timeit("c = concat_multi(a, b); deconcat_multi(c)", setup=setup)
t3 = timeit("c = concat_bitshift(a, b); deconcat_bitshift(c)", setup=setup)
t4 = timeit("c = concat_str(a, b); deconcat_str(c)", setup=setup)
print(f"concat_tuple: {t1:.3f}")
print(f"concat_multi: {t2:.3f}")
print(f"concat_bitshift: {t3:.3f}")
print(f"concat_str: {t4:.3f}")
