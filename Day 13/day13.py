import ast

def main():

    sorted_packets = []
    
    with open('input.txt', 'r') as f:
        packets = f.read().replace('\n\n', '\n').split('\n')[:-1]

    sort_packets(sorted_packets, [ast.literal_eval(packet) for packet in packets])

    print(sort_packets(sorted_packets, [[[2]], [[6]]]))
    
def check(left, right):
    lower_index = min(len(left), len(right))
   
    for i in range(0, lower_index):
        if isinstance(left[i], list) or isinstance(right[i], list):
            c = check(makelist(left[i]), makelist(right[i]))
            if c == "Same":
                continue
            else:
                return c
        else:
            if left[i] > right[i]:
                return False
            if left[i] < right[i]:
                return True

    if len(right) > len(left):
        return True
    elif len(right) < len(left):
        return False
    else:
        return "Same"

def sort_packets(sorted_packets, packets):
    res = 1

    for i in range(len(packets)):
        packet = packets[i]
        sorted_packets.append(packet)

        for j in range(len(sorted_packets)-1):
            c = check(sorted_packets[j], packet)
            if not c:
                sorted_packets.insert(j, packet)
                sorted_packets.pop()
                res*=j+1
                break
    return res

def makelist(l):
    if isinstance(l, list):
        return l
    else:
        return [l]



if __name__ == '__main__':
    main()
