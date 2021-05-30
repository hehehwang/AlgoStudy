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

# async def runProb(inp):
#     p = subprocess.Popen(['python', './prob.py'], stdin=subprocess.PIPE, stdout=subprocess.PIPE, shell=True)
#     p.communicate(input=inp.encode())
#     problem = p.communicate()[0].decode()
#     return problem


def main():
    idx = 1
    while(1):
        print("Case #", idx)
        idx += 1

        N = randint(0, 500_000)
        M = randint(0, 10)
        btn = choice(list(combinations([str(i) for i in range(10)], M)))

        inp = str(N) + '\n'
        inp += str(M) + '\n'
        inp += ' '.join(btn)

        loop = asyncio.get_event_loop()
        commands = asyncio.gather(runCmd('python', './ans.py', inp),
                                  runCmd('python', './prob.py', inp))
        ans, prob = loop.run_until_complete(commands)
        # print(ans, prob)
        if (ans != prob):
            print("!!!!")
            print("INPUT:")
            print(inp)
            print("ANSWER:")
            print(ans)
            print("WA:")
            print(prob)
            loop.close()
            break

# original
# def main():
#     idx = 1
#     while(1):
#         print("Case #", idx)
#         idx += 1
#
#         N = randint(0, 500_000)
#         M = randint(1, 10)
#         btn = choice(list(combinations([str(i) for i in range(10)], M)))
#
#         inp = str(N) + '\n'
#         inp += str(M) + '\n'
#         inp += ' '.join(btn)
#
#         p = subprocess.Popen(['python', './ans.py'], stdin=subprocess.PIPE, stdout=subprocess.PIPE, shell=True)
#         p.communicate(input=inp.encode())
#         answer = p.communicate()[0].decode()
#
#         p = subprocess.Popen(['python', './prob.py'], stdin=subprocess.PIPE, stdout=subprocess.PIPE, shell=True)
#         p.communicate(input=inp.encode())
#         problem = p.communicate()[0].decode()
#
#         if (answer != problem):
#             print("!!!!")
#             print("INPUT:")
#             print(inp)
#             print("ANSWER:")
#             print(answer)
#             print("WA:")
#             print(problem)
#             break

if __name__ != "__module__":
    main()