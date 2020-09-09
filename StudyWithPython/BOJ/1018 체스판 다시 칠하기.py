# 1018 체스판 다시 칠하기

input = __import__('sys').stdin.readline
M, N = map(int, input().split())
board = [[l for l in input()] for _ in range(M)]

class CLR_STNDRD:
    def __init__(self, c):
        self.c = c
    def switch(self):
        if self.c == 'W':
            self.c = 'B'
        else: self.c = 'W'

def getboardvalue(coord):
    global board
    return board[coord[0]][coord[1]]

def addvec(vec1, vec2):
    return (vec1[0]+vec2[0], vec1[1]+vec2[1])

def getBoardDiff(coord):
    rtn1 = 0
    bnch = CLR_STNDRD('W')
    for i in range(8):
        for j in range(8):
            rtn1 += (getboardvalue(addvec(coord, (i, j))) != bnch.c)
            bnch.switch()
        bnch.switch()

    rtn2 = 0
    bnch = CLR_STNDRD('B')
    for i in range(8):
        for j in range(8):
            rtn2 += (getboardvalue(addvec(coord, (i, j))) != bnch.c)
            bnch.switch()
        bnch.switch()
    return min(rtn1, rtn2)

to_search = []
for l in [[(i, j) for i in list(range(M-7))] for j in list(range(N-7))]:
    to_search += l

min_val = 64
for c in to_search:
    r = getBoardDiff(c)
    min_val = min(min_val, r)
print(min_val)