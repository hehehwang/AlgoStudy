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


def validate_target(target_output: str, answer_output: str, validate_float: bool):
    if not validate_float:
        return target_output == answer_output
    else:
        target_split = target_output.split()
        answer_split = answer_output.split()
        if len(target_split) != len(answer_split):
            return False
        for i in range(len(target_split)):
            try:
                target_split[i] = float(target_split[i])
                answer_split[i] = float(answer_split[i])
            except ValueError:
                return False
            if target_split[i] != answer_split[i]:
                return False
        return True


def main(args: argparse.Namespace):
    problem_name = "p" + str(args.problem_number)
    if not hasattr(TcGen, problem_name):
        raise Exception("Problem number not found")

    target_filename = args.target_filename
    ans_filename = args.ans_filename
    tc_gen = getattr(TcGen, problem_name)
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

        val = validate_target(target, ans, args.validate_float)
        if not val:
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
    parser.add_argument("-vf", "--validate_float", action="store_true")
    args = parser.parse_args()
    main(args)
    # if hasattr(TcGen, problem_name):
    #     main(
    #         args.target_filename,
    #         args.ans_filename,
    #         getattr(TcGen, problem_name),
    #     )
    # else:
    #     print("No such problem")
