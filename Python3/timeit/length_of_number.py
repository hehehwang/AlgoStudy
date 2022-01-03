from timeit import timeit
from time import perf_counter
from decimal import Decimal, getcontext
from math import log10, floor

getcontext().prec = 1000
num = Decimal(1e300)
t = perf_counter()
print(f"{len(str(num))=}, {perf_counter() - t}")
t = perf_counter()
print(f"{floor(log10(num))+1=}, {perf_counter() - t}")
l = 0
t = perf_counter()
while num:
    num //= 10
    l += 1
print(f"{l=}, {perf_counter() - t}")

print("==== without Decimal ====")
setup = """from math import log10, floor, fabs;
num = 1e40;
l=0"""
stmt1 = "l = len(str(num))"
stmt2 = "while num: num /= 10; l += 1"
stmt3 = "l = floor(log10(num)) + 1"
stmt4 = "l = fabs(log10(num)) + 1"
print(timeit(stmt1, setup))
print(timeit(stmt2, setup))
print(timeit(stmt3, setup))
print(timeit(stmt4, setup))

print("==== with Decimal ====")
setup = """from decimal import Decimal, getcontext;
from math import log10, floor;
getcontext().prec=100
num = Decimal('10e100');
l=0"""
stmt1 = "l = len(str(num))"
stmt2 = "while num: num /= 10; l += 1"
stmt3 = "l = floor(log10(num)) + 1"
print(timeit(stmt1, setup))
print(timeit(stmt2, setup))
print(timeit(stmt3, setup))
