# 오일러 회로
# TODO: 재귀 안재귀, 홀수지점 검출
# #     0  1  2  3  4
# adj=[[0, 1, 1, 0, 0], # 0
#      [1, 0, 1, 1, 1], # 1
#      [1, 1, 0, 0, 0], # 2
#      [0, 1, 0, 0, 1], # 3
#      [0, 1, 0, 1, 0], # 4
#     ]
#     0  1  2  3
adj=[[0, 1, 0, 1], # 0
     [1, 0, 1, 2], # 1
     [0, 1, 0, 1], # 2
     [1, 2, 1, 0], # 3
    ]
# #     0  1  2  3  4
# adj=[[0, 1, 0, 1, 1], # 0
#      [1, 0, 1, 1, 1], # 1
#      [0, 1, 0, 1, 0], # 2
#      [1, 1, 1, 0, 1], # 3
#      [1, 1, 0, 1, 0], # 4
#     ]

circuit = []

def getEulerCircuit(here:int):
    for there in range(len(adj)):
        while adj[here][there]:
            adj[here][there] -= 1
            adj[there][here] -= 1
            getEulerCircuit(there)
    circuit.append(here)
getEulerCircuit(1)


# stk = [0]
# while stk:
#     here = stk.pop()
#     for there in range(len(adj)):
#         while adj[here][there]:
#             adj[here][there] -= 1
#             adj[there][here] -= 1
#             here = there

print(circuit)