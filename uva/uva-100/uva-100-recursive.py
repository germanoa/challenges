#!/usr/bin/python3

# https://uva.onlinejudge.org/external/1/100.pdf

#iterative solution

# 0. Modules
import sys

# 1. Global definitions and initializations


# 2. Functions
def calc_cycle_length(n):
    if n == 1:
        return 1
    elif n%2==0:
        m = int(n/2)
    else:
        m = int((3*n)+1)
    return 1 + calc_cycle_length(m)

# 3. Main
if __name__ == "__main__":
    while True:
        try:
            line = next(sys.stdin)
        except StopIteration:
            break
        try:
            i,j = map(int, line.split(" "))
            if i==0 or j==0:
                continue
        except ValueError:
            continue

        max_cycle_length = 0
        for x in range(min(i,j) , max(i,j)+1):
            max_cycle_length = max(max_cycle_length,calc_cycle_length(x))

        sys.stdout.write("%d %d %d\n" %(i, j, max_cycle_length))
    sys.exit(0)
