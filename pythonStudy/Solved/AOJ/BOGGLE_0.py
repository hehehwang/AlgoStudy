# BOGGLE 보글 게임 1회차(AC)
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

for _ in range(int(input())):
    board = [[s for s in input().strip()] for _ in range(5)]
    words = [input().strip() for _ in range(int(input()))]
    points = []
    for i in range(5):
        points.extend([(i, j) for j in range(5)])
    for word in words:
        pts = points
        for letter in word:
            if not pts: break
            rtn = set([])
            for pt in pts:
                if board[pt[0]][pt[1]] == letter:
                    rtn.update(get_neighbor_points(pt))
            pts = rtn
        if pts:
            print(word, 'YES')
        else:
            print(word, 'NO')
