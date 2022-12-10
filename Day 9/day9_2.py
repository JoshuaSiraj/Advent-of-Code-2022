#!/usr/bin/env python3

check = {(0, 0)}

def main():
    global check
    
    knots = [[0, 0], [0, 0], [0, 0], [0, 0], [0, 0], [0, 0], [0, 0], [0, 0], [0, 0], [0, 0]]

    options = {'R': [1, 0], 'L': [-1, 0], 'U': [0, 1], 'D': [0, -1]}

    with open("input.txt", 'r') as f:
        instructions = f.readlines()

    for instruction in instructions:
        direction = instruction[0]
        distance = int(instruction[2:])

        move(knots, distance, options[direction])
    
    print(len(check))

def move(knots, distance, delta):
    global check

    for n in range(1, distance+1):
        head = knots[0]
        head[0]+=delta[0]
        head[1]+=delta[1]
        
        for i in range(1, len(knots)):
            head = knots[i-1]
            tail = knots[i]
            if not_adjacent(head, tail):
                if (head[0] != tail[0] or head[1] != tail[1]):
                    tail[0]+=sign(head[0] - tail[0])
                    tail[1]+=sign(head[1] - tail[1])
                else:
                    tail[0]+=delta[0]
                    tail[1]+=delta[1]
                
                if i == 9:
                        check.add((tail[0], tail[1]))
            head = tail

def not_adjacent(head, tail):
    dist_x = head[0] - tail[0]
    dist_y = head[1] - tail[1]

    if (abs(dist_x) < 2 and abs(dist_y) < 2):
        return False
    
    return True   

def sign(x):
    return -1 if x < 0 else (1 if x > 0 else 0)

if __name__ == '__main__':
    main()
