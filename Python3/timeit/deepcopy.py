from timeit import timeit
from copy import deepcopy

arr, memo = range(10), {}

arr1 = arr
arr2 = arr[:]
arr3 = deepcopy(arr, memo)
arr4 = [arr[i] for i in range(len(arr))]
arr5 = []
for i in range(len(arr)):
    arr5.append(arr[i])
arr6 = [0] * len(arr)
for i in range(len(arr)):
    arr6[i] = arr1[i]

print(f"id of arr: {id(arr)}")
print(f"id of arr1: {id(arr1)}")
print(f"id of arr2: {id(arr2)}")
print(f"id of arr3: {id(arr3)}")
print(memo)
print(f"id of arr4: {id(arr4)}")
print(f"id of arr5: {id(arr5)}")
print(f"id of arr6: {id(arr6)}")

print("===== timeit =====")
setup = """from copy import deepcopy;
arr = range(int(10e3))"""
num = 10000
stmt1 = """cpy = arr"""
stmt2 = """cpy = arr[:]"""
stmt3 = """cpy = deepcopy(arr)"""
stmt4 = """cpy  = [arr[i] for i in range(len(arr))]"""
stmt5 = """cpy = [];
for i in arr:
    cpy.append(i)"""
stmt6 = """cpy = [0]*len(arr)
for i in range(len(arr)):
    cpy[i] = arr[i]"""

print("statement 1:", timeit(stmt1, setup, number=num))
print("statement 2:", timeit(stmt2, setup, number=num))
print("statement 3:", timeit(stmt3, setup, number=num))
print("statement 4:", timeit(stmt4, setup, number=num))
print("statement 5:", timeit(stmt5, setup, number=num))
print("statement 6:", timeit(stmt6, setup, number=num))

"""
id of arr: 2683654031232
id of arr1: 2683654031232
id of arr2: 2683654031328
id of arr3: 2683654032192
{2683654031232: range(0, 10), 2683653730456: [range(0, 10)]}
id of arr4: 2683654114632
id of arr5: 2683654114760
id of arr6: 2683654181384
===== timeit =====
statement 1: 9.299999999999933e-05
statement 2: 0.0016486
statement 3: 0.027911099999999998
statement 4: 7.8926146
statement 5: 3.5871185999999993
statement 6: 9.020451399999999
"""
