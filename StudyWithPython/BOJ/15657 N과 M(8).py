# 15657 N과 M(8)
input = __import__('sys').stdin.readline

N, M = map(int, input().split())
faceNum = [int(i) for i in input().split()]
faceNum.sort()

def mkSeq(seq):
    if len(seq) == M:
        for s in seq:
            print(faceNum[s], end=' ')
        print()

    else:
        try: lastNum = seq[-1]
        except: lastNum = 0
        searchList = [i for i in range(lastNum, N)]
        for n in searchList:
            tmpSeq = seq + [n]
            mkSeq(tmpSeq)

mkSeq([])