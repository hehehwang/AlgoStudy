import sys

input = sys.stdin.readline
print = lambda x: sys.stdout.write(str(x))


def ccw(x0, y0, x1, y1, x2, y2):
    return (x1 - x0) * (y2 - y1) - (x2 - x1) * (y1 - y0)


x1, y1, x2, y2 = map(int, input().split())
x3, y3, x4, y4 = map(int, input().split())
(x1, y1), (x2, y2) = sorted(((x1, y1), (x2, y2)))
(x3, y3), (x4, y4) = sorted(((x3, y3), (x4, y4)))
p1, p2 = (x1, y1), (x2, y2)
p3, p4 = (x3, y3), (x4, y4)

denom = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4)
# if the two lines are parallel
if denom == 0:
    # if two line are on the same line (same slope)
    if ccw(*p1, *p2, *p3) == 0 and ccw(*p1, *p2, *p4) == 0:
        # meet at one point (p1)
        if p4 == p1:
            print(f"1\n{x1} {y1}")
        # meet at one point (p2)
        elif p2 == p3:
            print(f"1\n{x2} {y2}")
        # both line is same
        elif p1 == p3 or p2 == p4:
            print(1)
        # p1-p2 line covers p3-p4 partially
        elif (x1 <= x3 <= x2 and y1 <= y3 <= y2) or (x1 <= x4 <= x2 and y1 <= y4 <= y2):
            print(1)
        # p3-p4 line covers p1-p2 partially
        elif (x3 <= x1 <= x4 and y3 <= y1 <= y4) or (x3 <= x2 <= x4 and y3 <= y2 <= y4):
            print(1)
        else:
            print(0)
    # two line are parallel
    else:
        print(0)
# does both line intersect
elif (
    ccw(*p1, *p2, *p3) * ccw(*p1, *p2, *p4) <= 0
    and ccw(*p3, *p4, *p1) * ccw(*p3, *p4, *p2) <= 0
):
    px = ((x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4)) / denom
    py = ((x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4)) / denom
    print(f"1\n{px} {py}")
else:
    print(0)
