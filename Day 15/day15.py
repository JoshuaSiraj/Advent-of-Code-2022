import sys
import re

def main():

    args = sys.argv[1:]

    with open(args[0], 'r') as f:
        sensors = f.read().split('\n')
        sensors = [[int(i) for i in re.findall(r'\d+', s)] for s in sensors][:-1]
        sensors = [[s[0], s[1], abs(s[0] - s[2]) + abs(s[1] - s[3])] for s in sensors]
    
    check = 4000000
    
    for check_row in range(check+1):
        ranges = []

        for s in sensors:
            if (check_row <= s[1] + s[2] and check_row >= s[1] - s[2]):
                ranges.append([s[0] - (s[2] - abs(check_row-s[1])), s[0] + (s[2] - abs(check_row-s[1]))])

        ranges = merge(ranges)
        x = find(ranges, check)

        if x:
            print(x*check + check_row)
            break


def find(ranges, check):
    if len(ranges) > 1:
            for i in range(len(ranges)):
                if ranges[i][1] + 1 in range(0, check+1):
                    return ranges[i][1] + 1
    return 0

def merge(r):
    r.sort()
    stack = []
    # insert first interval into stack
    stack.append(r[0])
    for i in r[1:]:
        # Check for overlapping interval,
        # if interval overlap
        if stack[-1][0] <= i[0] <= stack[-1][-1]:
            stack[-1][-1] = max(stack[-1][-1], i[-1])
        else:
            stack.append(i)
    return stack 

if __name__ == '__main__':
    main()
