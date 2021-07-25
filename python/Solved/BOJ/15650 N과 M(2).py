# 15650 N과 M(2) (AC)
input = __import__('sys').stdin.readline

N, M = map(int, input().split())
pkd = [False] * N

# 만들던 수열과 뽑힌 번호를 받아 수열을 생성한다.
# 기저사례 : 수열을 다 만들었으면 print
def mkSeq(seq, pkd):
    if len(seq) == M:
        print(' '.join(map(str, seq)))

    else:
        minList = []
        for i, v in enumerate(pkd):
            if not v :
                if len(seq) > 0 and i+1 <= seq[-1] :
                    pass
                else: minList.append(i)
        for n in minList:
            pkd[n] = True
            tmpSeq = seq + [n+1]
            mkSeq(tmpSeq, pkd)
            pkd[n] = False

mkSeq([], pkd)