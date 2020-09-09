# QUADTREE 압축 해제해보기

def findLength(depth):
    global ss
    s = ss.pop()
    if s ==  'x':
        return max([findLength(depth+1) for _ in range(4)])
    else:
        return 2 ** depth

def decompressed(r, c, size):
    global board, ss
    s = ss.pop()
    # 기저사례: x가 아니면 해당 사이즈의 보드를 칠한다.
    if s != 'x':
        for i in range(size):
            for j in range(size):
                board[r+i][c+j] = s
    # x면 size를 반으로 쪼개고 4방향으로 decompress한다.
    else:
        size //= 2
        decompressed(r, c, size)
        decompressed(r, c+size, size)
        decompressed(r+size, c, size)
        decompressed(r+size, c+size, size)

sss = input()
ss = list(reversed(sss))
boardLength = findLength(0)
board = [[0]* boardLength for _ in range(boardLength)]
ss = list(reversed(sss))
decompressed(0, 0, boardLength)
[print(line) for line in board]