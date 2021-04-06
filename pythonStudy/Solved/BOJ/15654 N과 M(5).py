# 15654 N과 M(5)
input = __import__('sys').stdin.readline

N, M = map(int, input().split())
faceNum = [int(i) for i in input().split()]
faceNum.sort()
pkd = [False]*N

def mkSeq(seq, pkd):
    if len(seq) == M:
        for s in seq:
            print(faceNum[s], end=' ')
        print()

    else:
        minList = []
        for i, v in enumerate(pkd):
            if not v: minList.append(i)
        for n in minList:
            pkd[n] = True
            tmpSeq = seq + [n]
            mkSeq(tmpSeq, pkd)
            pkd[n] = False

mkSeq([], pkd)