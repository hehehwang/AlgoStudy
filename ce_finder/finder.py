# TODO:
# - Add information about elapsed time
# - Fluent message and options
import argparse
import asyncio
from pathlib import Path
from typing import Iterator, List

from tc_generator import TcGen


async def runCmd(args: List[str], stdin: str) -> str:
    process = await asyncio.create_subprocess_exec(
        *args, stdin=asyncio.subprocess.PIPE, stdout=asyncio.subprocess.PIPE
    )
    stdout, stderr = await process.communicate(input=stdin.encode())
    return stdout.decode().strip()


def ce_found_msg(stdin, ans, wa):
    print("!!!!Counter example found!!!!")
    print("INPUT:")
    print(stdin)
    print("ANSWER:")
    print(ans)
    print("WA:")
    print(wa)


def make_command(file_name: Path) -> List[str]:
    resolved_file_path = str(file_name.resolve())
    if file_name.suffix == ".py":
        return ["python", resolved_file_path]
    elif file_name.suffix == ".js":
        return ["node", resolved_file_path]
    else:
        return [resolved_file_path]


def main(target_filename: str, ans_filename: str, tc_gen: Iterator):
    ceFound = False
    idx = 1
    gen = tc_gen()

    base_path = Path("target/")
    target_path, ans_path = base_path.joinpath(target_filename), base_path.joinpath(
        ans_filename
    )
    target_cmd, ans_cmd = make_command(target_path), make_command(ans_path)
    for inp in gen:
        loop = asyncio.get_event_loop()
        print("Case No.", idx)
        commands = asyncio.gather(runCmd(ans_cmd, inp), runCmd(target_cmd, inp))
        ans, target = loop.run_until_complete(commands)
        idx += 1
        print("Input: ")
        print(inp)
        print("Answer: ")
        print(ans)
        print()
        if ans != target:
            ceFound = True
            ce_found_msg(inp, ans, target)
            loop.close()
            break

    print("NO CE FOUND T_T") if not ceFound else print("CE FOUND!")


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("target_filename", type=str)
    parser.add_argument("ans_filename", type=str)
    parser.add_argument("problem_number", type=int)
    args = parser.parse_args()
    problem_name = "p" + str(args.problem_number)
    if hasattr(TcGen, problem_name):
        main(
            args.target_filename,
            args.ans_filename,
            getattr(TcGen, problem_name),
        )
    else:
        print("No such problem")
