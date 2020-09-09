# BOARDCOVER 게임판 덮기 1회차(AC)
from copy import deepcopy
input = __import__('sys').stdin.readline

# piece1 : 0,0 1,0 1,1
# piece2 : 0,0 0,1 1,1
# piece3 : 0,0 1,-1 1,0
# piece4 : 0,0 0,1 1,0

class Board:
    def __init__(self, board, leftBlank=None):
        self.board = board
        self.leftBlank = leftBlank if leftBlank else self.countBlank()
    def __repr__(self):
        return str(self.leftBlank)
    def countBlank(self):
        cnt = 0
        lst = [s=='.' for line in self.board for s in line]
        # for line in self.board:
        #     for s in line:
        #         cnt += 1 if s == '.' else 0
        return sum(lst)
    def getValue(self, point):
        r, c = point
        return self.board[r][c]

boardPiecesR=[[0, 1, 1],
               [0, 0, 1],
               [0, 1, 1],
               [0, 0, 1]]
boardPiecesC=[[0, 0, 1],
              [0, 1, 1],
              [0, -1, 0],
              [0, 1, 0]]

def isValidCoord(point):
    global H, W
    r, c = point
    # if 0<=r<H and 0<=c<=W: return True
    # else: return False
    return True if 0<=r<H and 0<=c<W else False

def nextCoord(point):
    r, c = point
    if isValidCoord((r, c+1)): return (r, c+1)
    elif isValidCoord((r+1, 0)): return (r+1, 0)
    else: return False

def getEnableBlklst(point, board):
    lst = []
    r, c = point
    for i in range(4):
        cnt = 0
        for pr, pc in zip(boardPiecesR[i], boardPiecesC[i]):
            if not isValidCoord((r+pr, c+pc)): break
            if board.getValue((r+pr, c+pc)) == '#': break
            cnt += 1
        if cnt == 3: lst.append(i)
    return lst

def coverBlock(point, board, blknum):
    tmp = deepcopy(board.board)
    r, c = point
    for pr, pc in zip(boardPiecesR[blknum], boardPiecesC[blknum]):
        tmp[r+pr][c+pc] = '#'
    return Board(tmp, board.leftBlank-3)

def solution(point, board):
    if board.leftBlank%3 != 0 : return 0
    # 다 채웠는지 검사
    if board.leftBlank == 0 : return 1
    # 이 칸이 차있으면 다음 칸으로
    if board.getValue(point) == '#':
        return solution(nextCoord(point), board)
    blklst = getEnableBlklst(point, board)
    if not blklst: return 0

    ret = 0
    for blk in blklst:
        ret += solution(nextCoord(point), coverBlock(point, board, blk))
    return ret

# Main
for _ in range(int(input())):
    H, W = map(int, input().split())
    board = Board([[s for s in input().strip()] for _ in range(H)])
    print(solution((0, 0), board))


# Test#2 getEnableBlklst test
# b = Board([['.', '.', '.'],
#            ['.', '.', '.'],
#            ['.', '#', '.']])
# print(getEnableBlklst((1, 1), b))