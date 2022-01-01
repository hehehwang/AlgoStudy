# BOGGLE 보글 게임 2회차(TL)
input = __import__('sys').stdin.readline

# (-1,-1) (-1,0) (-1,1)
# (0,-1) (0,0) (0,1)
# (1,-1) (1,0) (1,1)
n_vec_r = [-1, 0, 1, -1, 1, -1, 0, 1]
n_vec_c = [-1, -1, -1, 0, 0, 1, 1, 1]

def addvec(vec1, vec2):
    return (vec1[0]+vec2[0], vec1[1]+vec2[1])

def get_neighbor_points(point):
    rtn = []
    for i in range(8):
        npoint = addvec(point, (n_vec_r[i], n_vec_c[i]))
        if npoint[0]<0 or npoint[1]<0:
            continue
        if 5<=npoint[0] or 5<=npoint[1]:
            continue
        rtn.append(npoint)
    return rtn


def hasWord(point, word, board):
    if board[point[0]][point[1]] != word[0]: return False
    if len(word) == 1: return True

    for pts in get_neighbor_points(point):
        if hasWord(pts, word[1:], board): # 이게 있으면 중간 False를 제끼고 탐색할 수 있다!
            return True

for _ in range(int(input())):
    board = [[s for s in input().strip()] for _ in range(5)]
    words = [input().strip() for _ in range(int(input()))]
    points=[]
    for i in range(5):
        points.extend([(i, j) for j in range(5)])

    for word in words:
        print(word, end=' ')

        flag = False
        for pts in points:
            if hasWord(pts, word, board): flag=True
        print('YES' if flag else 'NO')