def get_min_path(st,end,path):
    st_y = st[0]
    st_x = st[1]
    end_y = end[0]
    end_x = end[1]
    
    now_x, now_y = st_x, st_y
    
    while not (now_x == end_x and now_y == end_y):
        if now_y < end_y:
            now_y += 1
        elif now_y > end_y:
            now_y -= 1
        elif now_x < end_x:
            now_x += 1
        elif now_x > end_x:
            now_x -= 1
        
        path.append((now_y,now_x))

    return path
    
def all_bot_min_path(points,routes):
    
    all_paths = []
    
    for route in routes:
        st_p = points[route[0]-1] #[3,2]
        route.pop(0)
        path = [(st_p[0],st_p[1])]
        for end in route:
            end_p = points[end-1]
            get_min_path(st_p,end_p,path)
            st_p = end_p
        all_paths.append(path)
        
    return all_paths
        
def cal_accident(all_paths):
    d = {}
    for i, path in enumerate(all_paths):
        for t,pos in enumerate(path):
            d.setdefault(t+1,{})
            d[t+1].setdefault(pos,0)
            d[t+1][pos] += 1
            
    total_accient = 0
    
    for t in d:
        for pos in d[t]:
            if d[t][pos] > 1:
                total_accient += 1
                
    return total_accient

def solution(points, routes):
    all_paths = all_bot_min_path(points, routes)
    
    return cal_accident(all_paths)