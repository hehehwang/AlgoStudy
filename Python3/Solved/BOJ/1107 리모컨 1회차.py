# 1107 리모컨 1회차 (폭망)
targetNum = int(input().strip())
targetNumLen = len(str(targetNum))
if int(input()):
    broken = list((map(int, input().split())))
else:
    broken = []
notBroken = [i for i in range(10) if i not in broken]
notBroken.sort()

def mkNum(madeNum:int, madeNumLen = 0 , d:int = 0):
    global targetNum, notBroken
    # 만약 버튼이 다 개박살났거나 목표숫자길이가 0 이하라면 아이고 의미없다
    if (not notBroken) or targetNumLen+d<=0: return -101
    # 초행길이신지?
    isFirstRun = True if madeNum == -1 else False
    # 기저사례 : 목표하는 길이까지 도달했다면 반환. 초행이면 껒여
    if (not isFirstRun) and madeNumLen == targetNumLen+d: return madeNum
    # 측정기구
    minDiff, rtn = 5000000, 0
    for btn in notBroken:
        if isFirstRun :
            if btn == 0 and targetNum != 0 : continue
            # 목표가 0도 아닌데 처음부터 0으로 장난질이면 재미가 없다 이말이야
            else: nextNum = btn
        # 숫자 추가띠
        else: nextNum = madeNum*10 + btn
        rtnNum = mkNum(nextNum, madeNumLen+1, d)
        # if rtnNum == 0: continue
        diff = abs(rtnNum - targetNum)
        if diff < minDiff:
            minDiff = diff
            rtn = rtnNum
    return rtn


cases = [mkNum(-1, d = -1+i) for i in range(3)] if broken else [targetNum]
diffs = [abs(targetNum-c) for c in cases]
for i in range(len(diffs)): diffs[i] += len(str(cases[i]))
diffs += [abs(int(targetNum)-100)]
print(min(diffs), cases, diffs)
