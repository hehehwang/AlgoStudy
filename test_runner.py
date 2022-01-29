import os
import platform
import subprocess
from pathlib import Path
from time import perf_counter
from typing import List

PREFIX = "20149_"
IO_SELECTOR = ["i", "o"]
POSTFIX = ".txt"
IDX_RANGE = 1, 18
IDX_CONST_LEN = 2

INPUT_DIR = Path("testdata/input/")
IS_OUTPUT = True
OUTPUT_DIR = Path("testdata/output/")

LANGUAGE = "python"
FILE_NAME = "solving"

COMPARE_NUMS = True


def run(command: List[str], stdin: str):
    process = subprocess.Popen(
        command, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE
    )

    runtime_start = perf_counter()
    v = process.communicate(input=stdin.encode())
    runtime_end = perf_counter()

    stdout = v[0].decode("euc-kr").strip()
    stderr = v[1].decode("euc-kr")
    runtime = round((runtime_end - runtime_start) * 1000)
    return stdout, stderr, runtime


def runner():
    if LANGUAGE.lower() in ["c++", "cpp", "c"]:
        file_path = [
            "exec/solving" + (".exe" if platform.system() == "Windows" else "")
        ]

    elif LANGUAGE.lower() in ["python", "python3", "py"]:
        file_path = ["python", "solving.py"]
    else:
        raise Exception("Language not supported")

    if not os.path.isfile(file_path[-1]):
        raise Exception("File not found in " + str(file_path))

    for i in range(IDX_RANGE[0], IDX_RANGE[1] + 1):
        idx = str(i).zfill(IDX_CONST_LEN)
        input_testfile = INPUT_DIR.joinpath(PREFIX + IO_SELECTOR[0] + idx + POSTFIX)
        answer_testfile = OUTPUT_DIR.joinpath(PREFIX + IO_SELECTOR[1] + idx + POSTFIX)

        if not os.path.isfile(input_testfile):
            raise Exception("Test input file not found in " + str(input_testfile))
        if IS_OUTPUT and not os.path.isfile(answer_testfile):
            raise Exception("Test output file not found in " + str(answer_testfile))

        input_data, answer_data = "", ""
        with open(input_testfile, "r") as f:
            input_data = f.read()

        if IS_OUTPUT:
            with open(answer_testfile, "r") as f:
                answer_data = f.read().strip()

        # print(file_path)
        # print(input_data)
        result = run(file_path, input_data)
        result_handler(idx, result, answer_data if IS_OUTPUT else None)


def result_handler(idx, result, answer):
    stdout, stderr, runtime = result
    print("\nTest case #" + idx + ":")
    if stderr:
        print("Error:")
        print(stderr)
    else:
        if IS_OUTPUT:
            if not COMPARE_NUMS:
                if stdout == answer:
                    print("Correct")
                else:
                    print("Wrong")
                    print("Expected:")
                    print(answer)
                    print("Got:")
                    print(stdout)
            else:
                stdout_split = stdout.split()
                answer_split = answer.split()
                for i in range(max(len(stdout_split), len(answer_split))):
                    if len(stdout) == i:
                        print("elements of stdout is less than answer")
                        break
                    if len(answer) == i:
                        print("elements of answer is less than stdout")
                        break
                    if float(stdout_split[i]) != float(answer_split[i]):
                        print("Wrong")
                        print("Expected:")
                        print(answer)
                        print("Got:")
                        print(stdout)
                        break
                else:
                    print("Correct")
        else:
            print("Output:")
            print(stdout)

    print("Runtime: " + str(runtime) + " ms")


if __name__ == "__main__":
    runner()
