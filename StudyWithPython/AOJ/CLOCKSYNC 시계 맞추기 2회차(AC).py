# CLOCKSYNC 시계 맞추기 #2 (AC)
input = __import__('sys').stdin.readline

switch = [[0, 1, 2],
          [3, 7, 9, 11],
          [4, 10, 14, 15],
          [0, 4, 5, 6, 7],
          [6, 7, 8, 10, 12],
          [0, 2, 14, 15],
          [3, 14, 15],
          [4, 5, 7, 14, 15],
          [1, 2, 3, 4, 5],
          [3, 4, 5, 9, 13]]

class Clock:
    def __init__(self, time):
        self.clock = [(t//3)%4 for t in time]
    def pressSw(self, swNo, press=1):
        for s in switch[swNo]:
            self.clock[s] += press
            self.clock[s] %= 4
    def pressSwLst(self, swLst, press=1):
        # swLst = [2, 0, 0, ...] -> 1번 스위치를 2번 눌러라
            for i, pressNum in enumerate(swLst):
                for s in switch[i]:
                    self.clock[s] += pressNum*press
                    self.clock[s] %= 4

for _ in range(int(input())):
    clocks = Clock(map(int, input().split()))
    if clocks.clock[14] != clocks.clock[15] or clocks.clock[8] != clocks.clock[12]:
        print(-1)
        continue

    s1 = (4 - clocks.clock[11])%4
    s2 = (clocks.clock[5] - clocks.clock[4])%4
    s4 = (4 - clocks.clock[8])%4
    s5 = (clocks.clock[1] - clocks.clock[2])%4
    s9 = (4 - clocks.clock[13])%4

    minTurn = 31
    for s0 in range(4):
        for s3 in range(4):
            for s6 in range(4):
                for s7 in range(4):
                    for s8 in range(4):
                        swLst = [s0, s1, s2, s3, s4, s5, s6, s7, s8, s9]
                        clocks.pressSwLst(swLst)
                        if sum(clocks.clock) == 0:
                            # print(swLst)
                            minTurn = min(minTurn, sum(swLst))
                        clocks.pressSwLst(swLst, -1)
    print(minTurn if minTurn != 31 else -1)