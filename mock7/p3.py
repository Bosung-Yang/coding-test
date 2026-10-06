from collections import deque


def solution(grid):
    R, C = len(grid), len(grid[0])
    dist = [[-1] * C for _ in range(R)]
    q = deque()

    # 다중 시작점 BFS : 모든 V를 처음부터 큐에 넣음
    for y in range(R):
        for x in range(C):
            if grid[y][x] == 'V':
                dist[y][x] = 0
                q.append((y, x))

    while q:
        y, x = q.popleft()
        for dy, dx in ((1, 0), (-1, 0), (0, 1), (0, -1)):
            ny, nx = y + dy, x + dx
            if 0 <= ny < R and 0 <= nx < C and grid[ny][nx] == '.' and dist[ny][nx] == -1:
                dist[ny][nx] = dist[y][x] + 1
                q.append((ny, nx))

    # 깨끗했던 칸 중 가장 늦게 오염된 시각 (하나라도 안 되면 -1)
    answer = 0
    for y in range(R):
        for x in range(C):
            if grid[y][x] == '.':
                if dist[y][x] == -1:
                    return -1
                answer = max(answer, dist[y][x])
    return answer
