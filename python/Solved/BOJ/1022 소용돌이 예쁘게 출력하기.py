# 1022 소용돌이 예쁘게 출력하기
input = __import__('sys').stdin.readline

r1, c1, r2, c2 = map(int, input().split())

class cursor:
    def __init__(self, point, value):
        self.point = point
        self.value = value
        self.corner = 0

    def __repr__(self):
        info = [self.point, self.value, self.corner]
        return ' '.join(map(str, info))

    def IsCorner(self):
        r, c = self.point
        if r + c == 0 :
            return True
        elif r < 0 and c == r :
            return True
        elif r >= 0 and c == r+1:
            return True
        return False

    def WhenCorner(self):
        if self.IsCorner():
            self.corner += 1
            self.corner %= 4

    def Move(self):
        r, c = self.point
        if self.corner== 0: c += 1
        if self.corner== 1: r -= 1
        if self.corner== 2: c -= 1
        if self.corner== 3: r += 1
        self.point = (r, c)
        self.value += 1
        self.WhenCorner()

    def MoveBack(self):
        self.WhenCorner()
        r, c = self.point
        if self.corner== 0: c -= 1
        if self.corner== 1: r -= 1
        if self.corner== 2: c += 1
        if self.corner== 3: r += 1
        self.point = (r, c)
        self.value -= 1

grid = [[0 for i in range(c2-c1+1)] for j in range(r2-r1+1)]

def GetGridCorner():
    return [grid[0][0], grid[0][-1], grid[-1][0], grid[-1][-1]]

# def IsFull():
#     if all([all(l) for l in grid]):
#         return True
#     return False


# print('point, value, corner, sidelength')
# for i in range(10):
#     print(now)
#     now.Move(1)

# main
# 그리드의 각 코너에서 (0,0)과의 거리를 잰다.
maxlevel = max([abs(i) for i in [r1, r2, c1, c2]])
now = cursor((maxlevel, maxlevel), (2 * maxlevel+1) ** 2)
fullcnt = (r2-r1+1)*(c2-c1+1)

# while not IsFull():
while fullcnt:
    if r1 <= now.point[0] <= r2 and c1 <= now.point[1] <= c2:
        grid[now.point[0]-r1][now.point[1]-c1] = now.value
        fullcnt -= 1
    now.MoveBack()


    # # 1씩 움직이기
    # if r1 <= now.point[0] <= r2 and c1 <= now.point[1] <= c2:
    #     grid[now.point[0]-r1][now.point[1]-c1] = now.value
    #     now.Move()
    #     continue

def GetMax():
    return max(GetGridCorner())

def GetMaxIntLength():
    return len(str(GetMax()))

maxintlength = GetMaxIntLength()

for line in grid:
    for num in line:
        num = str(num)
        num = ' ' * (maxintlength-len(num)) + num
        print(num, end=' ')
    print('')
