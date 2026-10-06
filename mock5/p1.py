def solution(production):
    line_sums = [sum(row) for row in production]          # 라인(행) 합
    day_sums = [sum(col) for col in zip(*production)]     # 날짜(열) 합

    # index()는 최댓값이 여러 개면 가장 앞(작은 번호)을 돌려줌
    return [line_sums.index(max(line_sums)), day_sums.index(max(day_sums))]
