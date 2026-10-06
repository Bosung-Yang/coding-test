def solution(readings, t):
    count = best = run = 0      # 구간 개수, 최대 길이, 현재 연속 길이
    for v in readings:
        if v > t:               # t '초과'면 경보
            run += 1
            if run == 1:
                count += 1      # 새 구간 시작
            best = max(best, run)
        else:
            run = 0             # 구간 끊김
    return [count, best]
