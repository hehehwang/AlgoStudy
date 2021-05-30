import subprocess
import asyncio
from random import randint, choice
from itertools import combinations

async def runCmd(arg1, arg2, inp):
    process = await asyncio.create_subprocess_exec(
        arg1, arg2,
        stdin = asyncio.subprocess.PIPE,
        stdout = asyncio.subprocess.PIPE
    )
    stdout, stderr = await process.communicate(input = inp.encode())
    return stdout.decode().strip()

def processCe(inp, ans, prob):
    print("!!!!")
    print("INPUT:")
    print(inp)
    print("ANSWER:")
    print(ans)
    print("WA:")
    print(prob)

def makeInp(N, M, btn):
    inp = ''
    inp = str(N) + '\n'
    inp += str(M) + '\n'
    inp += ' '.join(btn)
    return inp

def main():
    ceFound = False
    for N in range(0, 10):
        for M in range(0, 10):
            for btn in combinations([str(i) for i in range(10)], M):
                inp = makeInp(N, M, btn)
                loop = asyncio.get_event_loop()
                commands = asyncio.gather(runCmd('python', './ans.py', inp),
                                          runCmd('python', './prob.py', inp))
                ans, prob = loop.run_until_complete(commands)
                print("Case:", N, M, "btn:", btn, ' ', ans, prob)
                if (ans != prob):
                    processCe(inp, ans, prob)
                    loop.close()
                    return

    for N in range(90, 110):
        for M in range(0, 10):
            for btn in combinations([str(i) for i in range(10)], M):
                inp = makeInp(N, M, btn)
                loop = asyncio.get_event_loop()
                commands = asyncio.gather(runCmd('python', './ans.py', inp),
                                          runCmd('python', './prob.py', inp))
                ans, prob = loop.run_until_complete(commands)
                print("Case:", N, M, "btn:", btn, ' ', ans, prob)
                if (ans != prob):
                    processCe(inp, ans, prob)
                    loop.close()
                    return

    for N in range(499_990, 500_001):
        for M in range(0, 10):
            for btn in combinations([str(i) for i in range(10)], M):
                inp = makeInp(N, M, btn)
                loop = asyncio.get_event_loop()
                commands = asyncio.gather(runCmd('python', './ans.py', inp),
                                          runCmd('python', './prob.py', inp))
                ans, prob = loop.run_until_complete(commands)
                print("Case:", N, M, "btn:", btn, ' ', ans, prob)
                if (ans != prob):
                    processCe(inp, ans, prob)
                    loop.close()
                    return

    print("NO CE FOUND bb")

if __name__ != "__module__":
    main()