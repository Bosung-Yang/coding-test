from collections import deque


def solution(grid, k):
    h, w = len(grid), len(grid[0])
    for y in range(h):
        for x in range(w):
            if grid[y][x] == 'S':
                sy, sx = y, x

    # 상태 = (y, x, 사용한 보호막 수)
    # 같은 칸이라도 남은 보호막이 다르면 이후 갈 수 있는 길이 달라지므로 따로 방문 처리
    dist = [[[-1] * (k + 1) for _ in range(w)] for _ in range(h)]
    dist[sy][sx][0] = 0
    q = deque([(sy, sx, 0)])

    while q:
        y, x, used = q.popleft()
        d = dist[y][x][used]
        if grid[y][x] == 'E':
            return d
        for dy, dx in ((1, 0), (-1, 0), (0, 1), (0, -1)):
            ny, nx = y + dy, x + dx
            if not (0 <= ny < h and 0 <= nx < w) or grid[ny][nx] == '#':
                continue
            nused = used + (1 if grid[ny][nx] == 'L' else 0)
            if nused > k or dist[ny][nx][nused] != -1:
                continue
            dist[ny][nx][nused] = d + 1
            q.append((ny, nx, nused))
    return -1
