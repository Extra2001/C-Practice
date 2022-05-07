import sys

with open('./in.txt', 'r+') as file:
    with open('./out2.txt', 'w+') as out:
        sys.stdin = file
        sys.stdout = out
        n = int(input())

        for item in range(n):
            str = input()
            old = input()
            new = input()
            print(str.replace(old, new))
