import heapq

def solution(scoville, K):
    answer = 0
    
    heapq.heapify(scoville)
    pq = scoville
    
    while len(pq):
        if pq[0] >= K:
            return answer
        elif len(pq) < 2:
            return -1
        first = heapq.heappop(pq)
        second = heapq.heappop(pq)
        heapq.heappush(pq,first + (second * 2))
        answer += 1
            
    
    return answer