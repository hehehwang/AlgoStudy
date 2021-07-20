# 1011 Fly me to the Alpha Centauri
# https://www.acmicpc.net/problem/1011
from math import floor, sqrt
input = __import__('sys').stdin.readline
[print(floor(2*sqrt((lambda x, y: y-x)(*[int(i) for i in input().split()]))-1e-9)) for _ in range(int(input()))]
