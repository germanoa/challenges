#!/usr/bin/python3

# https://uva.onlinejudge.org/external/1/100.pdf

# 0. Modules
import sys

# 0. Global definitions and initializations
worst_odd_n = 99999
cycle_length = [None] * ((3 * worst_odd_n) + 1 + 1)	# cycle_length[0] not used
cycle_length[1] = 1

# 2. Functions

def calc_cycle_length(n):
    cycles = 1
    if n == 1:
        pass
    elif n%2==0:
        m = int(n/2)
    else:
        m = int((3*n)+1)
    #sys.stdout.write("n->m: %d -> %d\n" %(n,m))
    if cycle_length[m] == None:
        calc_cycle_length(m)
    else:
        cycle_length[m]
    cycle_length[n] = 1 + cycle_length[m]

def is_int(s):
    try:
        int(s)
        return True
    except ValueError:
        return False

# 3. Main

with open(sys.argv[1], 'r') as f:
    for line in f:
        if is_int(line.split(" ")[0]):
            i,j = map(int, line.split(" "))
        else:
            continue

        max_cycle_length = 0
        for x in range(min(i,j) , max(i,j)+1):
            if cycle_length[x] == None:
                calc_cycle_length(x)
            max_cycle_length = max(max_cycle_length,cycle_length[x])

            #for x in range(1,30):
            #    sys.stdout.write("%d -> %s\n" %(x, str(cycle_length[x])))
        sys.stdout.write("%d %d %d\n" %(i, j, max_cycle_length))
