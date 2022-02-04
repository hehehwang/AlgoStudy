import multiprocessing as mp
from polard_rho import pollard_rho
from heapq import heappop, heappush
from time import sleep, perf_counter
from os import cpu_count

QEND = -1


def oddeven(n: int):
    l = len(pollard_rho(n))
    return l % 2


def worker(wid: int, qin: mp.Queue, qout: mp.Queue):
    while 1:
        if qin.empty():
            continue
        n = qin.get()
        if n == QEND:
            break
        r = oddeven(n)
        qout.put((n, r, wid))


def supervisor(target: int):
    c = [0, 0]
    cpus = cpu_count()
    taskMax = min(target, 1000)
    qin, qout = mp.Queue(), mp.Queue()
    for i in range(1, taskMax + 1):
        qin.put(i)
    pool = [mp.Process(target=worker, args=(i, qin, qout)) for i in range(cpus)]

    for p in pool:
        p.start()

    idx, cache = 1, []
    while idx != target + 1:
        heappush(cache, qout.get())
        taskMax += 1
        qin.put(taskMax)
        if cache[0][0] == idx:
            v = heappop(cache)

            c[v[1]] += 1
            if c[0] > c[1]:
                print(v[0])

            idx += 1
    for i in range(cpus):
        qin.put(QEND)
    sleep(1)
    for i, p in enumerate(pool):
        p.kill()


if __name__ == "__main__":
    pfc = perf_counter()
    supervisor(int(1e7))
    print(perf_counter() - pfc)
