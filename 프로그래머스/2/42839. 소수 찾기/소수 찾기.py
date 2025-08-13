import math

answer = 0
s = set()
def check(num):
    origin_num = num
    # if num != 110:
    #     return
    
    val = 2
    
    while val < num:
        while num % val == 0:
            num //= val
        val += 1
    
    
    if num == origin_num:
        return False
    else:
        return True

def select(numbers, depth, visited, now):
    global answer, s
    if len(numbers) <= depth:  
        if depth >= 1 and int(now) > 1 and int(now) not in s:
            if not check(int(now)):
                s.add(int(now))
        return
   
    if depth >= 1 and int(now) > 1 and int(now) not in s:
        if not check(int(now)):
            s.add(int(now))
    
    for idx,i in enumerate(numbers):
        if visited[idx]:
            continue
        visited[idx] = True
        now += numbers[idx]
        select(numbers, depth + 1, visited, now)
        now = now[:-1]
        visited[idx] = False
    

def solution(numbers):
    global answer, s
    visited = [False for _ in numbers]
    select(numbers, 0, visited, "")

    return len(s)