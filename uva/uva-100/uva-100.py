#!/usr/bin/python3

# https://uva.onlinejudge.org/external/1/100.pdf

#recursive solution

# 0. Modules
import sys

# 1. Global definitions and initializations
#worst_odd_n = 9038141
worst_odd_n = 100000000
cycle_length = [None] * ((3 * worst_odd_n) + 1 + 1) # cycle_length[0] not used
cycle_length[1] = 1

# 2. Functions
def calc_cycle_length(n):
    if n == 1:
        pass
    elif n%2==0:
        m = int(n/2)
    else:
        m = int((3*n)+1)

    if cycle_length[m] == None:
        calc_cycle_length(m)

    cycle_length[n] = 1 + cycle_length[m]

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
            if cycle_length[x] == None:
                calc_cycle_length(x)
            max_cycle_length = max(max_cycle_length,cycle_length[x])

        sys.stdout.write("%d %d %d\n" %(i, j, max_cycle_length))
    sys.exit(0)
