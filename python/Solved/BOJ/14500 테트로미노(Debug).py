# 14500 테트로미노
from random import random
input = __import__('sys').stdin.readline

def sol1():
    maxV1 = 0
    for i in range(bR):
        for j in range(bC):
            if j + 3 < bC: # type 1. 1*4
                # shape 1. ----
                v = bb[i][j] + bb[i][j + 1] + bb[i][j + 2] + bb[i][j + 3]
                maxV1 = max(maxV1, v)
            if (i + 3 < bR):  # type 2. 4*1
                # shape 2. |
                v = bb[i][j] + bb[i + 1][j] + bb[i + 2][j] + bb[i + 3][j]
                maxV1 = max(maxV1, v)
            if (i + 1 < bR and j + 1 < bC):  # type 3. 2*2
                # shape 3. square
                v = bb[i][j] + bb[i + 1][j] + bb[i][j + 1] + bb[i + 1][j + 1]
                maxV1 = max(maxV1, v)
            if (i + 2 < bR and j + 1 < bC):  # type 4. 3*2
                # shape 4. └
                v = bb[i][j] + bb[i + 1][j] + bb[i + 2][j] + bb[i + 2][j + 1]
                maxV1 = max(maxV1, v)
                # shape 5. ┘
                v = bb[i][j + 1] + bb[i + 1][j + 1] + bb[i + 2][j + 1] + bb[i + 2][j]
                maxV1 = max(maxV1, v)
                # shape 6. ┐
                v = bb[i][j] + bb[i][j + 1] + bb[i + 1][j + 1] + bb[i + 2][j + 1]
                maxV1 = max(maxV1, v)
                # shape 7. ┌
                v = bb[i][j + 1] + bb[i][j] + bb[i + 1][j] + bb[i + 2][j]
                maxV1 = max(maxV1, v)
                # shape 8. ├
                v = bb[i][j] + bb[i + 1][j] + bb[i + 1][j + 1] + bb[i + 2][j]
                maxV1 = max(maxV1, v)
                # shape 9. ┤
                v = bb[i][j + 1] + bb[i + 1][j + 1] + bb[i + 1][j] + bb[i + 2][j + 1]
                maxV1 = max(maxV1, v)
                # shape 10. z
                v = bb[i][j] + bb[i + 1][j] + bb[i + 1][j + 1] + bb[i + 2][j + 1]
                maxV1 = max(maxV1, v)
                # shape 11. s
                v = bb[i][j + 1] + bb[i + 1][j + 1] + bb[i + 1][j] + bb[i + 2][j]
                maxV1 = max(maxV1, v)

            if (i + 1 < bR and j + 2 < bC):  # type 5. 2*3
                # shape 12. └─
                v = bb[i][j] + bb[i + 1][j] + bb[i + 1][j + 1] + bb[i + 1][j + 2]
                maxV1 = max(maxV1, v)
                # shape 13. ─┘
                v = bb[i][j + 2] + bb[i + 1][j + 2] + bb[i + 1][j + 1] + bb[i + 1][j]
                maxV1 = max(maxV1, v)
                # shape 14. ┌─
                v = bb[i][j + 2] + bb[i][j + 1] + bb[i][j] + bb[i + 1][j]
                maxV1 = max(maxV1, v)
                # shape 15. ─┐
                v = bb[i][j] + bb[i][j + 1] + bb[i][j + 2] + bb[i + 1][j + 2]
                maxV1 = max(maxV1, v)
                # shape 16. ─┴─
                v = bb[i][j + 1] + bb[i + 1][j] + bb[i + 1][j + 1] + bb[i + 1][j + 2]
                maxV1 = max(maxV1, v)
                # shape 17. ─┬─
                v = bb[i][j] + bb[i][j + 1] + bb[i][j + 2] + bb[i + 1][j + 1]
                maxV1 = max(maxV1, v)
                # shape 18. z
                v = bb[i][j] + bb[i][j + 1] + bb[i + 1][j + 1] + bb[i + 1][j + 2]
                maxV1 = max(maxV1, v)
                # shape 19. s
                v = bb[i][j + 2] + bb[i][j + 1] + bb[i + 1][j + 1] + bb[i + 1][j]
                maxV1 = max(maxV1, v)
    return maxV1

## sol2
def sol2():
    Tetromino = [
        [[0, 0], [1, 0], [2, 0], [3, 0]],
        [[0, 0], [0, 1], [0, 2], [0, 3]],
        [[0, 0], [0, 1], [1, 0], [1, 1]],
        [[0, 0], [1, 0], [2, 0], [2, 1]],
        [[0, 0], [1, -2], [1, -1], [1, 0]],
        [[0, 0], [0, 1], [1, 1], [2, 1]],
        [[0, 0], [0, 1], [0, 2], [1, 0]],
        [[0, 0], [1, 0], [2, 0], [2, -1]],
        [[0, 0], [0, 1], [0, 2], [1, 2]],
        [[0, 0], [0, 1], [1, 0], [2, 0]],
        [[0, 0], [1, 0], [1, 1], [1, 2]],
        [[0, 0], [1, 0], [1, 1], [2, 1]],
        [[0, 0], [0, 1], [1, -1], [1, 0]],
        [[0, 0], [1, -1], [1, 0], [2, -1]],
        [[0, 0], [0, 1], [1, 1], [1, 2]],
        [[0, 0], [0, 1], [0, 2], [1, 1]],
        [[0, 0], [1, 0], [1, 1], [2, 0]],
        [[0, 0], [1, -1], [1, 0], [1, 1]],
        [[0, 0], [1, -1], [1, 0], [2, 0]],]

    maxV2 = 0
    for r in range(bR):
        for c in range(bC):
            for i in range(19):
                valid = True
                v = 0
                for j in range(4):
                    nr = r + Tetromino[i][j][0]
                    nc = c + Tetromino[i][j][1]
                    if (nr<0 or nc<0 or bR <= nr or bC<= nc):
                        valid = False
                        break
                    v += bb[nr][nc]
                if (valid): maxV2 = max(maxV2, v)
    return maxV2

bR, bC = map(int, input().split())
bb = [list(map(int, input().split())) for _ in range(bR)]
print(sol2())
# for i in range(100):
#     bR, bC = 4, 4
#     bb = [[round(random()) for _ in range(bC)] for _ in range(bR)]
#     v1 = sol1()
#     v2 = sol2()
#     if v1 != v2:
#         print('정해: ',  v2)
#         print('오답: ', v1)
#         [print(l) for l in bb]
#         break