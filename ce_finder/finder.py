import asyncio
from input_generator import *


async def runCmd(args, inp):
    process = await asyncio.create_subprocess_exec(
        *args, stdin=asyncio.subprocess.PIPE, stdout=asyncio.subprocess.PIPE
    )
    stdout, stderr = await process.communicate(input=inp.encode())
    return stdout.decode().strip()


def processCe(inp, ans, prob):
    print("!!!!Counter example found!!!!")
    print("INPUT:")
    print(inp)
    print("ANSWER:")
    print(ans)
    print("WA:")
    print(prob)


def make_command(file_name: list) -> list:
    if file_name[0].split(".")[-1] == "py":
        return ["python"] + file_name
    elif file_name[0].split(".")[-1] == "js":
        return ["node"] + file_name
    else:
        return file_name


def main(problem, answer, inputGenerator):
    path = "ce_finder/target/"
    ceFound = False
    idx = 1
    gen = inputGenerator()

    problem, answer = [path + problem], [path + answer]
    # if problem[0].split(".")[-1] == "py":
    #     problem = ["python"] + problem
    problem = make_command(problem)
    if answer[0].split(".")[-1] == "py":
        answer = ["python"] + answer
    for inp in gen:
        loop = asyncio.get_event_loop()
        print("Case No.", idx)
        commands = asyncio.gather(
            runCmd(answer, inp), runCmd(problem, inp)  # ['python', './prob.py']
        )
        ans, prob = loop.run_until_complete(commands)
        idx += 1
        print("Input: ")
        print(inp)
        print("Answer: ")
        print(ans)
        print()
        if ans != prob:
            ceFound = True
            processCe(inp, ans, prob)
            loop.close()
            break

    print("NO CE FOUND T_T") if not ceFound else print("CE FOUND!")


if __name__ != "__module__":
    main("problem.js", "solution", p1107)
