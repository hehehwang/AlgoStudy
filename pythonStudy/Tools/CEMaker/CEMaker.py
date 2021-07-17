import asyncio
from inputGenerator import *

async def runCmd(args, inp):
    process = await asyncio.create_subprocess_exec(
        *args,
        stdin = asyncio.subprocess.PIPE,
        stdout = asyncio.subprocess.PIPE
    )
    stdout, stderr = await process.communicate(input = inp.encode())
    return stdout.decode().strip()

def processCe(inp, ans, prob):
    print("!!!!Counter example found!!!!")
    print("INPUT:")
    print(inp)
    print("ANSWER:")
    print(ans)
    print("WA:")
    print(prob)

def main_p1799():
    ceFound = False
    idx = 1
    for inp in p1799(5):
        loop = asyncio.get_event_loop()
        commands = asyncio.gather(runCmd(['./exec/ans.exe'], inp), # ['python', './prob.py']
                                  runCmd(['./exec/prob.exe'], inp))
        ans, prob = loop.run_until_complete(commands)
        print("Case No.", idx)
        idx += 1
        if ans != prob:
            ceFound = True
            processCe(inp, ans, prob)
            loop.close()
            break

    print("NO CE FOUND T_T") if not ceFound else print('CE FOUND!')

def main():
    ceFound = False
    idx = 1
    gen = scpc2021_2()
    for inp in gen:
        loop = asyncio.get_event_loop()
        print("Case No.", idx)
        commands = asyncio.gather(runCmd(['./exec/2-naive.exe'], inp), # ['python', './prob.py']
                                  runCmd(['./exec/2.exe'], inp))
        ans, prob = loop.run_until_complete(commands)
        idx += 1
        print(inp)
        print(ans)
        print()
        if ans != prob:
            ceFound = True
            processCe(inp, ans, prob)
            loop.close()
            break

    print("NO CE FOUND T_T") if not ceFound else print('CE FOUND!')

if __name__ != "__module__":
    main()