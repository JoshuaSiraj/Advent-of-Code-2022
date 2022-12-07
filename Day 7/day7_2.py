#!/usr/bin/env python3

def calculate_size(instructions):
    dir_total = 0
    cd_request = 0

    for instruction in instructions:
        if '$ cd' in instruction and ".." not in  instruction:
            cd_request += 1

        if "cd .." in instruction:
            if cd_request != 0:
                print("changing dir")
                cd_request-=1
            else:
                break

        instruction = instruction.split()
        if instruction[0].isdigit():
            dir_total += int(instruction[0])
    
    print(dir_total)
    return dir_total 


with open("input.txt", 'r') as f:
    instructions = f.readlines()

i = 0
home_dir = calculate_size(instructions[1:])
space_available = 70000000 - home_dir

lowest_dir = home_dir
for instruction in instructions:
    
    if '$ cd' in instruction and ".." not in  instruction:
        print(instruction)
        curr_dir = calculate_size(instructions[i+1:])
        lowest_dir = curr_dir if (curr_dir + space_available >= 30000000) and curr_dir < lowest_dir else lowest_dir

    i+=1
print(lowest_dir)
