# 14956 Philosopher's Walk
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**9)

bN, walk = map(int, input().split())
def phil(walk, bN):
    if bN == 2:
        if walk == 1: return (1, 1)
        elif walk == 2: return (1, 2)
        elif walk == 3: return (2, 2)
        elif walk == 4: return (2, 1)
        else: raise NotImplementedError
    sQ = bN>>1
    Q = sQ*sQ
    if 0<walk<=Q:
        rv = phil(walk, sQ)
        return (rv[1], rv[0])
    elif Q<walk<=2*Q:
        rv = phil(walk-Q, sQ)
        return (rv[0], rv[1]+sQ)
    elif 2*Q<walk<=3*Q:
        rv = phil(walk-2*Q, sQ)
        return (rv[0]+sQ, rv[1]+sQ)
    elif 3*Q<walk<=4*Q:
        rv = phil(walk-3*Q, sQ)
        return (sQ-rv[1]+1+sQ, sQ-rv[0]+1)
    else: raise NotImplementedError

print(' '.join(map(str, phil(walk, bN))))