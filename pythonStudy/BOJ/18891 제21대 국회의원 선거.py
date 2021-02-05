# 18891 제21대 국회의원 선거
input = __import__('sys').stdin.readline

partyN, voteN = map(int, input().split())
pn, pri, pv, pvr = [], [], [], []
for i in range(partyN):
    a, b, c = input().split()
    pn.append(a)
    pri.append(int(b))
    pv.append(int(c))
    pvr.append(int(c)/voteN)

# step 1.
ppi, psi = [], []
validVote, validSeat = 0, 47
for i in range(partyN):
    if pri[i] < 5 and pvr[i] < 0.03: continue
    validVote += pv[i]
    validSeat += pri[i]

for i in range(partyN):
    if pri[i] < 5 and pvr[i] < 0.03:
        ppi.append(0)
        psi.append(0)
    else:
        ppi.append(pv[i]/validVote)
        tmp = (validSeat*ppi[i]-pri[i])/2
        if tmp>1: psi.append(round(tmp))
        else: psi.append(0)

# step 2.
psiSum = sum(psi)
tmp = []
if 30 < psiSum:
    for i in range(partyN):
        v = 30*psi[i]/psiSum
        tmp.append(v-int(v))
        psi[i] = int(v)
elif psiSum < 30:
    for i in range(partyN):
        v = psi[i]+(30-psiSum)*ppi[i]
        tmp.append(v-int(v))
        psi[i] = int(v)
while sum(psi) != 30:
    # ni = max(enumerate(tmp), key=lambda x: x[1])[0]
    maxV = max(tmp)
    for i in range(partyN):
        if tmp[i] == maxV:
            psi[i] += 1
            tmp[i] = 0
            break

# step 3.
tmp = []
pt = []
for i in range(partyN):
    v = 17*ppi[i]
    tmp.append(v - int(v))
    pt.append(int(v))
while sum(pt) != 17:
    maxV = max(tmp)
    for i in range(partyN):
        if tmp[i] == maxV:
            pt[i] += 1
            tmp[i] = 0
            break

# final
totalSeat = []
for i in range(partyN):
    totalSeat.append(pri[i]+psi[i]+pt[i])

# sort & print
index = [(i, t, n) for i, t, n in zip(range(partyN), totalSeat, pn)]
index.sort(key=lambda x: x[2])
index.sort(key=lambda x: x[1], reverse=True)
for i, t, n in index:
    print(pn[i], totalSeat[i])

# # debug
# print()
# for i in range(partyN):
#     print(i, pri[i], round(ppi[i],4), psi[i], pt[i], totalSeat[i])