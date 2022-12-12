
hieghtmap = []

def main():
    
    global hieghtmap
    start = (0, 0)
    end = (0, 0)
    
    i = 0
    with open('input.txt', 'r') as f:
        for line in f:
            line.replace('\n', '')

            find_S = line.find('S')
            start = (i, find_S) if find_S != -1 else start

            find_E = line.find('E')
            end = (i, find_E) if find_E != -1 else end
            
            hieghtmap.append(list(line))
            i+=1
    hieghtmap[start[0]][start[1]] = 'a'
    hieghtmap[end[0]][end[1]] = 'z'

    #print(bfs(start, end))
    
    a_list = []
    for i in range(len(hieghtmap)):
        for j in range(len(hieghtmap[0])):
            if hieghtmap[i][j] == 'a':
                dist = bfs((i, j), end)
                if dist != -1:
                    a_list.append(dist)

    print(min(a_list))
    
def nieghbours(node):
    
    global hieghtmap

    nieghbours = []

    if node[0] > 0:
        nieghbours.append((node[0]-1, node[1]))
    if node[0] < len(hieghtmap)-1:
        nieghbours.append((node[0]+1, node[1]))
    if node[1] > 0:
        nieghbours.append((node[0], node[1]-1))
    if node[1] < len(hieghtmap[0])-1:
        nieghbours.append((node[0], node[1]+1))
    
    nieghbours = [n for n in nieghbours if ord(hieghtmap[n[0]][n[1]])-1 <= ord(hieghtmap[node[0]][node[1]])]
    return nieghbours

def bfs(start, goal):

    if start == goal:
      return 0

    fvisited = {start}
    fqueue = [start]
    fdist = {start: 0}

    while fqueue:

      fnode = fqueue.pop(0)

      for nieghbour in nieghbours(fnode):
        if nieghbour not in fvisited:
          if nieghbour == goal:
              return fdist[fnode] + 1
          fvisited.add(nieghbour)
          fqueue.append(nieghbour)
          fdist[nieghbour] = fdist[fnode] + 1
      
    return -1

if __name__ == '__main__':
    main()
