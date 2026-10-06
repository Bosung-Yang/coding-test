def solution(scores, limit, K):
    # 행마다 limit '미만'인 칸 수를 세고, K개 '이상'인 행을 셈
    return sum(1 for row in scores if sum(1 for s in row if s < limit) >= K)
