from collections import deque

class Que:
    def __init__(self, que):
        self.queue = deque(que)
        self.sum = sum(self.queue)
    def appendLeft(self, n):
        self.queue.appendleft(n)
        self.sum += n
    def pop(self):
        n = self.queue.pop()
        self.sum -= n

queue = deque([])
def f(num, target):
    global queue
    queue.append(num)
    while target < sum(queue): queue.popleft()
    if sum(queue) == target: return 1
    return 0

queue2 = Que([])
def f2(num, target):
    global queue
    queue2.appendLeft(num)
    while target < queue2.sum: queue2.pop()
    if queue2.sum == target: return 1
    return 0

def sigGen():
    a = 1983
    while 1:
        yield (a%10000)+1
        a = (a*214013+2531011)%(2**32)

v = sigGen()
rtn = 0
for i in range(5000000):
    rtn += f2(next(v), 3578452)
    # print(queue)
print(rtn)