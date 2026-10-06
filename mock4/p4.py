def solution(cost, power, needPower, conflicts):
    n = len(cost)
    conflict = [[False] * n for _ in range(n)]
    for a, b in conflicts:
        conflict[a][b] = conflict[b][a] = True

    picked = [False] * n
    best = float('inf')

    # 고르기 백트래킹 : 순서가 상관없으므로 start번 이후만 후보
    def dfs(start, c, p):
        nonlocal best
        if c >= best:
            return                          # 가지치기
        if p >= needPower:
            best = c                        # 전력 충족 → 더 고르면 비용만 늘어남
            return
        for i in range(start, n):
            if any(picked[j] and conflict[i][j] for j in range(i)):
                continue                    # 이미 고른 장비와 간섭
            picked[i] = True
            dfs(i + 1, c + cost[i], p + power[i])
            picked[i] = False               # 되돌리기

    dfs(0, 0, 0)
    return -1 if best == float('inf') else best
