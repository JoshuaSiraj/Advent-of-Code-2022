import sys

def main():
    args = sys.argv[1:]

    with open(args[0], 'r') as f:
        lines = f.read().split('\n')[:-1]
        lines = [line.split(' -> ') for line in lines]
    
    filled = set()
    max_y = fill(filled, lines)

    print(simulate_2(filled, max_y+2))
    

def simulate_1(filled, max_y):
    
    set_sand = 0
    while(1):
        
        sand = (500, 0)
        while(1):
            if sand[1] + 1 > max_y:
                return set_sand
            
            if (sand[0], sand[1]+1) not in filled:
                sand = (sand[0], sand[1]+1)
            elif (sand[0]-1, sand[1]+1) not in filled:
                sand = (sand[0]-1, sand[1]+1)
            elif (sand[0]+1, sand[1]+1) not in filled:
                sand = (sand[0]+1, sand[1]+1)
            else:
                filled.add(sand)
                break

        set_sand+=1

def simulate_2(filled, max_y):

    set_sand = 0
    while((500, 0) not in filled):

        sand = (500, 0)
        while(1):
            
            if (sand[0], sand[1]+1) not in filled and sand[1] + 1 < max_y:
                sand = (sand[0], sand[1]+1)
            elif (sand[0]-1, sand[1]+1) not in filled and sand[1] + 1 < max_y:
                sand = (sand[0]-1, sand[1]+1)
            elif (sand[0]+1, sand[1]+1) not in filled and sand[1] + 1 < max_y:
                sand = (sand[0]+1, sand[1]+1)
            else:
                filled.add(sand)
                break

        set_sand+=1
    
    return set_sand

def fill(filled, lines):
    max_y = 0

    for line in lines:
        start = line[0].split(',')
        prev_x = int(start[0])
        prev_y = int(start[1])

        for cord in line[1:]:
            if prev_y > max_y:
                max_y = prev_y

            curr_cord = cord.split(',')
            curr_x = int(curr_cord[0])
            curr_y = int(curr_cord[1])

            path_x = curr_x - prev_x
            path_x = [x for x in range(path_x+1)] if path_x >= 0 else [x for x in range(0, path_x-1, -1)]
            path_y = curr_y - prev_y
            path_y = [x for x in range(path_y+1)] if path_y >= 0 else [x for x in range(0, path_y-1, -1)]


            for i in path_x:
                filled.add(((prev_x+i), prev_y))
            for j in path_y:
                filled.add((prev_x, prev_y+j))

            prev_x = curr_x
            prev_y = curr_y
    
    return max_y

if __name__ == '__main__':
    main()
