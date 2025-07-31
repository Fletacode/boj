from collections import deque

ay = [-1,1, 0,0]
ax = [ 0,0,-1,1]
area = [0 for _ in range(501*501)]
area_num = 1

def digg(col, land,visited):
    global area, area_num
    total = 0
    
    digg_visited = set()
    
    for i in range(len(land)):
        if land[i][col] == 1 and visited[i][col] == 0 and area[area_num] == 0:
            bfs(i,col,land,visited)
            total += area[area_num]
            digg_visited.add(area_num)
            area_num += 1
        elif land[i][col] == 1 and visited[i][col] != 0 and not visited[i][col] in digg_visited:
            digg_visited.add(visited[i][col])
            total += area[visited[i][col]]
    
    return total

def bfs(row,col, land,visited):
    global ay,ax, area_num,area
    
    dq = deque()
    dq.append((row,col))
    visited[row][col] = area_num
    cnt = 1
    
    while dq:
        now = dq.popleft()
        
        for i in range(4):
            y = now[0] + ay[i]
            x = now[1] + ax[i]
            
            if y < 0 or y >= len(land) or x < 0 or x >= len(land[0]):
                continue
            if visited[y][x] > 0 or land[y][x] == 0:
                continue
            
            cnt += 1
            dq.append((y,x))
            visited[y][x] = area_num
    
    area[area_num] = cnt
            
            
def solution(land):
    answer = 0
    
    visited = [[False for _ in range(len(land[0])) ] for _ in range(len(land))]
    
    for j in range(len(land[0])):
        answer = max(answer, digg(j,land,visited))
    
    
    return answer