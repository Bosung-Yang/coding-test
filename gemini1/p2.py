def solution(process, C):
    # 투 포인터 : [left, right] 안의 0 개수가 C 이하이면 전부 1로 만들 수 있음
    left = zeros = best = 0
    for right, v in enumerate(process):
        if v == 0:
            zeros += 1
        while zeros > C:              # 0이 너무 많으면 왼쪽을 당김
            if process[left] == 0:
                zeros -= 1
            left += 1
        best = max(best, right - left + 1)
    return best
