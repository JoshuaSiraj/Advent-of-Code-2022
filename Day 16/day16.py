import sys
import re
from collections import defaultdict

def main():

    args = sys.argv[1:]
    flow_rate = {}
    graph = defaultdict(list)

    with open(args[0], 'r') as f:
        text = f.readlines()
        for line in text:
            line = re.findall(r'\b(?:[A-Z]+|\d+)\b', line)
            rate = int(line[1])
            flow_rate[line[0]] = rate
            graph[line[0]] = line[2:]

    minutes = 0
    pressure = 0
    curr_valve = 'AA'
    
    while(1):
        best_valve = bfs(curr_valve, 10, graph, flow_rate)
        print(best_valve)

        if best_valve == -1 or best_valve[0] + 1 + minutes >= 30:
            break
        
        curr_valve = best_valve[1]
        minutes += best_valve[0] + 1 
        pressure += flow_rate[curr_valve]*(30-minutes)
        print(minutes, pressure, flow_rate[curr_valve])
        flow_rate.pop(curr_valve)
    
    print(minutes, pressure)

    while(1):
        best_valve = bfs(curr_valve, 1, graph, flow_rate)
        print(best_valve)

        if best_valve == -1 or best_valve[0] + 1 + minutes >= 30:
            break

        curr_valve = best_valve[1]
        minutes += best_valve[0] + 1
        pressure += flow_rate[curr_valve]*(30-minutes)
        flow_rate.pop(curr_valve)
    
    print(minutes, pressure)
    
    #while(1):
    #    valves = [bfs(curr_valve, valve, graph, flow_rate) for valve in flow_rate.keys() if valve != curr_valve]
    #    print(valves)
    #    best_valve = valves[0]
    #    best_pressure = (31-minutes)*flow_rate[best_valve[1]]
    #    for valve in valves[1:]:
    #        if (31-minutes)*flow_rate[valve[1]] > best_pressure:
    #            best_valve = valve
    #            best_pressure = (31-minutes)*valve[0]

    #    print(best_valve)

    #    if flow_rate[best_valve[1]] == 0 or best_valve[0] + 1 + minutes > 30:
    #        break

    #    curr_valve = best_valve[1]
    #    minutes += best_valve[0] + 1
    #    pressure += best_pressure
    #    flow_rate.pop(curr_valve)
    
    #print(minutes, pressure)

# Returns first node >= goal
def bfs(start, goal, graph, flow_rate):

    if start == goal:
      return 0

    fvisited = {start}
    fqueue = [start]
    fdist = {start: 0}

    while fqueue:

      fnode = fqueue.pop(0)

      for nieghbour in graph[fnode]:
        if nieghbour not in fvisited:
          if nieghbour in flow_rate.keys() and flow_rate[nieghbour] >= goal:#flow_rate[nieghbour]* > fdist[fnode]+1:
              return (fdist[fnode] + 1, nieghbour)
          fvisited.add(nieghbour)
          fqueue.append(nieghbour)
          fdist[nieghbour] = fdist[fnode] + 1
      
    return -1        

if __name__ == '__main__':
    main()
