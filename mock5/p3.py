from collections import deque


def solution(grid):
    R, C = len(grid), len(grid[0])

    def bfs(sy, sx, goal):
        # (sy, sx)에서 goal 문자 칸까지 최단 거리 (못 가면 -1)
        dist = [[-1] * C for _ in range(R)]
        dist[sy][sx] = 0
        q = deque([(sy, sx)])
        while q:
            y, x = q.popleft()
            if grid[y][x] == goal:
                return dist[y][x]
            for dy, dx in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                ny, nx = y + dy, x + dx
                if 0 <= ny < R and 0 <= nx < C and grid[ny][nx] != '#' and dist[ny][nx] == -1:
                    dist[ny][nx] = dist[y][x] + 1
                    q.append((ny, nx))
        return -1

    for y in range(R):
        for x in range(C):
            if grid[y][x] == 'S':
                sy, sx = y, x
            elif grid[y][x] == 'P':
                py, px = y, x

    # S → P 와 P → E 를 따로 BFS (부품을 싣기 전에 E를 지나도 도착이 아님)
    to_p = bfs(sy, sx, 'P')
    if to_p == -1:
        return -1
    to_e = bfs(py, px, 'E')
    if to_e == -1:
        return -1
    return to_p + to_e
