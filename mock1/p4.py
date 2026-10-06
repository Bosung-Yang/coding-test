from collections import deque


def solution(temp, k):
    n, m = len(temp), len(temp[0])

    def can_reach(h):
        # 온도 ≤ h 인 칸만 BFS → 도착까지 거리 ≤ k ?
        if temp[0][0] > h:
            return False
        dist = [[-1] * m for _ in range(n)]
        dist[0][0] = 0
        q = deque([(0, 0)])
        while q:
            y, x = q.popleft()
            if y == n - 1 and x == m - 1:
                return dist[y][x] <= k
            for dy, dx in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                ny, nx = y + dy, x + dx
                if 0 <= ny < n and 0 <= nx < m and dist[ny][nx] == -1 and temp[ny][nx] <= h:
                    dist[ny][nx] = dist[y][x] + 1
                    q.append((ny, nx))
        return False

    # 후보 H는 격자에 등장하는 온도값뿐 → 정렬해서 이분 탐색
    vals = sorted({v for row in temp for v in row})
    if not can_reach(vals[-1]):
        return -1
    lo, hi = 0, len(vals) - 1
    while lo < hi:
        mid = (lo + hi) // 2
        if can_reach(vals[mid]):
            hi = mid          # 가능 → 더 작은 H도 되는지
        else:
            lo = mid + 1      # 불가능 → H를 키움
    return vals[lo]
