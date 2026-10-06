def solution(grid, commands):
    R, C = len(grid), len(grid[0])
    # 북 → 동 → 남 → 서 (시계 방향), 0번 = 위쪽
    DY = [-1, 0, 1, 0]
    DX = [0, 1, 0, -1]
    d = 0

    for i in range(R):
        for j in range(C):
            if grid[i][j] == 'S':
                y, x = i, j

    visited = {(y, x)}                   # 시작 칸 포함
    for cmd in commands:
        if cmd == "L":
            d = (d + 3) % 4
        elif cmd == "R":
            d = (d + 1) % 4
        else:                            # "F k"
            for _ in range(int(cmd[2:])):
                ny, nx = y + DY[d], x + DX[d]
                if not (0 <= ny < R and 0 <= nx < C) or grid[ny][nx] == '#':
                    break                # 남은 전진 취소
                y, x = ny, nx
                visited.add((y, x))
    return [y, x, len(visited)]
