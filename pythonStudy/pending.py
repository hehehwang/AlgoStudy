
def f1(seq, i):
    global sss
    if i == len(sss): return len(seq)
    else:
        # print(seq, i)
        if (not seq) or seq[-1] < sss[i]:
            seq.append(sss[i])
        return max([f1(seq, i+j+1) for j in range(len(sss)-i)])


for _ in range(int(input())):
    input()
    sss = list(map(int, input().split()))
    print(max([f1([], i) for i in range(len(sss)-1)]))