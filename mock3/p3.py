from collections import deque


def solution(grid, k):
    R, C = len(grid), len(grid[0])
    g = [list(row) for row in grid]
    rounds = removed = 0

    while True:
        # 1. 크기 k 이상인 같은 종류 덩어리 찾기 (표시만 하고 아직 안 지움)
        seen = [[False] * C for _ in range(R)]
        to_remove = []
        for y in range(R):
            for x in range(C):
                if g[y][x] == '.' or seen[y][x]:
                    continue
                kind = g[y][x]
                seen[y][x] = True
                group = [(y, x)]
                q = deque([(y, x)])
                while q:
                    cy, cx = q.popleft()
                    for dy, dx in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                        ny, nx = cy + dy, cx + dx
                        if 0 <= ny < R and 0 <= nx < C and not seen[ny][nx] and g[ny][nx] == kind:
                            seen[ny][nx] = True
                            group.append((ny, nx))
                            q.append((ny, nx))
                if len(group) >= k:
                    to_remove.extend(group)

        if not to_remove:
            break
        rounds += 1

        # 2. 동시에 제거
        for y, x in to_remove:
            g[y][x] = '.'
        removed += len(to_remove)

        # 3. 낙하 : 각 열의 블록을 순서 유지한 채 아래로 모음
        for x in range(C):
            blocks = [g[y][x] for y in range(R) if g[y][x] != '.']
            column = ['.'] * (R - len(blocks)) + blocks
            for y in range(R):
                g[y][x] = column[y]

    return [rounds, removed]
