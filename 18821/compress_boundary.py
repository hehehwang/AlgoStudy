cursor = 0
init = True
with open("ce_output.txt", "r") as f:
    for line in f.readlines():
        num = int(line[6:])
        if init:
            cursor = num
            print(f"({cursor}, ", end="")
            init = False
            continue
        if num == cursor + 1:
            cursor += 1
        else:
            print(f"{cursor}), ")
            cursor = num
            print(f"({cursor}, ", end=" ")
    print(f"{num})")
