import heapq


def solution(jobs):
    # 요청 시간 순으로 정렬해 두고, 요청된 작업을 우선순위 큐에 넣으며 처리
    jobs = sorted(jobs, key=lambda j: j[1])
    heap = []          # (소요 시간, 요청 시간, 작업 번호) → 이 순서대로 작은 것이 우선
    answer = []
    now = 0
    i, n = 0, len(jobs)

    while len(answer) < n:
        # 지금까지 요청된 작업을 모두 큐에 넣음
        while i < n and jobs[i][1] <= now:
            job_id, req, proc = jobs[i]
            heapq.heappush(heap, (proc, req, job_id))
            i += 1

        if not heap:
            now = jobs[i][1]           # 쉬는 중 → 다음 요청 시각으로 이동
            continue

        proc, req, job_id = heapq.heappop(heap)
        now += proc
        answer.append(job_id)
    return answer
