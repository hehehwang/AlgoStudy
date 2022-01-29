def ccw(x0, y0, x1, y1, x2, y2):
    v = (x1 - x0) * (y2 - y1) - (x2 - x1) * (y1 - y0)
    return 1 if v > 0 else -1 if v < 0 else 0


def line_crossed(x1, y1, x2, y2, x3, y3, x4, y4):
    p1, p2, p3, p4 = (x1, y1), (x2, y2), (x3, y3), (x4, y4)
    # case 1. both line are aligned or parallel
    l1l2 = ccw(*p1, *p2, *p3) * ccw(*p1, *p2, *p4)
    l2l1 = ccw(*p3, *p4, *p1) * ccw(*p3, *p4, *p2)
    if l1l2 == 0 and l2l1 == 0:
        p1, p2 = sorted([p1, p2])
        p3, p4 = sorted([p3, p4])
        return p3 <= p2 and p1 <= p4
    # case 2. not aligned, crossed each other
    return l1l2 <= 0 and l2l1 <= 0


x1, y1, x2, y2 = map(int, input().split())
x3, y3, x4, y4 = map(int, input().split())
print(1 if line_crossed(x1, y1, x2, y2, x3, y3, x4, y4) else 0)
