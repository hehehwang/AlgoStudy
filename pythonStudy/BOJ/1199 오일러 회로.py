# 1199 오일러 회로 (TL)
input = __import__('sys').stdin.readline
__import__('sys').setrecursionlimit(10**9)
n = int(input())
adj = [list(map(int, input().split())) for _ in range(n)]

circuit = []

def getEulerCircuit(here:int):
    for there in range(len(adj)):
        while adj[here][there]:
            adj[here][there] -= 1
            adj[there][here] -= 1
            getEulerCircuit(there)
    circuit.append(str(here+1))

ok = True
for l in adj:
    if sum(l)%2: ok = False;break
if ok:
    getEulerCircuit(0)
    print(' '.join(circuit))
else: print(-1)