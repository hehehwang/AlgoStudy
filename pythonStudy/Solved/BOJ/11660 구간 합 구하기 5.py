# 11660 구간 합 구하기 5 (AC)
input = __import__('sys').stdin.readline
N, M = map(int, input().split())
table = []
for _ in range(N):
    table.append(list(map(int, input().split())))

def getTableValue(r, c):
    if r < 0 or N <= r or c < 0 or N <= c:
        return 0
    else: return table[r][c]

def sumTable(r, c):
    v = getTableValue(r-1, c) + \
        getTableValue(r, c-1) - \
        getTableValue(r-1, c-1)
    table[r][c] += v

def calc(x1, y1, x2, y2):
    return getTableValue(x2, y2) - \
           getTableValue(x2, y1-1) - \
           getTableValue(x1-1, y2) + \
           getTableValue(x1-1,y1-1)
for i in range(N):
    for j in range(N):
        sumTable(i, j)

for _ in range(M):
    coords = list(map(int, input().split()))
    coords = [x-1 for x in coords]
    print(calc(*coords))
# for t in table:
#     print(t)