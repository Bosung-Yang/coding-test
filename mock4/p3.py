from collections import deque


def solution(grid):
    h, w = len(grid), len(grid[0])
    visited = [[False] * w for _ in range(h)]
    regions = largest = 0

    for sy in range(h):
        for sx in range(w):
            if grid[sy][sx] != '#' or visited[sy][sx]:
                continue
            regions += 1
            visited[sy][sx] = True         # 시작점 방문 표시
            size = 1                       # 시작점 포함
            q = deque([(sy, sx)])
            while q:
                y, x = q.popleft()
                for dy in (-1, 0, 1):      # 8방향
                    for dx in (-1, 0, 1):
                        if dy == 0 and dx == 0:
                            continue
                        ny, nx = y + dy, x + dx
                        if 0 <= ny < h and 0 <= nx < w and grid[ny][nx] == '#' and not visited[ny][nx]:
                            visited[ny][nx] = True
                            size += 1
                            q.append((ny, nx))
            largest = max(largest, size)
    return [regions, largest]
