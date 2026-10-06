def solution(logs, k):
    best = {}    # 로트별 최고 점수
    count = {}   # 로트별 검사 횟수
    for log in logs:
        lot, score = log.split()
        score = int(score)
        best[lot] = max(best.get(lot, -1), score)
        count[lot] = count.get(lot, 0) + 1

    # 최고 점수 높은 순 → 검사 횟수 적은 순 → 로트ID 사전순
    ranked = sorted(best, key=lambda lot: (-best[lot], count[lot], lot))
    return ranked[:k]
