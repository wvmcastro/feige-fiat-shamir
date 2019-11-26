from argparse import ArgumentParser
import os

def make_command(src_dir: str, in_file: str, dst_dir: str) -> str:
    role = in_file[0].upper()
    out = in_file.replace(".in", ".out")
    out_dst_file = dst_dir + out
    command = f"./soueu {role} < {src_dir}{in_file} > {out_dst_file}"

    out_src_file = src_dir + out
    return command, out_src_file, out_dst_file

def run_command(command: str) -> None:
    os.system(command)

def run_diff(file1: str, file2: str) -> None:
    os.system(f"diff -w {file1} {file2}")


if __name__ == "__main__":
    parser = ArgumentParser()
    parser.add_argument("src_dir", type=str)
    parser.add_argument("dst_dir", type=str)
    args = parser.parse_args()

    for root, _, files in os.walk(args.src_dir):
        if files != []:
            for f in files:
                if ".in" in f:
                    command, src_file, out_file = make_command(root, f, args.dst_dir)
                    run_command(command)
                    print(f"diff output for {src_file} and {out_file}")
                    run_diff(src_file, out_file)
                    print("-"*20)
                    print("")