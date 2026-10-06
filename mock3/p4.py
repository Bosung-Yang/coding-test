from collections import deque
from itertools import permutations


def solution(grid):
    R, C = len(grid), len(grid[0])

    # 지점 모으기 : 0번 = S, 1번~ = P
    points = [(y, x) for y in range(R) for x in range(C) if grid[y][x] == 'S']
    points += [(y, x) for y in range(R) for x in range(C) if grid[y][x] == 'P']
    P = len(points)

    def bfs(sy, sx):
        dist = [[-1] * C for _ in range(R)]
        dist[sy][sx] = 0
        q = deque([(sy, sx)])
        while q:
            y, x = q.popleft()
            for dy, dx in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                ny, nx = y + dy, x + dx
                if 0 <= ny < R and 0 <= nx < C and grid[ny][nx] != '#' and dist[ny][nx] == -1:
                    dist[ny][nx] = dist[y][x] + 1
                    q.append((ny, nx))
        return dist

    # 지점마다 BFS 한 번 → 지점 사이 거리 표 D
    D = [[0] * P for _ in range(P)]
    for i, (y, x) in enumerate(points):
        dist = bfs(y, x)
        for j, (ty, tx) in enumerate(points):
            D[i][j] = dist[ty][tx]
            if D[i][j] == -1:
                return -1                 # 갈 수 없는 지점이 있음

    # 모든 방문 순서 시도 (P ≤ 8 → 8! = 40,320가지), S에서 출발해 S로 복귀
    best = float('inf')
    for order in permutations(range(1, P)):
        total = D[0][order[0]] + D[order[-1]][0]
        for a, b in zip(order, order[1:]):
            total += D[a][b]
        best = min(best, total)
    return best
