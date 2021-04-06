# LIS Logest Increasing Sequence

# startIdx에서 시작하는 증가 부분 수열 중 최대 길이 반환
def f(startIdx):
    global sss, cache
    ret = cache[startIdx]
    if ret != -1: return ret
    # 최소 1개 (기저사례)
    ret = 1
    # startIdx 다음 번호부터 순회 시작
    for i in range(len(sss)-startIdx-1):
        nextIdx = startIdx+i+1
        # 만약 지금 번호보다 큰 번호에 당도했다면
        if sss[startIdx] < sss[nextIdx]:
            # 거기서 증가부분 순열 다시 측정
            ret = max(ret, f(nextIdx)+1)
    cache[startIdx] = ret
    return ret

# ex
# 0 1 2 3 4 5
# 3 1 4 5 9 2
# startIdx가 2아라면 (sss[startIdx] = 4)
# sss[3]에서부터 sss[5]까지 순회를 돌기 시작한다.
# sss[3](=5)은 4보다 큼으로, 넣을지 말지 고민해본다.
# 만약 cache[3]에 숫자가 있는지 확인해보고, 없다면
# startIdx를 3으로 두고 다시 순회를 시작한다.
# 조사가 다 끝난다면, 그 순열 마지막에 sss[2]를 넣는 셈이므로
# +1을 해준 값과 ret를 비교애, ret보다 크다면 ret를 대체한다.
# cache에도 한번 넣어주고
# 재귀 좆같다

for _ in range(int(input())):
    input()
    sss = list(map(int, input().split()))
    cache = [-1]*(len(sss))
    maxNum = 0
    for i in range(len(sss)-1):
        maxNum = max(maxNum, f(i))
    print(maxNum)