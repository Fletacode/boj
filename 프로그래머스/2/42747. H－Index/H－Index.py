def solution(citations):
    answer = 0
    for h in range(10001):
        over = 0
        under = 0
        for i in citations:
            if h <= i:
                over += 1
            else:
                under += 1
        if over >= h and under <= h:
            answer = max(answer,h)
    
        
    return answer