from collections import deque


def solution(grid):
    R, C = len(grid), len(grid[0])
    for y in range(R):
        for x in range(C):
            if grid[y][x] == 'S':
                sy, sx = y, x

    # 상태 = (y, x, 카드 비트마스크)  — a: 1, b: 2, c: 4  → 0 ~ 7
    dist = [[[-1] * 8 for _ in range(C)] for _ in range(R)]
    dist[sy][sx][0] = 0
    q = deque([(sy, sx, 0)])

    while q:
        y, x, keys = q.popleft()
        d = dist[y][x][keys]
        if grid[y][x] == 'E':
            return d
        for dy, dx in ((1, 0), (-1, 0), (0, 1), (0, -1)):
            ny, nx = y + dy, x + dx
            if not (0 <= ny < R and 0 <= nx < C):
                continue
            ch = grid[ny][nx]
            if ch == '#':
                continue
            if 'A' <= ch <= 'C' and not (keys >> (ord(ch) - ord('A')) & 1):
                continue                                  # 카드가 없으면 문 통과 불가
            nkeys = keys
            if 'a' <= ch <= 'c':
                nkeys |= 1 << (ord(ch) - ord('a'))        # 카드 줍기
            if dist[ny][nx][nkeys] != -1:
                continue
            dist[ny][nx][nkeys] = d + 1
            q.append((ny, nx, nkeys))
    return -1
