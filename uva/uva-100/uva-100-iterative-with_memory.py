#!/usr/bin/python3

# https://uva.onlinejudge.org/external/1/100.pdf

#iterative solution

# 0. Modules
import sys

# 1. Global definitions and initializations
SIZE = 10000000
cycle_length = [None] * SIZE
cycle_length[1] = 1

# 2. Functions
def calc_cycle_length(x, acc=0):
    n = x

    while n > 1:

        try:
            if cycle_length[n] != None:
                acc += cycle_length[n]
                break
        except IndexError:
            pass
            
        if n%2==0:
            m = int(n/2)
        else:
            m = int((3*n)+1)
        sys.stdout.write("%d " %(m))
        (n, acc) = (m, acc+1)
    cycle_length[x] = acc + 1
    sys.stdout.write("\n\t%d -> %d\n" %(x, cycle_length[x]))

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

        #sys.stdout.write("%d %d %d\n" %(i, j, max_cycle_length))
    sys.exit(0)
