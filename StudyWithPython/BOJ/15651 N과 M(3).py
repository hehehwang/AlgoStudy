# 15651 N과 M(3)
input = __import__('sys').stdin.readline

N, M = map(int, input().split())

# 만들던 수열을 받아 수열을 생성한다.
# 기저사례 : 수열을 다 만들었으면 print
def mkSeq(seq):
    if len(seq) == M:
        print(' '.join(map(str, seq)))

    else:
        searchList = [i for i in range(N)]
        for n in searchList:
            tmpSeq = seq + [n+1]
            mkSeq(tmpSeq)

mkSeq([])