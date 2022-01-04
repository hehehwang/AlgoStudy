# TODO:
# 1. Add argparse
# 2. Add information about elapsed time
# 3. Colorize output
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


def main(prob_filename, ans_filename, inputGenerator):
    path = "ce_finder/target/"
    ceFound = False
    idx = 1
    gen = inputGenerator()

    prob_path, ans_path = [path + prob_filename], [path + ans_filename]
    prob_cmd, ans_cmd = make_command(prob_path), make_command(ans_path)
    for inp in gen:
        loop = asyncio.get_event_loop()
        print("Case No.", idx)
        commands = asyncio.gather(runCmd(ans_cmd, inp), runCmd(prob_cmd, inp))
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
    main("problem.py", "solution", p1107)
