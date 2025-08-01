import heapq


def solution(jobs):
    pq = []
    heapq.heapify(pq)

    total_end_time = 0
    job_end_time = 0

    jobs.sort()
    idx = 0
    now_job = False

    for time in range(500*1001):
        if idx < len(jobs):
            job = jobs[idx]
            st = job[0]
            during_time = job[1]

            if st <= time:
                heapq.heappush(pq, (during_time, st, idx))
                idx += 1

        if not now_job and pq:
            now_job = heapq.heappop(pq)
            job_end_time = time + now_job[0]
        elif now_job and time >= job_end_time:
            total_end_time += time - now_job[1]
            if pq:
                now_job = heapq.heappop(pq)
                job_end_time = time + now_job[0]
            else:
                now_job = False


    answer = total_end_time // len(jobs)

    return answer