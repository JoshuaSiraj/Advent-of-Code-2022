#!/usr/bin/env python3

total = 0

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
    return dir_total if dir_total <= 100000 else 0


with open("input.txt", 'r') as f:
    instructions = f.readlines()

i = 0
for instruction in instructions:
    
    if '$ cd' in instruction and ".." not in  instruction:
        print(instruction)
        total += calculate_size(instructions[i+1:])
    
    i+=1

print(total)
