# TODO:
# 0. Clearout path related problems & refactor structure
# 1. Add argparse
# 2. Add information about elapsed time
# 3. Colorize output
import asyncio
import pathlib
from pathlib import Path
from typing import Iterator, List

from input_generator import *


async def runCmd(args: List[str], stdin: str) -> str:
    process = await asyncio.create_subprocess_exec(
        *args, stdin=asyncio.subprocess.PIPE, stdout=asyncio.subprocess.PIPE
    )
    stdout, stderr = await process.communicate(input=stdin.encode())
    return stdout.decode().strip()


def ce_found_msg(wa, ans, prob):
    print("!!!!Counter example found!!!!")
    print("INPUT:")
    print(wa)
    print("ANSWER:")
    print(ans)
    print("WA:")
    print(prob)


def make_command(file_name: Path) -> List[str]:
    resolved_file_path = str(file_name.resolve())
    if file_name.suffix == ".py":
        return ["python", resolved_file_path]
    elif file_name.suffix == ".js":
        return ["node", resolved_file_path]
    else:
        return [resolved_file_path]


def main(prob_filename: str, ans_filename: str, case_gen: Iterator):
    base_path = Path("target/")
    ceFound = False
    idx = 1
    gen = case_gen()

    prob_path, ans_path = base_path.joinpath(prob_filename), base_path.joinpath(
        ans_filename
    )
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
            ce_found_msg(inp, ans, prob)
            loop.close()
            break

    print("NO CE FOUND T_T") if not ceFound else print("CE FOUND!")


if __name__ != "__module__":
    main("problem.py", "solution", p1107)
