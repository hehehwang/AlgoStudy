# BOARDCOVER 책 풀이
input = __import__('sys').stdin.readline

# 주어진 칸을 덮을 수 있는 네 가지 방법
# 블록을 구성하는 세 칸의 상대적 위치 (dy, dx)의 목록
coverType = [[(0, 0), (1, 0), (0, 1)],
             [(0, 0), (0, 1), (1, 1)],
             [(0, 0), (1, 0), (1, 1)],
             [(0, 0), (1, 0), (1, -1)]]

# board의 (y, x)를 type번 방법으로 덮거나, 덮었던 블록을 없엔다.
# delta = 1 이면 덮고, -1이면 덮었던 블록을 없앤다.
# 만약 블록이 제대로 덮이지 않은 경우
# (게임판을 벗어나거나, 겹치거나, 검은 칸틀 덮을 떄) False를 덮는다.
def set(board, y, x, type, delta):
    ok = True
    for i in range(3):
        ny = y+coverType[type][i][0]
        nx = x+coverType[type][i][1]
        if ny<0 or len(board)<=ny or nx < 0 or len(board[0])<= nx:
            ok = False
        else:
            board[ny][nx] += delta
            if board[ny][nx]>1: ok = False
    return ok

# board의 모든 빈 칸을 덮을 수 있는 방법의 수를 반환한다.
# board[i][j] = 1 이미 덮인 칸 혹은 검은 칸
# board[i][j] = 0 아직 덮이지 않은 칸
def cover(board):
    # 아직 채우지 못한 칸 중 가장 윗줄 왼쪽에 있는  칸을 찾는다.
    y, x = -1, -1
    for i in range(len(board)):
        for j in range(len(board[0])):
            if board[i][j] == 0:
                y, x = i, j
                break
        if y != -1: break
    # 기저 사례 : 모든 칸틀 채웠으면 1을 반환한다.
    if y == -1 : return 1
    ret = 0
    for type in range(4):
        if set(board, y, x, type, 1):
            ret += cover(board)
        set(board, y, x, type, -1)
    return ret

# IO
for _ in range(int(input())):
    H, W = map(int, input().split())
    _board = [[s for s in input().strip()] for _ in range(H)]
    board = [[] for _ in range(H)]
    for i, line in enumerate(_board):
        board[i] = [0 if s == '.' else 1 for s in line]
    print(cover(board))
