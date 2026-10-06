def solution(cost, order):
    n = len(cost)
    INF = float('inf')

    # pre[b] : b보다 먼저 와야 하는 공정들의 비트마스크
    pre = [0] * n
    for a, b in order:
        pre[b] |= 1 << a

    # 비트마스크 DP (Python은 10! 순열 탐색이 느려서 DP 사용)
    # dp[mask][last] : mask에 속한 공정을 배치했고 마지막이 last일 때 최소 비용
    dp = [[INF] * n for _ in range(1 << n)]
    for i in range(n):
        if pre[i] == 0:                       # 선행 공정이 없어야 첫 공정 가능
            dp[1 << i][i] = 0

    for mask in range(1 << n):
        for last in range(n):
            cur = dp[mask][last]
            if cur == INF:
                continue
            for nxt in range(n):
                if mask >> nxt & 1:
                    continue                  # 이미 배치함
                if pre[nxt] & mask != pre[nxt]:
                    continue                  # 선행 공정이 아직 안 끝남
                nmask = mask | (1 << nxt)
                if cur + cost[last][nxt] < dp[nmask][nxt]:
                    dp[nmask][nxt] = cur + cost[last][nxt]

    best = min(dp[(1 << n) - 1])
    return -1 if best == INF else best        # 완성된 순서가 없으면 사이클
