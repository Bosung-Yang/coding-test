def rotate90(p):
    # 시계 방향 90도 회전 : 원래 (i, j) → (j, m-1-i)
    # zip(*p[::-1]) : 행을 뒤집은 뒤 열을 행으로 → 같은 결과
    return ["".join(row) for row in zip(*p[::-1])]


def solution(grid, pattern):
    n, m = len(grid), len(pattern)

    # 0, 90, 180, 270도 모양 미리 만들기
    shapes = [pattern]
    for _ in range(3):
        shapes.append(rotate90(shapes[-1]))

    count = 0
    for top in range(n - m + 1):                 # 놓을 수 있는 위치는 n - m + 1개
        for left in range(n - m + 1):
            sub = [grid[top + i][left:left + m] for i in range(m)]
            if any(sub == s for s in shapes):    # 하나라도 같으면 이 위치는 한 번만 셈
                count += 1
    return count
