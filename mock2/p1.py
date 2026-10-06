def solution(score):
    h, w = len(score), len(score[0])

    # 기본 등급: 0 = A, 1 = B, 2 = F
    def grade(v):
        if v >= 90:
            return 0
        if v >= 70:
            return 1
        return 2

    base = [[grade(v) for v in row] for row in score]

    # 강등 판정은 모두 기본 등급 기준 (동시 판정)
    count = [0, 0, 0]
    for y in range(h):
        for x in range(w):
            f = 0
            for dy in (-1, 0, 1):
                for dx in (-1, 0, 1):
                    if dy == 0 and dx == 0:
                        continue
                    ny, nx = y + dy, x + dx
                    if 0 <= ny < h and 0 <= nx < w and base[ny][nx] == 2:
                        f += 1
            g = base[y][x]
            if f >= 3 and g != 2:
                g += 1                     # 한 단계 강등 (F는 그대로)
            count[g] += 1
    return count
