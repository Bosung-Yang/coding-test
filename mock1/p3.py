from collections import deque

DIRS = [(1, 0), (-1, 0), (0, 1), (0, -1)]


def solution(grid):
    h, w = len(grid), len(grid[0])
    INF = float('inf')

    # ① 가스 BFS (모든 G에서 동시에 시작) → gas[y][x] = 가스 도착 시각
    gas = [[INF] * w for _ in range(h)]
    q = deque()
    for y in range(h):
        for x in range(w):
            if grid[y][x] == 'S':
                sy, sx = y, x
            elif grid[y][x] == 'G':
                gas[y][x] = 0
                q.append((y, x))
    while q:
        y, x = q.popleft()
        for dy, dx in DIRS:
            ny, nx = y + dy, x + dx
            if 0 <= ny < h and 0 <= nx < w and grid[ny][nx] in '.S' and gas[ny][nx] == INF:
                gas[ny][nx] = gas[y][x] + 1
                q.append((ny, nx))

    # ② 작업자 BFS : t분에 가스가 오는 칸에는 t분에 못 들어감 (가스가 먼저 퍼짐)
    dist = [[-1] * w for _ in range(h)]
    dist[sy][sx] = 0
    q = deque([(sy, sx)])
    while q:
        y, x = q.popleft()
        if grid[y][x] == 'E':
            return dist[y][x]
        t = dist[y][x] + 1
        for dy, dx in DIRS:
            ny, nx = y + dy, x + dx
            if not (0 <= ny < h and 0 <= nx < w) or dist[ny][nx] != -1:
                continue
            ch = grid[ny][nx]
            if ch in '#G':
                continue
            if ch != 'E' and gas[ny][nx] <= t:
                continue
            dist[ny][nx] = t
            q.append((ny, nx))
    return -1
