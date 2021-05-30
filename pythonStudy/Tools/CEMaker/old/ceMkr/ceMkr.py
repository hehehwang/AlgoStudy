import subprocess
from random import randint

idx = 1
while(1):
    print("Case #", idx)
    idx += 1

    MXN = 40_000
    N = randint(1, 10)
    inp = str(N) + '\n'
    for i in range(N):
        inp += str(randint(-MXN, MXN)) + ' ' + str(randint(-MXN, MXN))
        inp += '\n'

    p = subprocess.Popen(['ans.exe'], stdin = subprocess.PIPE, stdout = subprocess.PIPE, shell=True)
    p.communicate(input=inp.encode())
    answer = p.communicate()[0]

    p = subprocess.Popen(['prob.exe'], stdin = subprocess.PIPE, stdout = subprocess.PIPE, shell=True)
    p.communicate(input=inp.encode())
    problem = p.communicate()[0]

    if (answer != problem):
        print("!!!!")
        print("INPUT:")
        print(inp)
        print("ANSWER:")
        print(answer)
        print("WA:")
        print(problem)
        break