import sys

def main():
    args = sys.argv[1:]

    with open(args[0], 'r') as f:
        instructions = f.read()[:-1]

    n_rock = 0
    i = 0 # index of instruction
    len_in = len(instructions) # used to loop through instructions
    grid = {(0, 0), (1, 0), (2, 0), (3, 0), (4, 0), (5, 0), (6, 0)}
    f = 0

    def rock(rock_cords):
        nonlocal i
        nonlocal f
        last_cord = rock_cords[len(rock_cords)-1]
        first_cord = rock_cords[0]
        while(1):
            x = i%len_in
            i+=1
            check = 0
            if instructions[x] == '>' and last_cord[0] < 6:
                dx = 1
            elif instructions[x] == '<' and first_cord[0] > 0:
                dx = -1
            else:
                check = 1
            
            # checks if one move left/right hits rock/floor
            for r in rock_cords:
                if (r[0]+dx, r[1]) in grid:
                    check = 1
                    break
            if not check:
                for r in rock_cords:
                    r[0]+=dx

            # checks if one move down will hit rock/floor
            check = 0
            for r in rock_cords:
                if (r[0], r[1]-1) in grid:
                    check = 1
                    break
            if check:
                rock_cords = [tuple(r) for r in rock_cords]
                grid.update(rock_cords)
                f = max(rock_cords[len(rock_cords)-2][1], f)
                break

            for r in rock_cords:
                r[1]-=1

    while (n_rock < 2022):

        n = n_rock % 5
        # index 0 - min left, len-1 - min right, len-2 - max hieght
        if (n ==0):
            rock([[2, f+4], [3, f+4], [4, f+4], [5, f+4]])
        if (n == 1):
            rock([[2, f+5], [3, f+4], [3, f+5], [3, f+6], [4, f+5]])
        if (n ==2):
            rock([[2, f+4], [3, f+4], [4, f+5], [4, f+6], [4, f+4]])
        if (n ==3):
            rock([[2, f+4], [2, f+5], [2, f+6], [2, f+7], [2, f+4]])
        if (n == 4):
            rock([[2, f+4], [2, f+5], [3, f+5], [3, f+4]])
        
        n_rock+=1



if __name__ == '__main__':
    main()
