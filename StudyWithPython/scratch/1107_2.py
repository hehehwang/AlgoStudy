from itertools import combinations
# 리모컨 반례 찾기
###########################
def mkNum(madeNum: int, madeNumLen=0, d: int = 0):
    global targetNum, notBroken
    # 만약 버튼이 다 개박살났거나 목표숫자길이가 0 이하라면 아이고 의미없다
    if (not notBroken) or targetNumLen + d <= 0: return -101
    # 초행길이신지?
    isFirstRun = True if madeNum == -1 else False
    # 기저사례 : 목표하는 길이까지 도달했다면 반환. 초행이면 껒여
    if (not isFirstRun) and madeNumLen == targetNumLen + d: return madeNum
    # 측정기구
    minDiff, rtn = 5000000, 0
    for btn in notBroken:
        if isFirstRun:
            if btn == 0 and targetNum != 0:
                continue
            # 목표가 0도 아닌데 처음부터 0으로 장난질이면 재미가 없다 이말이야
            else:
                nextNum = btn
        # 숫자 추가띠
        else:
            nextNum = madeNum * 10 + btn
        rtnNum = mkNum(nextNum, madeNumLen + 1, d)
        # if rtnNum == 0: continue
        diff = abs(rtnNum - targetNum)
        if diff < minDiff:
            minDiff = diff
            rtn = rtnNum
    return rtn
#############################

btns = [i for i in range(10)]

for N in range(10):
    for M in range(10):
        for c in combinations(btns, M):
            prob = []
            prob.append(N)
            prob.append(len(c))
            prob.append(' '.join(map(str, c)))

            ## get answer
            targetNum = int(prob[0])
            broken = list(prob[2].split()) if int(prob[1]) else []

            result = abs(targetNum - 100)
            # idx = 0
            for num in range(1000001):
                enable = True
                for n in str(num):
                    if n in broken:
                        enable = False
                        break
                if enable:
                    result = min(result, abs(targetNum - num) + len(str(num)))
                    # idx = i

            answer = result

            ## get trial
            targetNum = int(prob[0])
            targetNumLen = len(str(targetNum))
            if int(prob[1]):
                broken = list((map(int, prob[2].split())))
            else:
                broken = []
            notBroken = [i for i in range(10) if i not in broken]
            notBroken.sort()


            cases = [mkNum(-1, d=-1 + i) for i in range(3)] if broken else [targetNum]
            diffs = [abs(targetNum - c) for c in cases]
            for i in range(len(diffs)): diffs[i] += len(str(cases[i]))
            diffs += [abs(int(targetNum) - 100)]
            trial = min(diffs)

            # print(prob)
            if answer != trial:
                print('ERROR OCCURRED!')
                print('\n'.join(map(str, prob)))
                print('#####################################')
    print('Number', N, 'passed...')