import heapq
import math

def main():
    rounds = 10000 

    with open('input.txt', 'r') as f:
        lines = f.read().splitlines()
    
    monkeys = [0 for x in lines if 'Monkey' in x]
    monkey_items = [list(map(int, i)) for i in (line.split(':')[1].strip().split(',') for line in lines if 'S' in line)]
    monkey_operations = [line.split(': ')[1].split('= ')[1] for line in lines if 'O' in line]
    monkey_test = [int(line.split('by ')[1]) for line in lines if 'Test' in line]
    monkey_true = [int(line.split(': throw to monkey ')[1]) for line in lines if 'true' in line]
    monkey_false = [int(line.split(': throw to monkey ')[1]) for line in lines if 'false' in line]
    
    for r in range(0, rounds):
        
        for i in range(0, len(monkeys)):

            while(len(monkey_items[i]) != 0):
               
                monkeys[i]+=1
                
                bruh = 1
                for x in monkey_test:
                    bruh*=x
                old = monkey_items[i][0] 
                new = eval(monkey_operations[i]) % bruh  

                if not (new % monkey_test[i]):
                    monkey_items[monkey_true[i]].append(new)
                    monkey_items[i].pop(0)
                else:
                    monkey_items[monkey_false[i]].append(new)
                    monkey_items[i].pop(0)
        
        #print(f'Round {round}: {monkey_items}')
   
    top2 = heapq.nlargest(2, monkeys)
    print(top2[0]*top2[1])
    #print(monkeys)

if __name__ == '__main__':
    main()
