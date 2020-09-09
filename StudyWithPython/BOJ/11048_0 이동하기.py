# 11048 이동하기 1회차 (AC)

input = __import__('sys').stdin.readline
N, M = map(int, input().split())
mz = [list(map(int, input().split())) for _ in range(N)]

def sqMax(r, c):
    v1, v2, v3 = mz[r][c], mz[r+1][c], mz[r][c+1]
    mz[r+1][c+1] += max(v1, v2, v3)

# 전처리
for i in range(M-1):
    mz[0][i+1] += mz[0][i]

for i in range(1, N):
    mz[i][0] += mz[i - 1][0]

[sqMax(r, c) for r in range(N-1) for c in range(M-1)]
# for m in mz:
#     print(m)
print(mz[-1][-1])