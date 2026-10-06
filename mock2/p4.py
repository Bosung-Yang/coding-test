def solution(times, m, conflicts):
    n = len(times)
    conflict = [[False] * n for _ in range(n)]
    for a, b in conflicts:
        conflict[a][b] = conflict[b][a] = True

    assigned = [-1] * n
    load = [0] * m
    best = float('inf')

    # 나눠 담기 백트래킹 : task번 작업을 어느 장비에 줄지
    def dfs(task, cur_max):
        nonlocal best
        if cur_max >= best:
            return                           # 가지치기
        if task == n:
            best = cur_max
            return
        for mc in range(m):
            if any(assigned[p] == mc and conflict[p][task] for p in range(task)):
                continue                     # 같은 장비에 간섭 작업이 있음
            assigned[task] = mc
            load[mc] += times[task]
            dfs(task + 1, max(cur_max, load[mc]))
            load[mc] -= times[task]          # 되돌리기
            assigned[task] = -1

    dfs(0, 0)
    return -1 if best == float('inf') else best
