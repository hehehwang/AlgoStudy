# FENCE 울타리 잘라내기 (TL)
input = __import__('sys').stdin.readline

def maxFence(lo, hi):
    global fences
    if hi-lo ==1: return fences[lo]
    elif hi-lo ==2 :
        return max(min(fences[lo], fences[hi-1])*2, fences[lo], fences[hi-1])
    else:
        # 0, 1, 2, 3 -> mid = (4-0)//2 = 2
        # 0, 1, 2 -> mid = (3-0)//2 = 1; left: 0, right: 1, 2
        mid = (hi+lo)//2
        left = maxFence(lo, mid)
        right = maxFence(mid, hi)
        # 중간 2개부터 시작해서 좌우로 넓혀간다.
        centerLo, centerHi = mid-1, mid
        minHeight = min(fences[centerLo], fences[centerHi])
        center = minHeight*2
        for i in range(hi-lo-2):
            if centerLo==0:
                centerHi +=1
            elif centerHi==hi-1:
                centerLo -=1
            elif fences[centerLo-1] <= fences[centerHi+1]:
                centerHi += 1
            else:
                centerLo -= 1
            minHeight = min(minHeight, fences[centerLo], fences[centerHi])
            center = max(center, minHeight*(3+i))
        return max(left, right, center)

for _ in range(int(input())):
    _ = input()
    fences = list(map(int, input().split()))
    print( maxFence(0, len(fences)))