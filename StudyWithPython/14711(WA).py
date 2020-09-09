# 14711 타일 뒤집기(Easy) (WA)
input = __import__('sys').stdin.readline
N = int(input())
tile = input()
tileSet = []

def tileToNum(l):
    # 검정(#) 타일은 1, 흰(.) 타일은 0으로 변환
    return [0 if s == '.' else 1 for s in l]

def isValidIndex(i):
    if 0<= i and i < len(tile): return True
    else: return False

# 한 줄씩 입력 -> 숫자로 변환 ->
# 이번 행 (누르기 전)검정타일 누르기 -> 저번 행 (누르기 전)검정 타일 누르기 ->
# 홀수에 검정 채워 출력 -> 반복

print(tile)
for _ in range(N-1):
    numTile = tileToNum(tile)
    tileSet.append(tile)

    # 이번 행 검정 타일 누르기
    for i, t in enumerate(tile):
        if t == '#':
            numTile[i] += 1
            if isValidIndex(i-1): numTile[i-1] += 1
            if isValidIndex(i+1): numTile[i+1] += 1

    # 저번 행 검정 타일 누르기
    if len(tileSet)>=2:
        for i, t in enumerate(tileSet[-2]):
            if t == '#': numTile[i] += 1

    # 출력 및 다음 루프 준비
    tile = ''
    for n in numTile:
        if n%2 == 1:
            tile += '#'
        else: tile += '.'
    print(tile)