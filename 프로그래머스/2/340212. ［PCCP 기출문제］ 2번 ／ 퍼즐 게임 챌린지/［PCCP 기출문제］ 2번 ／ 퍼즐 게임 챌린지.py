def vaild_level(level,diffs, times, limit):
    
    prev_time = times[0]
    total_time = prev_time
    
    if total_time > limit:
        return False
    
    for idx, diff in enumerate(diffs):
        if idx == 0:
            continue
            
        wrong_cnt = 0 if diff <= level else diff - level
        
        total_time += (times[idx] +  prev_time) * wrong_cnt + times[idx]
        prev_time = times[idx]
        if total_time > limit:
            return False
        
    return True



def solution(diffs, times, limit):
    
    low = 1
    high = max(diffs)
    
    while low <= high:
        
        mid = (low+high) // 2
        
        if vaild_level(mid,diffs,times,limit):
            high = mid - 1
        else:
            low = mid + 1
    
    return low