def solution(grid, k):
    N = len(grid)
    placed = [[False] * N for _ in range(N)]
    best = -1

    # 고르기 백트래킹 : 칸 번호 c = y * N + x, start번 칸 이후만 후보
    def dfs(start, cnt, total):
        nonlocal best
        if cnt == k:
            best = max(best, total)
            return
        for c in range(start, N * N):
            y, x = divmod(c, N)
            if grid[y][x] == 0:
                continue                         # 장비가 있는 칸
            # 앞 번호 칸만 배치되어 있으므로 위쪽, 왼쪽만 확인하면 충분
            if (y > 0 and placed[y - 1][x]) or (x > 0 and placed[y][x - 1]):
                continue
            placed[y][x] = True
            dfs(c + 1, cnt + 1, total + grid[y][x])
            placed[y][x] = False                 # 되돌리기

    dfs(0, 0, 0)
    return best
