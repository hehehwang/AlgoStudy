# PICNIC 소풍 1회차(AC)
input = __import__('sys').stdin.readline

def getLowestUnpicked(pkdlst):
    for i, v in enumerate(pkdlst):
        if not v: return i

n = 1
setgroup = []

def makeSetGroup(pkdlst, combi):
    entry = [i for i in range(len(pkdlst)) if not pkdlst[i]]
    if len(entry) == 2:
        combi.append((entry[0], entry[1]))
        setgroup.append(combi)
    else:
        a = entry.pop()
        pkdlst[a] = True
        for i in entry:
            b = i
            pkdlst[b] = True
            combisend = combi + [(a, b)]
            makeSetGroup(pkdlst[:], combisend)
            pkdlst[b] = False

def calclen(n):
    rtn = 1
    for i in range(n//2+1, n+1):
        rtn *= i
        rtn /= 2
    return int(rtn)

for c in range(int(input())):
    n, m = map(int, input().split())
    friend = [[False]*n for _ in range(n)]
    picked = [False]*n
    setgroup = []
    relationship = list(map(int, input().split()))
    for i in range(m):
        a, b = relationship[2*i], relationship[2*i+1]
        friend[a][b] = True
        friend[b][a] = True
    makeSetGroup(picked, [])
    cnt = 0
    for group in setgroup:
        if all([friend[pair[0]][pair[1]] for pair in group]):
            cnt+=1
    print(cnt)

